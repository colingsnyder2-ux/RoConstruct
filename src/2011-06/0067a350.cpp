// from server: 22% by atomic.potato
struct FactoryProduct
{
    void *padding[17];
    void *field44;
    int f();
};

int FactoryProduct::f()
{
    void *p = field44;
    if (p != 0 && *((unsigned char *)p + 0x130) != 0)
        return 0;
    return 0;
}
