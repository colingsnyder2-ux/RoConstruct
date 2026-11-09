// from server: 84% by atomic.potato
extern "C" void __stdcall imported_call(void *);
extern "C" void __stdcall destroy_string(void *);

struct S_func_00792d70 {
    char pad[0xc020];
    S_func_00792d70 *f(int);
};

S_func_00792d70 *S_func_00792d70::f(int value)
{
    *((unsigned long *)this) = 0xbb2a1c;
    imported_call((char *)this + 0xc020);
    if (value & 1)
        destroy_string(this);
    return this;
}
