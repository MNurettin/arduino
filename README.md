# Arduino Potentiometer Mouse Controller

A lightweight, low-latency mouse controller system that enables hardware-based cursor positioning using an Arduino and custom C++ console application via Windows API (`windows.h`). 

The project avoids heavy frameworks (like `iostream`) and utilizes low-level serial communication protocols to ensure maximum efficiency.

## 🚀 Features
- **Zero-Overhead C++ Client:** Built entirely on standard C libraries (`stdio.h`) and Win32 API. No heavy C++ stream overhead.
- **Custom Packet Framing:** Implements a robust **SOF (Start of Frame)** mechanism using a specific Sync Byte (`255`) to prevent data alignment drift.
- **Byte Stuffing / Escaping:** Data integrity is secured by escaping data bytes that match the sync signature (`255 -> 254`).
- **Deadzone Filtering:** Noise reduction implemented on the hardware side to prevent cursor jittering.

## 🛠️ Project Structure
- `/Arduino_Code`: Contains the `.ino` sketch for reading analog pins and streaming byte frames.
- `/CPP_Console_Code`: Contains the native Win32 C++ application that reads the serial port and controls the mouse cursor.

## ⚙️ Architecture & Protocol Design
The communication protocol sends a **5-byte packet** for every verified coordinate change:
`[ 255 (SOF) ] -> [ X_High_Byte ] -> [ X_Low_Byte ] -> [ Y_High_Byte ] -> [ Y_Low_Byte ]`

- **Resolution Mapping:** The 10-bit analog input (`0-1023`) is mapped linearly to screen pixel spaces (e.g., `1920x1080`) using direct integer math without floating-point performance loss.

## 💻 Installation & Usage
1. Upload the sketch inside `Arduino_Code` to your Arduino board.
2. Connect two potentiometers to `A0` and `A1` pins.
3. Open the C++ project, ensure your COM port identifier matches (default is `\\\\.\\COM3`), compile and run.

# Arduino Potansiyometre ile Fare (Mouse) Kontrolcüsü

Bu proje, bir Arduino ve Windows API (`windows.h`) kullanan yerel bir C++ konsol uygulaması aracılığıyla donanım tabanlı imleç konumlandırması sağlayan hafif ve düşük gecikmeli bir kontrolcü sistemidir.

Maksimum performans ve bellek optimizasyonu için `iostream` gibi hantal kütüphaneler yerine saf C kütüphaneleri ve alt seviye seri iletişim mimarisi tercih edilmiştir.

## 🚀 Özellikler
- **Sıfır Yük (Zero-Overhead) C++ İstemcisi:** Tamamen `<stdio.h>` ve Win32 API mimarisi üzerine kurulmuştur.
- **Özel Paket Çerçeveleme (Packet Framing):** Veri kaymasını (Hizalama hatası) önlemek için `255` imzasını kullanan gelişmiş bir **SOF (Start of Frame)** protokolü içerir.
- **Byte Stuffing (Veri Kaçış Mekanizması):** Koordinat verilerinin başlangıç imzasıyla karışmasını engellemek için veri içindeki 255 değerleri otomatik olarak 254'e dönüştürülür.
- **Donanımsal Filtreleme (Deadzone):** Potansiyometrelerdeki elektriksel parazit ve titremeleri engellemek için Arduino tarafında gürültü filtresi uygulanmıştır.

## 🛠️ Proje Yapısı
- `/Arduino_Code`: Analog pinleri okuyan ve paket fırlatan `.ino` kodlarını içerir.
- `/CPP_Console_Code`: Seri portu dinleyen ve imleci hareket ettiren Win32 C++ kodlarını içerir.

## ⚙️ Protokol Tasarımı
Haberleşme hattı, her koordinat değiştiğinde **5 byte'lık bir paket** akışı gerçekleştirir:
`[ 255 (SOF) ] -> [ X_Tam_Sayı ] -> [ X_Mod_Değeri ] -> [ Y_Tam_Sayı ] -> [ Y_Mod_Değeri ]`

- **Çözünürlük Eşleme:** 10-bitlik analog veri (`0-1023`), float (ondalıklı) sayı yükü oluşturmadan doğrudan tam sayı matematiği ile ekran çözünürlüğüne (`1920x1080`) oranlanır.

## 💻 Kurulum ve Çalıştırma
1. `Arduino_Code` klasöründeki kodu Arduino'nuza yükleyin.
2. Potansiyometreleri `A0` ve `A1` analog pinlerine bağlayın.
3. C++ kodundaki COM port adının Arduino'nuzla eşleştiğinden emin olun (Varsayılan: `\\\\.\\COM3`), derleyin ve çalıştırın.
