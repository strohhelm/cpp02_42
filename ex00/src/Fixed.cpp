/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:57:01 by pstrohal          #+#    #+#             */
/*   Updated: 2024/11/25 12:34:32 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
/* ************************************************************************** */
/*		CONSTRUCTORS, DESTRUCTORS, ASSIGNMENT OPERATORS
*/

// Default destructor
Fixed::Fixed()
	:fixed_point_nb_value(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}
/*----------------------------------------------------------------------------*/

// Copy constructor
Fixed::Fixed(const Fixed &Orig)
{
	this->fixed_point_nb_value = Orig.fixed_point_nb_value;
	std::cout<<"Copy constructor called!"<<std::endl;
}
/*----------------------------------------------------------------------------*/
// Copy assignment operator
Fixed& Fixed::operator=(const Fixed &Orig)
{
	if (this != &Orig)
		this->fixed_point_nb_value = Orig.getRawBits();
	std::cout<<"Copy assignment operator called!"<<std::endl;
	return *this;
}
/*----------------------------------------------------------------------------*/

//Default constructor
Fixed::~Fixed()
{
	std::cout<<"Default destructor called!"<<std::endl;
}
/* ************************************************************************** */
/*		MEMBER FUNCTIONS
*/

int		Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member funciton called!"<<std::endl;
	return (this->fixed_point_nb_value);
}
/*----------------------------------------------------------------------------*/

void	Fixed::setRawBits(int const raw)
{
	std::cout<<"setRawBits member funciton called!"<<std::endl;

	this->fixed_point_nb_value = raw;
}
