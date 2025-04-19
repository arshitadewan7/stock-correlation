# 📈 Stock Correlation Network

This project visualizes correlations between different stocks by reading price data from a CSV file, computing a correlation matrix, and exporting it as a DOT graph file.

## 🚀 Features

- CSV parsing for stock prices
- Correlation matrix computation using Pearson's correlation
- Graph generation using DOT format
- Easy export for use with Graphviz

## 🛠️ Files Overview

| File | Purpose |
|------|---------|
| `main.cpp` | Main program that ties everything together |
| `CSVReader.h/.cpp` | Reads stock prices from a CSV file |
| `CorrelationMatrix.h/.cpp` | Computes the correlation matrix |
| `NetworkExporter.h/.cpp` | Exports the correlation matrix to a DOT file |
| `data/prices.csv` | Input CSV file with stock price data |
| `output/graph.dot` | Generated DOT file showing the correlation graph |
| `output/graph.png` | (Optional) PNG image of the graph if Graphviz is installed |

## 📊 CSV Format

The CSV file should look like:

Date,AAPL,GOOG,MSFT 2024-01-01,150,2800,300 2024-01-02,152,2815,305 ...

- First row = headers (stock symbols)
- First column = dates (ignored in computation)

## 🧪 How to Run

1. **Install Graphviz** (optional for PNG export):
   ```bash
   brew install graphviz   # macOS
   sudo apt install graphviz   # Linux
Build the project:
   g++ main.cpp CSVReader.cpp CorrelationMatrix.cpp NetworkExporter.cpp -o stock_network -std=c++11
Run the project:
  ./stock_network
Generate graph image:
  dot -Tpng output/graph.dot -o output/graph.png
  
📎 Dependencies

C++11 or later
Graphviz (optional, for graph rendering)

👩‍💻 Author

Arshita Dewan


