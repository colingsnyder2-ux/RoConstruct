// from server: 18% by atomic.potato
struct T
{
    void f(float, float);
};

struct S
{
    void f(float, float);
};

void T::f(float, float)
{
}

void S::f(float a, float b)
{
    T* p = (T*)((char*)this + 16);
    p->f(b, a);
}
