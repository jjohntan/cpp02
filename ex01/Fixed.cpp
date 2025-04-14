/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:26:12 by jetan             #+#    #+#             */
/*   Updated: 2025/04/13 16:47:37 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief default constructor
 */
Fixed::Fixed(): rawValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief A constructor that takes a constant integer as a parameter.
 * It converts it to the corresponding fixed-point value
 */
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	
	this->rawValue = value << fractionalBits;
}

/**
 * A constructor that takes a constant floating-point number as a parameter.
It converts it to the corresponding fixed-point value.
 */
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	
	this->rawValue = roundf(value * (1 << fractionalBits));//roundf: rounds a number to the nearest integer
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

/**
 * @brief destructor
 */
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

/**
 * @brief An overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as parameter.
 */
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}