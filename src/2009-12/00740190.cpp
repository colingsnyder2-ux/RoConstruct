// from server: 39% by atomic.potato
struct T
{
    float x;
    float y;
};

extern "C" void __cdecl call7400a0(T *, int);

struct S
{
    void f(float, float);
};

void S::f(float a, float b)
{
    T t;
    t.x = a;
    t.y = b;
    call7400a0(&t, 5);
}
