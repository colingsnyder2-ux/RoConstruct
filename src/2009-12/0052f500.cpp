// from server: 57% by atomic.potato
struct S
{
    S* p;
    char padding[0x15d];
    unsigned char flag;
    char padding2[2];
    S* next;
    void f();
};

void S::f()
{
    S* p = this;
    while (!p->flag)
        p = p->next;
}
