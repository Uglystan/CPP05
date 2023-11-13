/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:42:16 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/07 11:35:40 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include <iomanip>
#include "Bureaucrat.hpp"

class Bureaucrat;
class GradeTooLowException;

class	AForm
{
	public :
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm(AForm const& substitue);
		AForm&	operator=(AForm const& substitue);
		virtual ~AForm(void);
		std::string const&	getName(void) const;
		int	getGradeSign(void) const;
		int	getGradeExec(void) const;
		bool	getIsSign(void) const;
		void	beSigned(Bureaucrat const& bureaucrat);
		void	checkGrade(Bureaucrat const& executor) const;
		virtual void	execute(Bureaucrat const& executor) const = 0;
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
		class	UnsignedFormException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
				class	OpenFileException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};

	private :
		const std::string	_name;
		const int	_gradeSign;
		const int	_gradeExec;
		bool	_isSign;
};

std::ostream&	operator<<(std::ostream& flux, AForm const& form);

#endif