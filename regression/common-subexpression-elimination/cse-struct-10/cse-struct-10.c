// Example where common subexpressions should not be kept
// between assignments?

struct tuple
{
 int mem1;
 int mem2; 
 int mem3;
 int mem4;
 struct tuple * ptr;
};

int main()
{
  struct tuple tup1;
  struct tuple tup2;
  struct tuple *ptr = &tup1;
  ptr->mem1 = 1;
  ptr->mem2 = 0;
  ptr->mem3 = 1;
  ptr->mem4 = 1;
  ptr->ptr = ptr;
  tup2.mem1 = 0;
  tup2.mem2 = 0;
  tup2.mem3 = 0;
  tup2.mem4 = 0;
  tup2.ptr = &tup2;
  if (ptr->mem1 && ptr->mem2)
  {
    return 1;
  }
  ptr = &tup2; // shouldeffect common subexpression elimination
  if (ptr->mem3 && ptr->mem4)
  {
    return 2;
  }
  return 0;
}
