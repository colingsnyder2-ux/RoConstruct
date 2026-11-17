#pragma once
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
    // The bound property members take pair<const PropertyDescriptor*, Value> (non-const key): the original
    // std::for_each 00588240 converts each map element into that temporary through 00587710 before the call.
    void mergeProperty(const std::pair<const Reflection::PropertyDescriptor*, Reflection::Value>&);
    void update(const Reflection::PropertyDescriptor*);
    void applyProperty(const std::pair<const Reflection::PropertyDescriptor*, Reflection::Value>&);
    void unplayProperty(const std::pair<const Reflection::PropertyDescriptor*, Reflection::Value>&);
public:
	~HistoryItem(void);   // INFERRED: ??1HistoryItem@RBX@@QAE@XZ (header gap, header_gap_fill.py)
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
public:
	~HistoryRecord(void);   // INFERRED: ??1HistoryRecord@RBX@@QAE@XZ (header gap, header_gap_fill.py)
};
}
