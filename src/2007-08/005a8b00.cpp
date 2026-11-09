// from server: 100% by EspClaude
// roc 2007-08 005a8b00  RBX::Reflection::BoundProp<float,1>::BoundPropGetSet<Class>::setValue (reflection/property.h)
// 2007 exe: Class has a virtual base (vbptr @+0x108) so T Class::* is {mdisp,vbindex} and void (Class::*)() is {fn,mdisp,vbindex}.
// roc-flags: /O2 /GS /EHsc /MD /fp:fast
namespace RBX {
namespace Reflection {
class PropertyDescriptor { public: virtual ~PropertyDescriptor(); };
class DescribedBase { public: virtual ~DescribedBase(); int a; const void* descriptor; };
template<class T> class TypedPropertyDescriptor : public PropertyDescriptor {
public:
    class GetSet {
    public:
        virtual bool isReadOnly() const = 0;
        virtual T getValue(const DescribedBase* instance) const = 0;
        virtual void setValue(DescribedBase* instance, const T& value) const = 0;
    };
};
template<class T, int bound>
class BoundProp : public TypedPropertyDescriptor<T> {
public:
    template<class Class>
    class BoundPropGetSet : public TypedPropertyDescriptor<T>::GetSet {
    public:
        BoundPropGetSet(BoundProp<T, bound>* desc, T Class::* member, void (Class::*changed)(const PropertyDescriptor&))
            : desc(desc), member(member), changed(changed) {}
        virtual bool isReadOnly() const { return false; }
        virtual T getValue(const DescribedBase* instance) const { return static_cast<const Class*>(instance)->*member; }
        virtual void setValue(DescribedBase* instance, const T& value) const
        {
            Class* object = static_cast<Class*>(instance);
            if (object->*member != value) {
                object->*member = value;
                if (changed != 0)
                    (object->*changed)(*desc);
                object->raisePropertyChanged(*desc);
            }
        }
    private:
        BoundProp<T, bound>* desc;
        T Class::* member;
        void (Class::*changed)(const PropertyDescriptor&);
    };
};
}
class V0 { public: virtual ~V0(); };
class ExePad { public: virtual ~ExePad(); char pad[0x108 - 0x10 - 4]; };
class VirtualBase { public: virtual ~VirtualBase(); int v; };
class Humanoid : public V0, public Reflection::DescribedBase, public ExePad, public virtual VirtualBase {
public:
    float value;
    void raisePropertyChanged(const Reflection::PropertyDescriptor& desc);
};
template class Reflection::BoundProp<float, 1>::BoundPropGetSet<Humanoid>;
}
