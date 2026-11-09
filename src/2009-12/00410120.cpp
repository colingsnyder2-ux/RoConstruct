// from server: 69% by atomic.potato
struct S
{
    S *f(void *);
};

void SBase(void *, void *);

S *S::f(void *p)
{
    SBase(this, p);
    *(int *)((char *)this + 0x20) = 0x99fd90;
    *(int *)this = 0x9a1be0;
    *(int *)((char *)this + 0x0c) = 0x9a1bd8;
    *(int *)((char *)this + 0x20) = 0x9a1bc8;
    return this;
}
