// from server: 66% by atomic.potato
struct S_func_00647400 {
    char pad0[256];
    int f();
};

extern "C" void sub_007f8c90(void *);

int S_func_00647400::f()
{
    sub_007f8c90((char *)this + 0x100);
    sub_007f8c90((char *)this + 0x104);
    return 0;
}
