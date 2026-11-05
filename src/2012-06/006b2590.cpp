// from server: 40% by atomic.potato
struct EventDesc
{
    int f(void *);
    void *data;
};

extern "C" void __stdcall G1_func_006b0ad0(void *);

int EventDesc::f(void *arg)
{
    void *p = data;
    if (arg != 0)
        p = (char *)p + (long)arg - 0x1c;
    G1_func_006b0ad0(p);
    return 0;
}
