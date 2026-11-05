// from server: 80% by atomic.potato
extern "C" void __cdecl sub_7f4929(int);

unsigned char g_00b7b4d0;

struct S
{
    int f();
};

int S::f()
{
    g_00b7b4d0 += 0xb7;
    sub_7f4929(0);
    return 0xb7b4a4;
}
