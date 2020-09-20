import serial
import time
import sys
import signal

def signal_handler(signal, frame):
  print("closing program")
  SerialPort.close()
  sys.exit(0)

COM=input("Enter the COM Port\n")
BAUD=input("Enter the Baudrate\n")

SerialPort = serial.Serial(COM,BAUD,timeout=1)
ultra = []

while (1):
  try:
     OutgoingData='s'
     SerialPort.write(bytes(OutgoingData,'utf-8'))
  except KeyboardInterrupt:
     print("Closing and exiting the program")
     SerialPort.close()
     sys.exit(0)

  IncomingData1=SerialPort.readline()
  if(IncomingData1):
     ultra1 = (IncomingData1).decode('utf-8')
     print(ultra1)

  IncomingData2=SerialPort.readline()
  if(IncomingData2):
     ultra2 = (IncomingData2).decode('utf-8')
     print(ultra2)

  IncomingData3=SerialPort.readline()
  if(IncomingData3):
     ultra3 = (IncomingData3).decode('utf-8')
     print(ultra3)

  IncomingData4=SerialPort.readline()
  if(IncomingData4):
     ultra4 = (IncomingData4).decode('utf-8')
     print(ultra4)

  time.sleep(0.01)