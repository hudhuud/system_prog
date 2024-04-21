# solution.py
import os
import signal
import sys
import time

def sigurg_handler(signum, frame):

    sys.exit(0)

def daemonize():
    pid = os.fork()
    if pid > 0:
        sys.exit(0)

    os.chdir("/")
    os.setsid()
    os.umask(0)

    pid = os.fork()
    if pid > 0:
        sys.exit(0)

    sys.stdout.flush()
    sys.stderr.flush()

    dev_null = open("/dev/null", "r")
    os.dup2(dev_null.fileno(), sys.stdin.fileno())
    os.dup2(dev_null.fileno(), sys.stdout.fileno())
    os.dup2(dev_null.fileno(), sys.stderr.fileno())

def main():
    daemonize()

    signal.signal(signal.SIGURG, sigurg_handler)

    pid = os.getpid()
    print(pid)

    while True:
        time.sleep(1)

if __name__ == "__main__":
    main()
