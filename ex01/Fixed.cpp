/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:26:12 by jetan             #+#    #+#             */
/*   Updated: 2025/04/08 14:46:33 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): rawValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int )
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float )
{
	std::cout << "Float constructor called" << std::endl;
}

/**
 * @brief Copy constructor
 */
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	
	*this = other;
}

/**
 * @brief Copy assignment operator
 */
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &other)
		this->rawValue = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/**
 * @brief getter function
 */
int Fixed::getRawBits( void ) const{ return rawValue; }

/**
 * @brief setter function
 */
void Fixed::setRawBits( int const raw )
{
	this->rawValue = raw;
}

/**
 * @brief converts the fixed-point value to a floating-point value
 */
float Fixed::toFloat( void ) const
{
	return (float)rawValue / (1 << fractionalBits);
}

/**
 * @brief converts the fixed-point value to an integer value
 */
int Fixed::toInt( void ) const
{
	return rawValue >> fractionalBits;
}