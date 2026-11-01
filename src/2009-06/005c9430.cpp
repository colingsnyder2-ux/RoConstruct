// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct G { char pad[0x78]; double d; };
G* get();
double f()
{
    return get()->d;
}
