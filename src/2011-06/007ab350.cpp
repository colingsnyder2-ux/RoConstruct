// from server: 68% by atomic.potato
extern "C" void __cdecl free(void*);

struct S
{
    void f();
};

void S::f()
{
    void** p = (void**)this;
    while (*p)
    {
        void* value = *p;
        void* next = *(void**)((char*)value + 0x0c);
        free(value);
        *p = next;
    }
}
