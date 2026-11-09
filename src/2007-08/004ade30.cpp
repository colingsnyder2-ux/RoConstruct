// from server: 100% by EspClaude
// roc 2007-08 004ade30  Reflection::Described<NetworkMarker, sNetworkMarker, Base>::classDescriptor() (openrbx reflection.h)
// roc-flags: /O2 /GS /EHsc /MD
namespace RBX {
namespace Reflection {
class ClassDescriptor {
public:
    ClassDescriptor(ClassDescriptor& base, const char* name);
    ~ClassDescriptor();
};
template <class T, const char* sName, class Base>
class Described : public Base
{
public:
    static ClassDescriptor& classDescriptor()
    {
        static ClassDescriptor foo(Base::classDescriptor(), sName);
        return foo;
    }
};
}
class Instance {
public:
    static Reflection::ClassDescriptor& classDescriptor();
};
namespace Network {
extern const char sNetworkMarker[];
class NetworkMarker;
}
template class Reflection::Described<Network::NetworkMarker, Network::sNetworkMarker, Instance>;
}
