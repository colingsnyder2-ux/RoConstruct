// from server: 92% by atomic.potato
struct S
{
    unsigned char pad0[0x2c];
    void* field2c;
    unsigned char pad30[0x0c];
    unsigned char field3c;
    void f(void*);
};

extern "C" void __stdcall sub_760400(void*, void*);

void S::f(void* arg)
{
    if (field3c != 0)
    {
        sub_760400((char*)this - 0xb8, &field2c);
        field3c = 0;
    }
}
