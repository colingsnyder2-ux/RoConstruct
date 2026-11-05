// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct S { int pad; bool a; char p1[3]; int mode; char p2; bool b; void setMode(int m); };
void S::setMode(int m)
{
    mode = m;
    if (mode == 0) { a = false; b = false; }
    else if (mode == 1) { a = true; b = true; }
}
