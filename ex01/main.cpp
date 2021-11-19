#include "Bureaucrat.hpp"
#include "Form.hpp"

void    test_constructor_low()
{
    try
    {
        Form a("a", 100, 100);
    }
    catch(std::exception & e)
    {
		std::cerr << e.what() << std::endl;
    }

    try
    {
        Form b("b", 155, 100);
    }
    catch(std::exception & e)
    {
		std::cerr << e.what() << std::endl;
    }

    try
    {
        Form c("c", 100, 155);
    }
    catch(std::exception & e)
    {
		std::cerr << e.what() << std::endl;
    }
}

void    test_constructor_high()
{
    try
    {
        Form a("a", 100, 100);
    }
    catch(std::exception & e)
    {
		std::cerr << e.what() << std::endl;
    }

    try
    {
        Form b("b", -1, 100);
    }
    catch(std::exception & e)
    {
		std::cerr << e.what() << std::endl;
    }

    try
    {
        Form c("c", 100, -1);
    }
    catch(std::exception & e)
    {
		std::cerr << e.what() << std::endl;
    }
}

void    be_signed_test_pre_signed_ng()
{
    try
    {
        Bureaucrat pre("pre", 10);
        Form pre_form("pre_form", 50, 50);
        pre.signForm(pre_form);
        pre.signForm(pre_form);
    }
    catch(std::exception & e)
    {
		std::cerr << e.what() << std::endl;
    }
};

void    be_signed_test_low_ng()
{
    try
    {
        Bureaucrat pre("pre", 100);
        Form pre_form("pre_form", 50, 50);
        pre.signForm(pre_form);
    }
    catch(std::exception & e)
    {
		std::cerr << e.what() << std::endl;
    }
};

void    be_signed_test_ok()
{
    try
    {
        Bureaucrat pre("pre", 10);
        Form pre_form("pre_form", 50, 50);
        pre.signForm(pre_form);
    }
    catch(std::exception & e)
    {
		std::cerr << e.what() << std::endl;
    }
};


int main()
{
    Form a("ale", 100 , 100);
    Form e;
    e = a;
    std::cout <<" = operator src " << a << std::endl;
    std::cout <<" = operator dst" << e << std::endl;
    Form clone(a);
    std::cout <<" copy constructor src " << a << std::endl;
    std::cout <<" copy constructor dst " << clone << std::endl;
    test_constructor_high();
    test_constructor_low();
    be_signed_test_pre_signed_ng();
    be_signed_test_low_ng();
    be_signed_test_ok();
}

// constraints of grades number  constructor
// be signed grade too low exception
// signForm three road
