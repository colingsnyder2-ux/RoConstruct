// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8tree/enumproperty.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/enumconverter.h"
#include "reflection/property.h"
#include "util/ContentProvider.h"
#include "util/NormalId.h"
#include "v8datamodel/BrickColor.h"
#include "v8tree/Instance.h"

#include <G3D/Color3.h>
#include <G3D/Vector3.h>
#include <string>
#include <vector>

namespace RBX {
namespace Reflection {

// FUNCTION: WEBSERVICE 0x1003ef60
template <>
const Type& Type::singleton<boost::shared_ptr<DescribedBase> >()
{
	static Type type("Object", typeid(boost::shared_ptr<DescribedBase>));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003efd0
template <>
const Type& Type::singleton<boost::shared_ptr<Instance> >()
{
	static Type type("Instance", typeid(boost::shared_ptr<Instance>));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f040
template <>
const Type& Type::singleton<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >()
{
	static Type type("Objects", typeid(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f0b0
template <>
const Type& Type::singleton<int>()
{
	static Type type("int", typeid(int));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f120
template <>
const Type& Type::singleton<bool>()
{
	static Type type("bool", typeid(bool));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f190
template <>
const Type& Type::singleton<float>()
{
	static Type type("float", typeid(float));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f200
template <>
const Type& Type::singleton<double>()
{
	static Type type("double", typeid(double));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f270
template <>
const Type& Type::singleton<ContentId>()
{
	static Type type("Content", typeid(ContentId));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f2e0
template <>
const Type& Type::singleton<std::string>()
{
	static Type type("string", typeid(std::string));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f350
template <>
const Type& Type::singleton<G3D::Vector3>()
{
	static Type type("Vector3", typeid(G3D::Vector3));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f3c0
template <>
const Type& Type::singleton<G3D::Color3>()
{
	static Type type("Color3", typeid(G3D::Color3));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f430
template <>
const Type& Type::singleton<std::vector<Value> >()
{
	static Type type("Table", typeid(std::vector<Value>));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f5c0
template <>
const Type& Type::singleton<BrickColor>()
{
	static Type type("BrickColor", typeid(BrickColor), "int");

	return type;
}

// FUNCTION: WEBSERVICE 0x100421f0
template <>
EnumDesc<NormalId>::EnumDesc() : EnumDescriptor("NormalId", typeid(NormalId))
{
	addPair(NORM_Y, "Top");
	addPair(NORM_Y_NEG, "Bottom");
	addPair(NORM_Z, "Back");
	addPair(NORM_Z_NEG, "Front");
	addPair(NORM_X, "Right");
	addPair(NORM_X_NEG, "Left");
}

} // namespace Reflection
} // namespace RBX
