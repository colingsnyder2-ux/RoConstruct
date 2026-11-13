#include "v8datamodel/Tool.h"

#include "humanoid/Humanoid.h"
#include "network/Player.h"
#include "network/Players.h"
#include "reflection/property.h"
#include "reflection/signal.h"
#include "tool/DragUtilities.h"
#include "util/Name.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Mouse.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ToolMouseCommand.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/XmlElement.h"

#include <G3D/debugAssert.h>
#include <boost/bind.hpp>

namespace RBX {

// PORT: selective unit; remaining functions use the 2008 object.

void Tool::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
{
	const Name* name = NULL;
	const XmlAttribute* nameAttribute = propertyElement->findAttribute(name_name);

	if (nameAttribute && nameAttribute->getValue(name)) {
		if (name->name == "BackendToolState") {
			return;
		}

		if (name->name == "ActivationState") {
			return;
		}
	}

	Instance::readProperty(propertyElement, binder);
}

} // namespace RBX
