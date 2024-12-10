import zmq
import numpy as np

# Real-time data processing (received from C++ backend)
def receive_metrics():
    context = zmq.Context()
    socket = context.socket(zmq.PULL)
    socket.bind("tcp://*:port")

    while True:
        message = socket.recv_string()
        metrics = message.split(',')
        spread, depth, imbalance = map(float, metrics)
        
        # Return metrics to the visualizer for plotting
        yield spread, depth, imbalance
