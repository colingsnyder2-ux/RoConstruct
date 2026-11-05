// from server: 100% by king_originala
struct Interface
{
    virtual long __stdcall Query(void* id, void** result) = 0;
};

long __stdcall f(void* source, void* id, void** result)
{
    char* object = source ? (char*)source - 12 : 0;
    long status = (long)0x80004003;
    if (result)
    {
        Interface* inner = *(Interface**)(object + 16);
        if (inner)
            return inner->Query(id, result);
        *result = 0;
        status = (long)0x80004005;
    }
    return status;
}
