// from server: 46% by atomic.potato
extern "C" void __cdecl sub_983270(void *, int, int, unsigned long);

struct seg_00aa0000
{
    void f();
};

void seg_00aa0000::f()
{
    char local[752];
    extern unsigned long dword_b2263c;
    sub_983270(local, 28, 6, dword_b2263c);
}
