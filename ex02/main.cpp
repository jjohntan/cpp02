/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:01:51 by jetan             #+#    #+#             */
/*   Updated: 2025/04/18 18:24:59 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// int	main( void ) {

// 	Fixed		a;
// 	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
	
// 	std::cout << b << std::endl;
	
// 	std::cout << Fixed::max( a, b ) << std::endl;
	
// 	return 0;
// }


int main() {
    Fixed a(10);        // Integer constructor
    Fixed b(2);         // Another Fixed with value 2
    Fixed c = a / b;    // Should result in 5.0

    std::cout << "a = " << a << std::endl;     // 10
    std::cout << "b = " << b << std::endl;     // 2
    std::cout << "a / b = " << c << std::endl; // 5

    Fixed d(3.5f);      // Float constructor
    Fixed e(1.4f);      // Another float
    Fixed f = d / e;    // Should result in 2.5

    std::cout << "d = " << d << std::endl;     // 3.5
    std::cout << "e = " << e << std::endl;     // 1.4
    std::cout << "d / e = " << f << std::endl; // ~2.5

    return 0;
}