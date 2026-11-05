// from server: 43% by atomic.potato
extern "C" void bad_cast_destructor(void*);

struct S
{
    void f();
};

void S::f()
{
    *(int*)((char*)this + 0) = 0x00a5c24c;
    *(int*)((char*)this + 0x0c) = 0x00a5c244;
    *(int*)((char*)this + 0x0c) = 0x00a5bfdc;

    void* p = *(void**)((char*)this + 0x10);
    if (p != 0)
        bad_cast_destructor(p);
}
