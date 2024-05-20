#include <Arduino.h>
#include <WiFiS3.h>
#include <WiFiSSLClient.h>
#include <ArduinoHttpClient.h>
#include <ArduinoJson.h>

const char* ssid = "YOUR_NETWORK";
const char* password = "YOUR_PASSWORD";
const char* openaiApiKey = "YOUR_TOKEN";
String answer;
WiFiSSLClient sslClient;
HttpClient httpClient = HttpClient(sslClient, "api.openai.com", 443);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi network");
}

void loop() {
  int temperature_now = random(35);
  Serial.println(temperature_now);
  String question = "What to wear if temperature is ";
  question.concat(temperature_now);
  Serial.println(question);

    DynamicJsonDocument jsonDoc(1024);
    jsonDoc["model"] = "gpt-3.5-turbo";
    jsonDoc["temperature"] = 0.7;
    JsonArray messages = jsonDoc.createNestedArray("messages");
    JsonObject messageObj = messages.createNestedObject();
    messageObj["role"] = "user";
    messageObj["content"] = question;

    String requestBody;
    serializeJson(jsonDoc, requestBody);

    httpClient.beginRequest();
    httpClient.post("/v1/chat/completions");
    httpClient.sendHeader("Content-Type", "application/json");
    httpClient.sendHeader("Authorization", "Bearer " + String(openaiApiKey));
    httpClient.sendHeader("Content-Length", requestBody.length());
    httpClient.beginBody();
    httpClient.print(requestBody);
    httpClient.endRequest();

    int statusCode = httpClient.responseStatusCode();
    String response = httpClient.responseBody();
    
    DynamicJsonDocument jsonDoci(2048); 
    deserializeJson(jsonDoci, response);

    JsonArray choices = jsonDoci["choices"].as<JsonArray>();
    for (JsonObject choice : choices) {
        
        JsonObject message = choice["message"].as<JsonObject>();
        if (message["role"].as<String>() == "assistant") {
            answer = message["content"].as<String>();
            break; 
        }
    }

    
    Serial.println("Answer from OpenAI: " + answer);

    
    delay(10000);   
 
}
