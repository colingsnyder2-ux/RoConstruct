#pragma once

#include "v8world/Primitive.h"
#include "v8world/Joint.h"

namespace RBX
{
	class JointBuilder
	{
	public:
		static Joint* canJoin(Primitive* p0, Primitive* p1);
	};
}
// 2008-06 native header port of rbxgs App/include/v8world/JointBuilder.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
