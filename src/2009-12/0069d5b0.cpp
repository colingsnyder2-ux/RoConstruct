// from server: 61% by atomic.potato
extern "C" void freeze(void*, int);

struct S
{
    void f();
};

void S::f()
{
    void* p = (char*)this + 12;
    freeze(p, 1);
    *(void**)((char*)p + 32);
}
