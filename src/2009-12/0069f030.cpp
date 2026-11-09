// from server: 93% by atomic.potato
struct S
{
    unsigned char __cdecl f(unsigned char* p);
};

unsigned char __cdecl S::f(unsigned char* p)
{
    if (p)
        return p[-23];
    return 0;
}
