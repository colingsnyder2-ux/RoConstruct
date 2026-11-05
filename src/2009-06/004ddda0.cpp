// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost { template<class T> class shared_ptr { public: T* get() const { return px; } T* px; void* pn; }; }
namespace RBX {
class DescribedBase { public: virtual ~DescribedBase(); };
class InstanceBase { public: virtual ~InstanceBase(); char pad[0x14]; };
class Instance : public InstanceBase, public DescribedBase { };
namespace Reflection {
class RefPropertyDescriptor { public:
    virtual void v0() const; virtual void v1() const; virtual void v2() const; virtual void v3() const;
    virtual void v4() const; virtual void v5() const; virtual void v6() const; virtual void v7() const;
    virtual void v8() const; virtual void v9() const; virtual void v10() const; virtual void v11() const;
    virtual void v12() const;
    virtual void setRefValue(DescribedBase* instance, DescribedBase* value) const;
};
}
namespace Network {
class IdSerializer {
public:
    struct WaitItem {
        const Reflection::RefPropertyDescriptor* desc;
        Instance* instance;
    };
    static void __stdcall setRefValue(WaitItem& wi, Instance* instance);
};
void __stdcall IdSerializer::setRefValue(WaitItem& wi, Instance* instance)
{
    wi.desc->setRefValue(wi.instance, instance);
}
}
}
