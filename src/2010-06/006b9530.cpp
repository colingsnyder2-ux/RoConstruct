// from server: 60% by colin
struct DescribedBase {};

struct GetSet {
    virtual bool isReadOnly() const;
    virtual bool isWriteOnly() const;
    virtual void getValue(const DescribedBase*) const;
    virtual void setValue(DescribedBase*, const void*) const;
};

struct BoundPropGetSet {
    GetSet base;
    int desc;
    int member;
    int changed;
    void setValue(DescribedBase* object, const float* value);
};

extern "C" void __stdcall raisePropertyChanged(int);

void BoundPropGetSet::setValue(DescribedBase* object, const float* value)
{
    char* c = object ? (char*)object - 0x1c : 0;
    float* m = (float*)(*(int*)((char*)this + 8) + (int)c);
    if (m[0] != value[0] || m[1] != value[1] || m[2] != value[2])
    {
        m[0] = value[0];
        m[1] = value[1];
        m[2] = value[2];
        void (__stdcall* fn)(int) = (void (__stdcall*)(int))*(int*)((char*)this + 0x10);
        if (fn)
        {
            int a = *(int*)((char*)this + 4);
            int b = *(int*)((char*)this + 0x14) + (int)c;
            fn(a);
        }
        int d = *(int*)((char*)this + 4);
        raisePropertyChanged(d);
    }
}
