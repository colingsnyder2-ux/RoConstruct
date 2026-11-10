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
	ServiceAdded::ServiceAdded(const ServiceAdded& other) : service(other.service) {}
	ServiceRemoving::ServiceRemoving(const ServiceRemoving& other) : service(other.service) {}
	PropertyChanged::PropertyChanged(const PropertyChanged& other) : property(other.property) {}
	CanAggregateChanged::CanAggregateChanged(const CanAggregateChanged& other) : canClump(other.canClump) {}

	// before deletion an instance releases its children, so none keeps a dangling parent. Its own count is
	// already zero, so setParent (which takes shared_from_this of the old parent) cannot be used: children are
	// detached directly, without removal notifications, and each runs predelete when its last reference goes.
	void Instance::predelete()
	{
		boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > snapshot = children.read();
		if (snapshot)
		{
			for (size_t i = 0; i < snapshot->size(); ++i)
				(*snapshot)[i]->parent = NULL;
			children.reset();
		}
	}

	// one XML element per property the descriptor allows streaming
	void Instance::writeProperties(XmlElement* container) const
	{
		typedef Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor> Properties;
		const Properties& properties = getDescriptor();
		for (Properties::CollectionType::const_iterator iter = properties.descriptors_begin(); iter != properties.descriptors_end(); ++iter)
		{
			if (XmlElement* element = (*iter)->write(this, false))
				container->addChild(element);
		}
	}

	// a deep copy through the XML serializer, as Roblox's Clone(); non-archivable instances do not clone
	boost::shared_ptr<Instance> Instance::clone()
	{
		if (!archivable)
			return boost::shared_ptr<Instance>();
		std::auto_ptr<XmlElement> root(toNewXmlRoot(this));
		std::vector<boost::shared_ptr<Instance> > items;
		SerializerV2().loadInstances(root.get(), items);
		return items.empty() ? boost::shared_ptr<Instance>() : items[0];
	}
}
