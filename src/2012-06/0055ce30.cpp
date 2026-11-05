// from server: 62% by atomic.potato
extern "C" void G1_func_005372c0(void *);

struct EventDesc
{
    void *field_2c;
    void __thiscall f(void *);
};

void __thiscall EventDesc::f(void *value)
{
    if (value)
        G1_func_005372c0((char *)field_2c + ((char *)value - (char *)0) - 0x1c);
    else
        G1_func_005372c0(field_2c);
}
