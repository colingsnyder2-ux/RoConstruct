// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_unit_635f4dfa9410e08b.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#include "reflection/type.h"
#include <g3d/color3.h>
#include <g3d/vector3.h>
#include <boost/shared_ptr.hpp>
#include "v8tree/Instance.h"
#include "v8datamodel/BrickColor.h"
#include "util/NormalId.h"

namespace RBX
{
	namespace Reflection
	{
		template<>
		int& Value::convert<int>()
		{
			if (isType<float>())
			{
				value = G3D::iRound(boost::any_cast<float>(value));
				_type = &Type::singleton<int>();
			}
			if (isType<double>())
			{
				value = G3D::iRound(boost::any_cast<double>(value));
				_type = &Type::singleton<int>();
			}
			if (isType<bool>())
			{
				value = boost::any_cast<bool>(value) ? 1 : 0;
				_type = &Type::singleton<int>();
			}

			return genericConvert<int>();
		}
	}
}
