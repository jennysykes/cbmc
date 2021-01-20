// Common subexpressions that also include an assignment
// Ideally this would not cause problems for the common
// subexpression solution

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
  while (ptr->mem1 < 10 && ptr->mem2 && ptr->mem3) {
    ptr->mem1++;
  }
  return 0;
}
