###############################################################
# This advanced example shows how to command 4 motor thrusters
# to perform independent oscillations while reading feedback
# in real time using threads.
#
# Designed specifically to work with the
# SeaDroneTM Smart Thruster Breakout Board:
# https://seadronepro.com/shop-seadrone/
#
# Author:   Carlos Garcia-Saura (@CarlosGS)
# Copyright (C) 2017 SeaDroneTM (www.seadronepro.com)
# This program is free software; you can redistribute it
# and/or modify it under the terms of the GNU General Public
# License v3 as published by the Free Software Foundation.
###############################################################


##----------------------- TO DO LIST------------------------------------
#1. Create function to return motor_feedback
#2. Create function to make an emergency stop for all motors
#3. Create a library/module/package for m

import seadrone.smart_thruster as thrusters
import threading
import time
import math

N_motors = 15
port = '/dev/ttyS3'

print("Starting motors...")
m = thrusters.start(N_motors, port)

def motor_feedback_thread(m):
    while m.running:
        print("\n\n\n\n") # empty lines for space
        for id in m.motors: # show feedback for each motor
            motor_feedback = 'Motor {:2d}: '.format(id)
            motor_feedback += "ON  " if m.is_on[id] else "OFF "
            motor_feedback += '{:5d}rpm '.format(m.rpm[id])
            motor_feedback += '{:5.2f}A '.format(m.current[id])
            motor_feedback += '{:5.2f}V '.format(m.voltage[id])
            motor_feedback += '{:5.2f}C '.format(m.driver_temperature[id])
            motor_feedback += 'Alarm: ' + m.get_alarm_description(id)
            print(motor_feedback)
            if m.has_alarm[id]:
                print("Auto-resetting motor alarm")
                m.reset_alarm(id)
        time.sleep(0.05) # wait 50ms after each printout

thread = threading.Thread(target=motor_feedback_thread, args=(m,))
thread.daemon = True
thread.start()


# The main thread moves the motors using sinusoidal inputs
try:
    while True:
        for id in m.motors:
            #amplitude = (len(m.motors)+1-id)*300 # RPM
            #frequency = (id+1)/20. # Hz
            #m.target_rpm[id] = int(amplitude*math.sin(2*math.pi*(id+1)*frequency*time.time()))
            m.target_rpm[id] = 500
        time.sleep(0.01)
except KeyboardInterrupt: # Program can be stopped pressing CTRL+C
    for id in m.motors:
        m.target_rpm[id] = 0
    print("Shutting down smart thruster library...")

m.stop()
