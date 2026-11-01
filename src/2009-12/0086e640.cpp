// from server: 56% by atomic.potato
struct S
{
    void f();
};

struct T
{
    void f();
};

void T::f()
{
}

void S::f()
{
    reinterpret_cast<T*>(this)->f();
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 4) = 0;
}
