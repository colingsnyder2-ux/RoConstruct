// from server: 60% by atomic.potato
struct CXTIconHandle {
    int __stdcall f(int* result, unsigned int offset, unsigned int length);
};

int __stdcall CXTIconHandle::f(int* result, unsigned int offset, unsigned int length)
{
    if (length > 0xffffffffU - offset)
        return (int)0x80070057U;
    *result = (int)(offset + length);
    return 0;
}
