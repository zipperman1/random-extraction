#include <fstream>
#include <iostream>
#include <deque>
#include "triangle.hpp"

struct BlockInfo {
  long long blockNum = 0;
  int eventCount = 0;
};

// Applying Num() to a block and count number of events
BlockInfo NextBlockInfo(std::ifstream &inputSequence, int blockSize, PascalsTriangle &triangle, char event = '1') {
  char item;
  BlockInfo blockInfo;
  
  for (int pos = 0; pos < blockSize && (inputSequence >> std::noskipws >> item); pos++) {
    if (item == event) {
      blockInfo.eventCount++;
      blockInfo.blockNum += triangle.Combinations(pos, blockInfo.eventCount);
    }
  }

  return blockInfo;
}

// Extraction of random sequences
void Extraction(BlockInfo blockInfo, int blockSize, PascalsTriangle &triangle) {
  long long R_n = triangle.Combinations(blockSize, blockInfo.eventCount);
  long long Num = blockInfo.blockNum;
  std::deque<bool> binaryForm;
  long long numLimit = -1;
  long long r = 1;

  if (R_n == 1)
    return;
  
  while (numLimit < blockInfo.blockNum) {
    R_n >>= 1;
    r <<= 1;
    
    binaryForm.push_front(Num & 1);
    Num >>= 1;
    
    if ((R_n & 1) != 0)
      numLimit += r;
  }
  //Reversing the binary form of the exctracted Num() 
  for (bool item : binaryForm)
    std::cout << item;
}

int main() {
  const int BLOCK_SIZE = 8;
  std::ifstream inputSequence("input1.txt");
  int cPos = 0;
  BlockInfo blockInfo;

  // The alphabet is defined on the first line of the "input.txt" file
  std::string alphabet;
  std::getline(inputSequence, alphabet);

  PascalsTriangle triangle(BLOCK_SIZE);
  while (inputSequence.peek() != EOF) {
    cPos = inputSequence.tellg();
    //We iterate through all the letters except the last one
    for (int i = 0; i < alphabet.length() - 1; i++) {
      char event = alphabet[i];

      inputSequence.seekg(cPos, inputSequence.beg);
      blockInfo = NextBlockInfo(inputSequence, BLOCK_SIZE, triangle, event);
      Extraction(blockInfo, BLOCK_SIZE, triangle);
    }
    std::cout << std::endl;
  }
  return 0;
}