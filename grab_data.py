'''
Takes serial data from arduino, converts it into cartesian coordinates, and
writes it to a csv file. 
'''

import time
import serial
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import numpy as np
import csv
import pandas as pd
from math_functions import polar_to_cartesian, sensor_to_distance, apply_motor_correction

pitch = 120
min_pitch = 20

arduino_port = '/dev/ttyACM0'

baud_rate = 115200
serial_port = serial.Serial(arduino_port, baud_rate, timeout = 1)

sensor_data = pd.DataFrame(columns = ['x', 'y','z'])

try:
    while(pitch>min_pitch):
        data = serial_port.readline().decode()
        if len(data)>0:
            try:
                line_of_data = [int(x) for x in data.split(',')]
                print(line_of_data)
                distance = float(sensor_to_distance(line_of_data[0]))
                pitch = float(line_of_data[1])
                yaw = float(line_of_data[2])

                yaw_corrected = apply_motor_correction(yaw, 110, 20)
                pitch_corrected = apply_motor_correction(pitch, 70, 158)

                df_now = pd.DataFrame(
                    polar_to_cartesian(
                        distance, pitch_corrected, yaw_corrected).reshape(1,-1),
                    columns=list(sensor_data))
                sensor_data = sensor_data.append(df_now,ignore_index=True)
            except:
                continue

        time.sleep(0.5)
except KeyboardInterrupt:
    pass
print(sensor_data)
sensor_data.to_csv('sensor_data.csv', index = False)

