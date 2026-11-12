#include "v8datamodel/Accoutrement.h"

#include "humanoid/Humanoid.h"
#include "network/Players.h"
#include "reflection/property.h"
#include "tool/DragUtilities.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/XmlElement.h"

#include <boost/bind.hpp>

namespace RBX {

// PORT: selective unit; remaining functions use the 2008 object.

void Accoutrement::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
{
	const Name* name = NULL;
	const XmlAttribute* nameAttribute = propertyElement->findAttribute(name_name);

	if (nameAttribute && nameAttribute->getValue(name) && name->name == "BackendAccoutrementState") {
		return;
	}

	Instance::readProperty(propertyElement, binder);
}

} // namespace RBX
