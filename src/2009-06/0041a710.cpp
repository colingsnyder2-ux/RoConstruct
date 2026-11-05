// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Arg;
class M {
public:
    bool check(Arg* a);
    void prepare();
    void apply(Arg* a);
    M& set(Arg* a);
};
M& M::set(Arg* a)
{
    if (check(a)) {
        prepare();
        apply(a);
    }
    return *this;
}
