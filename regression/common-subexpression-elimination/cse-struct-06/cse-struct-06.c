// Multiple layers of common subexpressions and also
// an update deep inside. This may be a nice test
// of both layer subexpressions and assignments

struct tuple
{
 int mem1;
 int mem2; 
 int mem3;
 struct tuple *ptr;
};

int main()
{
  struct tuple tup1;
  struct tuple tup2;
  struct tuple *ptr = &tup1;
  ptr->ptr = ptr;  // ugly
  ptr->mem1 = 1;
  ptr->mem2 = 1;
  ptr->mem3 = 1;
  while (ptr->ptr->mem1 < 10 && ptr->mem2 && ptr->mem3) {
    ptr->ptr->mem1++;
  }
  return 0;
}
