#include <vector>
#include <set>
#include <iostream>

using namespace std;
class Same
{
public:
  static bool comp(std::vector<int> &a, std::vector<int> &b)
  {
    if (a.empty() || b.empty())
      return false;
    int alen = a.size();
    int blen = b.size();
    if (alen != blen)
      return false;
    multiset<int> bset;
    for (const auto &num : b)
    {
      bset.insert(num);
    }
    for (const auto &num : a)
    {
      auto isExist = bset.find(num * num);
      if (isExist == bset.end())
        return false;
      bset.erase(isExist);
    }
    return true;
  }
};

int main()
{
  Same sm;
  // vector<int> a = {121, 144, 19, 161, 19, 144, 19, 11};
  // vector<int> b = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
  vector<int> a = {121, 144, 19, 161, 19, 144, 19, 11};
  vector<int> b = {14641, 20736, 361, 25921, 361, 20736, 362, 121};
  cout << sm.comp(a, b) << endl;
}