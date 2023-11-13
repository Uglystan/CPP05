/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:30:59 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/09 14:40:14 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	bureaucrat("Paul", 1);
		//Bureaucrat	bureaucrat("Paul", 151);
		//Bureaucrat	bureaucrat("Paul", 0);
		//Bureaucrat	bureaucrat("Paul", 150);
		bureaucrat.demoteGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.promoteGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
}
