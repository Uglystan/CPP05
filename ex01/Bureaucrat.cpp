/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:08:07 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/07 11:29:52 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& substitue) : _name(substitue._name), _grade(substitue._grade)
{
	std::cout << "Bureaucrat copie constructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& substitue)
{
	if(this != &substitue)
	{
		_grade = substitue._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string const& Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return(_grade);
}

void	Bureaucrat::promoteGrade(void)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}
void	Bureaucrat::demoteGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Error grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Error grade too low");
}

std::ostream&	operator<<(std::ostream& flux, Bureaucrat const& bureaucrat)
{
	flux << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (flux);
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because grade too low" << std::endl;
	}
}