// from server: 77% by Intel
struct DescribedBase;
struct PropertyDescriptor;

struct GetSet
{
    virtual bool isReadOnly() const;
    virtual bool isWriteOnly() const;
    virtual void getValue(const DescribedBase* object) const;
    virtual void setValue(DescribedBase* object, const void* value) const;
};

struct BoundPropGetSet : GetSet
{
    char pad0[4];
    int desc;
    int member;
    int changed;
    void setValue(DescribedBase* object, const void* value) const;
};

extern "C" int __stdcall sub_743730(int a, int b);
extern "C" void __stdcall sub_414da0(int a);
extern "C" void __stdcall sub_b22658(int a);

void BoundPropGetSet::setValue(DescribedBase* object, const void* value) const
{
    int obj = (int)object;
    int base;
    if (obj != 0)
        base = obj - 0x1c;
    else
        base = 0;

    int m = *(int*)((char*)this + 8);
    int val = (int)value;
    if (sub_743730(m + base, val))
    {
        int target = *(int*)((char*)this + 8) + base;
        int vtable_func = *(int*)target;
        ((void (__thiscall*)(int))vtable_func)(target);
        *(int*)(target + 0x1c) = *(int*)(val + 0x1c);

        int ch = *(int*)((char*)this + 0x10);
        if (ch != 0)
        {
            int d = *(int*)((char*)this + 4);
            ((void (__stdcall*)(int))ch)(d);
        }
        sub_414da0(*(int*)((char*)this + 4));
    }
}
