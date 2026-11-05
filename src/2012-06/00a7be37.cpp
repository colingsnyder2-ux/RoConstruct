// from server: 75% by atomic.potato
struct S
{
    int __cdecl f(unsigned int* p, unsigned int offset, unsigned int size);
};

int __cdecl S::f(unsigned int* p, unsigned int offset, unsigned int size)
{
    if (0xffffffffu - offset < size)
        return (int)0x80070057u;
    *p = offset + size;
    return 0;
}
