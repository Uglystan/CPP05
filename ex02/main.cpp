/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:30:59 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/09 14:49:07 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

/*Signature ok mais execution non*/
int	main()
{
	Bureaucrat	b("Paul", 23);
	PresidentialPardonForm	p("TEST");

	b.signForm(p);

	b.excuteForm(p);
}

/*Pas de signature*/
// int	main()
// {
// 	Bureaucrat	b("Paul", 1);
// 	PresidentialPardonForm	p("TEST");
// 	b.excuteForm(p);
// 	b.excuteForm(p);
// }

/*Signature impossible*/
// int	main()
// {
// 	Bureaucrat	b("Paul", 123);
// 	PresidentialPardonForm	p("TEST");

// 	b.signForm(p);

// 	b.excuteForm(p);
// 	b.excuteForm(p);
// }

/*Form robot*/
// int	main()
// {
// 	Bureaucrat	b("Paul", 1);
// 	RobotomyRequestForm	p("TEST");

// 	b.signForm(p);

// 	b.excuteForm(p);
// }

/*Form arbre*/
// int	main()
// {
// 	Bureaucrat	b("Paul", 1);
// 	ShrubberyCreationForm	p("TEST");

// 	b.signForm(p);

// 	b.excuteForm(p);
// }
