/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:18:20 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/03 10:59:52 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public :
		Intern(void);
		Intern(Intern const& substitue);
		~Intern(void);
		Intern&	operator=(Intern const& substitue);
		AForm*	makeForm(std::string nameForm, std::string traget);
		class	NoMatchNameException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
};

#endif