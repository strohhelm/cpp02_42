/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:57:01 by pstrohal          #+#    #+#             */
/*   Updated: 2024/11/22 19:40:13 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

/* ************************************************************************** */
/*		CONSTRUCTORS, DESTRUCTORS											  */
/* ************************************************************************** */

//Default constructor
Fixed::Fixed()
	:fixed_point_nb_value(0)
	{
	// std::cout<<"Default constructor called"<<std::endl;
}
/*----------------------------------------------------------------------------*/

// Int consructor
Fixed::Fixed(const int in)
	:fixed_point_nb_value(in * 256.0f)
	{
	// std::cout<<"Int constructor called"<<std::endl;
}
/*----------------------------------------------------------------------------*/

//Float constructor
Fixed::Fixed(const float input)
{
	fixed_point_nb_value = static_cast<int>(round(input * 256));
	// std::cout<<"Float constructor called"<<std::endl;
}
/*----------------------------------------------------------------------------*/

// Copy constructor
Fixed::Fixed(const Fixed &orig)
{
	*this = orig;
}
/*----------------------------------------------------------------------------*/


// Default destructor
Fixed::~Fixed()
{
	// std::cout<<"Default destructor called!"<<std::endl;
}

/* ************************************************************************** */
/*		OPERATOR OVERLOADS													  */
/* ************************************************************************** */

// Copy assignment operator overload
Fixed& Fixed::operator=(const Fixed &orig)
{
	if (this != &orig)
		fixed_point_nb_value = orig.getRawBits();
	// std::cout<<"Copy assignment operator called!"<<std::endl;
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
//	<
bool Fixed::operator<(const Fixed &a) const{
	return(this->fixed_point_nb_value < a.getRawBits());
}
/*----------------------------------------------------------------------------*/
//	<=
bool Fixed::operator<=(const Fixed &a) const{
	return(this->fixed_point_nb_value <= a.getRawBits());
}
/*----------------------------------------------------------------------------*/
// >
bool Fixed::operator>(const Fixed &a) const{
	return(this->fixed_point_nb_value > a.getRawBits());
}
/*----------------------------------------------------------------------------*/
//	>=
bool Fixed::operator>=(const Fixed &a) const{
	return(this->fixed_point_nb_value >= a.getRawBits());
}
/*----------------------------------------------------------------------------*/
//	==
bool Fixed::operator==(const Fixed &a) const{
	return(this->fixed_point_nb_value == a.getRawBits());
}
/*----------------------------------------------------------------------------*/
//	!=
bool Fixed::operator!=(const Fixed &a) const{
	return(this->fixed_point_nb_value != a.getRawBits());
}
/*----------------------------------------------------------------------------*/
//	+
float Fixed::operator+(const Fixed &b){
	return (this->toFloat() + b.toFloat());
}
/*----------------------------------------------------------------------------*/
//	-
float Fixed::operator-(const Fixed &b){
	return (this->toFloat() - b.toFloat());
}
/*----------------------------------------------------------------------------*/
//	*
float Fixed::operator*(const Fixed &b){
	return (this->toFloat() * b.toFloat());
}
/*----------------------------------------------------------------------------*/
//	/
float Fixed::operator/(const Fixed &b){
	return (this->toFloat() / b.toFloat());
}
/*----------------------------------------------------------------------------*/
//	++(X)
Fixed& Fixed::operator++(void){
	this->fixed_point_nb_value++;
	return (*this);
}
/*----------------------------------------------------------------------------*/
//	--(X)
Fixed& Fixed::operator--(void)
{
	this->fixed_point_nb_value--;
	return (*this);
}
/*----------------------------------------------------------------------------*/
//	(X)++
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}
/*----------------------------------------------------------------------------*/
//	(X)--
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}
/*----------------------------------------------------------------------------*/



/* ************************************************************************** */
/*			MEMBER FUNCTIONS												  */
/* ************************************************************************** */
int		Fixed::getRawBits(void) const
{
	// std::cout<<"getRawBits member funciton called!"<<std::endl;
	return (fixed_point_nb_value);
}

/*----------------------------------------------------------------------------*/

void	Fixed::setRawBits(int const raw)
{
	// std::cout<<"setRawBits member funciton called!"<<std::endl;
	fixed_point_nb_value = raw;
}

/*----------------------------------------------------------------------------*/

float	Fixed::toFloat( void ) const
{
	return(static_cast<float>(fixed_point_nb_value) / (1 << fractional_bits));
}

/*----------------------------------------------------------------------------*/

int		Fixed::toInt( void ) const
{
	return((fixed_point_nb_value >> fractional_bits));

/*----------------------------------------------------------------------------*/
}
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

/*----------------------------------------------------------------------------*/

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{

	return ((a < b) ? a : b);
	
}

/*----------------------------------------------------------------------------*/

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
	
}

/*----------------------------------------------------------------------------*/

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}

