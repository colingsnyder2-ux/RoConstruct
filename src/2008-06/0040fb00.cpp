// from server: 100% by king_originala
struct IID {
    unsigned long words[4];
};

extern unsigned char interfaceMap[];
extern "C" long __stdcall queryInterface(
    void* object, const void* map, const IID& iid, void** result);

struct S {
    virtual long __stdcall QueryInterface(const IID& iid, void** result);
    virtual unsigned long __stdcall AddRef();
};

long __stdcall S::QueryInterface(const IID& iid, void** result)
{
    if (!result)
        return (long)0x80004003UL;

    *result = 0;
    long status = 0;

    if (iid.words[0] == 0 &&
        iid.words[1] == 0 &&
        iid.words[2] == 0x000000C0UL &&
        iid.words[3] == 0x46000000UL)
    {
        *result = this;
        AddRef();
    }
    else
    {
        status = queryInterface(
            (unsigned char*)this + 8, interfaceMap, iid, result);
    }

    return status;
}
