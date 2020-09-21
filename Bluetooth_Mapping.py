import tkinter as tk
import matplotlib.pyplot as plt
import serial
import time
import sys
import signal
      
def signal_handler(signal, frame):
  print("closing program")
  SerialPort.close()
  sys.exit(0)

def main():
   COM=input("Enter the COM Port\n")
   BAUD=input("Enter the Baudrate\n")

   SerialPort = serial.Serial(COM,BAUD,timeout=1)

   #window = tk.Tk()
   #window.title('Map')
   #canvas = tk.Canvas(window, width=500, height=500, bg='black')
   #canvas.pack()

   #car = Car(canvas)
   
   xplot = []
   yplot = []

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
         distance = ultra1.rstrip().split(",")
         print(distance[3])

      #IncomingData2=SerialPort.readline()
      #if(IncomingData2):
      #   ultra2 = (IncomingData2).decode('utf-8')
      #   print(ultra2)
  
      # if the sensors are equal with uncertainty of 5cm

      if(IncomingData1):
         if float(distance[0]) < float(distance[1]) + 0.02 and float(distance[0]) > float(distance[1]) - 0.02:
            if float(distance[0]) < 0.1 and float(distance[1]) < 0.1:
               print('wall')
               if float(distance[2]) < float(distance[3]):
                  xplot.append(float(distance[2]))
                  yplot.append(float(1.5 - float(distance[0])))
               else:
                  xplot.append(float(distance[3]))
                  yplot.append(float(distance[0]))
               # it is a wall, paint the canvas white
            elif float(distance[0]) < float(distance[1]): # if left scanned an obstacle
               print('left')
               yplot.append(float(distance[1]))
               if float(distance[2]) < float(distance[3]):
                  xplot.append(float(distance[2]))
               else:
                  xplot.append(float(distance[3]))
               # paint canvas white on the left side
            elif float(distance[0]) > float(distance[1]): # if right scanned an obstacle
               print('right')
               yplot.append(float(distance[0]))
               if float(distance[2]) < float(distance[3]):
                  xplot.append(float(distance[2]))
               else:
                  xplot.append(float(distance[3]))
               # paint canvas white on the right side

         if float(distance[3]) < 0.15 and float(distance[0]) < 0.1 and float(distance[1]) < 0.1:
            break
      #window.update()
      time.sleep(0.01)
   
   #window.mainloop()
   plt.axis([0, 1.5, 0, 1.5])
   plt.ylabel('some num')
   #for x, y in zip(xplot, yplot):
      #plt.plot([x], [y])
   plt.plot(xplot, yplot, 'ro')
   plt.show()


main()