/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:42:16 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/07 11:30:45 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include <iomanip>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	public :
		Form(std::string name, int gradeSign, int gradeExec);
		Form(Form const& substitue);
		Form&	operator=(Form const& substitue);
		~Form(void);
		std::string const&	getName(void) const;
		int	getGradeSign(void) const;
		int	getGradeExec(void) const;
		bool	getIsSign(void) const;
		void	beSigned(Bureaucrat const& bureaucrat);

	private :
		const std::string	_name;
		const int	_gradeSign;
		const int	_gradeExec;
		bool	_isSign;
		class	GradeTooHighException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& flux, Form const& form);

#endif