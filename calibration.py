import serial
import csv 

arduinoComPort = "/dev/ttyACM0"

baudRate = 9600 
serialPort = serial.Serial(arduinoComPort, baudRate, timeout = 1)

calibrationData = open('calibrationData.csv', 'w')
writer = csv.writer(calibrationData)
writer.writerow('sensor output')

while True: 
    lineOfData = serialPort.readline().decode()
    writer.writerow(lineOfData)

calibrationData.close()
