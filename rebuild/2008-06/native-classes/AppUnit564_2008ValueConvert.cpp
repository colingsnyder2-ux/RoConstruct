// 2008-06 native Value::convert<T> numeric specializations of the reflection unit in 00564000..00570000 (inactive).
// Built /Ob1 like the committed SoundValueConvertFloat.cpp (convert<float> 0056ed00, counted there): each one checks
// the held type against the other numeric types in the order the target compares type descriptors, stores the
// converted value, sets the Type singleton and falls through to genericConvert<T> (tail call).
// >>> native-status (generated) -- do not edit >>>
// AppUnit564_2008ValueConvert | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 2706dddf | roc native-status --write
#include "reflection/type.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector3.h"
#include "G3D/Vector2int16.h"
#include "G3D/Color3.h"
#include "G3D/CoordinateFrame.h"
#include "v8datamodel/BrickColor.h"
#include "util/ContentProvider.h"

namespace RBX
{
	namespace Reflection
	{
		// 0056ea60: float (0092bedc, G3D::iRound -> fld/fistp), double (0092bee8), bool (00929644); singleton<int> 0056cbc0
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
				value = (int)(boost::any_cast<bool>(value) != 0);
				_type = &Type::singleton<int>();
			}
			return genericConvert<int>();
		}

		// 0056ebb0: int (0092bed0), float (fcomp against 0.0f), double; singleton<bool> 0056cc30
		template<>
		bool& Value::convert<bool>()
		{
			if (isType<int>())
			{
				value = boost::any_cast<int>(value) != 0;
				_type = &Type::singleton<bool>();
			}
			if (isType<float>())
			{
				value = boost::any_cast<float>(value) != 0.0f;
				_type = &Type::singleton<bool>();
			}
			if (isType<double>())
			{
				value = boost::any_cast<double>(value) != 0.0;
				_type = &Type::singleton<bool>();
			}
			return genericConvert<bool>();
		}

		// 0056ee50: int, bool, float; singleton<double> 0056cd10
		template<>
		double& Value::convert<double>()
		{
			if (isType<int>())
			{
				value = (double)boost::any_cast<int>(value);
				_type = &Type::singleton<double>();
			}
			if (isType<bool>())
			{
				value = (double)(int)(boost::any_cast<bool>(value) != 0);
				_type = &Type::singleton<double>();
			}
			if (isType<float>())
			{
				value = (double)boost::any_cast<float>(value);
				_type = &Type::singleton<double>();
			}
			return genericConvert<double>();
		}
		// 0056efa0..0056efe0: one-instruction forwarders (jmp genericConvert<T> 0056d890 / 0056d9b0 / 0056dae0 /
		// 0056dc00 / 0056dd20)
		template<>
		G3D::Vector3& Value::convert<G3D::Vector3>()
		{
			return genericConvert<G3D::Vector3>();
		}

		template<>
		G3D::CoordinateFrame& Value::convert<G3D::CoordinateFrame>()
		{
			return genericConvert<G3D::CoordinateFrame>();
		}

		template<>
		G3D::Vector2int16& Value::convert<G3D::Vector2int16>()
		{
			return genericConvert<G3D::Vector2int16>();
		}

		template<>
		G3D::Color3& Value::convert<G3D::Color3>()
		{
			return genericConvert<G3D::Color3>();
		}

		template<>
		BrickColor& Value::convert<BrickColor>()
		{
			return genericConvert<BrickColor>();
		}

		// 0056eff0: a held std::string (0092bef8) becomes ContentId(string) (00615440); singleton<ContentId> 0056cd80;
		// then genericConvert<ContentId> 0056de80
		template<>
		ContentId& Value::convert<ContentId>()
		{
			if (isType<std::string>())
			{
				value = ContentId(boost::any_cast<std::string>(value));
				_type = &Type::singleton<ContentId>();
			}
			return genericConvert<ContentId>();
		}
	}
}
