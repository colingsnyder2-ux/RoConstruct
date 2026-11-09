// from server: 69% by atomic.potato
extern "C" void sub_4097c0(void *, void *);

struct S {
    S *clone(S *);
};

S *S::clone(S *arg)
{
    sub_4097c0(this, arg);
    *(unsigned long *)((char *)this + 0x3c) = 0x99fd90;
    *(unsigned long *)this = 0x99ff64;
    *(unsigned long *)((char *)this + 0x28) = 0x99ff5c;
    *(unsigned long *)((char *)this + 0x3c) = 0x99ff4c;
    return this;
}
