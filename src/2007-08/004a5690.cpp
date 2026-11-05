// from server: 100% by EspClaude
// roc 2007-08 004a5690  RBX::Association<Instance>::TItem<Network::ClientPhysics> ctor (util/Association.h)
// ClientPhysics is 8-aligned in the exe (TItem::t at +8 while TItem<int>::t is at +4).
// roc-flags: /O2 /GS /EHsc /MD
namespace RBX {
class Instance;
template<typename Associated>
class Association
{
public:
    class Item { public: virtual ~Item() {} };
    template<typename T> class TItem : public Item {
    public:
        T t;
        template<typename A> TItem(A a) : t(a) {}
    };
};
namespace Network {
class Replicator;
class __declspec(align(8)) ClientPhysics {
public:
    ClientPhysics(Replicator* replicator);
    virtual ~ClientPhysics();
    char pad[0x2c];
};
}
template Association<Instance>::TItem<Network::ClientPhysics>::TItem(Network::Replicator*);
template Association<Instance>::TItem<Network::ClientPhysics>::~TItem();
}
