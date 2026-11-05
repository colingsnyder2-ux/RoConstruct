// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_3c5ef1110f0fff6f.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
namespace RBX {
namespace Profiling {
class CodeProfiler { public: ~CodeProfiler(); int x; };
class Mark {
public:
    Mark(CodeProfiler& profiler, bool enabled);
    ~Mark();
    CodeProfiler* profiler;
    void* prev;
    bool enabled;
    double start;
};
}
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); };
class PropertyDescriptor {
public:
    char pad[0x10];
    unsigned int canReplicate : 1;
    unsigned int streamWrite : 1;
    bool canStreamWrite() const { return streamWrite; }
};
class Property {
public:
    const PropertyDescriptor* descriptor;
    DescribedBase* instance;
    Property(const PropertyDescriptor& d, DescribedBase* i) : descriptor(&d), instance(i) {}
    bool operator==(const Property& o) const { return descriptor == o.descriptor && instance == o.instance; }
};
}
struct InstPad { virtual ~InstPad(); char p[0x10]; };
class Instance : public InstPad, public Reflection::DescribedBase {
public:
    static const Reflection::PropertyDescriptor propParent;
    bool isDescendentOf(const Instance* ancestor) const;
};
namespace Network {
class Player {
public:
    char pad[0x170];
    Instance* character;
    Instance* getCharacter() const { return character; }
};
class Item { public: virtual ~Item(); };
class Replicator;
class ChangePropertyItem : public Item {
public:
    ChangePropertyItem(Replicator& replicator, const boost::shared_ptr<const Instance>& instance, const Reflection::PropertyDescriptor& desc) throw();
    char pad[0x10];
};
class ItemQueue {
public:
    void push_front(const boost::shared_ptr<Item>& item);
    void push_back(const boost::shared_ptr<Item>& item);
};
class Replicator {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual Player* findTargetPlayer();
    char pad[0x2c74 - 4];
    ItemQueue pendingItems;
    char pad2[0x2cd4 - 0x2c75];
    Reflection::Property* deserializeProperty;
    Instance* removingInstance;
    char pad3[0x2d1c - 0x2cdc];
    boost::scoped_ptr<Profiling::CodeProfiler> profileReplication;
    boost::scoped_ptr<Profiling::CodeProfiler> profileDataListening;
    bool isSerializePending(Instance* instance);
    void onParentChanged(boost::shared_ptr<Instance> instance);
    void onPropertyChanged(boost::shared_ptr<Instance> instance, const Reflection::PropertyDescriptor* descriptor);
};
void Replicator::onPropertyChanged(boost::shared_ptr<Instance> instance, const Reflection::PropertyDescriptor* descriptor)
{
    Profiling::Mark mark(*profileReplication, false);
    Profiling::Mark mark2(*profileDataListening, false);

    if (instance.get() == removingInstance)
        return;
    if (deserializeProperty)
    {
        Reflection::Property prop(*descriptor, instance.get());
        if (prop == *deserializeProperty)
            return;
    }
    if (isSerializePending(instance.get()))
        return;
    if (descriptor == &Instance::propParent)
    {
        onParentChanged(instance);
        return;
    }
    if (!descriptor->canStreamWrite())
        return;
    Player* targetPlayer = findTargetPlayer();
    if (targetPlayer && targetPlayer->getCharacter() && instance->isDescendentOf(targetPlayer->getCharacter()))
        pendingItems.push_front(boost::shared_ptr<Item>(new ChangePropertyItem(*this, instance, *descriptor)));
    else
        pendingItems.push_back(boost::shared_ptr<Item>(new ChangePropertyItem(*this, instance, *descriptor)));
}
}}
