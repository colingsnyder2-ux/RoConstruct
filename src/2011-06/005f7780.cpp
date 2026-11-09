// from server: 25% by atomic.potato
struct S_func_005f7780
{
    unsigned char pad[36];
    unsigned int __stdcall f();
};

unsigned int __stdcall S_func_005f7780::f()
{
    unsigned int value;
    value &= 0xc;
    *(unsigned int *)(this->pad + 36) = value;
    return (unsigned int)this;
}
