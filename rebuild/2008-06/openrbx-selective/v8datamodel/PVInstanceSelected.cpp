#include "v8datamodel/PVInstance.h"

#include "rbxgraphics/Adorn.h"
#include "reflection/property.h"
#include "v8datamodel/UserController.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/XmlElement.h"

namespace RBX {
// PORT: donor relied on G3D/boost type imports.
using G3D::CoordinateFrame;
using boost::shared_ptr;

// PORT: selective unit; other definitions remain in the 2008 object.

G3D::ReferenceCountedPointer<Controller> PVInstance::computeTopPVController() const
{
	if (!isTopLevelPVInstance()) {
		G3D::ReferenceCountedPointer<Controller> parentController =
			static_cast<const PVInstance*>(getParent())->TopPVController;

		if (parentController.notNull() && parentController->getControllerType() != Controller::NO_CONTROLLER) {
			if (!parentController->isUserController()) {
				// PORT: pointer() and getPointer() both return m_pointer in the 2008 header.
				return parentController.pointer();
			}
		}
	}

	ControllerService* service = ServiceProvider::create<ControllerService>(this);
	return service ? service->getController(getControllerType(), this) : G3D::ReferenceCountedPointer<Controller>();
}

} // namespace RBX
