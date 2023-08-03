/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:17:58 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/03 11:02:36 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(Intern const& substitue)
{
	(void)substitue;
	std::cout << "Intern copie constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern&	Intern::operator=(Intern const& substitue)
{
	if (this != &substitue)
	{
		
	}
	return (*this);
}

const char*	Intern::NoMatchNameException::what() const throw()
{
	return ("No form match for this name");
}

AForm*	Intern::makeForm(std::string nameForm, std::string target)
{
	AForm	*form;
	int	i = 0;
	std::string	formTab[3] = {"presidential pardon", "shrubbery creation", "robotomy request"};

	while (i < 3 && formTab[i] != nameForm)
		i++;

	switch (i)
	{
		case (0):
			form = new PresidentialPardonForm(target);
			std::cout << "Intern creates presidential pardon" << std::endl;
			break;
		case (1):
			form = new ShrubberyCreationForm(target);
			std::cout << "Intern creates shurbbery creation" << std::endl;
			break;
		case (2):
			form = new RobotomyRequestForm(target);
			std::cout << "Intern creates robotomy request" << std::endl;
			break;
	
		default:
			throw NoMatchNameException();
			break;
	}
	return (form);
}