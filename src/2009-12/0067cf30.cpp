// from server: 57% by atomic.potato
extern "C" void Call677E50(void *);
extern "C" void *Call67BC70(void *, int);
extern "C" void Call63C310(void *, int);

struct S
{
    void f(int);
};

void S::f(int)
{
    void *p = *(void **)((char *)this + 0x0c);
    Call677E50(p);
    void *q = Call67BC70((char *)this + 0x10, 1);
    Call63C310(q, 1);
}
