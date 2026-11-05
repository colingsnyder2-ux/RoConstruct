// from server: 100% by king_originala
struct Interface;

struct InterfaceTable {
    void* first;
    unsigned long (__stdcall *addRef)(Interface*);
};

struct Interface {
    InterfaceTable* table;
};

struct Cache {
    unsigned char reserved[12];
    Interface* value;
    long initialize(unsigned long locale);
};

extern Cache cache;

struct S {
    long __stdcall f(unsigned int index, unsigned long locale, Interface** output);
};

long __stdcall S::f(unsigned int index, unsigned long locale, Interface** output)
{
    if (index != 0)
        return (long)0x8002000BUL;
    if (output == 0)
        return (long)0x80004003UL;

    long result = 0;
    if (cache.value == 0)
        result = cache.initialize(locale);

    *output = cache.value;
    if (cache.value != 0) {
        cache.value->table->addRef(cache.value);
        result = 0;
    }
    return result;
}
