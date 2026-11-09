// from server: 100% by auto
// roc 2012-06 00628480  unit: G3D::ReferenceCountedObject  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00628480
//
// 00628480  8b4140               mov eax, dword ptr [ecx + 0x40]
// 00628483  8b5138               mov edx, dword ptr [ecx + 0x38]
// 00628486  56                   push esi
// 00628487  8b742408             mov esi, dword ptr [esp + 8]
// 0062848b  03c6                 add eax, esi
// 0062848d  3bd0                 cmp edx, eax
// 0062848f  7c02                 jl 0x628493
// 00628491  8bc2                 mov eax, edx
// 00628493  3b413c               cmp eax, dword ptr [ecx + 0x3c]
// 00628496  894138               mov dword ptr [ecx + 0x38], eax
// 00628499  7e07                 jle 0x6284a2
// 0062849b  52                   push edx
// 0062849c  56                   push esi
// 0062849d  e81ed10000           call 0x6355c0
// 006284a2  5e                   pop esi
// 006284a3  c20400               ret 4
// library rbx2016-g3d/BinaryOutput.cpp (function ?reserveBytes@BinaryOutput@G3D@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryOutput.cpp
