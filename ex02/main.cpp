#include "PresidentialPardonForm.hpp"


void president_test(int i)
{
  try
  {
    PresidentialPardonForm a("josseph");
    Bureaucrat ace("ace",i);
    ace.signForm(a);
    a.execute(ace);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
}

int main()
{
  president_test(50);
  president_test(20);
  president_test(1);
}

//form to virtual and
//vbuild presidente

