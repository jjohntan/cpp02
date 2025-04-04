/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:50:43 by jetan             #+#    #+#             */
/*   Updated: 2025/03/27 18:49:54 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int rawBits;
		static const int fractionalBits;
	public:
		Fixed();//Default constructor
		Fixed(const Fixed &other);//Copy constructor
		Fixed& operator=(const Fixed& other);//Copy assignment operator
		~Fixed();//Destructor
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif