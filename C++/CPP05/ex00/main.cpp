#include "Bureaucrat.hpp"

int main() {
    //	Testing bureaucrat set too high grade
{
	std::cout << "\033[0;32m" << "Testing bureaucrat set too high grade" << "\033[0m" << std::endl;
	try {
		Bureaucrat ponch("Armenchik", -89);
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "\033[0;031m" << e.what() << "\033[0m" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "\033[0;031m" << e.what() << "\033[0m" << std::endl;
	}
}
std::cout << '\n';
///////
//	Testing bureaucrat set too low grade
{
	std::cout << "\033[0;32m" << "Testing bureaucrat set too low grade" << "\033[0m" << std::endl;
	try {
		Bureaucrat ponch("Armenchik", 777);
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "\033[0;031m" << e.what() << "\033[0m" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "\033[0;031m" << e.what() << "\033[0m" << std::endl;
	}
}
std::cout << '\n';
//////////
//	Testing bureaucrat normal grade
{
	std::cout << "\033[0;32m" << "Testing bureaucrat normal grade" << "\033[0m" << std::endl;
	try {
		Bureaucrat ponch("Armenchik", 75);
		std::cout << ponch << std::endl;
		ponch.decrement_grade();
		std::cout << ponch << std::endl;
		ponch.increment_grade();
		std::cout << ponch << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "\033[0;031m" << e.what() << "\033[0m" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "\033[0;031m" << e.what() << "\033[0m" << std::endl;
	}
}//////////
std::cout << std::endl;
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;

        b1.increment_grade(); // Повышаем до 1
        std::cout << b1 << std::endl;

        b1.increment_grade(); // Попытка повысить выше 1 — выброс исключения
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;

        b2.decrement_grade(); // Понижаем до 150
        std::cout << b2 << std::endl;

        b2.decrement_grade(); // Попытка понизить ниже 150 — выброс исключения
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}