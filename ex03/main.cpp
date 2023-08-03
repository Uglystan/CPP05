/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:30:59 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/03 11:07:40 by lgirault         ###   ########.fr       */
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
	AForm* goodForm;
	AForm* badForm;

	try
	{
		goodForm = someRandomIntern.makeForm("robotomy request", "Bender");
		badForm = someRandomIntern.makeForm("robotmy request", "Bender");
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete goodForm;

	return (0);
}
