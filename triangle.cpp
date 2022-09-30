#include "triangle.hpp"

// Example:
//  1
//  1  1
//  1  2  1
//  1  3  3  1
//  1  4  6  4  1
//  1  5  10  10  5  1

// Triangle constructor
PascalsTriangle::PascalsTriangle(int triangleSize) {
  this->InitRows(triangleSize);
  // for (long long num : row)
  //   std::cout << num << " ";
  // std::cout << std::endl;
}

// Access the element on the n row, k column
long long PascalsTriangle::Combinations(int n, int k) {
  if (k > n || n < 0 || k < 0) {
    return 0;
  }
  return rows[n][k];
}

// Recursive method for Pascal's triangle
void PascalsTriangle::InitRows(int triangleSize) {
  for (int n = 0; n <= triangleSize; n++) {
    std::vector<long long> row = {1};

    for (int k = 1; k <= n; k++) {
      row.push_back(Combinations(n - 1, k) + Combinations(n - 1, k - 1));
    }

    rows.push_back(row);
  }
}
