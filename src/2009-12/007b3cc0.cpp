// from server: 68% by atomic.potato
struct Assembly
{
    char padding[0x20];
    int field20;
    int field24;
    void sub_7b30a0(void *, void *);
    void sub_7b3c00(int);
    Assembly *ctor(void *);
};

Assembly *Assembly::ctor(void *arg)
{
    char buf[0x1c];
    sub_7b30a0(buf, arg);
    sub_7b3c00(0xf);
    field20 = 0;
    field24 = 0xf;
    return this;
}
