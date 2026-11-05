// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD

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
