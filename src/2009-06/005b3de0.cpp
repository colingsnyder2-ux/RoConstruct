// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct A { double d[7]; };
struct B { double d[3]; };
class X {
public:
    A a;
    B b;
    X(const A& a_, const B& b_);
};
X::X(const A& a_, const B& b_) : a(a_), b(b_) {}
