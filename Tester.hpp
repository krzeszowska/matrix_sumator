#include <iostream>

template <typename ResultType, typename InputType>
class Tester
{
  public:
    bool runAllTests(std::istream& inputStream, std::ostream& outputStream = std::cout, const int testsNum = 1);
    virtual ~Tester() {}

  protected:
    virtual ResultType runAlgorithm(const InputType& /*inputData*/)
    {
        return ResultType{};
    }
    virtual InputType readSingleInput(std::istream& /*inputStream*/)
    {
        return InputType{};
    };
};

template <typename ResultType, typename InputType>
bool Tester<ResultType, InputType>::runAllTests(std::istream& inputStream, std::ostream& outputStream,
                                                const int testsNum)
{
    for(int i=0;i<testsNum && inputStream.good();++i)
    {
      //  std::cout<<inputStream.good()<<std::endl;
        InputType input = readSingleInput(inputStream);
        
       outputStream << runAlgorithm(input);

    }

  //  std::cout<<"bye"<<std::endl;

    return true;
}