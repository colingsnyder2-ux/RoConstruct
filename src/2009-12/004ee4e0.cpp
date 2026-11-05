// from server: 36% by atomic.potato
extern "C" void __cdecl sub_4EE650(int, int, unsigned char);

struct S
{
    void __cdecl f(int a, int b);
};

void S::f(int a, int b)
{
    unsigned char c = 0;
    sub_4EE650(a, b, c);
}
