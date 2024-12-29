int soilValue; // Variabel untuk membaca nilai analog
const int relayPin = 6; // Pin digital untuk relay
int previousState = -1; // Untuk menyimpan status sebelumnya dari relay
unsigned long lastMillis = 0; // Untuk debounce
unsigned long debounceDelay = 1000; // Penundaan debounce 1 detik

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
  int currentState = (soilValue < 900) ? HIGH : LOW; // Tentukan state relay (HIGH untuk tanah basah, LOW untuk tanah kering)

  // Jika kondisi relay berubah atau sudah cukup lama, maka kontrol relay
  if (currentState != previousState && (millis() - lastMillis) > debounceDelay) {
    previousState = currentState;
    lastMillis = millis();

    if (currentState == HIGH) {
      Serial.println("Tanah Basah");
      digitalWrite(relayPin, HIGH); // Matikan relay (tanah basah)
    } else {
      Serial.println("Tanah Kering");
      digitalWrite(relayPin, LOW); // Nyalakan relay (tanah kering)
    }
  }

  Serial.println("-------------------------"); // Pemisah untuk memudahkan pembacaan
  delay(1000); // Penundaan untuk stabilkan pembacaan
}
