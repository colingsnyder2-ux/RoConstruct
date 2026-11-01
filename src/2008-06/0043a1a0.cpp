// from server: 100% by atomic.potato
extern "C" int __stdcall f(unsigned char *a, unsigned char *b)
{
    return *a == *b;
}
