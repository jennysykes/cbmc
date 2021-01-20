// Ensure common subexpressions work for classes as well.

class Tuple
{
  public:
    int mem1;
    int mem2; 
    int mem3;
};

int main()
{
  Tuple tup;
  Tuple *ptr = &tup;
  ptr->mem1 = 1;
  ptr->mem2 = 1;
  ptr->mem3 = 1;
  if (ptr->mem1 && ptr->mem2 && ptr->mem3)
  {
    return 1;
  }
  return 0;
}
