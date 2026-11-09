// from server: 100% by atomic.potato
struct S {
    long __stdcall f(void* out);
};

long __stdcall S::f(void* out)
{
    if (out == 0)
        return (long)0x80004003;
    *(unsigned long*)((char*)out + 0) = *(unsigned long*)0x9a0ca4;
    *(unsigned long*)((char*)out + 4) = *(unsigned long*)0x9a0ca8;
    *(unsigned long*)((char*)out + 8) = *(unsigned long*)0x9a0cac;
    *(unsigned long*)((char*)out + 12) = *(unsigned long*)0x9a0cb0;
    return 0;
}
