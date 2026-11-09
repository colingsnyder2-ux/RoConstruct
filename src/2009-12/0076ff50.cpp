// from server: 67% by atomic.potato
struct S {
    char value;
    void f(char);
};

void S::f(char v)
{
    if (*(unsigned char *)((char *)this + 0x2bc) != (unsigned char)v) {
        *(unsigned char *)((char *)this + 0x2bc) = (unsigned char)v;
        *(unsigned long *)((char *)this + 0x2bc) = 0xb983b0;
    }
}
