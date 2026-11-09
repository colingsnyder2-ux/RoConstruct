// from server: 100% by colin
struct Inner {
    void method(int a, int b);
};

struct Outer {
    char pad[0x40];
    Inner* m_p;
    void f(int a1, int a2, int a3);
};

void Outer::f(int a1, int a2, int a3)
{
    m_p->method(a2, a3);
}
