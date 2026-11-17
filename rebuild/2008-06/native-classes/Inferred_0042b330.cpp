// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0042b330: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "util/Name.h"

void __cdecl f(void *a, void *b)
{
	typedef void (__cdecl *Fn)(void *, void *, void *);
	void **p = (void **)a;
	Fn fn = (Fn)p[0];
	fn(b, p[1], p[2]);
}
