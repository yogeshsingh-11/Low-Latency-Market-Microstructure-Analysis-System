#include <iostream>
#include <zmq.hpp>  // ZeroMQ for messaging
#include <thread>
#include <chrono>
#include "utils.hpp"

void fetch_data_from_exchange() {
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_SUB);
    socket.connect("tcp://exchange_data_feed:port");
    socket.setsockopt(ZMQ_SUBSCRIBE, "", 0);

    while (true) {
        zmq::message_t message;
        socket.recv(&message);

        // Process the incoming data (example JSON message)
        std::string data(static_cast<char*>(message.data()), message.size());
        OrderBook orderBook = parse_order_book(data);  // Parse data to order book structure

        // Send data to the processing queue
        process_order_book(orderBook);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));  // Simulate low-latency
    }
}

int main() {
    std::cout << "Starting market data ingestion..." << std::endl;
    fetch_data_from_exchange();
    return 0;
}
