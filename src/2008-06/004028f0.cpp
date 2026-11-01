// from server: 100% by king_originala
struct IID {
    unsigned long words[4];
};

struct Interface;

struct VTable {
    long (__stdcall *QueryInterface)(Interface *, const IID &, void **);
    unsigned long (__stdcall *AddRef)(Interface *);
};

struct Interface {
    VTable *vtable;
};

extern const unsigned char interfaceMap[];
extern "C" long __stdcall InternalQueryInterface(
    void *, const void *, const IID &, void **);

long __stdcall QueryInterface(Interface *object, const IID &iid, void **output)
{
    if (!output)
        return (long)0x80004003UL;

    *output = 0;
    long result = 0;

    if (iid.words[0] == 0 &&
        iid.words[1] == 0 &&
        iid.words[2] == 0x000000C0UL &&
        iid.words[3] == 0x46000000UL)
    {
        *output = object;
        object->vtable->AddRef(object);
    }
    else
    {
        result = InternalQueryInterface(
            reinterpret_cast<unsigned char *>(object) + 8,
            interfaceMap, iid, output);
    }

    return result;
}
