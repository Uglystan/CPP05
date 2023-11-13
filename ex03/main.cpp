/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:30:59 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/05 10:47:53 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	Bureaucrat	p("Paul", 2);
	AForm* goodForm;
	AForm* badForm;

	try
	{
		goodForm = someRandomIntern.makeForm("robotomy request", "Bender");
		p.signForm(*goodForm);
		p.excuteForm(*goodForm);
		badForm = someRandomIntern.makeForm("robotmy request", "Bender");
		p.signForm(*badForm);
		p.excuteForm(*badForm);
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete goodForm;

	return (0);
}
