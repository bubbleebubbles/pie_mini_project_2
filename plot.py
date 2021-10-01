'''
Grabs data from the csv file and plots it in 3D. 
'''
 
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import pandas as pd

#Setup the 3D figure
fig = plt.figure()
axes = plt.axes(projection='3d')

axes.set_ylabel('y')
axes.set_xlabel('x')
axes.set_zlabel('z')

#Read data from the file
sensor_data = pd.read_csv('sensor_data.csv')
x = sensor_data['x'].values
y = sensor_data['y'].values
z = sensor_data['z'].values

print(x)

#Plot the data
axes.scatter(x, y, z)
plt.show()
