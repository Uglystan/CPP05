/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:04:29 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/03 09:59:16 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("PresidentialRequestForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& substitue) : AForm(substitue), _target(substitue._target)
{
	std::cout << "ShrubberyCreationForm copie constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& substitue)
{
	std::cout << "ShrubberyCreationForm assignement called" << std::endl;
	if(this != &substitue)
	{
		*this = substitue;
		_target = substitue._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw (AForm::GradeTooLowException());
	if (this->getIsSign() == 0)
		throw (AForm::UnsignedFormException());
	 std::ofstream fichier((_target + "_shrubbery").c_str());
	 if (fichier.is_open())
	 {
		fichier << "$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n   ||   \n   ||   \n";
		fichier << "$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n   ||   \n   ||   ";
		fichier.close();
	 }
	 else
	 	throw (AForm::OpenFileException());
}