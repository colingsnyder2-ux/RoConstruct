// from server: 77% by atomic.potato
extern "C" void __cdecl sub_006a5fc0(void *);
extern "C" void __cdecl sub_00411f60(void *, const void *);

struct S_func_006c8d00 {
    char f();
};

char S_func_006c8d00::f()
{
    sub_006a5fc0(this);
    sub_00411f60(this, (const void *)0x00cd0f6c);
    sub_00411f60(this, (const void *)0x00cd0f28);
    return 0;
}
