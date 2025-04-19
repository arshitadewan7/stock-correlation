#ifndef NETWORKEXPORTER_H
#define NETWORKEXPORTER_H

#include <vector>
#include <string>

class NetworkExporter {
public:
    static void exportToDot(const std::vector<std::string>& labels, const std::vector<std::vector<double> >& matrix, const std::string& filename);
};

#endif
