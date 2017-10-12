/*
 * ProgramOptions.h
 *
 *  Created on: 27 wrz 2017
 *      Author: mikey
 */

#ifndef PROGRAMOPTIONS_H_
#define PROGRAMOPTIONS_H_
#include <boost/program_options.hpp>

class ProgramOptions {
	boost::program_options::options_description desc;

public:
	boost::program_options::variables_map vm;
	int platform;
	int device;
	int repeats;
	int size;
	/**
	 * Default Constructor - deleted
	 */
	ProgramOptions()=delete;
	/**
	 * Copy Constructor - deleted
	 * @param argc
	 * @param argv
	 */
	ProgramOptions(const ProgramOptions &val) = delete;
	/**
	 * Constructor based on command line parameters
	 * @param argc number of parameters
	 * @param argv array of parameters
	 */
	ProgramOptions(const int argc, const char *argv[]);
	/**
	 * Destructor
	 */
	~ProgramOptions();
};

#endif /* PROGRAMOPTIONS_H_ */
