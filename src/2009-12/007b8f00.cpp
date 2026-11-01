// from server: 100% by atomic.potato
struct S_func_007b2f20 {
    char pad0[4];
    void f(int a1);
};

struct S_func_007d9f40 {
    void g(int a1);
};

struct S {
    void f(int a1);
};

void S::f(int a1)
{
    ((S_func_007b2f20*)a1)->f((int)this);
    ((S_func_007d9f40*)this)->g(a1);
}
