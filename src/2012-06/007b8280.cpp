// from server: 90% by atomic.potato
struct VForceFieldFactoryProduct
{
    void f();
};

void VForceFieldFactoryProduct::f()
{
    *(int*)this = 0x00bb9d04;
    *((int*)this + 1) = 0x00bb9cfc;
    *((int*)this + 6) = 0x00bb9cf0;
    *((int*)this + 7) = 0x00bb9ce4;
}
