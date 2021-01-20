// Example where common subexpressions should be kept
// between through assignments..

struct tuple
{
 int mem1;
 int mem2; 
 int mem3;
 int mem4;
};

int main()
{
  struct tuple tup;
  struct tuple *ptr = &tup;
  int i = 3;
  int j = 5;
  ptr->mem1 = 1;
  ptr->mem2 = 0;
  ptr->mem3 = 1;
  ptr->mem4 = 1;
  if (ptr->mem1 && ptr->mem2)
  {
    return 1;
  }
  i = j;
  if (ptr->mem3 && ptr->mem4)
  {
    return 2;
  }
  return 0;
}
