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