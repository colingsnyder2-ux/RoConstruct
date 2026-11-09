// from server: 100% by atomic.potato
extern "C" void __cdecl sub_43c4a0(void*, void*, int);

struct Creator
{
    void __cdecl f(void*, int);
};

void Creator::f(void* a, int b)
{
    if (b != 4)
    {
        sub_43c4a0(this, a, b);
        return;
    }

    *(unsigned long*)a = 0x00d66f38;
    ((unsigned char*)a)[4] = 0;
    ((unsigned char*)a)[5] = 0;
}
