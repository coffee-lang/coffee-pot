/*
 * CoffeePot, the official VM for the Coffee programming language.
 * Copyright (C) 2019 Coffee Developers
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * *******************************
 * coffeetypes.hpp
 *
 *  Created on: Oct 11, 2019
 *      Author: vinceh121
 */

#ifndef COFFEETYPES_HPP_
#define COFFEETYPES_HPP_

#include <string>
#include <any>

enum CoffeeType {
	Byte, Char, Int, Long, Float, Double, String, Array, Object
};

template<class T>
class CoffeeValue {
private:
	CoffeeType type;
	std::any value;

public:
	CoffeeType get_type() {
		return type;
	}

	T as(); //TODO proper templating

};

class CoffeeVariable {
private:
	CoffeeType type;
	std::string name;
public:
	/**
	 * Returns the variable's declared type
	 */
	CoffeeType get_type() {
		return type;
	}
	/**
	 * Returns the variable's name
	 */
	std::string get_name() {
		return name;
	}
};

#endif /* COFFEETYPES_HPP_ */
