// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class TextureId { public: std::string id; int extra; };
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); void* descriptor; };
template<class V, int N> class BoundProp {
public:
    class GetSet { public: virtual V getValue(const DescribedBase* object) const = 0; int pad; };
    template<class C> class BoundPropGetSet : public GetSet {
    public:
        V C::* member;
        virtual V getValue(const DescribedBase* object) const;
    };
};
template<class V, int N> template<class C>
V BoundProp<V,N>::BoundPropGetSet<C>::getValue(const DescribedBase* object) const
{
    return static_cast<const C*>(object)->*member;
}
}
class InstancePad { public: virtual ~InstancePad(); char pad[0x14]; };
class Sky : public InstancePad, public Reflection::DescribedBase {
public:
    TextureId t;
};
template class Reflection::BoundProp<TextureId, 1>::BoundPropGetSet<Sky>;
}
