// Isolated source/ABI trial; signal declarations are not yet proven for runtime.
#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/HistoryRecord.h"
#include <boost/bind.hpp>
#include <algorithm>

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

static __forceinline RBX::HistoryItem* findHistoryItem(RBX::HistoryRecord* record, RBX::Instance* key)
{
    RBX::HistoryRecord::iterator found = record->find(key);
    return found != record->end() ? &found->second : NULL;
}

RBX::HistoryItem::HistoryItem() : kind(0)
{
}

void RBX::HistoryItem::mergeProperty(
    const std::pair<const Reflection::PropertyDescriptor* const, Reflection::Value>& property)
{
    properties[property.first] = property.second;
}

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

bool RBX::HistoryRecord::empty()
{
    iterator last = end();
    for (iterator it = begin(); it != last; ++it) {
        if (it->second.kind != 0) return false;
    }
    return true;
}

void RBX::ChangeHistoryService::commit(const char* name)
{
    if (enabled) {
        prepare();
        if (current && !current->empty()) {
            current->name = name;
            history.push_back(current);
            forward = history.end();
            backward = ++history.end();
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
                std::for_each(value.properties.begin(), value.properties.end(), boost::bind(&HistoryItem::mergeProperty, destination, _1));
            }
        } else {
            Instance* key = value.object.get();
            (*this)[key] = value;
        }
    }
}
