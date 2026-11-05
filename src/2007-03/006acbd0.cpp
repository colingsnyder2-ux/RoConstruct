// from server: 100% by tester
struct CXTPOffice2003Theme {
    char pad[0x6aa0d0];
    int f();
};

int CXTPOffice2003Theme::f()
{
    char *self = (char *)this;
    extern void sub_6bee10();
    sub_6bee10();
    *(void **)self = (void *)0x7d3e6c;
    *(int *)(self + 0x434) = 0;
    *(int *)(self + 0x520) = 1;
    return (int)this;
}