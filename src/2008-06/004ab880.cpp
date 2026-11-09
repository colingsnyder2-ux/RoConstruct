// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_rbxgs_change_property_item_c40ba38a692e54e0.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>

namespace RakNet {
class BitStream;
}

namespace RBX {

class Instance;

namespace Reflection {
class PropertyDescriptor;
}

namespace Network {

class Replicator;

class Item {
protected:
    Replicator& replicator;

    Item(Replicator& value)
        : replicator(value)
    {
    }

public:
    virtual ~Item();
    virtual void write(RakNet::BitStream& bitStream) = 0;
};

class ChangePropertyItem : public Item {
private:
    const Reflection::PropertyDescriptor& desc;
    const boost::shared_ptr<const Instance> instance;

public:
    ChangePropertyItem(
        Replicator& replicator,
        const boost::shared_ptr<const Instance>& instance,
        const Reflection::PropertyDescriptor& desc);
    virtual void write(RakNet::BitStream& bitStream);
};

ChangePropertyItem::ChangePropertyItem(
    Replicator& replicator,
    const boost::shared_ptr<const Instance>& instance,
    const Reflection::PropertyDescriptor& desc)
    : Item(replicator),
      instance(instance),
      desc(desc)
{
}

} // namespace Network
} // namespace RBX
