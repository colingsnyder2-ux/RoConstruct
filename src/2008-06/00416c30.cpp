// from server: 100% by king_originala
struct Interface
{
    unsigned long (__stdcall **vtable)(Interface *);
};

struct IID
{
    unsigned long words[4];
};

extern const unsigned char interfaceMap[];

extern "C" long __stdcall queryInterface(
    void *, const unsigned char *, const IID *, void **);

long __stdcall internalQueryInterface(
    Interface *object, const IID *iid, void **result)
{
    if (!result)
        return (long)0x80004003UL;

    *result = 0;
    long status = 0;

    if (iid->words[0] == 0 &&
        iid->words[1] == 0 &&
        iid->words[2] == 0x000000C0UL &&
        iid->words[3] == 0x46000000UL)
    {
        *result = object;
        object->vtable[1](object);
    }
    else
    {
        status = queryInterface(
            (char *)object + 8, interfaceMap, iid, result);
    }

    return status;
}
