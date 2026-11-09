// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Arg {
    char data[0x28];
    Arg(const Arg&);
    ~Arg();
};
struct Result {
    void* p;
    ~Result();
};
class Target { public: Result call(Arg a); };
static Target* idT(Target* t) { return t; }
class Owner {
public:
    Target* getTarget();
    Result forward(Arg a);
};
Result Owner::forward(Arg a)
{
    return idT(getTarget())->call(a);
}
