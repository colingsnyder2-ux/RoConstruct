// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00469320: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "util/Name.h"

struct DxUserInput;

void __cdecl Add(struct DxUserInput* a, struct DxUserInput* b)
{
	float* pa = reinterpret_cast<float*>(a);
	float* pb = reinterpret_cast<float*>(b);
	pb[0] += pa[0];
	pb[1] += pa[1];
}
