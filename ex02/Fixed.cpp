/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:01:48 by jetan             #+#    #+#             */
/*   Updated: 2025/04/11 16:40:48 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief Default constructor
 */
Fixed::Fixed(): rawValue(0)
{
}

/**
 * @brief integer constructor
 */
Fixed::Fixed(const int value)
{
	this->rawValue = value << fractionalBits;
}

/**
 * @brief float constructor
 */
Fixed::Fixed(const float value)
{
	this->rawValue = roundf(value * (1 << fractionalBits));
}

/**
 * @brief Copy constructor
 */
Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

/**
 * @brief Copy assignment operator
 */
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->rawValue = other.getRawBits();
	return *this;
}

/**
 * @brief Destructor
 */
Fixed::~Fixed()
{
}
/**
 * @brief getter function
 */
int Fixed::getRawBits( void ) const { return rawValue; }

/**
 * @brief setter function
 */
void Fixed::setRawBits( int const raw )
{
	this->rawValue = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)rawValue / (1 << fractionalBits);
}

int Fixed::toInt( void ) const
{
	return rawValue >> fractionalBits;
}

//comparison operators
bool Fixed::operator<(const Fixed &other) const
{
	return this->rawValue < other.rawValue;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->rawValue >= other.rawValue;
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->rawValue > other.rawValue;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->rawValue <= other.rawValue;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->rawValue == other.rawValue;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->rawValue != other.rawValue;
}

// arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed newObj = this->toFloat() + other.toFloat();

	return newObj;
}
	
Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed newObj = this->toFloat() - other.toFloat();

	return newObj;
}
	
Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed	newObj;
	
	newObj.setRawBits((this->rawValue * other.rawValue) >> fractionalBits);
	return newObj;
}
	
Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed newObj = (this->rawValue << fractionalBits) / other.rawValue;

	return newObj;
}

//increment/decrement operators
Fixed Fixed::operator++()//pre-increment
{
	this->rawValue++;
	
	return *this;
}

Fixed Fixed::operator++(int)// post-increment
{
	Fixed temp = *this;
	this->rawValue++;
	
	return temp;
}

Fixed Fixed::operator--()// pre-decrement
{
	this->rawValue--;
	
	return *this;
}

Fixed Fixed::operator--(int)//post-decrement
{
	Fixed temp = *this;
	this->rawValue--;
	
	return temp;
}

//two references on fixed-point number
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)	
		return (a);
	return (b);
}

//two references to constant fixed-point numbers
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

//two references on fixed-point numbers
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

//two references to constant fixed-point numbers
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}