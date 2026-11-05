// from server: 100% by auto
// roc 2011-06 00563320  unit: G3D::Random  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00563320
//
// 00563320  51                   push ecx
// 00563321  8b01                 mov eax, dword ptr [ecx]
// 00563323  8b5008               mov edx, dword ptr [eax + 8]
// 00563326  ffd2                 call edx
// 00563328  890424               mov dword ptr [esp], eax
// 0056332b  db0424               fild dword ptr [esp]
// 0056332e  85c0                 test eax, eax
// 00563330  7d06                 jge 0x563338
// 00563332  d805f04da600         fadd dword ptr [0xa64df0]
// 00563338  d80d0058a800         fmul dword ptr [0xa85800]
// 0056333e  59                   pop ecx
// 0056333f  c3                   ret 
// library rbx2016-g3d/Random.cpp (function ?uniform@Random@G3D@@UAEMXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Random.cpp
