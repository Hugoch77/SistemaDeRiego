#include <Arduino.h>

// Pin donde se conecta el relé o bomba de agua
const int RELAY_PIN = 7;

// Tiempos en milisegundos
const unsigned long RIEGO_DURACION  = 1UL * 60 * 60 * 1000;  // 1 hora
const unsigned long RIEGO_INTERVALO = 8UL * 60 * 60 * 1000;  // 8 horas

unsigned long tiempoAnterior = 0;
bool regando = false;

void setup() {
    Serial.begin(9600);
    pinMode(RELAY_PIN, OUTPUT);

    // Iniciar con un riego inmediato al encender
    digitalWrite(RELAY_PIN, HIGH);
    regando = true;
    tiempoAnterior = millis();

    Serial.println("Sistema de Riego iniciado");
    Serial.println("Riego activado (ciclo inicial)");
}

void loop() {
    unsigned long tiempoActual = millis();
    unsigned long transcurrido = tiempoActual - tiempoAnterior;

    if (regando) {
        // Si ya paso 1 hora, apagar el riego
        if (transcurrido >= RIEGO_DURACION) {
            digitalWrite(RELAY_PIN, LOW);
            regando = false;
            tiempoAnterior = tiempoActual;
            Serial.println("Riego desactivado. Esperando 8 horas...");
        }
    } else {
        // Si ya pasaron 8 horas, encender el riego
        if (transcurrido >= RIEGO_INTERVALO) {
            digitalWrite(RELAY_PIN, HIGH);
            regando = true;
            tiempoAnterior = tiempoActual;
            Serial.println("Riego activado");
        }
    }
}
