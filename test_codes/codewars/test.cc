#include <string>
#include <iostream>
using namespace std;

std::string reverse_words(std::string str)
{
  int len = str.length();
  int left = 0, right = 0, final = 0;
  for(; left < len; ++left) {
    if(str[left] != ' ') {
      right = left;
      while(right < len && str[right] != ' ') {
        ++right;
      }
      final = right;
      --right;
      while(left < right) {
        char tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;
        ++left; --right;
      }
      left = final;
    }
  }
  return str;
}

int main() {
    string apple = "double  spaced  words";
    string ret = reverse_words(apple);
    cout << ret << endl;
}