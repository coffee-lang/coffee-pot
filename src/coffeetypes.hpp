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
#include <utility>

enum CoffeeType {
    Byte, Char, Int, Long, Float, Double, String, Array, Object
};


class CoffeeValue {
private:
    CoffeeType type;
    std::any value;
public:
    ~CoffeeValue() {
        delete &value;
    }

    CoffeeType get_type() {
        return type;
    }

    std::any get_value() {
        return value;
    }
};

class CoffeeVariable {
private:
    CoffeeType type;
    std::string name;
    CoffeeValue value;
public:
    CoffeeVariable(std::string _name, CoffeeType _type, CoffeeValue _value) {
        name = std::move(_name);
        type = _type;
        value = _value;
    }

    ~CoffeeVariable() {
        delete &value;
    }

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

    CoffeeValue get_value() {
        return value;
    }

    bool has_value() {
        return value.get_value().has_value();
    }
};

#endif /* COFFEETYPES_HPP_ */
