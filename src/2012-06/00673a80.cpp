// from server: 36% by atomic.potato
extern "C" void __cdecl sub_673b60(int, int, unsigned char);

struct S
{
    void __cdecl f(int, int);
};

void S::f(int a, int b)
{
    unsigned char c = 0;
    sub_673b60(a, b, c);
}
