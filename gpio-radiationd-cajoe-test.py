#!/usr/bin/env python3
import RPi.GPIO as GPIO
import time
import datetime
import sys

PIN = 7 # digital pin 4

def sample(channel):
    print("!", end="")
    sys.stdout.flush()

GPIO.setmode(GPIO.BOARD)
GPIO.setup(PIN, GPIO.IN)
GPIO.add_event_detect(7, GPIO.FALLING, callback=sample)

while True:
    time.sleep(1)
    print(".", end="")
    sys.stdout.flush()
