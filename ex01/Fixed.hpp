/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:26:15 by jetan             #+#    #+#             */
/*   Updated: 2025/04/14 13:59:24 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int rawValue;//store the fixed-point number value
		static const int fractionalBits = 8;//store the number of fractional bits. Its value will always be the integer literal 8.
	public:
		Fixed();//Default constructor
		Fixed(const int value);//int constructor
		Fixed(const float value);//float constructor
		Fixed(const Fixed &other);//Copy constructor
		Fixed &operator=(const Fixed &other);//Copy assignment operator
		~Fixed();//Destructor
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif