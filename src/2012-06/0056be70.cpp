// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base0 { char pad[0x1c]; };
struct Described { int d; };
struct Instance : Base0, Described { };
struct RefDesc
{
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12();
    virtual void setRefValue(Described *obj, Described *value) const;
};
struct WaitItem { const RefDesc *desc; Instance *instance; };
struct IdSerializer { static void __stdcall setRefValue(WaitItem &item, Instance *instance); };
void __stdcall IdSerializer::setRefValue(WaitItem &item, Instance *instance)
{
    item.desc->setRefValue(item.instance, instance);
}