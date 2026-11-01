// from server: 100% by auto
// roc 2009-06 00403740  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00403740
//
// 00403740  b800100000           mov eax, 0x1000
// 00403745  e896643100           call 0x719be0
// 0040374a  56                   push esi
// 0040374b  57                   push edi
// 0040374c  8bbc240c100000       mov edi, dword ptr [esp + 0x100c]
// 00403753  803f3d               cmp byte ptr [edi], 0x3d
// 00403756  8bf1                 mov esi, ecx
// 00403758  752d                 jne 0x403787
// 0040375a  57                   push edi
// 0040375b  e820feffff           call 0x403580
// 00403760  85c0                 test eax, eax
// 00403762  7c25                 jl 0x403789
// 00403764  8bce                 mov ecx, esi
// 00403766  e8b5fdffff           call 0x403520
// 0040376b  8d442408             lea eax, [esp + 8]
// 0040376f  50                   push eax
// 00403770  8bce                 mov ecx, esi
// 00403772  e809feffff           call 0x403580
// 00403777  85c0                 test eax, eax
// 00403779  7c0e                 jl 0x403789
// 0040377b  57                   push edi
// 0040377c  8bce                 mov ecx, esi
// 0040377e  e8fdfdffff           call 0x403580
// 00403783  85c0                 test eax, eax
// 00403785  7c02                 jl 0x403789
// 00403787  33c0                 xor eax, eax
// 00403789  5f                   pop edi
// 0040378a  5e                   pop esi
// 0040378b  81c400100000         add esp, 0x1000
// 00403791  c20400               ret 4
// library atl-8.0/atl.cpp (function ?SkipAssignment@CRegParser@ATL@@IAEJPAD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
