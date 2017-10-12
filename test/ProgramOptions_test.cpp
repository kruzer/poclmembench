/*
 * ProgramOptions_test.cpp
 *
 *  Created on: 27 wrz 2017
 *      Author: mikey
 */

#define BOOST_TEST_MODULE ProgramOptions_Test
#include "ProgramOptions.hpp"
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE( OptionsTest ) {
	char const *argv[]={"poclmembench","-p", "3", "-r","4"};
	ProgramOptions po(sizeof(argv)/sizeof(argv[0]),argv);
	BOOST_CHECK_MESSAGE( po.device == -1 , "device is:" << po.device);
	BOOST_CHECK_MESSAGE( po.platform == 3 , "platform is:" << po.platform);
	BOOST_CHECK_MESSAGE( po.repeats == 4 , "repeats is:" << po.repeats);
	BOOST_CHECK_MESSAGE( po.size == 128 , "size is:" << po.size);
}
