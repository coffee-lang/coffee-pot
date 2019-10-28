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
 * coffeepot.hpp
 *
 *  Created on: Sep 30, 2019
 *      Author: vinceh121
 */

#ifndef COFFEEPOT_HPP_
#define COFFEEPOT_HPP_

#include <string>
#include <coffee/coffeetypes.hpp>

#define COFFEE_POT // Used by implementing programs to detect presence of API
#define COFFEE_POT_VERSION "0.0.1"
#define POWDDER_MAGIC_NUMBER 0xC0FFEE

bool is_file_cup(char *file);

void _vm_info(const std::string &text);

void _vm_err(const std::string &text);

class CoffeePot {
private:
    bool started = false;
public:
    CoffeePot();

    /**
     * Starts this instance of the VM.
     * This method cannot be called twice and throws an exception when it is.
     */
    void start(char *fileIn);

    /**
     * Returns whether the CoffeePot::start() method has been called.
     */
    bool is_started();

};

#endif /* COFFEEPOT_HPP_ */
