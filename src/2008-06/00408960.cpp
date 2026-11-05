// from server: 100% by king_originala
extern "C" int __cdecl sub_406300(char*, char*, unsigned int*, unsigned int);

struct VCContent_CComAggObject
{
    void Init();
    int sub_4082B0(int);
    void f(int, unsigned int);
};

void VCContent_CComAggObject::f(int value, unsigned int flags)
{
    Init();
    int result = sub_4082B0(value);
    if (!(flags & 5) || !result)
        return;

    unsigned int* count = (unsigned int*)((char*)this + 0x1234);
    if (*count > 0)
    {
        char* buffer = (char*)this + 0x122;
        if (!sub_406300(buffer, buffer, count, 0x81))
            return;
        --*count;
    }

    count = (unsigned int*)((char*)this + 0x1238);
    if (*count > 0)
    {
        char* buffer = (char*)this + 0x1A3;
        if (!sub_406300(buffer, buffer, count, 0x81))
            return;
        --*count;
    }

    count = (unsigned int*)((char*)this + 0x1230);
    if (*count > 0)
    {
        char* buffer = (char*)this + 0x21;
        if (!sub_406300(buffer, buffer, count, 0x101))
            return;
        --*count;
    }

    count = (unsigned int*)((char*)this + 0x123C);
    if (*count > 0)
    {
        char* buffer = (char*)this + 0x224;
        if (!sub_406300(buffer, buffer, count, 0x801))
            return;
        --*count;
    }

    count = (unsigned int*)((char*)this + 0x1240);
    if (*count > 0)
    {
        char* buffer = (char*)this + 0xA25;
        if (!sub_406300(buffer, buffer, count, 0x801))
            return;
        --*count;
    }
}
