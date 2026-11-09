// from server: 100% by king_originala
struct Interface {
    virtual long __stdcall QueryInterface(const void *, void **) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
};

struct TypeInfoHolder {
    unsigned char reserved[12];
    Interface *info;
    long Load(unsigned long locale);
};

extern TypeInfoHolder holder;

struct S {
    long __stdcall GetTypeInfo(unsigned int index, unsigned long locale,
                               Interface **result);
};

long __stdcall S::GetTypeInfo(unsigned int index, unsigned long locale,
                             Interface **result)
{
    if (index != 0)
        return (long)0x8002000B;
    if (result == 0)
        return (long)0x80004003;

    long status = 0;
    if (holder.info == 0)
        status = holder.Load(locale);

    *result = holder.info;
    if (holder.info != 0) {
        holder.info->AddRef();
        status = 0;
    }
    return status;
}
