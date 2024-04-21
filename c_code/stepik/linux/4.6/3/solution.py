import signal
import sys

sigusr1_count = 0
sigusr2_count = 0

def sigusr1_handler(signum, frame):
    global sigusr1_count
    sigusr1_count += 1

def sigusr2_handler(signum, frame):
    global sigusr2_count
    sigusr2_count += 1

def sigterm_handler(signum, frame):
    print(sigusr1_count, sigusr2_count)
    sys.exit(0)

signal.signal(signal.SIGUSR1, sigusr1_handler)
signal.signal(signal.SIGUSR2, sigusr2_handler)
signal.signal(signal.SIGTERM, sigterm_handler)

while True:
    signal.pause()
