// from server: 100% by atomic.potato
extern "C" void __cdecl sub_8d2f70();

struct FactoryProduct
{
    void method();
};

void FactoryProduct::method()
{
    *(unsigned int*)this = 0xbe5e2c;
    *((unsigned int*)this + 1) = 0xbe5e24;
    *((unsigned int*)this + 6) = 0xbe5e18;
    *((unsigned int*)this + 7) = 0xbe5e0c;
    *((unsigned int*)this + 32) = 0xbe5dfc;
    *((unsigned int*)this + 33) = 0xbe5dd0;
    sub_8d2f70();
}
