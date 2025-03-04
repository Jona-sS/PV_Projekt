import serial
import time
# Serielle Schnittstelle konfigurieren
ser = serial.Serial('/dev/serial0', 9600, timeout=1)
ser.flush()

# Datei zum Speichern der Daten öffnen
with open("spannung_log.txt", "a") as file:
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            print(line)
            file.write(f"{time.strftime('%Y-%m-%d %H:%M:%S')} - {line}\n")
            file.flush()
        time.sleep(1)