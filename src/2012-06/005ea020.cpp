// from server: 100% by auto
// roc 2012-06 005ea020  unit: G3D::Random  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005ea020
//
// 005ea020  51                   push ecx
// 005ea021  8b01                 mov eax, dword ptr [ecx]
// 005ea023  8b5008               mov edx, dword ptr [eax + 8]
// 005ea026  ffd2                 call edx
// 005ea028  890424               mov dword ptr [esp], eax
// 005ea02b  db0424               fild dword ptr [esp]
// 005ea02e  85c0                 test eax, eax
// 005ea030  7d06                 jge 0x5ea038
// 005ea032  d80544ebb400         fadd dword ptr [0xb4eb44]
// 005ea038  d80d7c26b800         fmul dword ptr [0xb8267c]
// 005ea03e  d944240c             fld dword ptr [esp + 0xc]
// 005ea042  d9442408             fld dword ptr [esp + 8]
// 005ea046  dce9                 fsub st(1), st(0)
// 005ea048  d9ca                 fxch st(2)
// 005ea04a  dec9                 fmulp st(1)
// 005ea04c  dec1                 faddp st(1)
// 005ea04e  59                   pop ecx
// 005ea04f  c20800               ret 8
// library rbx2016-g3d/Random.cpp (function ?uniform@Random@G3D@@UAEMMM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Random.cpp
