#include "NetworkExporter.h"
#include <fstream>
#include <iostream>

void NetworkExporter::exportToDot(const std::vector<std::string>& labels, const std::vector<std::vector<double> >& matrix, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    file << "graph correlation {\n";
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = i + 1; j < matrix[i].size(); ++j) {
            file << "  \"" << labels[i] << "\" -- \"" << labels[j] << "\" [weight=" << matrix[i][j] << "]\n";
        }
    }
    file << "}\n";
    file.close();
}
