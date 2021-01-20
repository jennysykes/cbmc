// Example with common subexpressions that are
// multiple layers, or subexpressions of other
// subexpressions.

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
  if (ptr->mem1 && ptr->ptr->mem2 && ptr->ptr->mem3)
  {
    return 1;
  }
  return 0;
}
