// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); void* descriptor; };
template<class C, class V> class PropDescriptor {
public:
    class GetSet { public: virtual V getValue(const DescribedBase* object) const = 0; virtual void setValue(DescribedBase* object, const V& value) const = 0; int pad; };
    template<class G, class S> class GetSetImpl : public GetSet {
    public:
        G get; S set;
        virtual V getValue(const DescribedBase* object) const;
        virtual void setValue(DescribedBase* object, const V& value) const;
    };
};
template<class C, class V> template<class G, class S>
V PropDescriptor<C,V>::GetSetImpl<G,S>::getValue(const DescribedBase* object) const
{
    return (static_cast<const C*>(object)->*get)();
}
template<class C, class V> template<class G, class S>
void PropDescriptor<C,V>::GetSetImpl<G,S>::setValue(DescribedBase* object, const V& value) const
{
    (static_cast<C*>(object)->*set)(value);
}
}
class InstancePad { public: virtual ~InstancePad(); char pad[0x14]; };
class DebugSettings : public InstancePad, public Reflection::DescribedBase {
public:
    bool getX() const;
    void setX(bool);
};
template class Reflection::PropDescriptor<DebugSettings, bool>::GetSetImpl<bool (DebugSettings::*)() const, void (DebugSettings::*)(bool)>;
}
