#include "CorrelationMatrix.h"
#include <cmath>
#include <iostream>

double calculateCorrelation(const std::vector<double>& x, const std::vector<double>& y) {
    double mean_x = 0.0, mean_y = 0.0;
    double numerator = 0.0, denominator_x = 0.0, denominator_y = 0.0;
    int n = x.size();

    for (int i = 0; i < n; ++i) {
        mean_x += x[i];
        mean_y += y[i];
    }

    mean_x /= n;
    mean_y /= n;

    for (int i = 0; i < n; ++i) {
        numerator += (x[i] - mean_x) * (y[i] - mean_y);
        denominator_x += (x[i] - mean_x) * (x[i] - mean_x);
        denominator_y += (y[i] - mean_y) * (y[i] - mean_y);
    }

    return numerator / std::sqrt(denominator_x * denominator_y);
}

std::vector<std::vector<double> > CorrelationMatrix::compute(const std::vector<std::vector<double> >& data, const std::vector<std::string>& labels) {
    int n = data.size();
    int m = data[0].size();

    std::vector<std::vector<double> > matrix(m, std::vector<double>(m, 0.0));

    for (int i = 0; i < m; ++i) {
        for (int j = i; j < m; ++j) {
            std::vector<double> x, y;
            for (int k = 0; k < n; ++k) {
                x.push_back(data[k][i]);
                y.push_back(data[k][j]);
            }

            double correlation = calculateCorrelation(x, y);
            matrix[i][j] = correlation;
            matrix[j][i] = correlation;
        }
    }

    return matrix;
}
