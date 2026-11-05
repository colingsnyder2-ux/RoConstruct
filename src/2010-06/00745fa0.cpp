// from server: 90% by atomic.potato
extern "C" void (__thiscall *sub_507510)(void *);

extern "C" void __cdecl sub_637210(void *, void *, void *);

struct AsyncHttpQueue
{
    void *f(void *, void *);
};

void *AsyncHttpQueue::f(void *a, void *b)
{
    sub_507510(a);
    sub_637210(this, b, a);
    return a;
}
