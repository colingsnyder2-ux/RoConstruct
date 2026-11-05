// from server: 18% by atomic.potato
struct S
{
    unsigned char f();
};

unsigned char S::f()
{
    unsigned char a = 0;
    unsigned char b = a;
    unsigned long v = *(unsigned long *)((char *)this + 4);
    return ((unsigned char (__cdecl *)(unsigned long))(*(unsigned long *)this))(v);
}
