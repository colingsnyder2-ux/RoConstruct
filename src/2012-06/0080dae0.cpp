// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct DescribedBase { int x; };
struct A { char pad[0x1c]; };
struct B { int y; };
struct Obj : A, DescribedBase, B {
    void set(int);
};
struct GetSetImpl {
    void (Obj::*setter)(int);
    virtual void setValue(DescribedBase* object, const int& value) const;
};
void GetSetImpl::setValue(DescribedBase* object, const int& value) const
{
    (static_cast<Obj*>(object)->*setter)(value);
}
