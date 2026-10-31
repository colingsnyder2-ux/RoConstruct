// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection {
class DescribedBase {
public:
    virtual ~DescribedBase();
    void* d1;
    void* descriptor;
};
}
class InstancePad {
public:
    virtual ~InstancePad();
    char pad[0x14];
};
class Instance : public InstancePad, public Reflection::DescribedBase {
};
namespace Reflection {
template<class Class, class T>
class GetSet {
public:
    virtual ~GetSet();
    virtual bool isReadOnly() const = 0;
    virtual T* getValue(const DescribedBase* instance) const = 0;
};
template<class Class, class T>
class RefPropDescriptor {
public:
    virtual DescribedBase* getRefValue(const DescribedBase* instance) const;
    T* getValue(const DescribedBase* instance) const { return getset->getValue(instance); }
    char pad[0x18];
    GetSet<Class, T>* getset;
};
template<class Class, class T>
DescribedBase* RefPropDescriptor<Class, T>::getRefValue(const DescribedBase* instance) const { return getValue(instance); }
template class RefPropDescriptor<Instance, Instance>;
}
}
