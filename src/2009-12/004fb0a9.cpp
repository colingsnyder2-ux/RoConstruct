// from server: 57% by atomic.potato
extern "C" void __cdecl call_6c7390(int, int);

struct S
{
    unsigned char pad14[0x15];
    int value24;
    int pad28[2];
    int value34;
    int f();
};

int S::f()
{
    int result;
    if (pad14[0x14] != 0)
    {
        call_6c7390(value34, value24);
        result = 0;
        return 0x4fb0c5;
    }
    return 0x4fb0c5;
}
