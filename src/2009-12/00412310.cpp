// from server: 82% by atomic.potato
struct S
{
    S* f(void*);
};

S* S::f(void* a)
{
    S* p = this;
    p->f(a);
    *(unsigned long*)((char*)this + 0x3c) = 0x99fd90;
    *(unsigned long*)this = 0x9a2124;
    *(unsigned long*)((char*)this + 0x28) = 0x9a211c;
    *(unsigned long*)((char*)this + 0x3c) = 0x9a210c;
    return this;
}
