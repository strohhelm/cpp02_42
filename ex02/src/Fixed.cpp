/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:57:01 by pstrohal          #+#    #+#             */
/*   Updated: 2024/11/25 12:11:20 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

/* ************************************************************************** */
/*		CONSTRUCTORS, DESTRUCTORS											  */
/* ************************************************************************** */

//Default constructor
Fixed::Fixed()
	:_fixed_point_nb_value(0)
	{
	// std::cout<<"Default constructor called"<<std::endl;
}
/*----------------------------------------------------------------------------*/

// Int consructor
Fixed::Fixed(const int in)
{
	if ((in < INTMIN / (1 << _fractional_bits)) || (in > INTMAX / (1 << _fractional_bits))){
		std::cout<<"INT overflow!"<<std::endl;
			std::exit(1);
	}
	_fixed_point_nb_value = in * (1 << _fractional_bits);
	// std::cout<<"Int constructor called"<<std::endl;
}
/*----------------------------------------------------------------------------*/

//Float constructor
Fixed::Fixed(const float input)
{
	if ((input < round(INTMINF / (1<<_fractional_bits))) || (input > round(INTMAXF / (1<<_fractional_bits)))){
		std::cout<<"INT overflow!"<<std::endl;
			std::exit(1);
	}
	_fixed_point_nb_value = static_cast<int>(round(input * (1 << _fractional_bits)));
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
		_fixed_point_nb_value = orig.getRawBits();
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
	return(this->_fixed_point_nb_value < a.getRawBits());
}


/*----------------------------------------------------------------------------*/
//	<=
bool Fixed::operator<=(const Fixed &a) const{
	return(this->_fixed_point_nb_value <= a.getRawBits());
}


/*----------------------------------------------------------------------------*/
// >
bool Fixed::operator>(const Fixed &a) const{
	return(this->_fixed_point_nb_value > a.getRawBits());
}


/*----------------------------------------------------------------------------*/
//	>=
bool Fixed::operator>=(const Fixed &a) const{
	return(this->_fixed_point_nb_value >= a.getRawBits());
}


/*----------------------------------------------------------------------------*/
//	==
bool Fixed::operator==(const Fixed &a) const{
	return(this->_fixed_point_nb_value == a.getRawBits());
}


/*----------------------------------------------------------------------------*/
//	!=
bool Fixed::operator!=(const Fixed &a) const{
	return(this->_fixed_point_nb_value != a.getRawBits());
}


/*----------------------------------------------------------------------------*/
//	+
Fixed Fixed::operator+(const Fixed &b){
	return Fixed(this->toFloat() + b.toFloat());
}


/*----------------------------------------------------------------------------*/
//	-
Fixed Fixed::operator-(const Fixed &b){
	return Fixed(this->toFloat() - b.toFloat());
}


/*----------------------------------------------------------------------------*/
//	*
Fixed Fixed::operator*(const Fixed &b){
	return Fixed(this->toFloat() * b.toFloat());
}


/*----------------------------------------------------------------------------*/
//	/
Fixed Fixed::operator/(const Fixed &b){
	if (b.getRawBits() == 0){
		std::cout<<"Hola hopa! thats a division by 0. Not a good idea!"<<std::endl;
		std::exit(1);
	}
	return Fixed(this->toFloat() / b.toFloat());
}


/*----------------------------------------------------------------------------*/
//	++(X)
Fixed& Fixed::operator++(void){
	this->_fixed_point_nb_value++;
	return (*this);
}


/*----------------------------------------------------------------------------*/
//	--(X)
Fixed& Fixed::operator--(void)
{
	this->_fixed_point_nb_value--;
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


/* ************************************************************************** */
/*			MEMBER FUNCTIONS												  */
/* ************************************************************************** */

int		Fixed::getRawBits(void) const{
	return (_fixed_point_nb_value);
}

/*----------------------------------------------------------------------------*/
void	Fixed::setRawBits(int const raw){
	_fixed_point_nb_value = raw;
}


/*----------------------------------------------------------------------------*/
float	Fixed::toFloat( void ) const{
	return(static_cast<float>(_fixed_point_nb_value) / (1 << _fractional_bits));
}


/*----------------------------------------------------------------------------*/
int		Fixed::toInt( void ) const{
	return((_fixed_point_nb_value >> _fractional_bits));
}


/*----------------------------------------------------------------------------*/
Fixed& Fixed::min(Fixed &a, Fixed &b){
	return ((a < b) ? a : b);
}


/*----------------------------------------------------------------------------*/

const Fixed& Fixed::min(const Fixed &a, const Fixed &b){
	return ((a < b) ? a : b);
}


/*----------------------------------------------------------------------------*/
Fixed& Fixed::max(Fixed &a, Fixed &b){
	return ((a > b) ? a : b);
	
}


/*----------------------------------------------------------------------------*/
const Fixed& Fixed::max(const Fixed &a, const Fixed &b){
	return ((a > b) ? a : b);
}

