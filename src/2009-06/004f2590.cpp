// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <set>
struct E { int v[8]; };
bool operator<(const E&, const E&);
typedef std::set<E> Tail;

struct I0 { virtual void f(); char padding[16]; };
struct I1 { virtual void f(); };
struct I2 { virtual void f(); char padding[4]; };
struct I3 { virtual void f(); char padding[0x68]; };

struct Base : I0, I1, I2, I3 {
    Base();
    ~Base();
};

struct Member {
    char storage[0x2A24];
    Member();
    ~Member();
};

struct SP { void* px; void* pn; SP() : px(0), pn(0) {} ~SP(); };

struct S : Base {
    Member member;
    SP sp;
    Tail tail;
    virtual void f();
    S();
};

S::S() : Base(), member(), sp(), tail()
{
}
