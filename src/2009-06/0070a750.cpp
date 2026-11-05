// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

struct Dur {
    double v;
    Dur() {}
};

Dur subtract(const Dur& a, const Dur& b)
{
    Dur r;
    r.v = a.v - b.v;
    return r;
}
