// from server: 55% by atomic.potato
struct S {
    void f(int, int, int);
    int m_e98;
    int m_e9c;
};

extern "C" void sub_59efe0(void*);

void S::f(int a, int b, int c)
{
    m_e98 = b;
    m_e9c = c;
    sub_59efe0((char*)this + 0xf50);
}
