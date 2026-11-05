#include "StdAfx.h"

#include "MolecularModel.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

extern "C" __declspec(dllexport) int TestAtomStruct(AtomStruct atom)

{
	// strangely, including a call to std::cerr causes link errors. 
// std::cerr<<"TestAtomStruct\n";
	printf("testatomstruct.\n");
	return atom.ID + atom.elementNumber;
}
