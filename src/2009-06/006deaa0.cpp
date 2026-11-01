// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Body_006deaa0;
struct Stage_006deaa0 {
    void f(Body_006deaa0* b);
    void g(Body_006deaa0* b);
};
struct Body_006deaa0 { void h(Stage_006deaa0* s); };
void Stage_006deaa0::f(Body_006deaa0* b)
{
    g(b);
    b->h(this);
}
