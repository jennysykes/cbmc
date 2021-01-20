// Simple extension to check common subexpressions
// inside a larger expression with other parts
// that are not involved in the dereference

struct tuple
{
 int mem1;
 int mem2; 
 int mem3;
};

int main()
{
  struct tuple tup;
  struct tuple *ptr = &tup;
  int x = 1;
  int y = 1;
  ptr->mem1 = 1;
  ptr->mem2 = 1;
  ptr->mem3 = 1;
  if (ptr->mem1 && x == y && ptr->mem3)
  {
    return 1;
  }
  return 0;
}
