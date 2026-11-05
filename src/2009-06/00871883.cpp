// from server: 68% by atomic.potato
extern "C" void __cdecl sub_719B76(void *, unsigned int, unsigned int, const char *);

struct seg_00870000
{
    void f();
};

void seg_00870000::f()
{
    sub_719B76((char *)this + 0x58, 0x20, 4, "SUVW");
}
