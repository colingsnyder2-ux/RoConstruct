// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_3b800b142fb251e5.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8kernel/Body.h", "roc_unit_9ebf98d898911199.cpp")
#pragma include_alias("v8world/Clump.h", "roc_unit_9da8b0a292a9525e.cpp")
#pragma include_alias("v8world/World.h", "roc_unit_b0ca8f08e1d06783.cpp")
#include "v8world/Primitive.h"
#include "v8world/Assembly.h"
#include "v8world/World.h"
namespace RBX {
Assembly* Primitive::getAssembly() const { Clump* c = *reinterpret_cast<Clump* const*>(reinterpret_cast<const char*>(this) + 0x5c); return c ? c->getAssembly() : NULL; }
Primitive* Assembly::getMainPrimitive() const { return (*reinterpret_cast<Clump* const*>(reinterpret_cast<const char*>(this) + 0x24))->getRootPrimitive(); }
void Primitive::setCoordinateFrame(const G3D::CoordinateFrame& value)
	{
		if (value != (*reinterpret_cast<Body* const*>(reinterpret_cast<const char*>(this) + 0xa0))->getPV().position)
		{
			Assembly* assembly = getAssembly();
			if (!assembly)
			{
				(*reinterpret_cast<Body* const*>(reinterpret_cast<const char*>(this) + 0xa0))->setCoordinateFrame(value);
				(*reinterpret_cast<IMoving* const*>(reinterpret_cast<const char*>(this) + 0xa4))->notifyMoved();
				if ((*reinterpret_cast<World* const*>(reinterpret_cast<const char*>(this) + 0x58)))
					(*reinterpret_cast<World* const*>(reinterpret_cast<const char*>(this) + 0x58))->onPrimitiveExtentsChanged(this);
			}
			else
			{
				RBXASSERT((*reinterpret_cast<World* const*>(reinterpret_cast<const char*>(this) + 0x58)));
				if (assembly->getMainPrimitive() == this)
				{
					(*reinterpret_cast<Body* const*>(reinterpret_cast<const char*>(this) + 0xa0))->setCoordinateFrame(value);
					assembly->notifyMoved();
					(*reinterpret_cast<World* const*>(reinterpret_cast<const char*>(this) + 0x58))->onAssemblyExtentsChanged(assembly);
					if (!*reinterpret_cast<const bool*>(reinterpret_cast<const char*>(this) + 0xa8) && !*reinterpret_cast<const bool*>(reinterpret_cast<const char*>(this) + 0xa9) && !*reinterpret_cast<const bool*>(reinterpret_cast<const char*>(this) + 0xaa))
						(*reinterpret_cast<World* const*>(reinterpret_cast<const char*>(this) + 0x58))->ticklePrimitive(this, false);
				}
			}
		}
	}

	
}
