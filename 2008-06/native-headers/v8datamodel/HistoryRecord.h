#pragma once
// >>> native-status (generated) -- do not edit >>>
// HistoryRecord | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src f36d0b4e | roc native-status --write
#include "reflection/type.h"
#include <boost/shared_ptr.hpp>
#include <map>
#include <string>

namespace RBX {
class ChangeHistoryService;
class Instance;
namespace Reflection { class PropertyDescriptor; class Property; }

// Types and member order follow the original history-record constructor and
// map operations; individual record behavior still requires recovery.
struct HistoryItem {
    ChangeHistoryService* service;
    boost::shared_ptr<Instance> object;
    int kind;
    boost::shared_ptr<Instance> parent;
    std::map<const Reflection::PropertyDescriptor*, Reflection::Value> properties;
    HistoryItem(ChangeHistoryService*, boost::shared_ptr<Instance>);
    void play();
    void unplay();
    void captureAll();
    void reset();
    void captureProperty(const Reflection::PropertyDescriptor*);
    void capture(const Reflection::Property&);
    HistoryItem();
    void mergeProperty(const std::pair<const Reflection::PropertyDescriptor* const, Reflection::Value>&);
    void update(const Reflection::PropertyDescriptor*);
    void applyProperty(const std::pair<const Reflection::PropertyDescriptor* const, Reflection::Value>&);
    void unplayProperty(const std::pair<const Reflection::PropertyDescriptor* const, Reflection::Value>&);
};

struct HistoryRecord : std::map<Instance*, HistoryItem> {
    ChangeHistoryService* service;
    std::string name;
    HistoryRecord(ChangeHistoryService*);
    HistoryItem* get(boost::shared_ptr<Instance>);
    bool empty();
    void merge(HistoryRecord*);
    void play();
    void unplay();
};
}
