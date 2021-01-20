// Test for common subexpressions to survive code that
// does no "real" assignments (note that return value
// is assigned, which should be considered a special
// case).

int main()
{
  int val0;
  int val1;
  int *ptr = &val1;
  val0 = 0;
  val1 = 1;
  if (*ptr && !(*ptr)) // always fail
  {
    return 1;
  }
  ptr = &val0; // ensure commom subexpression elimination is correct here
  if (!(*ptr || *ptr))
  {
    return 2;
  }
  return 0;
}
