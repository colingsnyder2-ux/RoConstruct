// from server: 100% by auto
// roc 2011-06 0053c510  unit: G3D::ReferenceCountedObject  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053c510
//
// 0053c510  8b4140               mov eax, dword ptr [ecx + 0x40]
// 0053c513  8b5138               mov edx, dword ptr [ecx + 0x38]
// 0053c516  56                   push esi
// 0053c517  8b742408             mov esi, dword ptr [esp + 8]
// 0053c51b  03c6                 add eax, esi
// 0053c51d  3bd0                 cmp edx, eax
// 0053c51f  7c02                 jl 0x53c523
// 0053c521  8bc2                 mov eax, edx
// 0053c523  3b413c               cmp eax, dword ptr [ecx + 0x3c]
// 0053c526  894138               mov dword ptr [ecx + 0x38], eax
// 0053c529  7e07                 jle 0x53c532
// 0053c52b  52                   push edx
// 0053c52c  56                   push esi
// 0053c52d  e8fe8b0000           call 0x545130
// 0053c532  5e                   pop esi
// 0053c533  c20400               ret 4
// library rbx2016-g3d/BinaryOutput.cpp (function ?reserveBytes@BinaryOutput@G3D@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryOutput.cpp
