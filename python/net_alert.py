import os
import serial
import time

# Adjust serial port as needed (e.g., '/dev/ttyACM0', '/dev/ttyUSB0')
ser = serial.Serial('/dev/ttyACM0', 9600)

def ping(host):
    """Attempts to ping a specified host and returns True if the host is reachable."""
    response = os.system(f"ping -c 1 {host}")
    return response == 0

# List of hosts to monitor (primary and failover servers)
hosts = ["8.8.8.8", "1.1.1.1"]

while True:
    connection_found = False
    for host in hosts:
        if ping(host):
            connection_found = True
            break  # Exit the loop if any server responds

    if connection_found:
        ser.write(b'0')  # Signal Arduino to deactivate alert
        print("Connection stable.")
    else:
        ser.write(b'1')  # Signal Arduino to activate alert
        print("Connection lost! Alert activated.")

    # Send a heartbeat signal indicating the script is running
    ser.write(b'2')
    print("Heartbeat sent.")

    time.sleep(7)  # Check every 7 seconds
