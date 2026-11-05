// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /EHsc /MD
struct P { char* p; char* f(int i); };
struct S {
    int x;
    P a;
    int y;
    P b;
    int g(char* s, char* e);
    int h(int i, int j);
};
int S::h(int i, int j) { return g(a.f(i), b.f(j)); }
