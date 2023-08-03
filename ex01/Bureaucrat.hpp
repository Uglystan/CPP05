/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:23:43 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/02 14:21:53 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include <iomanip>
#include "Form.hpp"

class	Form;

class Bureaucrat
{
	public :
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const& substitue);
		Bureaucrat&	operator=(Bureaucrat const& substitue);
		~Bureaucrat(void);
		std::string const&	getName(void) const;
		int	getGrade(void) const;
		void	promoteGrade(void);
		void	demoteGrade(void);
		void	signForm(Form& form);

	private :	
		std::string	_name;
		int	_grade;
		class GradeTooHighException : public std::exception
		{
			public :
				const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& flux, Bureaucrat const& bureaucrat);

#endif