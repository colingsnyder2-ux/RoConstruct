// Inactive 2008-06 native recovery: the ChangeHistoryService.cpp unit of the application range 00588000..0058c91f
// (ChangeHistoryService, HistoryRecord, HistoryItem), one translation unit as in the original. Layout from the
// committed read-only native v8datamodel/ChangeHistoryService.h / HistoryRecord.h (0x1a4 from 004150d0, HistoryRecord
// 0x40, HistoryItem 0x38; tests/NativeChangeHistoryLayout.cpp). Bodies consolidated from the ChangeHistory* /
// HistoryItem* / HistoryRecord* native-classes (their owners' per-method trials) into one unit; the original
// Instance::event_itemChanged definition is not part of this unit (its initializer is at 007f344b) and is omitted.
// Verified by tests/record_native_app_unit588_2008.py.
#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/HistoryRecord.h"
#include "v8tree/Instance.h"
#include "security/SecurityContext.h"
#include <boost/bind.hpp>
#include <boost/checked_delete.hpp>
#include <algorithm>
#include <deque>
#include <stdexcept>

// The member-pointer argument type of applyProperty / unplayProperty / mergeProperty. The committed HistoryRecord.h
// declares pair<const PropertyDescriptor* const, Value>; the std::for_each body 00588240 they are bound into (callers
// 00588486 / 005884b1 / 0058a0de / 0058bdf4) converts each map element into a temporary
// pair<const PropertyDescriptor*, Value> through 00587710 (copy of the key, Value clone through its vtable slot 2,
// call, destroy), so the 2008 parameter type is pair<const PropertyDescriptor*, Value> (pending HistoryRecord.h
// proposal; only the pending build uses it).
#ifdef NATIVE_APPUNIT588_PENDING
typedef std::pair<const RBX::Reflection::PropertyDescriptor*, RBX::Reflection::Value> HistoryPropertyArg;
#else
typedef std::pair<const RBX::Reflection::PropertyDescriptor* const, RBX::Reflection::Value> HistoryPropertyArg;
#endif

template<>
inline RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor>::Iterator&
RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor>::Iterator::operator++()
{
    ++iter;
    return *this;
}


static __forceinline RBX::HistoryItem* findHistoryItem(RBX::HistoryRecord* record, RBX::Instance* instance)
{
    RBX::HistoryRecord::iterator it = record->find(instance);
    return it != record->end() ? &it->second : NULL;
}


RBX::HistoryItem::HistoryItem(ChangeHistoryService* owner, boost::shared_ptr<Instance> instance)
    : service(owner), object(instance), kind(0)
{
}

RBX::HistoryItem* RBX::HistoryRecord::get(boost::shared_ptr<Instance> instance)
{
    iterator it = find(instance.get());
    if (it == end())
        it = insert(std::pair<Instance*, HistoryItem>(instance.get(), HistoryItem(service, instance))).first;
    return &it->second;
}

RBX::HistoryRecord::HistoryRecord(ChangeHistoryService* owner)
    : service(owner)
{
}

void RBX::HistoryItem::captureProperty(const Reflection::PropertyDescriptor* property)
{
    if (property->isReadOnly()) return;
    if (property->isWriteOnly()) return;
    Reflection::Value value;
    property->getVariant(object.get(), value);
    const Reflection::PropertyDescriptor* key = property;
    properties[key] = value;
}

void RBX::HistoryItem::reset()
{
    parent.reset();
    properties.clear();
    kind = kind == 1 ? 0 : 3;
}

void RBX::HistoryItem::update(const Reflection::PropertyDescriptor* property)
{
    captureProperty(property);
    if (kind != 1) {
        kind = 2;
        return;
    }
    if (property == &Instance::propParent) parent = shared_from(object->getParent());
}

void RBX::HistoryItem::captureAll()
{
    std::for_each(object->properties_begin(), object->properties_end(), boost::bind(&HistoryItem::capture, this, _1));
    parent = shared_from(object->getParent());
    kind = 1;
}

void RBX::HistoryItem::capture(const Reflection::Property& property)
{
    const Reflection::PropertyDescriptor* descriptor = &property.getDescriptor();
    if (descriptor != &Instance::propParent) captureProperty(descriptor);
}


void RBX::HistoryItem::play()
{
    switch (kind) {
    case 1:
        std::for_each(properties.begin(), properties.end(), boost::bind(&HistoryItem::applyProperty, this, _1));
        object->setParent(parent.get());
        break;
    case 2:
        std::for_each(properties.begin(), properties.end(), boost::bind(&HistoryItem::applyProperty, this, _1));
        break;
    case 3:
        object->setParent(NULL);
        break;
    }
}

static __forceinline RBX::HistoryItem* lookup(RBX::HistoryRecord* record, RBX::Instance* object)
{
    RBX::HistoryRecord::iterator it = record->find(object);
    if (it == record->end()) return NULL;
    return &it->second;
}

void RBX::HistoryItem::unplay()
{
    std::deque<HistoryItem*> pending;
    std::list<HistoryRecord*>::iterator it = service->backward;
    while (it != service->history.begin()) {
        --it;
        HistoryItem* item = lookup(*it, object.get());
        if (item) {
            if (item->kind == 1) {
                item->play();
                break;
            }
            pending.push_back(item);
        }
    }
    while (!pending.empty()) {
        pending.back()->play();
        pending.pop_back();
    }
}

void RBX::HistoryItem::applyProperty(
    const HistoryPropertyArg& property)
{
    property.first->setVariant(object.get(), property.second);
}


void RBX::HistoryItem::unplayProperty(
    const HistoryPropertyArg& property)
{
    bool isParent = property.first == &Instance::propParent;
    std::list<HistoryRecord*>::iterator it = service->backward;
    while (it != service->history.begin()) {
        --it;
        HistoryItem* item = findHistoryItem(*it, object.get());
        if (item) {
            std::map<const Reflection::PropertyDescriptor*, Reflection::Value>::iterator found = item->properties.find(property.first);
            if (found != item->properties.end()) {
                std::pair<const Reflection::PropertyDescriptor* const, Reflection::Value> value = *found;
                value.first->setVariant(item->object.get(), value.second);
                return;
            }
            if (isParent && item->kind == 1) {
                object->setParent(item->parent.get());
                return;
            }
        }
    }
}

void RBX::HistoryRecord::play()
{
    for (iterator it = begin(); it != end(); ++it) it->second.play();
}

void RBX::HistoryRecord::unplay()
{
    for (iterator it = begin(); it != end(); ++it) {
        HistoryItem& item = it->second;
        switch (item.kind) {
        case 1: item.object->setParent(NULL); break;
        case 2:
            std::for_each(item.properties.begin(), item.properties.end(),
                boost::bind(&HistoryItem::unplayProperty, &item, _1));
            break;
        case 3: item.unplay(); break;
        }
    }
}


RBX::HistoryItem::HistoryItem() : kind(0) {}

void RBX::HistoryItem::mergeProperty(
    const HistoryPropertyArg& property)
{
    properties[property.first] = property.second;
}

bool RBX::HistoryRecord::empty()
{
    iterator last = end();
    for (iterator it = begin(); it != last; ++it) {
        if (it->second.kind != 0) return false;
    }
    return true;
}

void RBX::HistoryRecord::merge(HistoryRecord* source)
{
    iterator last = source->end();
    for (iterator it = source->begin(); it != last; ++it) {
        const HistoryItem& value = it->second;
        HistoryItem* destination = findHistoryItem(this, value.object.get());
        if (destination) {
            if (value.kind == 3) {
                Instance* key = value.object.get();
                erase(find(key));
            } else {
                if (value.parent) destination->parent = value.parent;
                std::for_each(value.properties.begin(), value.properties.end(),
                              boost::bind(&HistoryItem::mergeProperty, destination, _1));
            }
        } else {
            Instance* key = value.object.get();
            (*this)[key] = value;
        }
    }
}

void RBX::ChangeHistoryService::commit(const char* name)
{
    if (enabled) {
        prepare();
        if (current && !current->empty()) {
            current->name = name;
            history.push_back(current);
            forward = history.end();
            backward = --history.end();   // 0058c2c0 calls list iterator operator-- (004962b0)
            current = new HistoryRecord(this);
        }
    }
}

void RBX::ChangeHistoryService::prepare()
{
    if (enabled) {
        if (forward != history.end()) {
            history.erase(forward, history.end());
            forward = history.end();
            backward = --history.end();
        }
        while (history.size() > 10) mergeFirst();
    }
}

void RBX::ChangeHistoryService::mergeFirst()
{
    std::list<HistoryRecord*>::iterator it = history.begin();
    ++it;
    (*history.begin())->merge(*it);
    if (backward == it) --backward;
    if (forward == it) ++forward;
    delete *it;
    history.erase(it);
}

namespace {
class RestoreFlag {
    bool& value;
    bool previous;
public:
    explicit RestoreFlag(bool& flag) : value(flag), previous(flag) { value = true; }
    ~RestoreFlag() { value = previous; }
};
}

void RBX::ChangeHistoryService::play()
{
    if (playing) throw std::runtime_error("ChangeHistoryService is currently playing");
    if (!enabled) throw std::runtime_error("ChangeHistoryService is disabled");
    if (forward == history.end()) throw std::runtime_error("Attempt to play beyond change history");
    RestoreFlag restore(playing);
    (*forward)->play();
    backward = forward;
    ++forward;
}

void RBX::ChangeHistoryService::unplay()
{
    if (playing) throw std::runtime_error("ChangeHistoryService is currently playing");
    if (!enabled) throw std::runtime_error("ChangeHistoryService is disabled");
    if (backward == history.begin()) throw std::runtime_error("Attempt to unplay before the change history");
    RestoreFlag restore(playing);
    (*backward)->unplay();
    forward = backward;
    --backward;
}

bool RBX::ChangeHistoryService::queryPlay(std::string& result, int count)
{
    if (!enabled) return false;
    std::list<HistoryRecord*>::iterator it = forward;
    for (int i = 0; i < count; ++i) {
        if (it == history.end()) return false;
        ++it;
    }
    if (it == history.end()) return false;
    result = (*it)->name;
    return true;
}

bool RBX::ChangeHistoryService::queryUnplay(std::string& result, int count)
{
    if (!enabled) return false;
    std::list<HistoryRecord*>::iterator it = backward;
    for (int i = 0; i < count; ++i) {
        if (it == history.begin()) return false;
        --it;
    }
    if (it == history.end()) return false;
    if (it == history.begin()) return false;
    result = (*it)->name;
    return true;
}

namespace RBX {
template<> Reflection::ClassDescriptor& Reflection::Described<ChangeHistoryService, sChangeHistoryService,
    FactoryProduct<ChangeHistoryService, Instance, sChangeHistoryService> >::classDescriptor() {
    static Reflection::ClassDescriptor descriptor(Instance::classDescriptor(), "ChangeHistoryService");
    return descriptor;
}
template<class C, class D, const char* N> template<class A>
DescribedCreatable<C,D,N>::DescribedCreatable(A value) : Reflection::Described<C,N,FactoryProduct<C,D,N> >(value) {}
template DescribedCreatable<ChangeHistoryService,Instance,sChangeHistoryService>::DescribedCreatable(const char*);
}

namespace RBX {
template<> ChangeHistoryService* ServiceProvider::find<ChangeHistoryService>(const Instance* context) {
    while (context) {
        if (const ServiceProvider* service = dynamic_cast<const ServiceProvider*>(context))
            return service->find<ChangeHistoryService>();
        context = context->getParent();
    }
    return NULL;
}

void recordCameraHistory(const char* name, const Instance* context) {
    ChangeHistoryService* history = ServiceProvider::find<ChangeHistoryService>(context);
    if (history) history->commit(name);
}
}

RBX::ChangeHistoryService::ChangeHistoryService()
    : DescribedCreatable<ChangeHistoryService, Instance, sChangeHistoryService>("ChangeHistoryService"),
      current(NULL), playing(false), enabled(false)
{
}

RBX::ChangeHistoryService::~ChangeHistoryService()
{
    delete current;
}

void RBX::ChangeHistoryService::onHistoryAdded(boost::shared_ptr<Instance> instance)
{
    if (playing) return;
    if (instance.get() == this) return;
    if (dynamic_cast<Service*>(instance.get())) return;
    if (current) current->get(instance)->captureAll();
}

void RBX::ChangeHistoryService::onHistoryRemoving(boost::shared_ptr<Instance> instance)
{
    if (playing) return;
    if (instance.get() == this) return;
    if (dynamic_cast<Service*>(instance.get())) return;
    if (current) current->get(instance)->reset();
}

void RBX::ChangeHistoryService::onHistoryChanged(boost::shared_ptr<Instance> instance,
    const Reflection::PropertyDescriptor* property)
{
    if (!playing && instance.get() != this && current) current->get(instance)->update(property);
}

typedef std::list<RBX::HistoryRecord*>::iterator HistoryIterator;
namespace std {
template<> __forceinline boost::checked_deleter<RBX::HistoryRecord> for_each(
    HistoryIterator first, HistoryIterator last, boost::checked_deleter<RBX::HistoryRecord> deleter)
{
    _Checked_iterator_base_helper<HistoryIterator>::_Checked_iterator_base_type begin(_CHECKED_BASE(first));
    _Checked_iterator_base_helper<HistoryIterator>::_Checked_iterator_base_type end(_CHECKED_BASE(last));
    for (; begin != end; ++begin) deleter(*begin);
    return deleter;
}
}

void RBX::ChangeHistoryService::reset()
{
    if (current) {
        delete current;
        current = new HistoryRecord(this);
    }
    std::for_each(history.begin(), history.end(), boost::checked_deleter<HistoryRecord>());
    history.clear();
    forward = history.end();
    backward = history.begin();
}

void RBX::ChangeHistoryService::setEnabled(bool value)
{
    Security::Context::current().requirePermission(Security::Administrator, "ChangeHistoryService.enabled");
    if (value != enabled) {
        enabled = value;
        if (value) start();
        else {
            reset();
            connectionAdded.disconnect();
            connectionRemoved.disconnect();
            connectionChanged.disconnect();
        }
    }
}

void RBX::ChangeHistoryService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
    if (oldProvider) {
        reset();
        connectionAdded.disconnect();
        connectionRemoved.disconnect();
        connectionChanged.disconnect();
        context = NULL;
    }
    if (newProvider) context = const_cast<ServiceProvider*>(newProvider);
}

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
