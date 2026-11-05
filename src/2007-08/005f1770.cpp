// from server: 43% by colin
struct DescribedBase;
struct PropertyDescriptor;

struct GetSet {
    virtual bool isReadOnly() const;
    virtual bool isWriteOnly() const;
    virtual void getValue(const DescribedBase* object, void* out) const;
    virtual void setValue(DescribedBase* object, const void* value) const;
};

struct BoundPropGetSet : GetSet {
    void* desc;
    unsigned int member;
    unsigned int changed;

    void setValue(DescribedBase* object, const void* value) const;
};

extern "C" void __stdcall sub_413C00(void* out);
extern "C" void __stdcall sub_414170(void* p);
extern "C" void __stdcall sub_5095D0(void* self, const void* src);

void BoundPropGetSet::setValue(DescribedBase* object, const void* value) const {
    if (*(void**)this == 0) {
        char buf[40];
        sub_413C00(buf);
        sub_414170(buf);
    }
    char tmp[48];
    sub_5095D0(tmp, value);
    *(float*)(tmp + 0x24) = *(const float*)((const char*)value + 0x24);
    *(float*)(tmp + 0x28) = *(const float*)((const char*)value + 0x28);
    *(float*)(tmp + 0x2c) = *(const float*)((const char*)value + 0x2c);
    void (*fn)(void*, const void*) = *(void (**)(void*, const void*))((const char*)this + 8);
    fn(*(void**)((const char*)this + 4), tmp);
}
