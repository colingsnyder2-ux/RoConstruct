// from server: 75% by atomic.potato
extern "C" void sub_597d70(void *, void *);
extern "C" void sub_58a320(void *);

struct S {
    void f(void *);
};

void S::f(void *arg)
{
    sub_597d70(this, arg);
    sub_58a320((char *)this + 148);
}
