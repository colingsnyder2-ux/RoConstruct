// from server: 73% by atomic.potato
extern "C" void sub_004ABF30(void *, void *, void *, int, int);

struct S
{
    int a[55];
    void f();
};

void S::f()
{
    char x[4];
    char y[4];
    sub_004ABF30(x, y, (char *)this + 0xBC, a[49], a[54]);
}
