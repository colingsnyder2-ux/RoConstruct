// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client roc_espclaude_865a2f0d5e3ec9fe.cpp

// Candidate translation unit (score above; library headers required).
#define private public
#define protected public
#include "v8kernel/Kernel.h"
#include "v8kernel/Body.h"
#include "v8kernel/Connector.h"
#include "v8kernel/KernelData.h"
#include "v8kernel/Point.h"
#undef private
#undef protected
#include "decomp.h"
#include <cstddef>

namespace RBX {

// exe KernelData has one more IndexArray before points (points at 0x18)
struct ExKernelData {
	IndexArray<Body, &Body::getKernelIndex> bodies;     // 0x00
	IndexArray<Body, &Body::getKernelIndex> bodies2;    // 0x0c
	IndexArray<Point, &Point::getKernelIndex> points;   // 0x18
};

static inline ExKernelData* exData(KernelData* d) { return reinterpret_cast<ExKernelData*>(d); }

Point* Kernel::newPoint(Body* _body, const Vector3& worldPos)
{
	Point* point = new Point(_body);

	point->setWorldPos(worldPos);

	for (int i = 0; i < exData(kernelData)->points.size(); ++i) {
		Point* other = exData(kernelData)->points[i];

		if (Point::sameBodyAndOffset(point, other)) {
			exData(kernelData)->points[i]->numOwners++;
			delete point;

			return exData(kernelData)->points[i];
		}
	}

	exData(kernelData)->points.fastAppend(point);

	return point;
}

}
