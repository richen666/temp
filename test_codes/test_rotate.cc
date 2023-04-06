#include <vector>
using namespace std;

class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    int len = nums.size();
    int sublen = len;
    int move = k % len;
    int frontArrPos = 0;
    int backArrPos = len - move;
    while (move != 0)
    {
      // move: right eles,
      // len - move: left eles
      int shortArrLen = min(move, sublen - move);
      int i = 0;
      int j = frontArrPos;
      for (; i < shortArrLen; ++i, ++j)
      {
        swap(nums[j], nums[backArrPos + i]);
      }
      // 5 6 7 4/ 1 2 3, 1 3
      //       f  b
      // 5 6 7 1 4/ 2 3
      //       f  b l
      if (move != sublen - move)
      {
        // int longerArrPos = sublen - move < move? (backArrPos + i):j;
        int longerArrPos = sublen - move < move ? (backArrPos + i) : (j);
        backArrPos = max(longerArrPos, backArrPos);
        frontArrPos = min(j, backArrPos);
        sublen = len - frontArrPos;
        move = (sublen - backArrPos + frontArrPos) % sublen;
      }
      else
      {
        break;
      }
    }
  }
};

int main()
{
  Solution s;
  vector<int> test = {1, 2, 3, 4, 5, 6, 7};
  s.rotate(test, 3);
}