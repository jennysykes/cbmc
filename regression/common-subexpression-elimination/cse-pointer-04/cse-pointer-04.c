// This is a stress test for the way we handle
// and maintain the common subexpression cache
// (depending on implementation). Here we should
// possible have many dereferences that may or may
// not be invalidated.
// Note that TESTSIZE can be easily changed if we
// need larger numbers.

#define TESTSIZE 1024

int main()
{
  int idx = 0;
  int *arr[TESTSIZE];
  while (idx < TESTSIZE)
  {
    arr[idx] = &idx;
    idx++;
  }
  idx = 0;
  while (idx < TESTSIZE - 1)
  {
    if (*(arr[idx]) != *(arr[idx+1]))
    {
      return 1;
    }
    idx++;
  }
  return 0;
}
