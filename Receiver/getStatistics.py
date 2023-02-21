"""
Author :  HKT1COB
Name:  Karthikeyani Shanmuga Sundaram
Department: BGSW/ETS
"""

class StatsCalculate:
    def getMaxMin(self,inputArray):
        Min = 1000
        Max = 0
        for element in inputArray:
            if element < Min:
                Min = element
            if element > Max:
                Max = element
        return Max,Min
    
    def getMovingAverage(self,inputArray):
        return sum(inputArray)/len(inputArray)
