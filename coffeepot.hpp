/*
 * coffeepot.hpp
 *
 *  Created on: Sep 30, 2019
 *      Author: vinceh121
 */

#ifndef COFFEEPOT_HPP_
#define COFFEEPOT_HPP_

#include <string>

#define COFFEE_POT // Used by implementing programs to detect presence of API
#define COFFEE_POT_VERSION "0.0.1"
#define POT_MAGIC_NUMBER 0xC0FFEE

bool is_file_cup(char *file);
void _vm_info(std::string text);
void _vm_err(std::string text);

class CoffeePot {
private:
	bool started = false;
	bool node = false;
public:
	CoffeePot();
	/**
	 * Returns whether the instance of the VM is running as a node in a network.
	 */
	bool is_node();
	/**
	 * Set this instance of the VM to run as a node in a network
	 */
	void set_as_node();

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
