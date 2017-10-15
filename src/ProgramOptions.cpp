#include <iostream>
#include "ProgramOptions.hpp"
#include "Version.h"

namespace po = boost::program_options;

ProgramOptions::ProgramOptions(int argc, const char* argv[]) :
		desc("Options") {

	desc.add_options()("help,h", "Display this help message describing all options");
	desc.add_options()("version,v", "Display the version number");
	desc.add_options()("platform,p", po::value<int>()->default_value(-1), "Select test platform (-1 autodetect)");
	desc.add_options()("device,d", po::value<int>()->default_value(-1), "Select test device (-1 autodetect)");
	desc.add_options()("size,s", po::value<int>()->default_value(128), "Memory block size in MB");
	desc.add_options()("repeats,r", po::value<int>()->default_value(100), "Number of repeated operations");
	try {
		po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
		po::notify(vm);

		if (vm.count("help")) {
			std::cout << "pocmlbench version " << poclmembench_VERSION_MAJOR << "." << poclmembench_VERSION_MINOR << std::endl;
			std::cout << desc;
			exit( EXIT_SUCCESS);
		}

		if (vm.count("version")) {
			std::cout << "pocmlbench version " << poclmembench_VERSION_MAJOR << "." << poclmembench_VERSION_MINOR << std::endl;
			std::cout << "";
			exit( EXIT_SUCCESS);
		}

		platform = vm["platform"].as<int>();
		device = vm["device"].as<int>();
		repeats = vm["repeats"].as<int>();
		size = vm["size"].as<int>();

	} catch (po::error const &err) {
		std::cerr << "problem: " << err.what() << std::endl;
		exit( EXIT_FAILURE);
	}
}

ProgramOptions::~ProgramOptions() {
}

