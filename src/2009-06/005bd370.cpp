// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct C { unsigned int n; int f(); };
int C::f()
{
    if (n >= 0x3d09000)
        return 0x400;
    else
        return 0x200;
}
