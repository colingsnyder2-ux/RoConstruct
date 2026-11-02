#pragma once
#include "reflection/type.h"
#include <boost/shared_ptr.hpp>
#include <map>
#include <string>

namespace RBX {
class ChangeHistoryService;
class Instance;
namespace Reflection { class PropertyDescriptor; }

// Types and member order follow the original history-record constructor and
// map operations; individual record behavior still requires recovery.
struct HistoryItem {
    ChangeHistoryService* service;
    boost::shared_ptr<Instance> object;
    int kind;
    boost::shared_ptr<Instance> parent;
    std::map<const Reflection::PropertyDescriptor*, Reflection::Value> properties;
    ~HistoryItem();
    void play();
    void unplay();
    void applyProperty(const std::pair<const Reflection::PropertyDescriptor* const, Reflection::Value>&);
    void unplayProperty(const std::pair<const Reflection::PropertyDescriptor* const, Reflection::Value>&);
};

struct HistoryRecord : std::map<Instance*, HistoryItem> {
    ChangeHistoryService* service;
    std::string name;
    ~HistoryRecord();
    void play();
    void unplay();
};
}
