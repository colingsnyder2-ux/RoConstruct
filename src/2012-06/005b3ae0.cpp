// from server: 50% by atomic.potato
extern "C" void __cdecl Function5076F0(void *, void *);
extern "C" void Function5B3530(void *);

struct S {
    void f(void *);
};

void S::f(void *arg)
{
    char local[8];
    Function5076F0(local + 8, local);
    Function5B3530(this);
}
