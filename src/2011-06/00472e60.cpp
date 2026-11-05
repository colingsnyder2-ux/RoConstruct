// from server: 100% by atomic.potato
extern "C" void __cdecl sub_46FA90(int, void*, int);

struct VerbBinder
{
};

void __cdecl f(int a, void* p, int c)
{
    if (c != 4)
    {
        sub_46FA90(a, p, c);
        return;
    }

    *(int*)p = 0x00C15860;
    *((unsigned char*)p + 4) = 0;
    *((unsigned char*)p + 5) = 0;
}
