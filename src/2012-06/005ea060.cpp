// from server: 100% by auto
// roc 2012-06 005ea060  unit: G3D::Random  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005ea060
//
// 005ea060  51                   push ecx
// 005ea061  8b01                 mov eax, dword ptr [ecx]
// 005ea063  8b5008               mov edx, dword ptr [eax + 8]
// 005ea066  ffd2                 call edx
// 005ea068  890424               mov dword ptr [esp], eax
// 005ea06b  db0424               fild dword ptr [esp]
// 005ea06e  85c0                 test eax, eax
// 005ea070  7d06                 jge 0x5ea078
// 005ea072  d80544ebb400         fadd dword ptr [0xb4eb44]
// 005ea078  d80d7c26b800         fmul dword ptr [0xb8267c]
// 005ea07e  59                   pop ecx
// 005ea07f  c3                   ret 
// library rbx2016-g3d/Random.cpp (function ?uniform@Random@G3D@@UAEMXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Random.cpp
