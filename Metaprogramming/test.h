#include <iomanip>

struct Test
{
  int m_n;
  int m_nCheck;
  bool m_bThrowLater;
  static bool ms_bThrowDeferred;
  //
  Test(int n = 0, bool bThrow = false, bool bThrowLater = false)
    : m_n(n),
      m_nCheck(1),
      m_bThrowLater(bThrowLater)
  {
    cout << "Test(" << setw(3) << n << ")" << endl;
    if (bThrow)
    {
      cout << "Throwing..." << endl;
      throw std::logic_error(string("Test(") + to_string(n) + ")");
    }
  }
  //
  Test(Test &&rrTest)
    : m_n(rrTest.m_n),
      m_nCheck(rrTest.m_nCheck),
      m_bThrowLater(rrTest.m_bThrowLater)
  {
    cout << "Test(Test &&rrTest), rrTest == " << rrTest << endl;
    if (m_bThrowLater && ms_bThrowDeferred)
    {
      cout << "Throwing..." << endl;
      throw std::logic_error("Test(Test &&)");
    }
  }
  //
  friend std::ostream &operator << (std::ostream &rStream, const Test &rcTest)
  {
    if (rcTest.m_nCheck == 1)
      rStream << setw(3) << rcTest.m_n;
    else
      rStream << "invalid";
    //
    return rStream;
  }
  //
  Test(const Test &) = delete;
  Test &operator = (const Test &) = delete;
  Test &operator = (Test &&) = delete;
};

bool Test::ms_bThrowDeferred = false;

