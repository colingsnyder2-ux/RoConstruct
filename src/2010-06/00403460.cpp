// from server: 100% by auto
// roc 2010-06 00403460  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00403460
//
// 00403460  b800100000           mov eax, 0x1000
// 00403465  e8e6563a00           call 0x7a8b50
// 0040346a  56                   push esi
// 0040346b  57                   push edi
// 0040346c  8bbc240c100000       mov edi, dword ptr [esp + 0x100c]
// 00403473  803f3d               cmp byte ptr [edi], 0x3d
// 00403476  8bf1                 mov esi, ecx
// 00403478  752d                 jne 0x4034a7
// 0040347a  57                   push edi
// 0040347b  e820feffff           call 0x4032a0
// 00403480  85c0                 test eax, eax
// 00403482  7c25                 jl 0x4034a9
// 00403484  8bce                 mov ecx, esi
// 00403486  e8b5fdffff           call 0x403240
// 0040348b  8d442408             lea eax, [esp + 8]
// 0040348f  50                   push eax
// 00403490  8bce                 mov ecx, esi
// 00403492  e809feffff           call 0x4032a0
// 00403497  85c0                 test eax, eax
// 00403499  7c0e                 jl 0x4034a9
// 0040349b  57                   push edi
// 0040349c  8bce                 mov ecx, esi
// 0040349e  e8fdfdffff           call 0x4032a0
// 004034a3  85c0                 test eax, eax
// 004034a5  7c02                 jl 0x4034a9
// 004034a7  33c0                 xor eax, eax
// 004034a9  5f                   pop edi
// 004034aa  5e                   pop esi
// 004034ab  81c400100000         add esp, 0x1000
// 004034b1  c20400               ret 4
// library atl-8.0/atl.cpp (function ?SkipAssignment@CRegParser@ATL@@IAEJPAD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
