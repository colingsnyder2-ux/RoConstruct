// from server: 100% by atomic.potato
extern "C" void FactoryProduct_tail();

struct FactoryProduct
{
    void set();
};

void FactoryProduct::set()
{
    *(int*)((char*)this + 0) = 0x9a022c;
    *(int*)((char*)this + 4) = 0x9a0224;
    *(int*)((char*)this + 0x18) = 0x9a0218;
    *(int*)((char*)this + 0x1c) = 0x9a0210;
    FactoryProduct_tail();
}
