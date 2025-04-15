import sounddevice as sd
import numpy as np
from rpi_ws281x import PixelStrip, Color
import time

# Configuración de la matriz LED
LED_COUNT = 64          # 8x8
LED_PIN = 18            # GPIO18
LED_FREQ_HZ = 800000
LED_DMA = 10
LED_BRIGHTNESS = 20     # Brillo bajo para evitar sobrecalentamiento
LED_INVERT = False

strip = PixelStrip(LED_COUNT, LED_PIN, LED_FREQ_HZ, LED_DMA, LED_INVERT, LED_BRIGHTNESS)
strip.begin()

# Configuración de audio
SAMPLE_RATE = 44100     # Tasa de muestreo estándar
DURATION = 0.05         # Duración del buffer en segundos
COLORS = [
    (0, 0, 255),        # Azul (bajos)
    (0, 255, 0),        # Verde (medios)
    (255, 0, 0)         # Rojo (agudos)
]

def audio_callback(indata, frames, time, status):
    """Analiza el audio y actualiza la matriz."""
    if status:
        print("Error de audio:", status)
        return
    
    # Calcular FFT (transformada rápida de Fourier)
    fft_data = np.abs(np.fft.rfft(indata[:, 0]))
    fft_data = fft_data[:len(fft_data)//2]  # Solo frecuencias relevantes
    
    # Dividir en 3 bandas de frecuencia (bajos, medios, agudos)
    bass = np.mean(fft_data[:10])
    mid = np.mean(fft_data[10:50])
    treble = np.mean(fft_data[50:100])
    
    # Mapear intensidad a LEDs (8 filas)
    bass_level = min(int(bass / 500 * 8), 8)
    mid_level = min(int(mid / 200 * 8), 8)
    treble_level = min(int(treble / 100 * 8), 8)
    
    # Dibujar en la matriz
    strip.fill(Color(0, 0, 0))
    for i in range(bass_level):
        for col in range(2):  # Columnas 0-1 para bajos
            strip.setPixelColor(i * 8 + col, Color(*COLORS[0]))
    for i in range(mid_level):
        for col in range(2, 5):  # Columnas 2-4 para medios
            strip.setPixelColor(i * 8 + col, Color(*COLORS[1]))
    for i in range(treble_level):
        for col in range(5, 8):  # Columnas 5-7 para agudos
            strip.setPixelColor(i * 8 + col, Color(*COLORS[2]))
    strip.show()

try:
    print("Iniciando visualizador de música... (Presiona Ctrl+C para detener)")
    with sd.InputStream(callback=audio_callback, channels=1, samplerate=SAMPLE_RATE, blocksize=int(SAMPLE_RATE * DURATION)):
        while True:
            time.sleep(0.1)
except KeyboardInterrupt:
    print("\nDeteniendo...")
    strip.fill(Color(0, 0, 0))
    strip.show()
