// from server: 100% by king_originala
typedef unsigned long (__stdcall *AddRefFunction)(void *);

struct InterfaceId
{
    unsigned long words[4];
};

extern const char queryMap[];

extern "C" long __stdcall sub_402280(
    void *, const void *, const InterfaceId *, void **);

long __stdcall sub_408770(void *object, const InterfaceId *iid, void **result)
{
    if (!result)
        return (long)0x80004003;

    *result = 0;
    long status = 0;

    if (iid->words[0] == 0 &&
        iid->words[1] == 0 &&
        iid->words[2] == 0xC0 &&
        iid->words[3] == 0x46000000)
    {
        *result = object;
        (*(AddRefFunction **)object)[1](object);
    }
    else
    {
        status = sub_402280(
            (char *)object + 8, queryMap, iid, result);
    }

    return status;
}
