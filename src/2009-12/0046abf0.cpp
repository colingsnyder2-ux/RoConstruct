// from server: 100% by atomic.potato
struct S
{
    void f();
};

struct T
{
    void a(int);
    void b(int);
};

void S::f()
{
    T* p = (T*)((char*)this + 0x58);
    p->a(1);
    p->b(1);
}
