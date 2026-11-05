// from server: 54% by atomic.potato
struct S
{
    int f();
};

extern "C" int sub_502c30(void *);
extern "C" void sub_65bce0(void *, int *, int);

int S::f()
{
    int value = sub_502c30((char *)this + 0xb8);
    sub_65bce0(this, &value, 0);
    return value;
}
