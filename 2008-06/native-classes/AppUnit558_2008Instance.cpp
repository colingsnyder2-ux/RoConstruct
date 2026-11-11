// Inactive 2008-06 native unit for v8tree/Instance.cpp (original 00557310..0055bad9), recorded by
// tests/record_native_app_unit558_2008.py (lease 'RBX::app unit 00558000 2008'). Built against the read-only native
// v8tree/Instance.h, v8tree/InstanceEvents.h and v8xml/XmlElement.h; RBX::DescendantRemoving is defined in
// native-headers/AppUnit558_2008/InstanceDescendantRemoving2008.h until v8tree/InstanceEvents.h adopts it.
// Each body follows the target bytes (relocation-masked exact, every call/data target verified by the recorder).
// The 2008 struct names are DescendentAdded / DescendentRemoving (evidence symbols of 00557780 / 00557e80); the native
// headers spell them DescendantAdded / DescendantRemoving, which changes only the mangled names (proposal).
#include "AppUnit558_2008/InstanceDescendantRemoving2008.h"
#include "v8xml/XmlElement.h"
#include <algorithm>
#ifdef NATIVE_APPUNIT558_PENDING
#include "v8datamodel/MergeBinder2008.h"  // IReferenceBinder (announceID slot 0)
#endif
#include <boost/bind.hpp>

namespace RBX {
// 0055af90
void Instance::setName(const std::string& value)
{
    if (name != value) {
        name = value;
        raisePropertyChanged(desc_Name);
    }
}

// 00557490
void Instance::onChildChanged(Instance* instance, const PropertyChanged& event)
{
    Instance* p = parent;
    if (p)
        p->onChildChanged(instance, event);
}

// 005574b0
bool Instance::contains(const Instance* child) const
{
    for (; child != NULL; child = child->parent) {
        if (child == this)
            return true;
    }
    return false;
}

// 00557950
Instance* Instance::findFirstChildByName(const std::string& findName) const
{
    if (!children)
        return NULL;
    const std::vector<boost::shared_ptr<Instance> >& c = *children;
    for (size_t i = 0; i < c.size(); i++) {
        if (c[i]->name == findName)
            return c[i].get();
    }
    return NULL;
}

// 0055afd0
void Instance::removeAllChildren()
{
    while (children)
        children->back()->setParent(NULL);
}

// for_eachChild<RaiseDescendentAdded2> 00558ff0 (the functor is inlined; the class is a friend of Instance)
class RaiseDescendentAdded2 {
    const Instance* notifier;
    Listener<Instance, DescendantAdded>* listener;
public:
    RaiseDescendentAdded2(const Instance* notifier, Listener<Instance, DescendantAdded>* listener)
        : notifier(notifier), listener(listener) {}
    void operator()(Instance* instance)
    {
        const Instance* receiver = notifier;
        Instance* parent = instance->parent;
        receiver->Notifier<Instance, DescendantAdded>::raise(DescendantAdded(instance, parent), listener);
        instance->for_eachChild(*this);
    }
};

// 00559230: tail-calls for_eachChild 00558ff0
void Instance::onAddListener(Listener<Instance, DescendantAdded>* listener) const
{
    for_eachChild(RaiseDescendentAdded2(this, listener));
}

// 00558d90: end() is read before begin(), as in for_eachChild
void Instance::onAddListener(Listener<Instance, ChildAdded>* listener) const
{
    if (children) {
        boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > c = children.read();
        std::vector<boost::shared_ptr<Instance> >::const_iterator end = c->end();
        std::vector<boost::shared_ptr<Instance> >::const_iterator iter = c->begin();
        for (; iter != end; ++iter)
            Notifier<Instance, ChildAdded>::raise(ChildAdded(iter->get()), listener);
    }
}

// 0055acc0; Notifier<Instance, AncestorChanged>::raise 00558730
void Instance::onAncestorChanged(const AncestorChanged& event)
{
    typedef std::vector<boost::shared_ptr<Instance> >::const_iterator Iterator;
    if (children) {
        boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > r = children.read();
        for (Iterator it = r->begin(); it != r->end(); it++)
            (*it)->onAncestorChanged(event);
    }
    event_ancestryChanged.fire(this, shared_from(event.child));
    Notifier<Instance, AncestorChanged>::raise(event);
}

// 0055ae20 (not exact: register choice for the parent load, eax vs edx); DescendantAdded ctor 00558910, raise 00557e80
void Instance::onDescendentAdded(Instance* instance)
{
    if (Notifier<Instance, DescendantAdded>::hasListeners())
        Notifier<Instance, DescendantAdded>::raise(DescendantAdded(instance, instance->parent));
    event_descendentAdded.fire(this, shared_from(instance));
}

// 0055ae90; Notifier<Instance, DescendantRemoving>::raise 00558660
void Instance::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
{
    event_descendentRemoving.fire(this, instance);
    if (Notifier<Instance, DescendantRemoving>::hasListeners())
        Notifier<Instance, DescendantRemoving>::raise(DescendantRemoving(instance, shared_from(instance->parent)));
}

// 0055b6a0
void Instance::readChildren(const XmlElement* element, IReferenceBinder& binder)
{
    if (element) {
        for (const XmlElement* current = element->findFirstChildByTag(tag_Item); current != NULL;
             current = element->findNextChildWithSameTag(current))
            readChild(current, binder);
    }
}

// 00559170
void Instance::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
{
    const Name* value = NULL;
    if (const XmlAttribute* attribute = propertyElement->findAttribute(name_name)) {
        if (attribute->getValue(value)) {
            Reflection::PropertyIterator iter = findProperty(*value);
            if (iter != properties_end())
                (*iter).read(propertyElement, binder);
        }
    }
}

// 00558c50; XmlElement(Name, InstanceHandle) 00417510, addAttribute<const Name*> 00557e30, addAttribute<InstanceHandle> 00558830 / XmlAttribute 00558030
XmlElement* Instance::write()
{
    if (archivable) {
        if (getClassName() != Name::getNullName()) {
            XmlElement* element = new XmlElement(tag_Item);
            element->addAttribute(tag_class, &getClassName());
            element->addAttribute(name_referent, InstanceHandle(this));
            writeProperties(element->addChild(tag_Properties));
            writeChildren(element);
            return element;
        }
    }
    return new XmlElement(tag_External, InstanceHandle(this));
}

// 0055b4a0; std::for_each<bind_t<mf0<void, Instance> > > 00558fa0
void Instance::remove()
{
    boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > c = children.read();
    setParent(NULL);
    if (c)
        std::for_each(c->begin(), c->end(), boost::bind(&Instance::remove, _1));
}

#ifdef NATIVE_APPUNIT558_PENDING
// Bodies that need declarations v8tree/Instance.h does not have yet (proposal; the recorder builds them against a
// generated copy of the header that adds them). Not counted.
// 00557920
void Instance::readProperties(const XmlElement* container, IReferenceBinder& binder)
{
    for (const XmlElement* i = container->firstChild(); i != NULL; i = i->nextSibling())
        readProperty(i, binder);
}

// 0055b5a0
void Instance::readChild(const XmlElement* childElement, IReferenceBinder& binder)
{
    const Name* className = NULL;
    const XmlAttribute* classAttrib = childElement->findAttribute(tag_class);
    if (classAttrib) {
        if (classAttrib->getValue(className)) {
            boost::shared_ptr<Instance> childInstance = createChild(*className);
            if (childInstance) {
                childInstance->read(childElement, binder);
                if (childInstance)
                    childInstance->setParent(this);
            } else {
                const XmlAttribute* nameRef = childElement->findAttribute(name_referent);
                if (nameRef)
                    binder.announceID(nameRef, NULL);
            }
        }
    }
}

// 0055b6f0
void Instance::read(const XmlElement* element, IReferenceBinder& binder)
{
    const XmlAttribute* nameRef = element->findAttribute(name_referent);
    if (nameRef)
        binder.announceID(nameRef, this);
    if (element->getTag() == tag_Item) {
        const XmlElement* properties = element->findFirstChildByTag(tag_Properties);
        if (properties)
            readProperties(properties, binder);
        readChildren(element, binder);
    } else
        readProperty(element, binder);
}

// 005581b0
Instance* Instance::findFirstChildByNameRecursive(const std::string& findName) const
{
    Instance* foundChild = findFirstChildByName(findName);
    if (foundChild)
        return foundChild;
    if (!children)
        return NULL;
    const std::vector<boost::shared_ptr<Instance> >& c = *children;
    for (size_t i = 0; i < c.size(); i++) {
        Instance* child = c[i]->findFirstChildByNameRecursive(findName);
        if (child)
            return child;
    }
    return NULL;
}

// 005580e0
boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > Instance::getChildren2()
{
    return children.read();
}

// 00558970
boost::shared_ptr<Instance> Instance::findFirstChildByName2(std::string findName, bool recursive)
{
    return shared_from(recursive ? findFirstChildByNameRecursive(findName) : findFirstChildByName(findName));
}
#endif
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::CopyOnWrite<std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > >;
template class RBX::Reflection::SignalDescImpl<1,void __cdecl(boost::shared_ptr<RBX::Instance>)>;
template class RBX::Reflection::TSignalDesc<void __cdecl(boost::shared_ptr<RBX::Instance>)>;
template class boost::function1<void,boost::shared_ptr<RBX::Instance>,std::allocator<void> >;
template class boost::shared_ptr<RBX::Instance>;
template class boost::shared_ptr<RBX::StandardOut>;
template class boost::shared_ptr<boost::signals::detail::basic_connection>;
template class boost::shared_ptr<boost::signals::detail::signal_base_impl>;
template class boost::shared_ptr<std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > >;
template class boost::shared_ptr<std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > const >;
template class boost::signal1<void,boost::shared_ptr<RBX::Instance>,boost::last_value<void>,int,std::less<int>,boost::function<void __cdecl(boost::shared_ptr<RBX::Instance>),std::allocator<void> > >;
template class std::_Tree<std::_Tmap_traits<boost::signals::detail::stored_group,std::list<boost::signals::detail::connection_slot_pair,std::allocator<boost::signals::detail::connection_slot_pair> >,boost::function2<bool,boost::signals::detail::stored_group,boost::signals::detail::stored_group,std::allocator<boost::function_base> >,std::allocator<std::pair<boost::signals::detail::stored_group const ,std::list<boost::signals::detail::connection_slot_pair,std::allocator<boost::signals::detail::connection_slot_pair> > > >,0> >;
template class std::_Vector_const_iterator<RBX::Reflection::PropertyDescriptor *,std::allocator<RBX::Reflection::PropertyDescriptor *> >;
template class std::_Vector_const_iterator<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > >;
template class std::list<boost::signals::detail::connection_slot_pair,std::allocator<boost::signals::detail::connection_slot_pair> >;
template class std::vector<RBX::Listener<RBX::Instance,RBX::AncestorChanged> *,std::allocator<RBX::Listener<RBX::Instance,RBX::AncestorChanged> *> >;
template class std::vector<RBX::Listener<RBX::Instance,RBX::DescendantAdded> *,std::allocator<RBX::Listener<RBX::Instance,RBX::DescendantAdded> *> >;
template class std::vector<RBX::Listener<RBX::Instance,RBX::DescendantRemoving> *,std::allocator<RBX::Listener<RBX::Instance,RBX::DescendantRemoving> *> >;
template class std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > >;

// Methods recovered from exact mined packets: field offsets mapped to this header by compiler layout.
bool RBX::Instance::isDescendentOf(RBX::Instance const * node) const { Instance* p = parent; while (node != p) { if (!p) return false; p = p->parent; } return true; }
