// from server: 100% by auto
// roc 2008-06 00402220  unit: VCWorkspace::?$CComObject  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402220
//
// 00402220  b800100000           mov eax, 0x1000
// 00402225  e8f6f22900           call 0x6a1520
// 0040222a  56                   push esi
// 0040222b  57                   push edi
// 0040222c  8bbc240c100000       mov edi, dword ptr [esp + 0x100c]
// 00402233  803f3d               cmp byte ptr [edi], 0x3d
// 00402236  8bf1                 mov esi, ecx
// 00402238  752d                 jne 0x402267
// 0040223a  57                   push edi
// 0040223b  e820feffff           call 0x402060
// 00402240  85c0                 test eax, eax
// 00402242  7c25                 jl 0x402269
// 00402244  8bce                 mov ecx, esi
// 00402246  e8b5fdffff           call 0x402000
// 0040224b  8d442408             lea eax, [esp + 8]
// 0040224f  50                   push eax
// 00402250  8bce                 mov ecx, esi
// 00402252  e809feffff           call 0x402060
// 00402257  85c0                 test eax, eax
// 00402259  7c0e                 jl 0x402269
// 0040225b  57                   push edi
// 0040225c  8bce                 mov ecx, esi
// 0040225e  e8fdfdffff           call 0x402060
// 00402263  85c0                 test eax, eax
// 00402265  7c02                 jl 0x402269
// 00402267  33c0                 xor eax, eax
// 00402269  5f                   pop edi
// 0040226a  5e                   pop esi
// 0040226b  81c400100000         add esp, 0x1000
// 00402271  c20400               ret 4
// library atl-8.0/atl.cpp (function ?SkipAssignment@CRegParser@ATL@@IAEJPAD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
