#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "YOUR_SSID";     // Enter your ssid
const char *password = "YOUR_PASSWORD"; // Enter your password

ESP8266WebServer server(80);

int soilMoisture = 0; // Variable to store soil moisture value

void setup()
{
    Serial.begin(9600);

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi. IP address: ");
    Serial.println(WiFi.localIP());

    // Set up routes
    server.on("/", handleRoot);
    server.on("/moisture", handleMoisture);

    // Start server
    server.begin();
    Serial.println("HTTP server started");
}

void loop()
{
    server.handleClient();

    // Read soil moisture every 5 seconds
    static unsigned long lastMillis = 0;
    if (millis() - lastMillis > 5000)
    {
        lastMillis = millis();
        soilMoisture = analogRead(A0);
        Serial.print("Moisture Value: ");
        Serial.println(soilMoisture);
    }
}

// Handle root URL
void handleRoot()
{
    server.send(200, "text/html", getIndexPage());
}

// Handle moisture URL
void handleMoisture()
{
    server.send(200, "text/plain", String(soilMoisture));
}

// Generate HTML for the index page
String getIndexPage()
{
    String page = "<!DOCTYPE html>";
    page += "<html><head><title>Soil Moisture Sensor</title></head>";
    page += "<body><h1>Soil Moisture: <span id='soilMoisture'>Loading...</span></h1>";
    page += "<script>";
    page += "function updateMoisture() {";
    page += "fetch('/moisture').then(response => response.text()).then(data => {";
    page += "document.getElementById('soilMoisture').innerText = data;";
    page += "}).catch(error => console.error('Error fetching data:', error));";
    page += "}";
    page += "setInterval(updateMoisture, 5000);"; // Fetch data every 5 seconds
    page += "updateMoisture();";                  // Initial fetch
    page += "</script>";
    page += "</body></html>";
    return page;
}
