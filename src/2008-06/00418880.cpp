// from server: 100% by king_originala
struct IID
{
    unsigned long words[4];
};

struct Interface;

struct InterfaceTable
{
    long (__stdcall *query)(Interface*, const IID&, void**);
    unsigned long (__stdcall *addRef)(Interface*);
};

struct Interface
{
    InterfaceTable* table;
};

extern unsigned char interfaceMap[];
extern "C" long __stdcall internalQueryInterface(
    void*, const void*, const IID&, void**);

long __stdcall queryInterface(Interface* object, const IID& iid, void** result)
{
    if (!result)
        return (long)0x80004003UL;

    *result = 0;
    long status = 0;

    if (iid.words[0] == 0 &&
        iid.words[1] == 0 &&
        iid.words[2] == 0x000000c0UL &&
        iid.words[3] == 0x46000000UL)
    {
        *result = object;
        object->table->addRef(object);
    }
    else
    {
        status = internalQueryInterface(
            (unsigned char*)object + 8, interfaceMap, iid, result);
    }

    return status;
}
