// from server: 46% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8tree/Instance.cpp

// Candidate translation unit (score above; library headers required).
#include "v8tree/Instance.h"

#include "decomp.h"
#include "v8xml/SerializerV2.h"

#include <algorithm>
#include <boost/bind.hpp>
#include <boost/scoped_ptr.hpp>
#include <cstddef>

namespace RBX {

const char sInstance[] = "Instance";

Reflection::BoundProp<bool, 1> Instance::propArchivable("archivable", "Behavior", &Instance::archivable);

static Reflection::BoundFuncDesc<Instance, boost::shared_ptr<Instance>(std::string, bool), 2> findFirstChild(
	&Instance::findFirstChildByName2,
	"FindFirstChild",
	"name",
	"recursive",
	false,
	Reflection::FunctionDescriptor::AnyCaller
);

static Reflection::BoundFuncDesc<Instance, boost::shared_ptr<Instance>(), 0> func_clone(
	&Instance::clone, "Clone", Reflection::FunctionDescriptor::AnyCaller
);

static Reflection::BoundFuncDesc<Instance, void(), 0> func_Remove(
	&Instance::remove, "Remove", Reflection::FunctionDescriptor::AnyCaller
);

static Reflection::BoundFuncDesc<Instance, boost::shared_ptr<const std::vector<shared_ptr<Instance> > >(), 0>
	func_childrenOld(&Instance::getChildren2, "children", Reflection::FunctionDescriptor::AnyCaller);
static Reflection::BoundFuncDesc<Instance, boost::shared_ptr<const std::vector<shared_ptr<Instance> > >(), 0>
	func_children(&Instance::getChildren2, "GetChildren", Reflection::FunctionDescriptor::AnyCaller);
static Reflection::BoundFuncDesc<Instance, bool(shared_ptr<Instance>), 1> func_isDescendentOf(
	&Instance::isDescendentOf2, "IsDescendentOf", "ancestor", Reflection::FunctionDescriptor::AnyCaller
);

static Reflection::BoundFuncDesc<Instance, bool(shared_ptr<Instance>), 1> func_isAncestorOf(
	&Instance::isAncestorOf2, "IsAncestorOf", "descendent", Reflection::FunctionDescriptor::AnyCaller
);

static const Reflection::PropDescriptor<Instance, std::string> prop_className(
	"className", "Data", &Instance::getClassNameStr, NULL, Reflection::PropertyDescriptor::UI
);

const Reflection::PropDescriptor<Instance, std::string> Instance::desc_Name(
	"Name", "Data", &Instance::getName, &Instance::setName, Reflection::PropertyDescriptor::STANDARD
);

const Reflection::RefPropDescriptor<Instance, Instance> Instance::propParent(
	"Parent", "Data", &Instance::getParent, &Instance::setParent, Reflection::PropertyDescriptor::UI
);

Reflection::SignalDesc<Instance, void(shared_ptr<Instance>)> Instance::event_childAdded("ChildAdded", "child");

Reflection::SignalDesc<Instance, void(shared_ptr<Instance>)> Instance::event_childRemoved("ChildRemoved", "child");

Reflection::SignalDesc<Instance, void(shared_ptr<Instance>)> Instance::event_descendentAdded(
	"DescendentAdded", "descendent"
);

Reflection::SignalDesc<Instance, void(shared_ptr<Instance>)> Instance::event_descendentRemoving(
	"DescendentRemoving", "descendent"
);

Reflection::SignalDesc<Instance, void(shared_ptr<Instance>)> Instance::event_ancestryChanged(
	"AncestryChanged", "child"
);

Reflection::SignalDesc<Instance, void(const Reflection::PropertyDescriptor*)> Instance::event_propertyChanged(
	"Changed", "property"
);

static const Name& nameName = Name::declare("Name", 3000);
static const Name& nameParent = Name::declare("Parent", 3001);

ChildAdded::ChildAdded(Instance* child) : child(shared_from(child))
{
}

ChildAdded::ChildAdded(const ChildAdded& other) : child(other.child)
{
}

ChildRemoved::ChildRemoved(Instance* child) : child(shared_from(child))
{
}

ChildRemoved::ChildRemoved(const ChildRemoved& other) : child(other.child)
{
}

// FUNCTION: WEBSERVICE 0x10047af0
// FUNCTION: ROBLOX 0x00576310
void Instance::onChildChanged(Instance* instance, const PropertyChanged& event)
{
	if (getParent() != NULL) {
		getParent()->onChildChanged(instance, event);
	}
}

// FUNCTION: WEBSERVICE 0x10047b20
// FUNCTION: ROBLOX 0x00576340
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
// FUNCTION: ROBLOX 0x00576740
void Instance::readProperties(const XmlElement* container, IReferenceBinder& binder)
{
	for (XmlElement* child = container->firstChild(); child != NULL; child = child->nextSibling()) {
		readProperty(child, binder);
	}
}

// FUNCTION: WEBSERVICE 0x10048370
// FUNCTION: ROBLOX 0x00576770
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

// FUNCTION: WEBSERVICE 0x100483f0
// FUNCTION: ROBLOX 0x005767f0
Instance* Instance::findFirstChildByName(const std::string& findName) const
{
	const std::vector<shared_ptr<Instance> >* c = children.operator->();
	if (!c) {
		return NULL;
	}

	for (unsigned int i = 0; i < c->size(); ++i) {
		if ((*c)[i]->getName() == findName) {
			return (*c)[i].get();
		}
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x10048f30
// FUNCTION: ROBLOX 0x005770a0
Instance* Instance::findFirstChildByNameRecursive(const std::string& findName) const
{
	Instance* result = findFirstChildByName(findName);
	if (result) {
		return result;
	}

	const std::vector<shared_ptr<Instance> >* c = children.operator->();
	if (!c) {
		return NULL;
	}

	for (unsigned int i = 0; i < c->size(); ++i) {
		result = (*c)[i]->findFirstChildByNameRecursive(findName);
		if (result) {
			return result;
		}
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x10048fb0
// FUNCTION: ROBLOX 0x00577120
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
// FUNCTION: ROBLOX 0x00577240
void Instance::signalDescendentRemoving(
	const shared_ptr<Instance>& instance, Instance* beginParent, Instance* newParent
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

// FUNCTION: WEBSERVICE 0x10049b30
// FUNCTION: ROBLOX 0x005777d0
boost::shared_ptr<Instance> Instance::findFirstChildByName2(std::string findName, bool recursive)
{
	return recursive ? shared_from(findFirstChildByNameRecursive(findName))
					 : shared_from(findFirstChildByName(findName));
}

// FUNCTION: ROBLOX 0x00577920
XmlElement* Instance::writeDelete()
{
	XmlElement* element = new XmlElement(name_DeleteItem);
	element->addAttribute(name_referent, InstanceHandle(this));
	return element;
}

// FUNCTION: WEBSERVICE 0x10049c80
// FUNCTION: ROBLOX 0x00577980
void Instance::writeProperties(XmlElement* container) const
{
	Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor>::ConstIterator iter = properties_begin();
	while (iter != properties_end()) {
		const Reflection::PropertyDescriptor& descriptor = iter.getDescriptor();

		XmlElement* child = descriptor.write(this, false);
		if (child) {
			container->addChild(child);
		}

		++iter;
	}
}

// FUNCTION: WEBSERVICE 0x10049d40
// FUNCTION: ROBLOX 0x00577a40
XmlElement* Instance::write()
{
	if (!archivable || getClassName() == Name::getNullName()) {
		return new XmlElement(tag_External, InstanceHandle(this));
	}

	XmlElement* element = new XmlElement(tag_Item);

	element->addAttribute(tag_class, &getClassName());

	element->addAttribute(name_referent, InstanceHandle(this));

	writeProperties(element->addChild(tag_Properties));

	writeChildren(element);

	return element;
}

// FUNCTION: WEBSERVICE 0x10049e80
// FUNCTION: ROBLOX 0x00577b80
int Instance::findChildIndex(const Instance* instance) const
{
	const std::vector<shared_ptr<Instance> >& c = *children;
	std::vector<shared_ptr<Instance> >::const_iterator iter =
		std::find(c.begin(), c.end(), instance->shared_from_this());
	return iter - c.begin();
}

// FUNCTION: WEBSERVICE 0x1004a010
// FUNCTION: ROBLOX 0x00577c40
void Instance::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
{
	const Name* name = NULL;
	if (propertyElement->findAttributeValue(name_name, name)) {
		Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor>::Iterator iter = findProperty(*name);
		if (iter != properties_end()) {
			(*iter).read(propertyElement, binder);
		}
	}
}

// FUNCTION: WEBSERVICE 0x1004a0e0
// FUNCTION: ROBLOX 0x00577d10
void Instance::onAddListener(Listener<Instance, ChildAdded>* listener) const
{
	if (children) {
		boost::shared_ptr<const std::vector<shared_ptr<Instance> > > c = children.read();
		std::vector<shared_ptr<Instance> >::const_iterator end = c->end();
		for (std::vector<shared_ptr<Instance> >::const_iterator iter = c->begin(); iter != end; ++iter) {
			Notifier<Instance, ChildAdded>::raise(ChildAdded(iter->get()), listener);
		}
	}
}

// SIZE 0x8
class RaiseDescendentAdded2
{
	const Instance* const notifier;                      // 0x00
	Listener<Instance, DescendentAdded>* const listener; // 0x04

public:
	RaiseDescendentAdded2(const Instance* notifier, Listener<Instance, DescendentAdded>* listener)
		: notifier(notifier), listener(listener)
	{
	}

	void operator()(Instance* child)
	{
		notifier->Notifier<Instance, DescendentAdded>::raise(DescendentAdded(child, child->getParent()), listener);
		child->for_eachChild(*this);
	}
};

// FUNCTION: WEBSERVICE 0x1004a470
// FUNCTION: ROBLOX 0x00577fe0
void Instance::onAddListener(Listener<Instance, DescendentAdded>* listener) const
{
	for_eachChild(RaiseDescendentAdded2(this, listener));
}

// FUNCTION: WEBSERVICE 0x1004a9c0
// FUNCTION: ROBLOX 0x00578000
boost::shared_ptr<Instance> Instance::fromXmlRoot(XmlElement* xmlRoot)
{
	Serializer serializer;

	SerializerV2::isolateHandles(xmlRoot);
	std::vector<shared_ptr<Instance> > newInstances;
	serializer.loadInstances(xmlRoot, newInstances);
	if (newInstances.size() == 0) {
		return shared_ptr<Instance>();
	}

	return newInstances.front();
}

inline XmlElement* Instance::toNewXmlRoot(Instance* instance)
{
	XmlElement* root = SerializerV2::newRootElement();
	root->addChild(instance->write());
	return root;
}

// FUNCTION: WEBSERVICE 0x1004ab00
// FUNCTION: ROBLOX 0x00578140
boost::shared_ptr<Instance> Instance::clone()
{
	boost::scoped_ptr<XmlElement> root(toNewXmlRoot(this));
	return fromXmlRoot(root.get());
}

// FUNCTION: WEBSERVICE 0x1004cdf0
// FUNCTION: ROBLOX 0x005794d0
shared_ptr<Instance> Instance::createChild(const Name& className)
{
	return Instance::create(className);
}

// FUNCTION: WEBSERVICE 0x1004d0b0
// FUNCTION: ROBLOX 0x00579580
Instance::~Instance()
{
}

// FUNCTION: WEBSERVICE 0x1004da80
// FUNCTION: ROBLOX 0x005799c0
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

// FUNCTION: WEBSERVICE 0x1004ddb0
// FUNCTION: ROBLOX 0x00579cf0
void Instance::onAncestorChanged(const AncestorChanged& event)
{
	if (children) {
		boost::shared_ptr<const std::vector<shared_ptr<Instance> > > c = children.read();
		for (std::vector<shared_ptr<Instance> >::const_iterator it = c->begin(); it != c->end(); ++it) {
			(*it)->onAncestorChanged(event);
		}
	}

	event_ancestryChanged.fire(this, shared_from(event.child));

	Notifier<Instance, AncestorChanged>::raise(event);
}

// FUNCTION: WEBSERVICE 0x1004dee0
// FUNCTION: ROBLOX 0x00579e20
void Instance::onDescendentAdded(Instance* instance)
{
	if (Notifier<Instance, DescendentAdded>::hasListeners()) {
		Notifier<Instance, DescendentAdded>::raise(DescendentAdded(instance, instance->getParent()));
	}
	event_descendentAdded.fire(this, shared_from(instance));
}

// FUNCTION: WEBSERVICE 0x1004df50
// FUNCTION: ROBLOX 0x00579e90
void Instance::onDescendentRemoving(const shared_ptr<Instance>& instance)
{
	event_descendentRemoving.fire(this, instance);
	if (Notifier<Instance, DescendentRemoving>::hasListeners()) {
		Notifier<Instance, DescendentRemoving>::raise(DescendentRemoving(instance, shared_from(instance->getParent())));
	}
}

// FUNCTION: WEBSERVICE 0x1004e040
// FUNCTION: ROBLOX 0x00579f80
void Instance::setName(const std::string& value)
{
	if (name != value) {
		name = value;
		raisePropertyChanged(desc_Name);
	}
}

// FUNCTION: WEBSERVICE 0x1004e080
// FUNCTION: ROBLOX 0x00579fc0
void Instance::removeAllChildren()
{
	while (children) {
		children->back()->setParent(NULL);
	}
}

// FUNCTION: WEBSERVICE 0x1004e0f0
// FUNCTION: ROBLOX 0x0057a030
void Instance::predelete()
{
	while (children) {
		shared_ptr<Instance> child;

		{
			shared_ptr<std::vector<shared_ptr<Instance> > > c = children.write();
			child = c->back();

			signalDescendentRemoving(child, this, NULL);
			onChildRemoving(child.get());
			child->parent = NULL;

			c->pop_back();

			if (c->size() == 0) {
				children.reset();
			}
		}

		event_childRemoved.fire(this, child);
		Notifier<Instance, ChildRemoved>::raise(child.get());

		child->onAncestorChanged(AncestorChanged(child.get(), this, NULL));
		child->raisePropertyChanged(propParent);
	}
}

// FUNCTION: WEBSERVICE 0x1004e4f0
// FUNCTION: ROBLOX 0x005663a0
void Instance::remove()
{
	boost::shared_ptr<const std::vector<shared_ptr<Instance> > > c = children.read();
	setParent(NULL);
	if (c) {
		std::for_each(c->begin(), c->end(), boost::bind(&Instance::remove, _1));
	}
}

// FUNCTION: ROBLOX 0x0057a2f0
void Instance::promoteChildren()
{
	while (numChildren()) {
		getChild(0)->setParent(getParent());
	}
}

// FUNCTION: WEBSERVICE 0x1004e5e0
// FUNCTION: ROBLOX 0x0057a3f0
void Instance::readChild(const XmlElement* childElement, IReferenceBinder& binder)
{
	const Name* className = NULL;
	if (childElement->findAttributeValue(tag_class, className)) {
		shared_ptr<Instance> childInstance = createChild(*className);

		if (childInstance) {
			childInstance->read(childElement, binder);
			if (childInstance) {
				childInstance->setParent(this);
			}
		}
		else {
			const XmlAttribute* referent = childElement->findAttribute(name_referent);
			if (referent) {
				binder.announceID(referent, NULL);
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x1004e6e0
// FUNCTION: ROBLOX 0x0057a4f0
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

// FUNCTION: WEBSERVICE 0x1004e730
// FUNCTION: ROBLOX 0x0057a540
void Instance::read(const XmlElement* element, IReferenceBinder& binder)
{
	const XmlAttribute* referent = element->findAttribute(name_referent);
	if (referent) {
		binder.announceID(referent, this);
	}

	if (&element->getTag() == &tag_Item) {
		const XmlElement* properties = element->findFirstChildByTag(tag_Properties);
		if (properties) {
			readProperties(properties, binder);
		}

		readChildren(element, binder);
	}
	else {
		readProperty(element, binder);
	}
}

// FUNCTION: WEBSERVICE 0x1004e7b0
// FUNCTION: ROBLOX 0x0057a5c0
void Instance::predelete(Instance* instance)
{
	instance->predelete();
}

// FUNCTION: WEBSERVICE 0x1004eb10
// FUNCTION: ROBLOX 0x0057a780
Instance::Instance() : parent(NULL), name("Instance"), archivable(true)
{
}

// FUNCTION: WEBSERVICE 0x1004ec70
// FUNCTION: ROBLOX 0x0057a8e0
Instance::Instance(const char* name) : parent(NULL), name(name), archivable(true)
{
}

// FUNCTION: WEBSERVICE 0x101019f0 FOLDED
// FUNCTION: ROBLOX 0x007859e0 FOLDED
void Instance::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
}

// FUNCTION: WEBSERVICE 0x100c74e0 FOLDED
bool Instance::askSetParent(const Instance* instance) const
{
	return false;
}

// FUNCTION: WEBSERVICE 0x100c74e0 FOLDED
bool Instance::askAddChild(const Instance* instance) const
{
	return false;
}

} // namespace RBX
