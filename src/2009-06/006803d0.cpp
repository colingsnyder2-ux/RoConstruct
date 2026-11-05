// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct T;
struct G { char pad[0x5c]; T* t; };
struct P { G* getGeometry(); };
T* getT(P* p)
{
    if (p) {
        if (G* g = p->getGeometry()) {
            if (T* t = g->t) return t;
        }
    }
    return 0;
}
