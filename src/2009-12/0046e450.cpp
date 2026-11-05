// from server: 100% by atomic.potato
struct CScriptDoc
{
};

extern "C" void __cdecl G1_func_0046df60(int, int, int);

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        G1_func_0046df60(a, b, c);
        return;
    }

    *(int*)b = 0x00b0b750;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}
