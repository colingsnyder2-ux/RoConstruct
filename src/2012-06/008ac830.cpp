// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct B1{ B1(int); virtual ~B1(); virtual void a(); }; struct __declspec(novtable) P2{ virtual void b(); }; void report(unsigned char, const char*, void*); unsigned char gflag; struct NT : B1, P2 { NT(int x); virtual void a(); virtual void b(); }; NT::NT(int x) : B1(x) { if(gflag) report(gflag, "NullTool created: %p", this); }
