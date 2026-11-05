// from server: 95% by atomic.potato
struct S
{
    int __cdecl f(int);
};

int S::f(int shift)
{
    int x = ((int*)this)[2] * 0x04f9ffb7;
    int y = ((int*)this)[1] * 0x0127409f;
    int z = ((int*)this)[0] * 0x0466f45d;
    return (x ^ y ^ z) & (0xffff >> shift);
}
