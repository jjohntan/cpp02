/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:01:48 by jetan             #+#    #+#             */
/*   Updated: 2025/04/20 19:16:12 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief Default constructor
 */
Fixed::Fixed(): rawValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief integer constructor
 */
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	
	this->rawValue = value << fractionalBits;
}

/**
 * @brief float constructor
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
 * @brief Destructor
 */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
	
	newObj.setRawBits((this->rawValue * other.rawValue) >> fractionalBits);//convert back to float
	return newObj;
}
	
Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed newObj;

	newObj.setRawBits((this->rawValue << fractionalBits) / other.rawValue);//convert back to float
	return newObj;
}

//increment/decrement operators
Fixed Fixed::operator++()//pre-increment
{
	this->rawValue++;//increase the raw value by 1
	
	return *this;//return new value by reference
}

Fixed Fixed::operator++(int)// post-increment
{
	Fixed temp = *this;//store the current value
	this->rawValue++;//increment raw value
	
	return temp;//return old value
}

Fixed Fixed::operator--()// pre-decrement
{
	this->rawValue--;//decrease the raw value by 1
	
	return *this;//return new value by reference
}

Fixed Fixed::operator--(int)//post-decrement
{
	Fixed temp = *this;//store the current value
	this->rawValue--;//decrement raw value
	
	return temp;//return old value
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

/**
 * @param os: out stream
 * @param obj: object
 * @brief An overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as parameter.
 */
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}