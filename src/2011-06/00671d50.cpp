// from server: 88% by atomic.potato
extern "C" void __cdecl sub_6A3AD0(unsigned char);
extern "C" void __cdecl sub_411F60(void*, const char*);

struct ActionStation
{
    void f(unsigned char);
};

void ActionStation::f(unsigned char value)
{
    if (value != *(unsigned char*)((char*)*(void**)((char*)this + 0x168) + 0x114))
    {
        sub_6A3AD0(value);
        sub_411F60(this, (const char*)0xCCDF84);
    }
}
