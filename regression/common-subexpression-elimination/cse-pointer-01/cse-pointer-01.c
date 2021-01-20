// A very simple example with pointers only.

int main()
{
  int val;
  int *ptr = &val; // should this populate the cache for *ptr? (and invalidate old values)
  val = 1;
  if (*ptr && *ptr)
  {
    return 1;
  }
  return 0;
}
