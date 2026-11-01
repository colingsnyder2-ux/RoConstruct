// from server: 100% by auto
// roc 2010-06 004030c0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004030c0
//
// 004030c0  56                   push esi
// 004030c1  8b742408             mov esi, dword ptr [esp + 8]
// 004030c5  57                   push edi
// 004030c6  56                   push esi
// 004030c7  8bf9                 mov edi, ecx
// 004030c9  ff1564ba9e00         call dword ptr [0x9eba64]
// 004030cf  2bc6                 sub eax, esi
// 004030d1  50                   push eax
// 004030d2  56                   push esi
// 004030d3  8bcf                 mov ecx, edi
// 004030d5  e846ffffff           call 0x403020
// 004030da  5f                   pop edi
// 004030db  5e                   pop esi
// 004030dc  c20400               ret 4
// library atl-8.0/atl.cpp (function ?AddChar@CParseBuffer@CRegParser@ATL@@QAEHPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
