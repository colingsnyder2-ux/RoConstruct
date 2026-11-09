// from server: 27% by atomic.potato
struct T
{
    T* f(T* p);
    void g(T* p);
};

T* T::f(T* p)
{
    return p;
}

void T::g(T* p)
{
    p->g(f(p));
}
