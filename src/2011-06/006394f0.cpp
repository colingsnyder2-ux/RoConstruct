// from server: 57% by atomic.potato
struct P8BaseScript_GetSetImpl {
    char pad[8];
    int (__stdcall *fn)(void *);
    int offset;
    int method(int, int);
};

extern "C" void __stdcall sub_a404c8(void *, const void *);

int P8BaseScript_GetSetImpl::method(int a, int b)
{
    int local = 0;
    int *p = (int *)a;
    if (p != 0)
        local = (int)((char *)p - 0x1c);
    int *obj = (int *)((char *)this + 8);
    int (__stdcall *f)(void *) = (int (__stdcall *)(void *))obj[1];
    int r = f((char *)local + obj[0]);
    sub_a404c8((void *)b, (const void *)r);
    *(int *)(b + 0x1c) = *(int *)(r + 0x1c);
    return b;
}
