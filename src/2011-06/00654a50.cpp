// from server: 80% by atomic.potato
extern "C" void __cdecl boost_thread_destructor(void*);
extern "C" void __cdecl func_0080a058(void*);

struct S
{
    void f();
    char padding[12];
    void* member;
};

void S::f()
{
    void* value = member;
    if (value)
    {
        boost_thread_destructor(value);
        func_0080a058(value);
    }
}
