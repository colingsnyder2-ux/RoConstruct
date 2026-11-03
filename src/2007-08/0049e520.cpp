// from server: 100% by EspClaude
// roc 2007-08 0049e520  Reflection::Described<Network::Server, FactoryProduct<Server, Peer, &sServer>, &sServer>::Described()
// Instance-derived layout from the target: polymorphic subobjects at 0,4,0x10,0x14,0x2c,0x44,0x5c,0x74,0x8c,0xe8,0xec;
// DescribedBase descriptor @0xc. Base (FactoryProduct) ctor and classDescriptor() are out of line.
// roc-flags: /O2 /GS /EHsc /MD
namespace RBX {
class V0 { public: virtual ~V0(); };
namespace Reflection {
class ClassDescriptor;
class DescribedBase { public: virtual ~DescribedBase(); int a; protected: const ClassDescriptor* descriptor; };
}
class V2 { public: virtual ~V2(); };
template<int N> class Notifier { public: virtual ~Notifier(); int pad[5]; };
class V8 { public: virtual ~V8(); char pad[0xe8 - 0x90]; };
class V9 { public: virtual ~V9(); };
class V10 { public: virtual ~V10(); };
class InstanceBase : public V0, public Reflection::DescribedBase, public V2, public Notifier<1>, public Notifier<2>,
                     public Notifier<3>, public Notifier<4>, public Notifier<5>, public V8 {
};
namespace Network {
extern char* sServer;
class Peer : public InstanceBase, public V9, public V10 {};
}
template<class Class, class Base, char** name>
class FactoryProduct : public Base {
protected:
    FactoryProduct();
};
namespace Reflection {
template<class Class, class Base, char** name>
class Described : public Base {
public:
    static const ClassDescriptor& classDescriptor();
protected:
    Described() { this->descriptor = &classDescriptor(); }
};
}
namespace Network { class Server; }
template class Reflection::Described<Network::Server, FactoryProduct<Network::Server, Network::Peer, &Network::sServer>, &Network::sServer>;
}
