// from server: 100% by auto
// roc 2009-06 004036b0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004036b0
//
// 004036b0  53                   push ebx
// 004036b1  8b1ddce18900         mov ebx, dword ptr [0x89e1dc]
// 004036b7  56                   push esi
// 004036b8  57                   push edi
// 004036b9  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004036bd  be5ccb8a00           mov esi, 0x8acb5c
// 004036c2  8b06                 mov eax, dword ptr [esi]
// 004036c4  50                   push eax
// 004036c5  57                   push edi
// 004036c6  ffd3                 call ebx
// 004036c8  85c0                 test eax, eax
// 004036ca  7416                 je 0x4036e2
// 004036cc  83c604               add esi, 4
// 004036cf  81fe8ccb8a00         cmp esi, 0x8acb8c
// 004036d5  7ceb                 jl 0x4036c2
// 004036d7  5f                   pop edi
// 004036d8  5e                   pop esi
// 004036d9  b801000000           mov eax, 1
// 004036de  5b                   pop ebx
// 004036df  c20400               ret 4
// 004036e2  5f                   pop edi
// 004036e3  5e                   pop esi
// 004036e4  33c0                 xor eax, eax
// 004036e6  5b                   pop ebx
// 004036e7  c20400               ret 4
// library atl-8.0/atl.cpp (function ?CanForceRemoveKey@CRegParser@ATL@@IAEHPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
