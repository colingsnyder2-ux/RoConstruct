// from server: 82% by atomic.potato
struct S_func_006c93c0 {
};

int __cdecl f(char c)
{
    unsigned char v = (unsigned char)c;
    if (v >= 0x21 && v <= 0x7e)
        return 1;
    if (v == 0x20 || v == 9 || v == 10)
        return 1;
    return 0;
}
