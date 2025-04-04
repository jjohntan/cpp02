/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:50:46 by jetan             #+#    #+#             */
/*   Updated: 2025/04/05 20:03:26 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): rawValue(0)
{
}

Fixed::Fixed(const Fixed &other)//Copy constructor
{
	std::cout << "copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)//Copy assignment operator
{
	std::cout << "copy assignment operator called" << std::endl;
	
	if (this != &other)
		this->rawValue = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor" << std::endl;
}
