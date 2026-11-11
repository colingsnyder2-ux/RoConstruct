// Rebuild glue: Instance core members and event copy constructors rbxgs declares but never defines.
// Behavioural reconstructions, not byte-verified.
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include "v8datamodel/PartInstance.h"
#include "v8xml/XmlElement.h"
#include "v8xml/SerializerV2.h"
#include <memory>

namespace RBX
{
	// out of line in the 2008 Instance (the guid lives in the GuidItem<Instance> base, which has no
	// onGuidChanged hook); bodies as rbxgs's inline ones
	const Guid& Instance::getGuid() const
	{
		return guid;
	}

	void Instance::assignGuid(const Guid::Data& id)
	{
		guid.assign(id);
	}

	// events are copied when signals are fired by value
	ChildAdded::ChildAdded(const ChildAdded& other) : child(other.child) {}
	ChildRemoved::ChildRemoved(const ChildRemoved& other) : child(other.child) {}
	PropertyChanged::PropertyChanged(const PropertyChanged& other) : property(other.property) {}
	// before deletion an instance releases its children, so none keeps a dangling parent. Its own count is
	// already zero, so setParent (which takes shared_from_this of the old parent) cannot be used: children are
	// detached directly, without removal notifications, and each runs predelete when its last reference goes.

	// one XML element per property the descriptor allows streaming

	// a deep copy through the XML serializer, as Roblox's Clone(); non-archivable instances do not clone
}
