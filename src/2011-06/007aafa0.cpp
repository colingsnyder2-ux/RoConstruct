// from server: 71% by atomic.potato
struct S;

extern "C" void __cdecl sub_7aae30(S*, int);
extern "C" void __cdecl sub_80a058(S*);

struct S
{
    void f();
    int field_0c;
};

void S::f()
{
    S* p = reinterpret_cast<S*>(field_0c);
    if (p)
    {
        sub_7aae30(p, p->field_0c);
        sub_80a058(p);
    }
}
