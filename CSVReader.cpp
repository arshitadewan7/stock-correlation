#include "CSVReader.h"
#include <fstream>
#include <sstream>

std::vector<std::vector<std::string> > CSVReader::readStockPrices(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<std::string> > data;
    std::string line;

    while (getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string value;

        while (getline(ss, value, ',')) {
            row.push_back(value);
        }

        data.push_back(row);
    }

    return data;
}
