/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:37:31 by pstrohal          #+#    #+#             */
/*   Updated: 2024/11/22 12:11:11 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
// #include <string

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &Orig);
		Fixed& operator=(const Fixed &Orig);
		~Fixed();
	
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int	fixed_point_nb_value;
		static const int fractional_bits = 8;
		
	
};

#endif