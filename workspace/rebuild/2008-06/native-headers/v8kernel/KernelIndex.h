#pragma once
#include "util/debug.h"

namespace RBX{
	class KernelIndex
	{
		public:
			int kernelIndex;
			KernelIndex::KernelIndex():kernelIndex(-1) {}
			KernelIndex::~KernelIndex() {RBXASSERT(kernelIndex == -1);}
			//virtual void fakeFunc(){};

	};
}