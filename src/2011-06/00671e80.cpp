// from server: 87% by atomic.potato
extern "C" void sub_6A3AF0(void*, unsigned char);
extern "C" void sub_411F60(void*, const void*);

struct ActionStation
{
    void f(unsigned char value);
};

void ActionStation::f(unsigned char value)
{
    unsigned char* p = *(unsigned char**)((char*)this + 0x168);
    if (value != p[0x115])
    {
        sub_6A3AF0(this, value);
        sub_411F60(this, (const void*)0x00CCDFF0);
    }
}
