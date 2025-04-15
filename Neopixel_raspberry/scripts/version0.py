import time
from rpi_ws281x import PixelStrip, Color

# Configuración de la matriz
LED_COUNT = 64          # Número de LEDs (8x8)
LED_PIN = 18            # GPIO18 (Pin 12)
LED_FREQ_HZ = 800000    # Frecuencia de la señal (no modificar)
LED_DMA = 10            # Canal DMA (usar 10 para Pi 3B+)
LED_BRIGHTNESS = 10     # Brillo (0-255)
LED_INVERT = False      # Invertir señal (no necesario)

# Inicializar la tira de LEDs
strip = PixelStrip(LED_COUNT, LED_PIN, LED_FREQ_HZ, LED_DMA, LED_INVERT, LED_BRIGHTNESS)
strip.begin()

def color_all(color):
    """Encender todos los LEDs del mismo color"""
    for i in range(strip.numPixels()):
        strip.setPixelColor(i, color)
    strip.show()

def spiral_animation(wait_ms=50):
    """Animación en espiral con colores aleatorios"""
    from random import randint
    for i in range(LED_COUNT):
        strip.setPixelColor(i, Color(randint(0, 255), randint(0, 255), randint(0, 255)))
        strip.show()
        time.sleep(wait_ms / 1000.0)

def mi_funcion():
    print("Entrando a mi funcion JAMID")
    for i in range(strip.numPixels()):
        if i%2 == 1:
            print(i)
            strip.setPixelColor(i, Color(0, i, 0))
            strip.show()
            time.sleep(1)
            strip.setPixelColor(i, Color(0, 0, 0))

def scanner(color, delay=0.1):
    for i in range(strip.numPixels()):
        strip.setPixelColor(i, color)
        strip.show()
        time.sleep(delay)
        strip.setPixelColor(i, Color(0, 0, 0))  # Apagar

def chessboard(color1, color2):
    for i in range(LED_COUNT):
        row = i // 8
        col = i % 8
        strip.setPixelColor(i, color1 if (row + col) % 2 == 0 else color2)
    strip.show()

def clock(hour, minute):
    #color_all(Color(0, 0, 0))
    hour_led = (hour % 12) * 5 + (minute // 12)  # Mapeo a LEDs
    strip.setPixelColor(hour_led, Color(255, 0, 0))  # Hora en rojo
    strip.setPixelColor(minute, Color(0, 255, 0))    # Minuto en verde
    strip.show()

import random

def rain(color, drops=10):
    for _ in range(drops):
        col = random.randint(0, 7)
        for row in range(8):
            strip.setPixelColor(row * 8 + col, color)
            strip.show()
            time.sleep(0.1)
            strip.setPixelColor(row * 8 + col, Color(0, 0, 0))

def spiral():
    colors = [Color(255,0,0), Color(0,255,0), Color(0,0,255)]
    for i in range(LED_COUNT):
        strip.setPixelColor(i, colors[i % 3])
        print("El valor de i % 3 cuando i es igual a ", i)
        print(i % 3)
        strip.show()
        time.sleep(0.1)

if __name__ == "__main__":
    try:
        print("Encendiendo matriz NeoPixel...")
        #color_all(Color(255, 255, 255))  # Rojo (R, G, B)
        #time.sleep(2)
        #color_all(Color(0, 0, 0))    # Apagar
        #spiral_animation()
        #mi_funcion()
        #time.sleep(3)
        #scanner(Color(255, 0, 255))
        #chessboard(Color(255, 255, 255), Color(0, 0, 0))  # Blanco y negro
        #clock(3, 45)
        #rain(Color(0, 255, 0))
        #time.sleep(5)
        spiral()
        color_all(Color(0, 0, 0))
    except KeyboardInterrupt:
        color_all(Color(0, 0, 0))
