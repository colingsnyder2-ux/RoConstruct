// from server: 100% by atomic.potato
extern "C" void __cdecl Function_0046fbc0(int, int, int);

struct CSelectionCaption
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        Function_0046fbc0(a, b, c);
        return;
    }

    *(int*)b = 0x00b0b8d0;
    *((char*)b + 4) = 0;
    *((char*)b + 5) = 0;
}
