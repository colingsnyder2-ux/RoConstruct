// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern unsigned char gFlag;
extern int gTag;
void helper(unsigned char, int*, void*);
struct Base { virtual ~Base(); };
struct __declspec(novtable) I { virtual void f() = 0; };
struct ArrowToolBase : Base, I { ~ArrowToolBase(); virtual void f(); };
ArrowToolBase::~ArrowToolBase() { if (gFlag) helper(gFlag, &gTag, this); }