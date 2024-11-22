/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:49:20 by pstrohal          #+#    #+#             */
/*   Updated: 2024/11/22 19:44:24 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout <<"   a: "<< a << std::endl;
	std::cout <<" ++a: "<< ++a << std::endl;
	std::cout <<"   a: "<<a << std::endl;
	std::cout <<" a++: "<<a++ << std::endl;
	std::cout <<"   a: "<<a << std::endl;
	std::cout <<"   b: "<<b <<"\n"<< std::endl;
	
	std::cout << "max(a, b) "<<Fixed::max( a, b ) << std::endl;
	std::cout << "min(a, b) "<<Fixed::min( a, b ) << std::endl;
	std::cout << "max(a, b) "<<Fixed::max( a, b ) << std::endl;
	std::cout << "min(a, b) "<<Fixed::min( a, b ) << std::endl;
	return 0;
	
}