// from server: 100% by EspClaude
// roc 2007-08 00459ce0  (trial)
struct Member {
    Member(int n);
    ~Member();
};

struct Base {
    virtual ~Base();
};

struct Derived : public Base {
    int m_arg;
    Member m_member;
    Derived(int a);
    virtual ~Derived();
};

Derived::Derived(int a) : m_arg(a), m_member(0xa00000)
{
}
