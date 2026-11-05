// from server: 71% by atomic.potato
extern "C" float __fastcall sub_7506d0(void*);

struct S
{
    unsigned char pad[132];
    void* value;
    float f();
};

float S::f()
{
    extern unsigned char flag;
    if (!flag)
    {
        volatile float result = 0.0f;
        return result;
    }
    return sub_7506d0((void*)((char*)value + *(unsigned int*)value + 132));
}
