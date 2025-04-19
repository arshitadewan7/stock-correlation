#include "CSVReader.h"
#include "CorrelationMatrix.h"
#include "NetworkExporter.h"
#include <iostream>

int main() {
    std::vector<std::vector<std::string> > rawData = CSVReader::readStockPrices("prices.csv");

    // Extract labels
    std::vector<std::string> labels = rawData[0];
    rawData.erase(rawData.begin());

    // Convert data to numeric
    std::vector<std::vector<double> > data;
    for (const auto& row : rawData) {
        std::vector<double> numericRow;
        for (const auto& value : row) {
            numericRow.push_back(std::stod(value));
        }
        data.push_back(numericRow);
    }

    // Compute correlation matrix
    std::vector<std::vector<double> > matrix = CorrelationMatrix::compute(data, labels);

    // Export graph
    NetworkExporter::exportToDot(labels, matrix, "output/graph.dot");

    std::cout << "Correlation graph exported to output/graph.dot" << std::endl;
    return 0;
}
