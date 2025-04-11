/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:01:45 by jetan             #+#    #+#             */
/*   Updated: 2025/04/11 15:22:17 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int rawValue;
		static const int fractionalBits = 8;
	public:
		Fixed();//Default constructor
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);//Copy constructor
		Fixed &operator=(const Fixed &other);//Copy assignment operator
		~Fixed();//Destructor
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		//comparison operators
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		
		// arithmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		
		//increment/decrement operators
		Fixed operator++();//pre-increment
		Fixed operator++(int);// post-increment
		Fixed operator--();// pre-decrement
		Fixed operator--(int);//post-decrement
		
		//two references on fixed-point number
		static Fixed &min(Fixed &a, Fixed &b);
		//two references to constant fixed-point numbers
		const Fixed &min(const Fixed &a, const Fixed &b);
		//two references on fixed-point numbers
		static Fixed &max(Fixed &a, Fixed &b);
		//two references to constant fixed-point numbers
		const Fixed &max(const Fixed &a, const Fixed &b);
};

#endif