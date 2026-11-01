// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct C { int state; void f(int e); };
void C::f(int e)
{
    switch (e) {
    case 0: if (state == 1) state = 0; break;
    case 2: state = 2; break;
    }
}
