// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct B1 { int a, b; };
struct B2 { int c; };
class Primitive : public B1, public B2 {};
struct Holder { char pad[0x1c]; B2* root; };
struct arg1 {};
struct list1 { arg1 a; };
template<class F> struct bind_t {
    F f; list1 l;
    bind_t(F f_, list1 l_) : f(f_) {}
};
template<class F> bind_t<F> bind(F f, arg1) { return bind_t<F>(f, list1()); }
extern arg1 _1;
void doA(Primitive* p);
class Assembly {
public:
    char pad[0x24];
    Holder* h;
    template<class F> void visit(F f, Primitive* p);
    void run();
};
void Assembly::run()
{
    bind_t<void(*)(Primitive*)> f = bind(&doA, _1);
    visit(f, static_cast<Primitive*>(h->root));
}
