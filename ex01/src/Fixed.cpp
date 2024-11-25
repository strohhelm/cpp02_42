/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:57:01 by pstrohal          #+#    #+#             */
/*   Updated: 2024/11/25 11:33:41 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

/* ************************************************************************** */
/*		CONSTRUCTORS, DESTRUCTORS, ASSIGNMENT OPERATORS
*/
//Default constructor
Fixed::Fixed()
	:_fixed_point_nb_value(0)
	{
	std::cout<<"Default constructor called"<<std::endl;
}
/*----------------------------------------------------------------------------*/

// Int consructor
Fixed::Fixed(const int in)
	:_fixed_point_nb_value(in * 256.0f)
	{
	std::cout<<"Int constructor called"<<std::endl;
}
/*----------------------------------------------------------------------------*/

//Float constructor
Fixed::Fixed(const float input)
{
	_fixed_point_nb_value = static_cast<int>(round(input * 256));
	std::cout<<"Float constructor called"<<std::endl;
}
/*----------------------------------------------------------------------------*/

// Copy constructor
Fixed::Fixed(const Fixed &orig)
{
	*this = orig;
}
/*----------------------------------------------------------------------------*/

// Copy assignment operator overload
Fixed& Fixed::operator=(const Fixed &orig)
{
	if (this != &orig)
		_fixed_point_nb_value = orig.getRawBits();
	std::cout<<"Copy assignment operator called!"<<std::endl;
	return *this;
}
/*----------------------------------------------------------------------------*/

// Insertion assignment operator overload
std::ostream &operator<<(std::ostream &ostream, const Fixed &orig)
{
	ostream << orig.toFloat();
	return ostream;
}
/*----------------------------------------------------------------------------*/

// Default destructor
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
	return (_fixed_point_nb_value);
}

/*----------------------------------------------------------------------------*/

void	Fixed::setRawBits(int const raw)
{
	std::cout<<"setRawBits member funciton called!"<<std::endl;
	_fixed_point_nb_value = raw;
}

/*----------------------------------------------------------------------------*/

float	Fixed::toFloat( void ) const
{
	return(static_cast<float>(_fixed_point_nb_value) / (1 << _fractional_bits));
}

/*----------------------------------------------------------------------------*/

int		Fixed::toInt( void ) const
{
	return((_fixed_point_nb_value >> _fractional_bits));
}
