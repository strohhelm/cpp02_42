/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:37:31 by pstrohal          #+#    #+#             */
/*   Updated: 2024/11/25 12:23:01 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#define INTMIN -2147483648
#define INTMAX  2147483647
#define INTMINF -2147483648.0f
#define INTMAXF  2147483647.0f

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const int in);
		Fixed(const float in);
		Fixed(const Fixed &Orig);
		Fixed& operator=(const Fixed &Orig);
		friend std::ostream& operator<<(std::ostream& os, const Fixed &Orig);
	
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
	private:
		int	_fixed_point_nb_value;
		static const int _fractional_bits = 8;
		
	
};

#endif