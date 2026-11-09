// from server: 18% by atomic.potato
struct S
{
    int f();
    int a;
    int b;
};

int S::f()
{
    unsigned char x = 0;
    unsigned char y = x;
    int z = b;
    return reinterpret_cast<int (__cdecl *)(int)>(a)(z);
}
