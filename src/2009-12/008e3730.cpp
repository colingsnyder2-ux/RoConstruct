// from server: 54% by atomic.potato
struct S
{
    void f(void *);
};

extern "C" void sub_008e3450(void *);
extern "C" void sub_008c3b80(void *);

void S::f(void *p)
{
    sub_008e3450(this);
    sub_008c3b80(this);
}
