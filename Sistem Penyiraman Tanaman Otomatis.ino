int soilValue; // Variabel untuk membaca nilai analog
const int relayPin = 3; // Pin digital untuk relay

void setup() {
  Serial.begin(9600); // Inisialisasi komunikasi serial
  pinMode(relayPin, OUTPUT); // Pin relay diatur sebagai output
  digitalWrite(relayPin, LOW); // Pastikan relay dalam kondisi mati saat awal
}

void loop() { 
  // Membaca nilai analog dari pin A0
  soilValue = analogRead(A0); 

  // Menampilkan hasil pembacaan analog
  Serial.print("Analog Value: ");
  Serial.println(soilValue);

  // Logika kontrol relay berdasarkan nilai analog
  if (soilValue < 500) { // Sesuaikan threshold sesuai dengan kondisi sensor
    Serial.println("Tanah Basah");
    digitalWrite(relayPin, HIGH); // Matikan relay (tanah basah)
  } else {
    Serial.println("Tanah Kering");
    digitalWrite(relayPin, LOW); // Nyalakan relay (tanah kering)
  }

  Serial.println("-------------------------"); // Pemisah untuk memudahkan pembacaan
  delay(400); 
}
