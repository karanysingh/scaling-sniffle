#include <ESP8266WiFi.h>

const char* ssid = "BSNL_FIBRE";
const char* password = "28200311";

const char* host = "arduinoiotbot.herokuapp.com";

char state   = '-';

const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;


void setup() {
state = 'w';
  Serial.begin(115200);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
    pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void loop() {

  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "/";
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 10000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  
 while (client.available()) {
    char c = client.read();

    if(c == '\n')
    {
      c = client.read();
      if(c == '\r')
      {
        c = client.read();
        if(c == '\n')
        {
          c = client.read();
          Serial.print(F("Machine state: "));
          Serial.println(c);
          state = c;
            execution(state);
        }
      }
    }
}

//delay(100);
//execution('p');
}


void execution(char state){
//  if(state == 'w' || state == 'a'|| state == 's' || state == 'd' || state == 'p'){
  switch(state)
  {
    case 'w': {
  Serial.println("Forward");
  forward();
  break;
}
    case 'a': { 
  Serial.println("Moving Left");
  left();
  break;
    }
    case 'd': {
  Serial.println("Moving Right");
  right();
  break;
}
case 's': {
  Serial.println("Reverse");
  reverse();
  break;
}
 
  case 'p' :
  {
    s_stop();
    break;
  }
 }
// }
}

void forward()
{
  digitalWrite(IN1, HIGH);
//  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
//  digitalWrite(IN4, LOW);
//  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
//  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(2000);
}

void reverse()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2000);
}

void left()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2000);
}

void right()
{

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2000);
}

void s_stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(2000);
}
