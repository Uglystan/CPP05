/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:49:09 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/07 11:35:58 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
	_isSign = 0;
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(AForm const& substitue) : _name(substitue._name), _gradeSign(substitue._gradeSign), _gradeExec(substitue._gradeExec), _isSign(substitue._isSign)
{
	std::cout << "AForm copie constructor called" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm&	AForm::operator=(AForm const& substitue)
{
	if (this != &substitue)
	{
		_isSign = substitue._isSign;
	}
	return (*this);
}

std::string const&	AForm::getName(void) const
{
	return (_name);
}

int	AForm::getGradeSign(void) const
{
	return (_gradeSign);
}

int	AForm::getGradeExec(void) const
{
	return (_gradeExec);
}

bool	AForm::getIsSign(void) const
{
	return (_isSign);
}

std::ostream&	operator<<(std::ostream& flux, AForm const& form)
{
	flux << "AForm Name : " << form.getName() << " | Grade for sign : " << form.getGradeSign() << " | Grade for execute : " << form.getGradeExec() << " | is signed " << form.getIsSign();
	return (flux);
}

void	AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw AForm::GradeTooLowException();
	_isSign = 1;
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Error grade too high");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Error grade too low");
}

const char*	AForm::UnsignedFormException::what(void) const throw()
{
	return ("Error Form unsigned");
}

const char*	AForm::OpenFileException::what(void) const throw()
{
	return ("Error File can't be open");
}

void	AForm::checkGrade(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw (AForm::GradeTooLowException());
	if (this->getIsSign() == 0)
		throw (AForm::UnsignedFormException());
}