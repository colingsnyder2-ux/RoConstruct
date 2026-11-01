// from server: 100% by atomic.potato
extern "C" void (__cdecl *free)(void *);

struct S_func_0040d5c0
{
    void f();
    void *value;
    int count;
};

void S_func_0040d5c0::f()
{
    if (count > 0)
        free(value);
}
