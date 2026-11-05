// from server: 24% by atomic.potato
struct CXTPPropertyGridItem
{
    char pad[0x90];
    int m_nValue;
    void OnValueChanged(int value);
    void SetValue(int value);
};

struct VColor3
{
    void sub_443700();
    void sub_446010(int a, int b);
    void sub_87a0c0(int a);
    void sub_446a80(int a, int b);
};

extern "C" void *__stdcall sub_a404cc(int a);
extern "C" void __stdcall sub_a42e00(void *a, void *b);

void VColor3::sub_446a80(int a, int b)
{
    char *self = (char *)this;
    int *p = (int *)a;
    void *q = sub_a404cc(*(int *)(a + 4) + 4);
    sub_a42e00(q, 0);
    sub_443700();
    sub_446010(*(int *)(self + 0x24), a);
    *(int *)(self + 0xfc) = 1;
    *(int *)self = 0xa69944;
    *(int *)(self + 0x20) = 0xa698e4;
    *(int *)(self + 0x118) = 0xa698dc;
    *(int *)(self + 0x130) = a;
    int (*fp)(void *) = *(int (**)(void *))(*p + 4);
    int r = fp((void *)a);
    sub_87a0c0(r & 0xff);
}
