#include "utils.hpp"
#include <zmq.hpp>

double calculate_spread(const OrderBook& orderBook) {
    return orderBook.ask_price - orderBook.bid_price;
}

double calculate_market_depth(const OrderBook& orderBook) {
    return orderBook.ask_volume + orderBook.bid_volume;
}

double calculate_order_flow_imbalance(const OrderBook& orderBook) {
    return orderBook.bid_volume / (orderBook.bid_volume + orderBook.ask_volume);
}

void send_metrics_to_frontend(double spread, double depth, double imbalance) {
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_PUSH);
    socket.connect("tcp://python_frontend:port");

    zmq::message_t message(256);
    snprintf((char*)message.data(), 256, "%f,%f,%f", spread, depth, imbalance);
    socket.send(message);
}

