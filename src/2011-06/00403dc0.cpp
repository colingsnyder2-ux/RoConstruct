// from server: 100% by auto
// roc 2011-06 00403dc0  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403dc0
//
// 00403dc0  53                   push ebx
// 00403dc1  8b1d5403a400         mov ebx, dword ptr [0xa40354]
// 00403dc7  56                   push esi
// 00403dc8  57                   push edi
// 00403dc9  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00403dcd  befcb7a500           mov esi, 0xa5b7fc
// 00403dd2  8b06                 mov eax, dword ptr [esi]
// 00403dd4  50                   push eax
// 00403dd5  57                   push edi
// 00403dd6  ffd3                 call ebx
// 00403dd8  85c0                 test eax, eax
// 00403dda  7416                 je 0x403df2
// 00403ddc  83c604               add esi, 4
// 00403ddf  81fe2cb8a500         cmp esi, 0xa5b82c
// 00403de5  7ceb                 jl 0x403dd2
// 00403de7  5f                   pop edi
// 00403de8  5e                   pop esi
// 00403de9  b801000000           mov eax, 1
// 00403dee  5b                   pop ebx
// 00403def  c20400               ret 4
// 00403df2  5f                   pop edi
// 00403df3  5e                   pop esi
// 00403df4  33c0                 xor eax, eax
// 00403df6  5b                   pop ebx
// 00403df7  c20400               ret 4
// library atl-8.0/atl.cpp (function ?CanForceRemoveKey@CRegParser@ATL@@IAEHPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
