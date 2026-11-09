// from server: 8% by atomic.potato
struct S {
    void f();
};

extern "C" void __stdcall sub_7f90f0();

void S::f()
{
    char buf[0x38];
    int *p = (int *)buf;
    *p = 0;
    *(int *)((char *)this) = 0;
    *(int *)(buf + 0x20) = *(int *)((char *)&buf + 0x74);
    *(int *)(buf + 0x24) = *(int *)((char *)&buf + 0x78);
    *(int *)(buf + 0x28) = *(int *)((char *)&buf + 0x7c);
    *(int *)(buf + 0x2c) = *(int *)((char *)&buf + 0x80);
    *(int *)(buf + 0x30) = *(int *)((char *)&buf + 0x84);
    sub_7f90f0();
}
