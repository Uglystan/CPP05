/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:30:59 by lgirault          #+#    #+#             */
/*   Updated: 2023/09/12 14:00:19 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Form	f("test", 100, 110);
	Bureaucrat	b("Paul", 101);
	
	std::cout << f << std::endl;
	std::cout << b << std::endl;

	b.signForm(f);
}
