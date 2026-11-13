#include "reflection/enumconverter.h"
#include "reflection/object.h"
#include "reflection/property.h"
#include "v8xml/XmlElement.h"

namespace RBX {
namespace Reflection {

// PORT: selective unit; remaining functions use the 2008 object.

EnumDescriptor::~EnumDescriptor()
{
	allEnums().erase(std::find(allEnums().begin(), allEnums().end(), this));
}

} } // namespace RBX::Reflection
