// from server: 40% by atomic.potato
extern "C" void __cdecl sub_983270(void*, unsigned int, unsigned int, const void*);

struct seg_00aa0000
{
    void f();
};

void seg_00aa0000::f()
{
    char buffer[488];
    sub_983270(buffer, 0x20, 6, (const void*)0x7dd040);
}
