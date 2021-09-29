'''
Functions to process and convert raw data into plottable data.
'''

import numpy as np

def polar_to_cartesian(distance, inclination, azimuth):
    '''
    Converts polar coordinates into cartesian coordinates for plotting.

    Args:
        distance: distance from the sensor to the object in inches
        inclination: inclination angle of the sensor in radians
        azimuth: azimuth angle of the sensor in radians
    Returns:
        The corresponding x,y, and z cartesian coordinates for one sensor 
        reading.

    '''
    return distance * np.array([sin(inclination)*cos(azimuth), 
                                sin(inclination)*cos(inclination),
                                cos(inclination)])

def sensor_to_distance(sensor_reading):
    #include the calibration function here
    '''
    Converts serial data to distance data. 

    Args:
        sensor_reading: Array of values that the sensor inputs. 
    Returns: 
        distance_data: Array of values  
    '''
    distance_data = -0.2119 * sensor_reading + 113.5
    return(distance_data)
