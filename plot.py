'''
Takes the Arduino serial output data and plots it in 3D. 
'''

import serial
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import numpy as np

arduino_port = "/dev/tty"

#Setup the 3D figure
fig = plt.figure()
axes = plt.axes(projection='3d')

axes.set_ylabel('y')
axes.set_xlabel('x')
axes.set_zlabel('z')

plt.show()



