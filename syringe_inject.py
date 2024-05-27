import serial
import time

ser = serial.Serial('COM7', baudrate=9600, timeout=1)
time.sleep(2)

ser.write(b'1')

ser.close()