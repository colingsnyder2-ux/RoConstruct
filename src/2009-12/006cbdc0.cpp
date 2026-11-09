// from server: 100% by atomic.potato
struct S {
    int pad[90];
    int *field;
    unsigned char f();
};

unsigned char S::f()
{
    return ((unsigned char *)field)[0x100];
}
