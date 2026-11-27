// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O1 /Oy- /GS- /EHsc /MD /hotpatch
#include <mm3dnow.h>
#include <intrin.h>
void __stdcall g(int,int,int);

int __stdcall f(int a,int b,int c){ _m_femms(); _ReadWriteBarrier(); g(a,b,c); _m_femms(); _ReadWriteBarrier(); return a; }
