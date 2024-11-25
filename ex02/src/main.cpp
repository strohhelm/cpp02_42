/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:49:20 by pstrohal          #+#    #+#             */
/*   Updated: 2024/11/25 12:39:22 by pstrohal         ###   ########.fr       */
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
	
	std::cout << "max("<<a<<", "<<b<<"): "<<Fixed::max( a, b ) << std::endl;
	std::cout << "min("<<a<<", "<<b<<"): "<<Fixed::min( a, b ) << std::endl;
	std::cout << "max("<<a<<", "<<b<<"): "<<Fixed::max( a, b ) << std::endl;
	std::cout << "min("<<a<<", "<<b<<"): "<<Fixed::min( a, b ) <<"\n"<<std::endl;
	
	Fixed c = 5.25f;
	Fixed d = 4.5f;
	std::cout<<c<<" + "<<b<<" = " <<c + b<<std::endl;
	std::cout<<c<<" - "<<b<<" = " <<c - b<<std::endl;
	std::cout<<c<<" * "<<b<<" = " <<c * b<<std::endl;
	std::cout<<c<<" / "<<b<<" = " <<c / b<<"\n"<<std::endl;
	
	std::cout<<"max("<<c + a<<", "<< c/d<<"):          "<<Fixed::max(c+a, c/d) <<std::endl;
	std::cout<<"min("<<c<<" + "<<a<<", "<< c/d<<"): "<<Fixed::min(c+a, c/d) <<std::endl;
	std::cout<<"min("<<c + a<<", "<< c/d<<"):          "<<Fixed::min(c+a, c/d)<<"\n" <<std::endl;
	
	std::cout<<Fixed(c/d)<<std::endl;
	std::cout<<c/d<<"\n"<<std::endl;
	
	std::cout<<"int min int max test:"<<std::endl;
	Fixed f = 8388607;
	std::cout<<f <<std::endl;
	Fixed g = 8388607.0f;
	std::cout<<g <<std::endl;
	std::cout<<c/Fixed()<<"\n"<<std::endl;

	return 0;
	
}