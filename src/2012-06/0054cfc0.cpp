// from server: 100% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __cdecl sub_54ced0(int, int, int);

struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        sub_54ced0(a, b, c);
        return;
    }

    *(DWORD*)b = 0x00d846c0;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}
