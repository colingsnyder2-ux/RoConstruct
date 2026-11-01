// from server: 100% by king_originala
extern "C" {
extern void (__cdecl *invalid_parameter_noinfo)();
}

struct IndexProvider {
    virtual void slot0();
    virtual void slot1();
    virtual int lookup(int value);
};

struct ValueTable {
    char padding[0xac];
    void** begin;
    void** volatile end;
};

struct Descriptor {
    char padding[0x1c];
    IndexProvider* provider;
    ValueTable* table;

    void* get(int value);
};

void* Descriptor::get(int value)
{
    int index = provider->lookup(value);
    ValueTable* values = table;

    if (index < 0)
        return 0;

    if ((unsigned int)index >= (unsigned int)(values->end - values->begin))
        return 0;

    if ((unsigned int)index >= (unsigned int)(values->end - values->begin))
        invalid_parameter_noinfo();

    return values->begin[index];
}
