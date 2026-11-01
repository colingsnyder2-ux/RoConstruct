// from server: 100% by colin
struct CXTPOffice2003Theme {
    char pad[0x528];
    int f();
};

int CXTPOffice2003Theme::f()
{
    char *self = (char *)this;
    extern void sub_6bee10();
    sub_6bee10();
    *(void **)self = (void *)0x7d7094;
    *(int *)(self + 0x438) = 0;
    *(int *)(self + 0x524) = 1;
    return (int)this;
}
