/*
 * Copyright (c) 2019-present Bowser65 & vinceh121, All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef COFFEETYPES_HPP_
#define COFFEETYPES_HPP_

#include <string>
#include <any>

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
		name = _name;
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
