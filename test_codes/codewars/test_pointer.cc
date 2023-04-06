int main()
{
  int x = 10;
  int const *a = &x;
  int y = 12;
  *a = y;
  a = &y;
  return 0;
}