/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:37:31 by pstrohal          #+#    #+#             */
/*   Updated: 2024/11/25 11:56:10 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#define INTMIN -2147483648
#define INTMAX  2147483647
#define INTMINF -2147483648.0
#define INTMAXF  2147483647.0

#include <iostream>
#include <cmath>

class Fixed
{
	public:
	//CONSTRUCTORS
		Fixed();
		Fixed(const int in);
		Fixed(const float in);
		Fixed(const Fixed &Orig);
	//DESTRUCTORS	
		~Fixed();

	// OPERATOR OVERLOADS
		Fixed& operator=(const Fixed &Orig);
		friend std::ostream& operator<<(std::ostream& os, const Fixed &Orig);

		bool operator<(const Fixed &a) const;
		bool operator<=(const Fixed &a) const;
		bool operator>(const Fixed &a) const;
		bool operator>=(const Fixed &a) const;
		bool operator==(const Fixed &a) const;
		bool operator!=(const Fixed &a) const;

		Fixed operator+(const Fixed &b);
		Fixed operator-(const Fixed &b);
		Fixed operator*(const Fixed &b);
		Fixed operator/(const Fixed &b);
		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		//MEMBER FUCNTIONS
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int	_fixed_point_nb_value;
		static const int _fractional_bits = 8;
};

#endif