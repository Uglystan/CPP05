/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:49:09 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/07 11:31:30 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
	_isSign = 0;
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(Form const& substitue) : _name(substitue._name), _gradeSign(substitue._gradeSign), _gradeExec(substitue._gradeExec), _isSign(substitue._isSign)
{
	std::cout << "Form copie constructor called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

Form&	Form::operator=(Form const& substitue)
{
	if (this != &substitue)
	{
		_isSign = substitue._isSign;
	}
	return (*this);
}

std::string const&	Form::getName(void) const
{
	return (_name);
}

int	Form::getGradeSign(void) const
{
	return (_gradeSign);
}

int	Form::getGradeExec(void) const
{
	return (_gradeExec);
}

bool	Form::getIsSign(void) const
{
	return (_isSign);
}

std::ostream&	operator<<(std::ostream& flux, Form const& form)
{
	flux << "Form Name : " << form.getName() << " | Grade for sign : " << form.getGradeSign() << " | Grade for execute : " << form.getGradeExec() << " | is signed " << form.getIsSign();
	return (flux);
}

void	Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw Form::GradeTooLowException();
	_isSign = 1;
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Error grade too high");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("Error grade too low");
}