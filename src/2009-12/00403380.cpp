// from server: 100% by auto
// roc 2009-12 00403380  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00403380
//
// 00403380  53                   push ebx
// 00403381  8b1d14b29800         mov ebx, dword ptr [0x98b214]
// 00403387  56                   push esi
// 00403388  57                   push edi
// 00403389  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0040338d  be9cf69900           mov esi, 0x99f69c
// 00403392  8b06                 mov eax, dword ptr [esi]
// 00403394  50                   push eax
// 00403395  57                   push edi
// 00403396  ffd3                 call ebx
// 00403398  85c0                 test eax, eax
// 0040339a  7416                 je 0x4033b2
// 0040339c  83c604               add esi, 4
// 0040339f  81feccf69900         cmp esi, 0x99f6cc
// 004033a5  7ceb                 jl 0x403392
// 004033a7  5f                   pop edi
// 004033a8  5e                   pop esi
// 004033a9  b801000000           mov eax, 1
// 004033ae  5b                   pop ebx
// 004033af  c20400               ret 4
// 004033b2  5f                   pop edi
// 004033b3  5e                   pop esi
// 004033b4  33c0                 xor eax, eax
// 004033b6  5b                   pop ebx
// 004033b7  c20400               ret 4
// library atl-8.0/atl.cpp (function ?CanForceRemoveKey@CRegParser@ATL@@IAEHPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
