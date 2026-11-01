// from server: 84% by atomic.potato
extern "C" void __cdecl free(void*);

struct S
{
    void f();
    void* ptr;
    int count;
};

void S::f()
{
    if (count > 0)
        free(ptr);
}
