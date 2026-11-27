// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern unsigned char gFlag;
extern int gTag;
void helper(unsigned char, int*, void*);
struct S;
__declspec(dllimport) void __stdcall imp(S*);
struct S { void f(); };
void S::f() {
    imp(this);
    if (gFlag) helper(gFlag, &gTag, this);
}