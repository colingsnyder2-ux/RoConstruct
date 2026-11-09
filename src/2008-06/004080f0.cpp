// from server: 100% by king_originala
struct Interface;

struct InterfaceTable {
    void *unused;
    unsigned long (__stdcall *AddRef)(Interface *);
};

struct Interface {
    InterfaceTable *table;
};

struct Cache {
    unsigned char padding[12];
    Interface *value;
    long initialize(unsigned long locale);
};

extern Cache cache;

long __stdcall GetTypeInfo(void *object, unsigned int index,
                           unsigned long locale, Interface **output)
{
    if (index != 0)
        return 0x8002000BL;

    if (!output)
        return 0x80004003L;

    long result = 0;
    if (!cache.value)
        result = cache.initialize(locale);

    *output = cache.value;
    if (cache.value) {
        cache.value->table->AddRef(cache.value);
        result = 0;
    }
    return result;
}
