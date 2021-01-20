// This test is to stress the efficiency a little since we may
// keep doing new assignments and expression elimination
// inside a large loop.

struct tuple
{
 int mem1;
 int mem2; 
 int mem3;
 struct tuple *ptr;
};

int main()
{
  struct tuple tup;
  struct tuple *ptr = &tup;
  ptr->ptr = ptr;  // ugly
  ptr->mem1 = 1;
  ptr->mem2 = 1;
  ptr->mem3 = 1;
  while (ptr->mem1 < 10000)
  {
    if (!(ptr->mem2 && ptr->mem3))
    {
      return 3;
    }
    ptr->mem1++;
  }
  return 0;
}
