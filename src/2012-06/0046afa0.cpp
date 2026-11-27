// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Sig { void fire(const int*); };
struct C { char pad[0x8c]; int x; char pad2[0x144-0x90]; Sig sig; void set(int v); };
extern int g;
void C::set(int v) { if (v != x) { x = v; sig.fire(&g); } }
