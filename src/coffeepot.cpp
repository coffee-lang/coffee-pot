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
 */

#include "coffeepot.hpp"

#include <stdexcept>
#include <cstdarg>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream> //XXX: eclipse removes this one at optimization

bool quiet = false;

bool is_file_powdder(char *file) {
    std::ifstream in(file);
    int fin = ((in.get() & 0xFF) << 16) | ((in.get() & 0xFF) << 8) | in.get();
    return fin == POWDDER_MAGIC_NUMBER;
}

void _vm_info(const std::string &text) {
    if (quiet) return;
    std::cout << text << std::endl;
}

void _vm_err(const std::string &text) {
    if (quiet) return;
    std::cerr << text << std::endl;
}

CoffeePot::CoffeePot() {

}

bool CoffeePot::is_started() {
    return started;
}

void CoffeePot::start(char *inFile) {
    if (started) {
        throw std::runtime_error("Tried to start a VM that is already started");
    }
    started = true;

}

void print_license() {
    std::cout
            << "CoffeePot, the official VM for the Coffee programming language. \n\
    Copyright (C) 2019 Coffee Developers \n\
 \n\
    This program is free software: you can redistribute it and/or modify \n\
    it under the terms of the GNU Affero General Public License as \n\
    published by the Free Software Foundation, either version 3 of the \n\
    License, or (at your option) any later version. \n\
 \n\
    This program is distributed in the hope that it will be useful, \n\
    but WITHOUT ANY WARRANTY; without even the implied warranty of \n\
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the \n\
    GNU Affero General Public License for more details. \n\
 \n\
    You should have received a copy of the GNU Affero General Public License \n\
    along with this program.  If not, see <https://www.gnu.org/licenses/>."
            << std::endl;
}

void print_help() {
    std::cout << "CoffePot VM v" << COFFEE_POT_VERSION << std::endl;
    std::cout << "coffeepot [options] CUP_FILE" << std::endl;
    std::cout << "-- General Options" << std::endl;
    std::cout << "\t-q, --quiet\tPrevents the VM from printing to stdout and stderr. Program will still output."
              << std::endl;
    std::cout << "-- About CoffeePot" << std::endl;
    std::cout << "\t-h, --help\tShows this help page." << std::endl;
    std::cout << "\t-v, --version\tPrints version information and exits." << std::endl;
    std::cout << "\t--license\tPrints the program's license and exists." << std::endl;
    std::exit(0);
}

void unknown_arg(char *arg) {
    _vm_err("Unknown argument \"" + std::string(arg) + "\"");
    std::exit(-1);
}

int main(int argc, char **argv) {
    // std::cout << __cplusplus << std::endl;
    if (argc <= 1)
        print_help();
    CoffeePot *cof = new CoffeePot();

    if (argc > 2) {
        for (int i = 1; i < argc - 1; i++) { // Do not read the last argument here as it is the .cup file
            if (strcmp("-h", argv[i]) == 0 || strcmp("--help", argv[i]) == 0) {
                print_help();
            } else if (strcmp("--version", argv[i]) == 0 || strcmp("-v", argv[i]) == 0) {
                std::cout << "CoffePot VM v" << COFFEE_POT_VERSION << std::endl;
                std::exit(0);
            } else if (strcmp("--license", argv[i]) == 0) {
                print_license();
                std::exit(0);
            } else if (strcmp("--quiet", argv[i]) == 0 || strcmp("-q", argv[i]) == 0) {
                quiet = true;
            } else {
                unknown_arg(argv[i]);
            }
        }
    }

    cof->start(argv[argc - 1]);
    return 0;
}
