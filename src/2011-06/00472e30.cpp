// from server: 100% by atomic.potato
extern "C" void __cdecl Dispatch(void* a, int b, int c);

struct S
{
};

void __cdecl f(void* a, int b, int c)
{
    if (c != 4)
    {
        Dispatch(a, b, c);
        return;
    }

    *(int*)b = 0x00C157E0;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}
