const char* host = "32.monitoring-esp.ml";
const char* key = "712";
void sendtoweb(int people){
    WiFiClient client;
    const int httpPort = 80;
    if (!client.connect(host, httpPort)) { //works!
      Serial.println("connection failed");
      return;
    }
    String url = "/add.php";
    url += "?people=";
    if(people>0){url += people;}
    if(people==0){url += "00";}
    url += "&key=";
    url += key;
    Serial.print("Requesting URL: ");
    Serial.println(url);
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");

    Serial.println();
    Serial.println("closing connection");
}
