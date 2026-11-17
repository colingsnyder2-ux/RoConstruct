// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

#include "reflection/type.h"
#include "axis-vector-negation/G3D/Vector3.h"

namespace RBX {
namespace Reflection {

template<>
G3D::Vector3 Value::get<G3D::Vector3>() const
{
	if (isType<G3D::Vector3>())
		return cast<G3D::Vector3>();

	Value converted(*this);
	return converted.convert<G3D::Vector3>();
}

}
}
