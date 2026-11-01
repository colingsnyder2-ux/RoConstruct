// from server: 100% by auto
// roc 2010-06 004033d0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004033d0
//
// 004033d0  53                   push ebx
// 004033d1  8b1d84a39e00         mov ebx, dword ptr [0x9ea384]
// 004033d7  56                   push esi
// 004033d8  57                   push edi
// 004033d9  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004033dd  be4002a000           mov esi, 0xa00240
// 004033e2  8b06                 mov eax, dword ptr [esi]
// 004033e4  50                   push eax
// 004033e5  57                   push edi
// 004033e6  ffd3                 call ebx
// 004033e8  85c0                 test eax, eax
// 004033ea  7416                 je 0x403402
// 004033ec  83c604               add esi, 4
// 004033ef  81fe7002a000         cmp esi, 0xa00270
// 004033f5  7ceb                 jl 0x4033e2
// 004033f7  5f                   pop edi
// 004033f8  5e                   pop esi
// 004033f9  b801000000           mov eax, 1
// 004033fe  5b                   pop ebx
// 004033ff  c20400               ret 4
// 00403402  5f                   pop edi
// 00403403  5e                   pop esi
// 00403404  33c0                 xor eax, eax
// 00403406  5b                   pop ebx
// 00403407  c20400               ret 4
// library atl-8.0/atl.cpp (function ?CanForceRemoveKey@CRegParser@ATL@@IAEHPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
