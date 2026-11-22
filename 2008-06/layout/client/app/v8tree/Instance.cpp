#include "AppUnit558_2008/InstanceDescendantRemoving2008.h"
#include "v8xml/XmlElement.h"
#include <algorithm>
#ifdef NATIVE_APPUNIT558_PENDING
#include "v8datamodel/MergeBinder2008.h"  // IReferenceBinder (announceID slot 0)
#endif
#include <boost/bind.hpp>

namespace RBX {
void Instance::setName(const std::string& value)
{
    if (name != value) {
        name = value;
        raisePropertyChanged(desc_Name);
    }
}

void Instance::onChildChanged(Instance* instance, const PropertyChanged& event)
{
    Instance* p = parent;
    if (p)
        p->onChildChanged(instance, event);
}

bool Instance::contains(const Instance* child) const
{
    for (; child != NULL; child = child->parent) {
        if (child == this)
            return true;
    }
    return false;
}

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

void Instance::removeAllChildren()
{
    while (children)
        children->back()->setParent(NULL);
}

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

void Instance::onAddListener(Listener<Instance, DescendantAdded>* listener) const
{
    for_eachChild(RaiseDescendentAdded2(this, listener));
}

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

void Instance::onDescendentAdded(Instance* instance)
{
    if (Notifier<Instance, DescendantAdded>::hasListeners())
        Notifier<Instance, DescendantAdded>::raise(DescendantAdded(instance, instance->getParent()));
    event_descendentAdded.fire(this, shared_from(instance));
}

void Instance::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
{
    event_descendentRemoving.fire(this, instance);
    if (Notifier<Instance, DescendantRemoving>::hasListeners())
        Notifier<Instance, DescendantRemoving>::raise(DescendantRemoving(instance, shared_from(instance->parent)));
}

void Instance::readChildren(const XmlElement* element, IReferenceBinder& binder)
{
    if (element) {
        for (const XmlElement* current = element->findFirstChildByTag(tag_Item); current != NULL;
             current = element->findNextChildWithSameTag(current))
            readChild(current, binder);
    }
}

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

template<>
inline Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor>::ConstIterator&
Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor>::ConstIterator::operator++()
{
    ++iter;
    return *this;
}

void Instance::writeProperties(XmlElement* container) const
{
    Reflection::ConstPropertyIterator iter = properties_begin();
    while (iter != properties_end()) {
        const Reflection::PropertyDescriptor& descriptor = iter.getDescriptor();
        XmlElement* child = descriptor.write(this, false);
        if (child)
            container->addChild(child);
        ++iter;
    }
}

void Instance::remove()
{
    boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > c = children.read();
    setParent(NULL);
    if (c)
        std::for_each(c->begin(), c->end(), boost::bind(&Instance::remove, _1));
}

#ifdef NATIVE_APPUNIT558_PENDING
void Instance::readProperties(const XmlElement* container, IReferenceBinder& binder)
{
    for (const XmlElement* i = container->firstChild(); i != NULL; i = i->nextSibling())
        readProperty(i, binder);
}

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

boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > Instance::getChildren2()
{
    return children.read();
}

boost::shared_ptr<Instance> Instance::findFirstChildByName2(std::string findName, bool recursive)
{
    return shared_from(recursive ? findFirstChildByNameRecursive(findName) : findFirstChildByName(findName));
}
#endif
}

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

bool RBX::Instance::isDescendentOf(RBX::Instance const * node) const { Instance* p = parent; while (node != p) { if (!p) return false; p = p->parent; } return true; }

#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/HistoryRecord.h"

namespace RBX { namespace Reflection {
template<class S>
SignalDescImpl<2, S>::GenericSlotAdapter::GenericSlotAdapter(GenericSlotWrapper* wrapper)
    : wrapper(wrapper)
{
}

template<class S>
void SignalDescImpl<2, S>::GenericSlotAdapter::operator()(
    typename boost::function_traits<S>::arg1_type a, typename boost::function_traits<S>::arg2_type b)
{
    std::vector<boost::any> args(2);
    args[0] = a;
    args[1] = b;
    wrapper->execute(args);
}

template<class S>
boost::signals::connection SignalDescImpl<2, S>::connectGeneric(
    SignalInstance* instance, GenericSlotWrapper* wrapper, boost::signals::connect_position pos) const
{
    return static_cast<typename TSignalDesc<S>::TSignalInstance*>(instance)->connect(GenericSlotAdapter(wrapper), pos);
}
}}

RBX::Reflection::SignalDesc<RBX::Instance, void(boost::shared_ptr<RBX::Instance>, const RBX::Reflection::PropertyDescriptor*)>
    RBX::Instance::event_itemChanged("ItemChanged", "object", "descriptor");

void RBX::ChangeHistoryService::start()
{
    current = new HistoryRecord(this);
    forward = history.end();
    backward = history.begin();
    context->visitDescendents(boost::bind(&ChangeHistoryService::onHistoryAdded, this, _1));
    if (enabled) {
        commit("base");
        while (history.size() > 1) mergeFirst();
    }
    connectionAdded = Instance::event_descendentAdded.connect(context, boost::bind(&ChangeHistoryService::onHistoryAdded, this, _1), 10);
    connectionRemoved = Instance::event_descendentRemoving.connect(context, boost::bind(&ChangeHistoryService::onHistoryRemoving, this, _1), 10);
    connectionChanged = Instance::event_itemChanged.connect(context, boost::bind(&ChangeHistoryService::onHistoryChanged, this, _1, _2), 10);
}

template class RBX::Reflection::SignalDescImpl<2,void __cdecl(boost::shared_ptr<RBX::Instance>,RBX::Reflection::PropertyDescriptor const *)>;
template class boost::_bi::value<RBX::ChangeHistoryService *>;
template class boost::_mfi::mf1<void,RBX::ChangeHistoryService,boost::shared_ptr<RBX::Instance> >;
template class boost::_mfi::mf2<void,RBX::ChangeHistoryService,boost::shared_ptr<RBX::Instance>,RBX::Reflection::PropertyDescriptor const *>;
template class boost::function2<void,boost::shared_ptr<RBX::Instance>,RBX::Reflection::PropertyDescriptor const *,std::allocator<void> >;
template class boost::function<void __cdecl(boost::shared_ptr<RBX::Instance>,RBX::Reflection::PropertyDescriptor const *),std::allocator<void> >;
template class boost::signal2<void,boost::shared_ptr<RBX::Instance>,RBX::Reflection::PropertyDescriptor const *,boost::last_value<void>,int,std::less<int>,boost::function<void __cdecl(boost::shared_ptr<RBX::Instance>,RBX::Reflection::PropertyDescriptor const *),std::allocator<void> > >;

#include "v8datamodel/PartInstance.h"

namespace RBX {
void Instance::applyAnchoredToChildren(AnchorAction value)
{
    if (children) {
        boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > list = children.read();
        std::vector<boost::shared_ptr<Instance> >::const_iterator end = list->end();
        std::vector<boost::shared_ptr<Instance> >::const_iterator it = list->begin();
        for (; it != end; ++it) {
            Instance* child = it->get();
            if (PartInstance* part = dynamic_cast<PartInstance*>(child))
                part->setAnchored(value.value);
            else
                child->applyAnchoredToChildren(value);
        }
    }
}
}

#include "v8tree/Instance.h"

namespace RBX {
Reflection::BoundProp<bool, 1> Instance::propArchivable("archivable", "Behavior", &Instance::archivable, Reflection::PropertyDescriptor::STANDARD);
}

RBX::Instance* RBX::Instance::findFirstChildByClassName(std::string className) const
{
    if (children) {
        std::vector<boost::shared_ptr<Instance> >::const_iterator end = children->end();
        for (std::vector<boost::shared_ptr<Instance> >::const_iterator it = children->begin(); it != end; ++it)
            if ((*it)->getClassNameStr() == className) return it->get();
    }
    return NULL;
}

namespace RBX {
std::string Instance::getFullName() const {
    if (parent) {
        if (parent->parent)
            return parent->getFullName() + "." + name;
        return name;
    }
    return "";
}
}

#include <windows.h>

namespace RBX {
extern long instanceCount;
Instance::Instance() : parent(0), name("Instance"), archivable(true)
{
    InterlockedIncrement(&instanceCount);
}
Instance::Instance(const char* value) : parent(0), name(value), archivable(true)
{
    InterlockedIncrement(&instanceCount);
}
Instance::~Instance()
{
    InterlockedDecrement(&instanceCount);
}
}

#ifndef NATIVE_INSTANCE_EXTERNAL_CREATE_CHILD
boost::shared_ptr<RBX::Instance> RBX::Instance::createChild(const Name& className)
{
    return AbstractFactoryProduct::create(className);
}
#endif

template class boost::scoped_ptr<std::map<RBX::Reflection::SignalDescriptor const *,boost::shared_ptr<RBX::Reflection::SignalInstance>,std::less<RBX::Reflection::SignalDescriptor const *>,std::allocator<std::pair<RBX::Reflection::SignalDescriptor const * const,boost::shared_ptr<RBX::Reflection::SignalInstance> > > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Association<RBX::Instance>::Item *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Instance,RBX::AncestorChanged> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Instance,RBX::ChildAdded> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Instance,RBX::ChildRemoved> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Instance,RBX::DescendantAdded> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Instance,RBX::DescendantRemoving> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Instance,RBX::PropertyChanged> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Reflection::SignalDescriptor const * const,boost::shared_ptr<RBX::Reflection::SignalInstance> > > >;
template class std::_Tmap_traits<RBX::Reflection::SignalDescriptor const *,boost::shared_ptr<RBX::Reflection::SignalInstance>,std::less<RBX::Reflection::SignalDescriptor const *>,std::allocator<std::pair<RBX::Reflection::SignalDescriptor const * const,boost::shared_ptr<RBX::Reflection::SignalInstance> > >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Reflection::SignalDescriptor const *,boost::shared_ptr<RBX::Reflection::SignalInstance>,std::less<RBX::Reflection::SignalDescriptor const *>,std::allocator<std::pair<RBX::Reflection::SignalDescriptor const * const,boost::shared_ptr<RBX::Reflection::SignalInstance> > >,0> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Reflection::SignalDescriptor const *,boost::shared_ptr<RBX::Reflection::SignalInstance>,std::less<RBX::Reflection::SignalDescriptor const *>,std::allocator<std::pair<RBX::Reflection::SignalDescriptor const * const,boost::shared_ptr<RBX::Reflection::SignalInstance> > >,0> >::_Node *>;
template class std::map<RBX::Reflection::SignalDescriptor const *,boost::shared_ptr<RBX::Reflection::SignalInstance>,std::less<RBX::Reflection::SignalDescriptor const *>,std::allocator<std::pair<RBX::Reflection::SignalDescriptor const * const,boost::shared_ptr<RBX::Reflection::SignalInstance> > > >;

namespace RBX {
const Reflection::PropDescriptor<Instance, std::string> Instance::desc_Name("Name", "Data", &Instance::getName, &Instance::setName, Reflection::PropertyDescriptor::STANDARD);
}

namespace RBX {
const Reflection::RefPropDescriptor<Instance, Instance> Instance::propParent("Parent", "Data", &Instance::getParent, &Instance::setParent, Reflection::PropertyDescriptor::UI);
}

namespace RBX {
Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)>
    Instance::event_descendentAdded("DescendantAdded", "descendant");
Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)>
    Instance::event_descendentRemoving("DescendantRemoving", "descendant");
Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)>
    Instance::event_ancestryChanged("AncestryChanged", "child");
}
