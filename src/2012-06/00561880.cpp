// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) unsigned short __stdcall imp(unsigned short);
struct S{ short pad; short a; char p2[0xc]; short b; void m(int x); };
void S::m(int x){ a=x; b=imp(x); }

