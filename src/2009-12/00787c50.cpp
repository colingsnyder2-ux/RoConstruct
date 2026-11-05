// from server: 78% by atomic.potato
struct S
{
    int f(void *);
};

extern "C" void call_6cba50(void *);
extern "C" void call_71d4e0(void *);
extern "C" void call_6cba70(void *);

int S::f(void *p)
{
    call_6cba50(*(void **)p);
    call_71d4e0(p);
    call_6cba70(*(void **)p);
    return 0;
}
