// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); void* descriptor; };
template<class C, class V> class PropDescriptor {
public:
    class GetSet { public:
        virtual V getValue(const DescribedBase* object) const = 0;
        int flags;
    };
    template<class G> class GetSetImpl : public GetSet {
    public:
        G get;
        virtual V getValue(const DescribedBase* object) const;
    };
};
template<class C, class V> template<class G>
V PropDescriptor<C,V>::GetSetImpl<G>::getValue(const DescribedBase* object) const
{
    return (static_cast<const C*>(object)->*get)();
}
}
class InstancePad { public: virtual ~InstancePad(); char pad[0x14]; };
class Pad3 { public: virtual void p3(); char pad[0x6c]; };
class VB { public: virtual void vb(); };
class Part : public InstancePad, public Reflection::DescribedBase, public Pad3, public virtual VB {
public:
    const std::string& getName2() const;
};
template class Reflection::PropDescriptor<Part, std::string>::GetSetImpl<const std::string& (Part::*)() const>;
}
