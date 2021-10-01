'''
Functions to process and convert raw data into plottable data.
'''

import numpy as np

def polar_to_cartesian(distance, pitch, yaw):
    '''
    Converts polar coordinates into cartesian coordinates for plotting.

    Args:
        distance: distance from the sensor to the object in inches
        pitch: pitch angle of the sensor in radians
        yaw: yaw angle of the sensor in radians
    Returns:
        The corresponding x,y, and z cartesian coordinates for one sensor 
        reading.

    '''
    pitch = np.deg2rad(pitch)
    yaw = np.deg2rad(yaw)
    return distance * np.array([np.sin(pitch)*np.cos(yaw), 
                                np.cos(pitch)*np.cos(yaw),
                                np.cos(pitch)])

def sensor_to_distance(sensor_reading):
    #include the calibration function here
    '''
    Converts serial data to distance data. 

    Args:
        sensor_reading: an integer representing the infrared sensor reading 
    Returns: 
        the distance corresponding to the IR sensor reading
    '''
    return (178.4 * np.exp(-0.004995*float(sensor_reading)))


def apply_motor_correction(measured_angle, center_angle, negative_90_deg_angle):
    measured_from_center = measured_angle - center_angle
    pcnt_90_from_center = measured_from_center / (center_angle - negative_90_deg_angle)
    degrees_from_center = pcnt_90_from_center * 90

    return degrees_from_center
