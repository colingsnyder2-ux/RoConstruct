// from server: 61% by atomic.potato
extern "C" void G1_func_008dcf70();

struct S
{
    void __cdecl f(void* value, int type);
};

void S::f(void* value, int type)
{
    if (type != 4)
    {
        G1_func_008dcf70();
        return;
    }

    *(unsigned long*)value = 0x00df6fa0;
    ((unsigned char*)value)[4] = 0;
    ((unsigned char*)value)[5] = 0;
}
