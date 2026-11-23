// =============================================================================
// g3dmath.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/g3d/g3dcpp/g3dmath.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#line 1 ".\\G3Dcpp\\g3dmath.cpp"
/**
 @file g3dmath.cpp

 @author Morgan McGuire, graphics3d.com

 @created 2001-06-02
 @edited  2004-02-24
 */

#include "G3D/g3dmath.h"
#include <stdlib.h>

namespace G3D
{

float gaussRandom(float mean, float stdev) {

	// Using Box-Mueller method from http://www.taygeta.com/random/gaussian.html
	// Modified to specify standard deviation and mean of distribution
	float w, x1, x2;

	// Loop until w is less than 1 so that log(w) is negative
	do {
		x1 = uniformRandom(-1.0, 1.0);
		x2 = uniformRandom(-1.0, 1.0);

		w = float(square(x1) + square(x2));
	} while (w > 1.0f);

	// Transform to gassian distribution
	// Multiply by sigma (stdev ^ 2) and add mean.
	return x2 * (float)square(stdev) * sqrtf((-2.0f * logf(w) ) / w) + mean;
}

int highestBit(uint32 x) {
	// Binary search.
	int base = 0;

	if (x & 0xffff0000)	{
		base = 16;
		x >>= 16;
	}
	if (x & 0x0000ff00) {
		base += 8;
		x >>= 8;
	}
	if (x & 0x000000f0) {
		base += 4;
		x >>= 4;
	}

	static const int lut[] = {-1,0,1,1,2,2,2,2,3,3,3,3,3,3,3,3};
	return base + lut[x];
}

int iRandom(int low, int high) {
	int r = iFloor(low + (high - low + 1) * (double)rand() / RAND_MAX);

	// There is a *very small* chance of generating
	// a number larger than high.
	if (r > high) {
		return high;
	} else {
		return r;
	}
}

double G3D_DEPRECATED random(double low, double high) {
	return low + (high - low) * rand() / (double)RAND_MAX;
}

}
