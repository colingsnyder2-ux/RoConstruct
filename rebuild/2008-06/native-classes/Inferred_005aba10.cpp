// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005aba10: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "util/Name.h"

struct S;

int __cdecl invoke(S* s, int x)
{
	return (*reinterpret_cast<int (__cdecl **)(int)>(s))(x);
}
