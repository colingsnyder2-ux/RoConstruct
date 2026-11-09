// from server: 65% by atomic.potato
extern "C" void __cdecl sub_00983270(void *, int, int, const void *);

struct seg_00ad0000 {
    void f();
};

void seg_00ad0000::f()
{
    static const unsigned char data[1] = { 0 };
    sub_00983270((char *)this + 0x108, 0x10, 2, data);
}
