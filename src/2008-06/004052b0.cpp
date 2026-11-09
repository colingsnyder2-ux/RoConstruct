// from server: 100% by king_originala
struct TypeInfo {
    virtual long __stdcall QueryInterface(void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
};

struct TypeInfoCache {
    unsigned long reserved[3];
    TypeInfo* info;
    long Load(unsigned long locale);
};

extern TypeInfoCache cache;

struct S {
    long __stdcall GetTypeInfo(unsigned int index,
                              unsigned long locale,
                              TypeInfo** result);
};

long __stdcall S::GetTypeInfo(unsigned int index,
                             unsigned long locale,
                             TypeInfo** result)
{
    if (index != 0)
        return (long)0x8002000B;
    if (result == 0)
        return (long)0x80004003;

    long status = 0;
    if (cache.info == 0)
        status = cache.Load(locale);

    *result = cache.info;
    if (cache.info != 0) {
        cache.info->AddRef();
        status = 0;
    }
    return status;
}
