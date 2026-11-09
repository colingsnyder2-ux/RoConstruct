// from server: 100% by king_originala
struct ValueSource {
    virtual void slot0();
    virtual void slot1();
    virtual unsigned int get(void*);
};

struct EnumTable {
    char padding[0xdc];
    int* begin;
    int* volatile end;
};

extern void __cdecl initializeOnce(void (__cdecl*)(), int*);
extern EnumTable* __cdecl getTable();
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Descriptor {
    char padding[0x1c];
    ValueSource* source;
    int lookup(void*);
};

int Descriptor::lookup(void* object)
{
    unsigned int index = source->get(object);
    initializeOnce(
        reinterpret_cast<void (__cdecl*)()>(0x5ed690),
        reinterpret_cast<int*>(0x97b120));
    EnumTable* table = getTable();

    if (index < static_cast<unsigned int>(table->end - table->begin)) {
        if (index >= static_cast<unsigned int>(table->end - table->begin))
            _invalid_parameter_noinfo();
        return table->begin[index];
    }

    return -1;
}
