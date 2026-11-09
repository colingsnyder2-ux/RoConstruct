// from server: 100% by atomic.potato
extern "C" void __stdcall sub_007f49a4(void *, int, int, void *);

struct BeveledBlockBuilder
{
    void f();
};

void BeveledBlockBuilder::f()
{
    sub_007f49a4((char *)this + 0x5ce8, 0x18, 6, (void *)0x522c10);
}
