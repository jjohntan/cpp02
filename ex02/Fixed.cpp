/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:01:48 by jetan             #+#    #+#             */
/*   Updated: 2025/04/09 15:19:55 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


/**
 * @brief Default constructor
 */
Fixed::Fixed()
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
