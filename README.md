# Low-Latency Market Microstructure Analysis System

## Overview

The Low-Latency Market Microstructure Analysis System is designed to facilitate high-frequency trading (HFT) research and development. By leveraging both C++ and Python, this system offers a robust framework for analyzing market microstructure with minimal latency, enabling users to gain insights into market dynamics and develop efficient trading strategies.

## Features

- **High-Performance Data Processing**: Utilizes C++ for low-latency handling of large-scale market data.
- **Flexible Analysis Tools**: Incorporates Python modules for statistical analysis and visualization.
- **Modular Architecture**: Easily extendable to include custom algorithms and data sources.
- **Real-Time Monitoring**: Supports live data feeds for up-to-the-moment analysis.

## Installation

### Prerequisites

- **C++ Compiler**: Ensure you have a C++17 compatible compiler installed.
- **Python 3.8+**: Required for running analysis scripts.
- **CMake**: For building the C++ components.

### Steps

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yogeshsingh-11/Low-Latency-Market-Microstructure-Analysis-System.git
   cd Low-Latency-Market-Microstructure-Analysis-System
   ```

2. **Build C++ Components**:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Set Up Python Environment**:
   ```bash
   cd ../python
   python3 -m venv venv
   source venv/bin/activate  # On Windows, use `venv\Scripts\activate`
   pip install -r requirements.txt
   ```

## Usage

1. **Start Data Processing Module**:
   This module handles the ingestion and initial processing of market data.
   ```bash
   ./build/data_processor --config config/data_processor_config.json
   ```

2. **Run Analysis Scripts**:
   Utilize the provided Python scripts for various analyses.
   ```bash
   python python/scripts/analyze_order_book.py --input data/processed/order_book.csv
   ```

3. **Visualize Results**:
   Generate plots and visualizations to interpret the analysis.
   ```bash
   python python/scripts/plot_liquidity_metrics.py --input results/liquidity_metrics.csv
   ```

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your enhancements or bug fixes. Ensure that your code adheres to the project's coding standards and includes appropriate tests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
