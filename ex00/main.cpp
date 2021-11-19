#include "Bureaucrat.hpp"


void    increment_test(Bureaucrat sample)
{
    try
    {
        sample.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << sample << std::endl;
}

void    decrement_test(Bureaucrat sample)
{
    try
    {
        sample.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << sample << std::endl;
}

int main()
{
    Bureaucrat a("ale", 150);
    Bureaucrat e;
    e = a;
    std::cout <<" = operator src " << a << std::endl;
    std::cout <<" = operator dst" << e << std::endl;
    Bureaucrat clone(a);
    std::cout <<" copy constructor src " << a << std::endl;
    std::cout <<" copy constructor dst " << clone << std::endl;

    Bureaucrat b("bob", 1);
    increment_test(a);
    increment_test(b);
    Bureaucrat c("charles", 150);
    Bureaucrat d("danny", 1);
    decrement_test(c);
    decrement_test(d);
    try
    {
        Bureaucrat f("daeny", 1150);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat f("falco", -1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}