/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:26:12 by jetan             #+#    #+#             */
/*   Updated: 2025/04/07 15:09:38 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
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

Fixed::Fixed(const Fixed &other)//Copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
	
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
