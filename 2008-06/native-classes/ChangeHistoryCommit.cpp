#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/HistoryRecord.h"
#include <algorithm>
#include <boost/bind.hpp>

namespace {
RBX::HistoryItem* findHistoryItem(RBX::HistoryRecord* record, RBX::Instance* key)
{
    RBX::HistoryRecord::iterator found = record->find(key);
    return found != record->end() ? &found->second : NULL;
}
}

RBX::HistoryItem::HistoryItem() : kind(0) {}

void RBX::HistoryItem::mergeProperty(
    const std::pair<const Reflection::PropertyDescriptor* const, Reflection::Value>& property)
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
