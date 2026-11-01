// from server: 100% by colin
struct EnumTable {
    unsigned char padding0[40];
    unsigned int count;
    unsigned char padding1[152];
    int* begin;
    int* end;
};

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const int&);
};

extern unsigned char registrationState;
extern void __cdecl initialize();
extern void __cdecl registerInitializer(void (__cdecl*)(), void*);
extern EnumTable* __cdecl getEnumTable();
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Descriptor {
    unsigned char padding[28];
    Setter* setter;

    bool setValue(void*, unsigned int);
};

bool Descriptor::setValue(void* object, unsigned int index)
{
    int value;
    registerInitializer(initialize, &registrationState);
    EnumTable* table = getEnumTable();

    if (index < table->count) {
        if (index >= static_cast<unsigned int>(table->end - table->begin))
            _invalid_parameter_noinfo();

        value = table->begin[index];
        setter->set(object, value);
        return true;
    }
    return false;
}
