######  PROGRAM MEMANGGIL WINDOWS PYQT5 ##########################

####### memanggil library PyQt5 ##################################
#----------------------------------------------------------------#
from PyQt5.QtCore import * 
from PyQt5.QtGui import * 
from PyQt5.QtQml import * 
from PyQt5.QtWidgets import *
from PyQt5.QtQuick import *  
import sys
import threading
import pygame
import time
pygame.init()

import serial

import speech_recognition as sr

r = sr.Recognizer()

print(sr.Microphone.list_microphone_names())

baudrate = 9600
reset_port = ""
port = ""
ser = ""
serial_status = 'disconnected'
serial_status_prev = 'disconnected'


message = ""
message_prev = ""

message_time = 0
message_time_prev = 0

words = ""
text = ""
print ("select your arduino port:")

def serial_ports():
    if sys.platform.startswith('win'):
        ports = ['COM%s' % (i + 1) for i in range(256)]
    elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
        # this excludes your current terminal "/dev/tty"
        ports = glob.glob('/dev/tty[A-Za-z]*')
    elif sys.platform.startswith('darwin'):
        ports = glob.glob('/dev/tty.*')
    else:
        raise EnvironmentError('Unsupported platform')

    result = []
    for port in ports:
        try:
            s = serial.Serial(port)
            s.close()
            result.append(port)
        except (OSError, serial.SerialException):
            pass
    return result
print(str(serial_ports()))


button_record = ""
recording_status = ""



#mic = 'Microphone (2- USB PnP Audio Device)'#sr.Microphone()

#mic = sr.Microphone()

sound_detect = "off"


#----------------------------------------------------------------#

analog1_x = 0
analog1_y = 0
analog1_x_prev = 0
analog1_y_prev = 0

analog2_x = 0
analog2_y = 0
analog2_x_prev = 0
analog2_y_prev = 0

hat = ""
hat_prev = ""


up_color = "transparent"
left_color = "transparent"
right_color = "transparent"
down_color = "transparent"

button1_color = "transparent"
button2_color = "transparent"
button3_color = "transparent"
button4_color = "transparent"

button_L1_color = "transparent"
button_L2_color = "transparent"
button_R1_color = "transparent"
button_R2_color = "transparent"

analog1_color = "transparent"
analog2_color = "transparent"

voice_status_color = "transparent"

########## mengisi class table dengan instruksi pyqt5#############
#----------------------------------------------------------------#
class table(QObject):    
    def __init__(self, parent = None):
        super().__init__(parent)
        self.app = QApplication(sys.argv)
        self.engine = QQmlApplicationEngine(self)
        self.engine.rootContext().setContextProperty("backend", self)    
        self.engine.load(QUrl("main.qml"))
        sys.exit(self.app.exec_())
        
        
    @pyqtSlot(result=str)
    def up_color(self):  return (up_color)
    
    
    @pyqtSlot(result=str)
    def left_color(self):  return (left_color)
    
    @pyqtSlot(result=str)
    def right_color(self):  return (right_color)
    
    @pyqtSlot(result=str)
    def down_color(self):  return (down_color)
    
    @pyqtSlot(result=str)
    def button1_color(self):  return (button1_color)
    
    @pyqtSlot(result=str)
    def button2_color(self):  return (button2_color)
    
    @pyqtSlot(result=str)
    def button3_color(self):  return (button3_color)
    
    @pyqtSlot(result=str)
    def button4_color(self):  return (button4_color)

    @pyqtSlot(result=str)
    def button_L1_color(self):  return (button_L1_color)

    @pyqtSlot(result=str)
    def button_L2_color(self):  return (button_L2_color)
    
    @pyqtSlot(result=str)
    def button_R1_color(self):  return (button_R1_color)

    @pyqtSlot(result=str)
    def button_R2_color(self):  return (button_R2_color)
    
    @pyqtSlot(result=float)
    def analog1_x(self):  return float(analog1_x * 10)
    
    @pyqtSlot(result=float)
    def analog1_y(self):  return float(analog1_y * 10)
    
    @pyqtSlot(result=float)
    def analog2_x(self):  return float(analog2_x*10)
    
    @pyqtSlot(result=float)
    def analog2_y(self):  return float(analog2_y*10)
    
    @pyqtSlot(result=str)
    def analog1_color(self):  return analog1_color
    
    @pyqtSlot(result=str)
    def analog2_color(self):  return analog2_color
    
    @pyqtSlot(result=list)
    def port(self):  return serial_ports()
    
    @pyqtSlot(result=str)
    def voice_color(self):  return voice_status_color
    
    @pyqtSlot(result=str)
    def voice_command(self):  return text
    
    
    @pyqtSlot('QString')
    def port_number(self, port_number):
        global port
        port = str(port_number)  
        #print(port)
        
    @pyqtSlot('QString')
    def connection(self, status):
        global serial_status
        
        serial_status = status
        print(status)
    
    

#----------------------------------------------------------------#

def pygame_run(num):
    global analog1_x
    global analog1_y
    global analog1_x_prev
    global analog1_y_prev

    global analog2_x
    global analog2_y
    global analog2_x_prev
    global analog2_y_prev
    
    global hat
    global hat_prev
    
    global up_color
    global down_color
    global left_color
    global right_color
    
    global button1_color
    global button2_color
    global button3_color
    global button4_color
    
    
    global button_L1_color
    global button_L2_color
    global button_R1_color
    global button_R2_color
    
    global analog1_color
    global analog2_color
    
    global message
    global message_prev
    
    global sound_detect
    global voice_status_color
    
    global words
    global text
    clock = pygame.time.Clock()
    joysticks = {}
    done = False
    while not done:
        # Event processing step.
        # Possible joystick events: JOYAXISMOTION, JOYBALLMOTION, JOYBUTTONDOWN,
        # JOYBUTTONUP, JOYHATMOTION, JOYDEVICEADDED, JOYDEVICEREMOVED
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                done = True  # Flag that we are done so we exit this loop.

            if event.type == pygame.JOYBUTTONDOWN:
                #print("Joystick button pressed.")
                status_button = "pressed"
                joy_button_status = status_button
                joy_button_event = event.button
                #print(joy_button_status)
                print(joy_button_event)
                
                if (joy_button_event == 0):
                    button1_color = "#d84860"
                    
                if (joy_button_event == 1):
                    button2_color = "#d84860"
                    
                if (joy_button_event == 2):
                    button3_color = "#d84860"
                    
                if (joy_button_event == 3):
                    button4_color = "#d84860"
                    
                if (joy_button_event == 4):
                    button_L1_color = "#d84860"
                    
                if (joy_button_event == 5):
                    button_R1_color = "#d84860"
                    
                if (joy_button_event == 6):
                    button_L2_color = "#d84860"
                
                if (joy_button_event == 7):
                    button_R2_color = "#d84860"
                
                if (joy_button_event == 9):
                    sound_detect = "on"
                    voice_status_color = "#d84860"
                    
                if (joy_button_event < 9):    
                    message = str(joy_button_event + 1)
                
                if (joy_button_event == 10):
                    analog1_color = "#d84860"
                    
                if (joy_button_event == 11):
                    analog2_color = "#d84860"
                
                if event.button == 0:
                    
                    joystick = joysticks[event.instance_id]
                    
                
                
           
            if event.type == pygame.JOYBUTTONUP:
                #print("Joystick button released.")
                joy_button_status = status_button
                joy_button_event = event.button
                message = str("")
                if (joy_button_event == 0):
                    button1_color = "transparent"
                    
                if (joy_button_event == 1):
                    button2_color = "transparent"
                    
                if (joy_button_event == 2):
                    button3_color = "transparent"
                    
                if (joy_button_event == 3):
                    button4_color = "transparent"
                    
                if (joy_button_event == 4):
                    button_L1_color = "transparent"
                    
                if (joy_button_event == 5):
                    button_R1_color = "transparent"
                    
                if (joy_button_event == 6):
                    button_L2_color = "transparent"
                
                if (joy_button_event == 7):
                    button_R2_color = "transparent"
                    
                
                    
                    
                if (joy_button_event == 10):
                    analog1_color = "transparent"
                    
                if (joy_button_event == 11):
                    analog2_color = "transparent"

                
                
                
            # Handle hotplugging
            if event.type == pygame.JOYDEVICEADDED:
                # This event will be generated when the program starts for every
                # joystick, filling up the list without needing to create them manually.
                joy = pygame.joystick.Joystick(event.device_index)
                joysticks[joy.get_instance_id()] = joy
                print("Joystick {} connected".format(joy.get_instance_id()))
                

            if event.type == pygame.JOYDEVICEREMOVED:
                del joysticks[event.instance_id]
                print("Joystick {} disconnected".format(event.instance_id))

       
            
        # For each joystick:
        for joystick in joysticks.values():
                
            jid = joystick.get_instance_id()
            name = joystick.get_name()
            guid = joystick.get_guid()
            power_level = joystick.get_power_level()
            axes = joystick.get_numaxes()
            

            for i in range(axes):
                axis = joystick.get_axis(i)
                if i == 0 :
                    analog1_x = axis
                if i == 1 :
                    analog1_y = axis
                if i == 2 :
                    analog2_y = axis
                if i == 3 :
                    analog2_x = axis
                    #print(axis)
                
                a =+ 1
            
            
            
            buttons = joystick.get_numbuttons()
            

            for i in range(buttons):
                button = joystick.get_button(i)
                
            hats = joystick.get_numhats()
            
            
            
            for i in range(hats):
                hat = joystick.get_hat(i)
            
        if (hat != hat_prev):    
            print(hat)
            if (hat[0] == -1):
                left_color = "#d84860"
                right_color = "transparent"
                
            if (hat[0] == 0):
                left_color = "transparent"
                right_color = "transparent"
                
            if (hat[0] == 1):
                left_color = "transparent"
                right_color = "#d84860"
                
                
            if (hat[1] == -1):
                down_color = "#d84860"
                up_color = "transparent"
                
            if (hat[1] == 0):
                down_color = "transparent"
                up_color = "transparent"
                
            if (hat[1] == 1):
                down_color = "transparent"
                up_color = "#d84860"
                
                
        hat_prev = hat
        
        if (analog1_x != (analog1_x_prev) ):
            print(analog1_x)
            
        if (analog1_y != (analog1_y_prev) ):
            print(analog1_y)
            
        if (analog2_x != (analog2_x_prev) ):
            print(analog2_x)
            
        if (analog2_y != (analog2_y_prev) ):
            print(analog2_y)
        
        
        
        analog1_x_prev = analog1_x
        analog1_y_prev = analog1_y
        analog2_x_prev = analog2_x
        analog2_y_prev = analog2_y
        
        global serial_status
        global serial_status_prev
        global port
        
        
        global ser
        global message_time
        global message_time_prev
        
        ######################################################
        
        
        if (sound_detect == "on"):
            with sr.Microphone() as source:
                print('speak please:')
                audio = r.listen(source)
                # r.pause_threshold = 0.4
                r.energy_threshold = 1000
                r.duration = 3
            
            try:
                text = r.recognize_google(audio, language = "ID")
                
                words = text
                print(words)
            except:
                text = "ulangi"
                words = ""
            
            if (words == "Balonku Ada Lima"):
                message = "f"
                #ser.write(str("f").encode())
                
            if (words == "Si Kancil Anak Nakal"):
                message = "e"
                #ser.write(str("e").encode())
                
            if (words == "Lihat Kebunku"):
                message = "a"
                #ser.write(str("a").encode())
                
            if (words == "kasih ibu"):
                message = "b"
                #ser.write(str("b").encode())
            
            if (words == "dua mata saya"):
                message = "c"
                #ser.write(str("c").encode())
            if (words == "Ambilkan Bulan Bu"):
                message = "d"
                #ser.write(str("d").encode())
                
            if (words == "Ibu Kita Kartini"):
                message = "g"
                #ser.write(str("g").encode())
            
            sound_detect = "off"
            
        if (sound_detect == "off"):
            voice_status_color = "transparent"
            
            
        
        if (serial_status == 'connected'):
            if (serial_status != serial_status_prev):
                '''
                arduino nano / arduino uno timeout = 0.1
                arduino mega timeout = 1

                '''
                ser = serial.Serial(str(port),9600,timeout=1)
                
            if (message != message_prev):
                ser.write(str(message).encode())
                print("send")
                print(message)
                
        else:
            if (serial_status != serial_status_prev):
                ser.close()
                
        
        
        message_time = time.time() - message_time_prev
        if (message_time > 5) :
            
            message_time_prev = time.time()
        
        
        
        
        
        
        serial_status_prev = serial_status
        
        message_prev = message
        
        
        clock.tick(30)


        
        

########## memanggil class table di mainloop######################
#----------------------------------------------------------------#    
if __name__ == "__main__":
    t1 = threading.Thread(target=pygame_run, args=(10,))
    t1.start()
    
    
    main = table()
    
    
#----------------------------------------------------------------#