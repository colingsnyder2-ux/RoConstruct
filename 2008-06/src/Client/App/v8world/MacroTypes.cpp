#include "reflection/enumconverter.h"
#include "util/SurfaceType.h"

namespace RBX
{
	namespace Reflection
	{
		EnumDesc<SurfaceType>::EnumDesc()
			: EnumDescriptor("SurfaceType", typeid(SurfaceType))
		{
			addPair(NO_SURFACE, "Smooth");
			addPair(GLUE, "Glue");
			addPair(WELD, "Weld");
			addPair(STUDS, "Studs");
			addPair(INLET, "Inlet");
			addLegacyName("Spawn", NO_SURFACE);
			addPair(ROTATE, "Hinge");
			addPair(ROTATE_V, "Motor");
			addPair(ROTATE_P, "SteppingMotor");
			addLegacyName("Bumps", GLUE);
		}

		void dummy()
		{
			EnumDesc<SurfaceType>::singleton().convertToIndex(NO_SURFACE);

			std::string t1;
			SurfaceType t2 = NO_SURFACE;
			EnumDesc<SurfaceType>::singleton().convertToValue(t1, t2);

			const Name& t3 = Name::declare("bruh",-1);
			EnumDesc<SurfaceType>::singleton().convertToValue(t3, t2);

			EnumDesc<SurfaceType>::singleton().convertToString(t2);
		}
	}
}
