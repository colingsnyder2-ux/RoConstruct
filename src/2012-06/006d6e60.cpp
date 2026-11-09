// from server: 82% by atomic.potato
struct S
{
    S* f(void*);
};

S* S::f(void* p)
{
    S* r = this;
    r->S::f(p);
    *(unsigned long*)((char*)r + 0x28) = 0x00B43C34;
    *(unsigned long*)r = 0x00B99008;
    *(unsigned long*)((char*)r + 0x14) = 0x00B99000;
    *(unsigned long*)((char*)r + 0x28) = 0x00B98FF0;
    return r;
}
