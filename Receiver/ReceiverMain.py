"""
Author :  HKT1COB
Name:  Karthikeyani Shanmuga Sundaram
Department: BGSW/ETS
"""

import csv
from getStatistics import StatsCalculate

statsCalculator = StatsCalculate()
with open('data.csv', mode ='r')as file:
    csvFile = csv.reader(file)
    temperatureData = []
    chargingData = []
    for lines in csvFile:
        if lines[0] == "temperature":
            continue
        temperatureData.append(int(lines[0]))
        chargingData.append(int(lines[1]))

    print("Temperature Max , Min:", statsCalculator.getMaxMin(temperatureData))
    print("chargingData Max , Min:",statsCalculator.getMaxMin(chargingData))

    print("Temperature Moving Average:",statsCalculator.getMovingAverage(temperatureData[-5:]))
    print("ChargingData Moving Average:", statsCalculator.getMovingAverage(chargingData[-5:]))






