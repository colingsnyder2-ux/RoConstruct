// from server: 69% by atomic.potato
extern "C" void sub_44da10(void *, const void *);

struct S
{
    S(const void *);
};

S::S(const void *p)
{
    sub_44da10(this, p);
    *(unsigned long *)((char *)this + 0x3c) = 0x00b43c34;
    *(unsigned long *)this = 0x00b53210;
    *(unsigned long *)((char *)this + 0x28) = 0x00b53208;
    *(unsigned long *)((char *)this + 0x3c) = 0x00b531f8;
}
