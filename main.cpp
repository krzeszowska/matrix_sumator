#include "Tester.hpp"
#include "Matrix.hpp"
//#include "spdlog/spdlog.h"

using namespace std;

class MatrixSumTester: public Tester <Matrix, SumInput>{
protected:
  Matrix runAlgorithm(const SumInput& inputData) override;
  SumInput readSingleInput(std::istream& inputStream) override;	
};

Matrix MatrixSumTester::runAlgorithm(const SumInput& inputData){
	Matrix result;
	result = inputData.a + inputData.b;

	cout << result;

	return result;
}

SumInput MatrixSumTester::readSingleInput(std::istream& inputStream){
	SumInput matrix;
	inputStream >> matrix;

	return matrix;
}

int main(){

	std::ifstream inputFile{"input.txt"};
    std::ofstream dataOutputFile{"output.txt"};

    MatrixSumTester tester;
    SumInput data;

    if(!inputFile)
    {
        std::cerr<<"input.txt cannot be opened!";
        return -1;
    }

    tester.runAllTests(inputFile,dataOutputFile,2);

	return 0;
}
