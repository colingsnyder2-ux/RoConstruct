// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); void* descriptor; };
template<class C, class V> class PropDescriptor {
public:
    class GetSet { public: virtual V getValue(const DescribedBase* object) const = 0; int pad; };
    template<class G, class S> class GetSetImpl : public GetSet {
    public:
        G get; S set;
        virtual V getValue(const DescribedBase* object) const;
    };
};
template<class C, class V> template<class G, class S>
V PropDescriptor<C,V>::GetSetImpl<G,S>::getValue(const DescribedBase* object) const
{
    return (static_cast<const C*>(object)->*get)();
}
}
class InstancePad { public: virtual ~InstancePad(); char pad[0x14]; };
class Message : public InstancePad, public Reflection::DescribedBase {
public:
    const std::string& getText() const;
    void setText(const std::string&);
};
template class Reflection::PropDescriptor<Message, std::string>::GetSetImpl<const std::string& (Message::*)() const, void (Message::*)(const std::string&)>;
}
