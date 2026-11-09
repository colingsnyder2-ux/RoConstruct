// from server: 52% by atomic.potato
extern "C" void __cdecl Function5076F0(void *, void *);
extern "C" void Function5B08C0(void *);

struct S
{
    void f(void *);
};

void S::f(void *arg)
{
    void *local;
    local = 0;
    Function5076F0(&local, arg);
    Function5B08C0(this);
}
