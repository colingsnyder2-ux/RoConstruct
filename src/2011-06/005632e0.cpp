// from server: 100% by auto
// roc 2011-06 005632e0  unit: G3D::Random  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005632e0
//
// 005632e0  51                   push ecx
// 005632e1  8b01                 mov eax, dword ptr [ecx]
// 005632e3  8b5008               mov edx, dword ptr [eax + 8]
// 005632e6  ffd2                 call edx
// 005632e8  890424               mov dword ptr [esp], eax
// 005632eb  db0424               fild dword ptr [esp]
// 005632ee  85c0                 test eax, eax
// 005632f0  7d06                 jge 0x5632f8
// 005632f2  d805f04da600         fadd dword ptr [0xa64df0]
// 005632f8  d80d0058a800         fmul dword ptr [0xa85800]
// 005632fe  d944240c             fld dword ptr [esp + 0xc]
// 00563302  d9442408             fld dword ptr [esp + 8]
// 00563306  dce9                 fsub st(1), st(0)
// 00563308  d9ca                 fxch st(2)
// 0056330a  dec9                 fmulp st(1)
// 0056330c  dec1                 faddp st(1)
// 0056330e  59                   pop ecx
// 0056330f  c20800               ret 8
// library rbx2016-g3d/Random.cpp (function ?uniform@Random@G3D@@UAEMMM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Random.cpp
