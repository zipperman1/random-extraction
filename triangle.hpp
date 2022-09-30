#pragma once
#include <vector>
#include <iostream>

class PascalsTriangle {
  private:
    std::vector<std::vector<long long>> rows;
    void InitRows(int triangleSize);

  public:
    PascalsTriangle(int triangleSize);
    long long Combinations(int n, int k);  
};
