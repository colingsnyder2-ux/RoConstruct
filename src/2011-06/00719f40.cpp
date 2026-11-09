// from server: 100% by atomic.potato
extern "C" void __stdcall Function719ec0(void *);
extern "C" void __stdcall Function719d80(void *);

struct TypedPropertyDescriptor
{
    void __stdcall f(void *);
};

void __stdcall TypedPropertyDescriptor::f(void *value)
{
    unsigned char *p = (unsigned char *)value;
    if (p[0x2f6] != 0)
        Function719ec0(value);
    else
        Function719d80(value);
}
