// from server: 36% by atomic.potato
extern "C" void __cdecl sub_40F520(void*);

struct TypeInfo {
    virtual bool operator==(const TypeInfo&) const;
};

struct BadCast {
    BadCast(const char*);
};

struct VReplicator {
    void* field0;
    void* field4;
    void func();
};

void VReplicator::func()
{
    TypeInfo* a = (TypeInfo*)field0;
    const TypeInfo* t1;
    if (a)
        t1 = *(const TypeInfo**)a;
    else
        t1 = (const TypeInfo*)0xD60AC8;

    if (t1 == (const TypeInfo*)0xD86094)
        return;

    TypeInfo* b;
    if (a)
        b = *(TypeInfo**)a;
    else
        b = (TypeInfo*)0xD60AC8;

    if (!b->operator==(*(const TypeInfo*)0xD86094))
        return;

    BadCast bc((const char*)0xB44128);
    *(void**)0xB44120 = (void*)0xB44120;
    sub_40F520(&bc);
}
