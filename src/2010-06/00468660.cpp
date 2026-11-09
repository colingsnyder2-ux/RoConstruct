// from server: 100% by atomic.potato
struct T {
    ~T();
};

struct S {
    T* m_p;
    void f(T* p);
};

void S::f(T* p) {
    T* old = m_p;
    m_p = p;
    if (old) delete old;
}
