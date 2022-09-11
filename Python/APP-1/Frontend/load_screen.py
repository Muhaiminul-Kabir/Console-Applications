from Frontend.Modules.load import *
from Frontend.Modules.cmd import *
from Frontend.Modules.interaction import *

def start():
        greetings()
        load_menu()     
        take_input()
        if show_input() == None:
                print('e')
                create_view()
                

def create_view():
        i = 0
        label(i)
        take_input()
        if show_input() != None:               
                label(i)
                create_view()


