#include <iostream>
#include "utils.hpp"

// Order book processing: calculate spread, depth, and imbalance
void process_order_book(const OrderBook& orderBook) {
    double spread = calculate_spread(orderBook);
    double depth = calculate_market_depth(orderBook);
    double imbalance = calculate_order_flow_imbalance(orderBook);

    // Send calculated metrics to the Python frontend via ZeroMQ
    send_metrics_to_frontend(spread, depth, imbalance);
}

