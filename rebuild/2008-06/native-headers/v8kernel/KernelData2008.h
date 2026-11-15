#pragma once
// 2008-06 native RBX::KernelData (inactive). Declared under a non-colliding name: the original path v8kernel/KernelData.h
// is the donor header reached through the donor v8kernel/Kernel.h by every engine unit (and it includes the donor
// Body.h / Point.h / Connector.h, which cannot be declared next to native-headers/v8kernel/Body2008.h, C2011). A unit
// must not include both this header and the donor v8kernel/KernelData.h or Kernel.h.
// Connector must be complete before this header is included (it is the IndexArray getter owner): the includer defines
// NATIVE_PRIMITIVE_NATIVE_BODY and includes native-headers/v8kernel/Connector2008.h first (its 2008 Body path takes
// Body2008.h / Point2008.h instead of the donor Body.h / Point.h), as native-classes/KernelStep.cpp does.
//
// Every field, size and offset below is read from the 2008-06 binary:
//   size     0x3c: Kernel(IStage*) 005fb650 `push 0x3c; call operator new`, then KernelData() 005fb5f0.
//   ctor     005fb5f0 (out of line): five G3D::Array triples zeroed (data / num / numAllocated) at +0x0, +0xc, +0x18,
//            +0x24 and +0x30.
//   dtor     005fa970 (out of line; ~Kernel 005faca0 calls it before operator delete): the five arrays are destroyed in
//            reverse order (+0x30, +0x24, +0x18, +0xc, +0x0; alignedFree 00507d20, then the triple = 0).
//   bodies   +0x0: bodyKineticEnergy 005faa50 iterates data +0x0 / num +0x4 (Body::kineticEnergy 00614670).
//   leafBodies +0xc (analog name): Array<Body*> (append 005fabc0, resize 005fa770); 005faff0 / 005fb050 index it
//            through Body +0x4 (Body2008.h leafBodyIndex), not a KernelIndex getter.
//   points   +0x18: removePoint 005fb1a0 swap-removes through 005fa610 (`lea eax, [ecx + 4]`: KernelIndex after the
//            vptr) and resizes with Array<Point*>::resize 005fa870.
//   connectors +0x24: insertConnector 005fb160 / removeConnector 005fb1f0 (Connector getKernelIndex 005fa610,
//            Array<Connector*>::append 005fab50 / resize 005fa670).
//   connectors2ndPass +0x30: insertConnector2ndPass 005fad50 / removeConnector2ndPass 005fad80 (same calls).
// The donor KernelData is 0x30 (no leaf body array; points +0xc, connectors +0x18) with an inline destructor.
#include <G3D/Array.h>
#include "util/IndexArray.h"
#include "v8kernel/Body2008.h"
#include "v8kernel/Point2008.h"

namespace RBX
{
	class KernelData
	{
	public:
		KernelData();                                                       // 005fb5f0
		~KernelData();                                                      // 005fa970

		// The donor IndexArray (single G3D::Array, same layout): bodyKineticEnergy 005faa50 reads the element by value
		// (IndexArray::operator[] returns tInstance*); Body::getKernelIndex is inline (removeBody 005fb110).
		IndexArray<Body, &Body::getKernelIndex> bodies;                     // +0x0
		// INFERRED: Array<Body*> (005fabc0 / 005fa770); 005faff0 / 005fb050 maintain Body +0x4 inline.
		G3D::Array<Body*> leafBodies;                                       // +0xc  (analog name)
		// The donor IndexArray: removePoint 005fb1a0 / newPoint 005fb260 index it through the out-of-line Point::
		// getKernelIndex 005fa610 and grow / shrink it with Array<Point*>::append 005fac30 / resize 005fa870.
		IndexArray<Point, &Point::getKernelIndex> points;                   // +0x18
		IndexArray<Connector, &Connector::getKernelIndex> connectors;       // +0x24
		IndexArray<Connector, &Connector::getKernelIndex> connectors2ndPass; // +0x30

		// 005faff0 (`ret 4`): for i in 0..1, Connector::getBody(i) (slot 4); a non-NULL body gets ++[body + 0x8] and,
		// when its root (+0x10) is in the kernel (root kernelIndex +0x0 != -1), it is not the root and its +0x4 index
		// is < 0, is appended to leafBodies with +0x4 = leafBodies.size() (analog name).
		void onConnectorAdded(Connector* c);                                // 005faff0
		// 005fb050 (`ret 4`): for i in 0..1, getBody(i); --[body + 0x8]; when it drops to 0 and +0x4 >= 0 the body is
		// swap-removed from leafBodies and +0x4 = -1 (analog name).
		void onConnectorRemoved(Connector* c);                              // 005fb050
	};
}
