// from server: 60% by atomic.potato
extern "C" void __cdecl sub_4f6fc0(void *);
extern "C" void __cdecl sub_4f1a20(void *, void *);

void function_004f85a0(void *arg)
{
    char local[48];
    sub_4f6fc0(local);
    sub_4f1a20(arg, local);
}
