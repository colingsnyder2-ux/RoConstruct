// from server: 79% by atomic.potato
struct S {
    unsigned char a[0x15];
    void f(unsigned char, unsigned char, unsigned char);
};

void S::f(unsigned char, unsigned char, unsigned char c)
{
    if (a[0x14] && a[9] && c == a[8]) {
        ((void (*)(void))0)();
        a[0x14] = 0;
    }
}
