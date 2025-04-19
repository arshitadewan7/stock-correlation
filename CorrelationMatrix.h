#ifndef CORRELATIONMATRIX_H
#define CORRELATIONMATRIX_H

#include <vector>
#include <string>

class CorrelationMatrix {
public:
    static std::vector<std::vector<double> > compute(const std::vector<std::vector<double> >& data, const std::vector<std::string>& labels);
};

#endif
