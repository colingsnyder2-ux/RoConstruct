#pragma once
#include "v8kernel/Body.h"
#include "v8kernel/Point.h"
#include "v8kernel/Connector.h"
#include "util/IndexArray.h"

namespace RBX {
	class KernelData
	{
		public:
			KernelData::~KernelData()
			{
				RBXASSERT(!points.size());
				RBXASSERT(!bodies.size());
				RBXASSERT(!connectors.size());
				RBXASSERT(!connectors2ndPass.size());
			}
			IndexArray<Body, &Body::getKernelIndex> bodies;
			IndexArray<Point, &Point::getKernelIndex> points;
			IndexArray<Connector, &Connector::getKernelIndex> connectors;
			IndexArray<Connector, &Connector::getKernelIndex> connectors2ndPass;
	};
}
// 2008-06 native header port of rbxgs App/include/v8kernel/KernelData.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
