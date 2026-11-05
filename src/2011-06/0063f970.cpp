// from server: 54% by atomic.potato
struct S
{
    int f();
};

extern "C" void sub_679e70(void*);
extern "C" void sub_63f4a0(void*, int);

int S::f()
{
    sub_679e70((char*)this + 0x190);
    sub_63f4a0(this, 0);
    return 0;
}
