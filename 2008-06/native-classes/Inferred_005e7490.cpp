// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: sub_005e7490 (placeholder name for 005e7490 from the identity tier; body byte-proved by the placeholder lane, includes as the lane resolved them)
#include "util/Name.h"
#include "v8world/Contact2008.h"
#include "v8world/Primitive2008.h"
#include "v8kernel/Body2008.h"

#define NATIVE_PRIMITIVE_NATIVE_BODY




namespace RBX
{
	Primitive* sub_005e7490(Edge* edge)
	{
		Primitive* result = edge->getPrimitive(0);
		Primitive* other = edge->getPrimitive(1);
		if (other && result->getBody()->getParent() != other->getBody())
			result = other;
		return result;
	}
}
