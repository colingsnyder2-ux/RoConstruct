// from server: 32% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8tree/Instance.cpp

// Candidate translation unit (score above; library headers required).
#include "v8tree/Instance.h"

#include "decomp.h"

#include <algorithm>
#include <cstddef>

namespace RBX {

const char sInstance[] = "Instance";

const Reflection::RefPropDescriptor<Instance, Instance> Instance::propParent(
	"Parent",
	"Data",
	&Instance::getParent,
	&Instance::setParent,
	Reflection::PropertyDescriptor::UI
);

Reflection::SignalDesc<Instance, void(shared_ptr<Instance>)> Instance::event_childAdded("ChildAdded", "child");

Reflection::SignalDesc<Instance, void(shared_ptr<Instance>)> Instance::event_childRemoved("ChildRemoved", "child");

Reflection::SignalDesc<Instance, void(shared_ptr<Instance>)> Instance::event_ancestryChanged(
	"AncestryChanged",
	"child"
);

Reflection::SignalDesc<Instance, void(const Reflection::PropertyDescriptor*)> Instance::event_propertyChanged(
	"Changed",
	"property"
);

ChildAdded::ChildAdded(Instance* child) : child(shared_from(child))
{
}

ChildRemoved::ChildRemoved(Instance* child) : child(shared_from(child))
{
}

// STUB: WEBSERVICE 0x10047af0
void Instance::onChildChanged(Instance* instance, const PropertyChanged& event)
{
	if (parent != NULL) {
		parent->onChildChanged(instance, event);
	}
}

// FUNCTION: WEBSERVICE 0x10047b20
bool Instance::contains(const Instance* child) const
{
	while (child != 0) {
		if (child == this) {
			return true;
		}

		child = child->parent;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x10048340
void Instance::readProperties(const XmlElement* container, IReferenceBinder& binder)
{
	for (XmlElement* child = container->firstChild(); child != NULL; child = child->nextSibling()) {
		readProperty(child, binder);
	}
}

// FUNCTION: WEBSERVICE 0x10048370
void Instance::writeChildren(XmlElement* container)
{
	const std::vector<shared_ptr<Instance> >* kids = children.operator->();

	if (kids != NULL) {
		for (std::vector<shared_ptr<Instance> >::const_iterator it = kids->begin(); it != kids->end(); ++it) {
			XmlElement* child = (*it)->write();

			if (child != NULL) {
				container->addChild(child);
			}
		}
	}
}

// STUB: WEBSERVICE 0x100483f0
Instance* Instance::findFirstChildByName(const std::string& findName) const
{
	STUB(0x100483f0);
	return NULL;
}

// FUNCTION: WEBSERVICE 0x10048fb0
void Instance::signalDescendentAdded(Instance* instance, Instance* beginParent, Instance* oldParent)
{
	for (Instance* walk = beginParent; walk != NULL; walk = walk->parent) {
		if (walk == oldParent) {
			break;
		}

		if (walk->isAncestorOf(oldParent)) {
			break;
		}

		walk->onDescendentAdded(instance);
	}

	boost::shared_ptr<const std::vector<shared_ptr<Instance> > > c = instance->children.read();

	if (c) {
		for (std::vector<shared_ptr<Instance> >::const_iterator it = c->begin(); it != c->end(); ++it) {
			signalDescendentAdded(it->get(), beginParent, oldParent);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100490d0
void Instance::signalDescendentRemoving(
	const shared_ptr<Instance>& instance,
	Instance* beginParent,
	Instance* newParent
)
{
	for (Instance* walk = beginParent; walk != NULL; walk = walk->parent) {
		if (walk == newParent) {
			break;
		}

		if (walk->isAncestorOf(newParent)) {
			break;
		}

		walk->onDescendentRemoving(instance);
	}

	boost::shared_ptr<const std::vector<shared_ptr<Instance> > > c = instance->children.read();

	if (c) {
		for (std::vector<shared_ptr<Instance> >::const_iterator it = c->begin(); it != c->end(); ++it) {
			signalDescendentRemoving(*it, beginParent, newParent);
		}
	}
}

// STUB: WEBSERVICE 0x10049d40
XmlElement* Instance::write()
{
	STUB(0x10049d40);
	return NULL;
}

// STUB: WEBSERVICE 0x1004a010
void Instance::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
{
	STUB(0x1004a010);
}

// STUB: WEBSERVICE 0x1004cdf0
shared_ptr<Instance> Instance::createChild(const Name& className)
{
	STUB(0x1004cdf0);
	return shared_ptr<Instance>();
}

// STUB: WEBSERVICE 0x1004d0b0
Instance::~Instance()
{
}

// STUB: WEBSERVICE 0x1004da80
void Instance::setParent(Instance* newParent)
{
	if (newParent == parent) {
		return;
	}

	shared_ptr<Instance> oldParent = shared_from(parent);
	shared_ptr<Instance> self = shared_from_this();

	if (oldParent) {
		if (!oldParent->contains(newParent)) {
			signalDescendentRemoving(self, oldParent.get(), newParent);
		}

		oldParent->onChildRemoving(this);

		shared_ptr<std::vector<shared_ptr<Instance> > >& children = oldParent->children.write();

		children->erase(std::find(children->begin(), children->end(), self));

		if (children->size() == 0) {
			oldParent->children.reset();
		}

		parent = NULL;

		event_childRemoved.fire(oldParent.get(), self);

		oldParent->Notifier<Instance, ChildRemoved>::raise(this);
		oldParent->onChildRemoved(this);

		if (oldParent->numChildren() == 0) {
			oldParent->onLastChildRemoved();
		}
	}

	if (newParent != NULL) {
		newParent->children.write()->push_back(self);
	}

	parent = newParent;

	if (newParent != NULL) {
		newParent->onChildAdded(this);

		if (!newParent->contains(oldParent.get())) {
			signalDescendentAdded(this, newParent, oldParent.get());
		}

		newParent->Notifier<Instance, ChildAdded>::raise(this);

		event_childAdded.fire(newParent, self);
	}

	onAncestorChanged(AncestorChanged(this, oldParent.get(), newParent));
	raisePropertyChanged(propParent);
}

// STUB: WEBSERVICE 0x1004ddb0
void Instance::onAncestorChanged(const AncestorChanged& event)
{
	STUB(0x1004ddb0);
}

// STUB: WEBSERVICE 0x1004dee0
void Instance::onDescendentAdded(Instance* instance)
{
	STUB(0x1004dee0);
}

// STUB: WEBSERVICE 0x1004df50
void Instance::onDescendentRemoving(const shared_ptr<Instance>& instance)
{
	STUB(0x1004df50);
}

// STUB: WEBSERVICE 0x1004e040
void Instance::setName(const std::string& value)
{
	STUB(0x1004e040);
}

// STUB: WEBSERVICE 0x1004e0f0
void Instance::predelete()
{
	STUB(0x1004e0f0);
}

// STUB: WEBSERVICE 0x1004e5e0
void Instance::readChild(const XmlElement* childElement, IReferenceBinder& binder)
{
	STUB(0x1004e5e0);
}

// STUB: WEBSERVICE 0x1004e6e0
void Instance::readChildren(const XmlElement* element, IReferenceBinder& binder)
{
	if (element != NULL) {
		const XmlElement* item = element->findFirstChildByTag(tag_Item);

		while (item != NULL) {
			readChild(item, binder);
			item = element->findNextChildWithSameTag(item);
		}
	}
}

// FUNCTION: WEBSERVICE 0x1004e7b0
void Instance::predelete(Instance* instance)
{
	instance->predelete();
}

// STUB: WEBSERVICE 0x1004eb10
Instance::Instance() : parent(0), archivable(true)
{
}

// STUB: WEBSERVICE 0x1004ec70
Instance::Instance(const char* name) : name(name), parent(0), archivable(true)
{
	STUB(0x1004ec70);
}

} // namespace RBX
