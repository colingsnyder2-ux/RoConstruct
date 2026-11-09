// from server: 51% by atomic.potato
struct P_0057a700
{
    int a;
    int b;
};

struct S_0057c0b0;

P_0057a700* fn_0057a700(S_0057c0b0*);

struct S_0057c0b0
{
    int a;
    int b;
    void* f();
};

void* S_0057c0b0::f()
{
    P_0057a700* p = fn_0057a700((S_0057c0b0*)((char*)this + 4));
    S_0057c0b0* q = (S_0057c0b0*)(((char*)this) + 4);
    q->a = p->a;
    q->b = p->b;
    return q;
}
