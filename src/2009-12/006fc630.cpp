// from server: 63% by atomic.potato
extern "C" void sub_007bbf80(void*, void*, void*, void*);

struct S_func_006fc630 {
    unsigned char pad[0x15];
    unsigned char flag;

    void f(void* a1);
};

void S_func_006fc630::f(void* a1)
{
    if (flag)
    {
        void* local;
        sub_007bbf80((char*)this - 0x98, &local, (void*)0x006fc070, a1);
    }
}
