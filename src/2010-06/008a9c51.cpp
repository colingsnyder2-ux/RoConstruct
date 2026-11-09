// from server: 65% by atomic.potato
struct CXTIconHandle
{
    long __stdcall f(unsigned long* result, unsigned long offset, unsigned long size);
};

long __stdcall CXTIconHandle::f(unsigned long* result, unsigned long offset, unsigned long size)
{
    if (0xffffffffUL - offset < size)
        return (long)0x80070057UL;

    *result = offset + size;
    return 0;
}
