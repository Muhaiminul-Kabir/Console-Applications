import os

def echo(state):
        
        os.system('cmd /k "echo {}"'.format(state))