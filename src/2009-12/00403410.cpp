// from server: 100% by auto
// roc 2009-12 00403410  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00403410
//
// 00403410  b800100000           mov eax, 0x1000
// 00403415  e8f6153f00           call 0x7f4a10
// 0040341a  56                   push esi
// 0040341b  57                   push edi
// 0040341c  8bbc240c100000       mov edi, dword ptr [esp + 0x100c]
// 00403423  803f3d               cmp byte ptr [edi], 0x3d
// 00403426  8bf1                 mov esi, ecx
// 00403428  752d                 jne 0x403457
// 0040342a  57                   push edi
// 0040342b  e820feffff           call 0x403250
// 00403430  85c0                 test eax, eax
// 00403432  7c25                 jl 0x403459
// 00403434  8bce                 mov ecx, esi
// 00403436  e8b5fdffff           call 0x4031f0
// 0040343b  8d442408             lea eax, [esp + 8]
// 0040343f  50                   push eax
// 00403440  8bce                 mov ecx, esi
// 00403442  e809feffff           call 0x403250
// 00403447  85c0                 test eax, eax
// 00403449  7c0e                 jl 0x403459
// 0040344b  57                   push edi
// 0040344c  8bce                 mov ecx, esi
// 0040344e  e8fdfdffff           call 0x403250
// 00403453  85c0                 test eax, eax
// 00403455  7c02                 jl 0x403459
// 00403457  33c0                 xor eax, eax
// 00403459  5f                   pop edi
// 0040345a  5e                   pop esi
// 0040345b  81c400100000         add esp, 0x1000
// 00403461  c20400               ret 4
// library atl-8.0/atl.cpp (function ?SkipAssignment@CRegParser@ATL@@IAEJPAD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
