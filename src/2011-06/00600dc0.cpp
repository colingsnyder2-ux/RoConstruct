// from server: 92% by atomic.potato
struct S
{
    void *value;
    void f();
};

extern "C" void __cdecl target(void *, void *, void *, int, int);

void S::f()
{
    target(*(void **)((char *)this + 0x44), 0, (void *)0x00c071f8,
           (int)0x00c0a510, 0);
}
