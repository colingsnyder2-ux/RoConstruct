// from server: 100% by auto
// roc 2011-06 00403e50  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403e50
//
// 00403e50  b800100000           mov eax, 0x1000
// 00403e55  e8f6734000           call 0x80b250
// 00403e5a  56                   push esi
// 00403e5b  57                   push edi
// 00403e5c  8bbc240c100000       mov edi, dword ptr [esp + 0x100c]
// 00403e63  803f3d               cmp byte ptr [edi], 0x3d
// 00403e66  8bf1                 mov esi, ecx
// 00403e68  752d                 jne 0x403e97
// 00403e6a  57                   push edi
// 00403e6b  e820feffff           call 0x403c90
// 00403e70  85c0                 test eax, eax
// 00403e72  7c25                 jl 0x403e99
// 00403e74  8bce                 mov ecx, esi
// 00403e76  e8b5fdffff           call 0x403c30
// 00403e7b  8d442408             lea eax, [esp + 8]
// 00403e7f  50                   push eax
// 00403e80  8bce                 mov ecx, esi
// 00403e82  e809feffff           call 0x403c90
// 00403e87  85c0                 test eax, eax
// 00403e89  7c0e                 jl 0x403e99
// 00403e8b  57                   push edi
// 00403e8c  8bce                 mov ecx, esi
// 00403e8e  e8fdfdffff           call 0x403c90
// 00403e93  85c0                 test eax, eax
// 00403e95  7c02                 jl 0x403e99
// 00403e97  33c0                 xor eax, eax
// 00403e99  5f                   pop edi
// 00403e9a  5e                   pop esi
// 00403e9b  81c400100000         add esp, 0x1000
// 00403ea1  c20400               ret 4
// library atl-8.0/atl.cpp (function ?SkipAssignment@CRegParser@ATL@@IAEJPAD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
