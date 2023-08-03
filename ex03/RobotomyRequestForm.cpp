/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:02:25 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/03 10:09:11 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("PresidentialRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& substitue) : AForm(substitue), _target(substitue._target)
{
	std::cout << "RobotomyRequestForm copie constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& substitue)
{
	std::cout << "RobotomyRequestForm assignement called" << std::endl;
	if(this != &substitue)
	{
		*this = substitue;
		_target = substitue._target;
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw (AForm::GradeTooLowException());
	if (this->getIsSign() == 0)
		throw (AForm::UnsignedFormException());
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << "*drill noise* " << _target << " was robotomised" << std::endl;
	else
		std::cout << "*drill noise* " << _target << " operation failed" << std::endl;
}