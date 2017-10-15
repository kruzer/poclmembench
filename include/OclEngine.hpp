#ifndef OCLENGINE_H_
#define OCLENGINE_H_
#include <boost/program_options.hpp>
#define CL_HPP_TARGET_OPENCL_VERSION 120
#define CL_HPP_MINIMUM_OPENCL_VERSION 120
#include <ostream>
#include "cl2.hpp"

class OclEngine {
	cl::Platform platform;
	cl::Device device;
	cl::Context context;
	std::vector<cl::Buffer> buffers;

public:
	/**
	 * Default constructor
	 */
	OclEngine();
	OclEngine(const int platform, const int device);

	/**
	 * Select chosen platform and device
	 * @param platform - this is platform (-1) means get default
	 * @param device - this is device (-1) means get default (GPU)
	 * @return
	 */
	bool select(const int platform, const int device);

	/**
	 * get readable info about detected platforms an devices
	 * @return string containing gathered info
	 */
	void clinfo(std::ostream &os);

	cl::Program CreateProgram();
	int RunBench1(const std::string &function, const int size, const int repeats);

	size_t AllocBuffers(const int chunkSize);

	/**
	 * Destructor
	 */
	virtual ~OclEngine();
};

#endif /* OCLENGINE_H_ */
