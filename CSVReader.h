#ifndef CSVREADER_H
#define CSVREADER_H

#include <vector>
#include <string>

class CSVReader {
public:
    static std::vector<std::vector<std::string> > readStockPrices(const std::string& filename);
};

#endif
