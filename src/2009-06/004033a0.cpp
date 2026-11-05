// from server: 100% by auto
// roc 2009-06 004033a0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004033a0
//
// 004033a0  56                   push esi
// 004033a1  8b742408             mov esi, dword ptr [esp + 8]
// 004033a5  57                   push edi
// 004033a6  56                   push esi
// 004033a7  8bf9                 mov edi, ecx
// 004033a9  ff1580ee8900         call dword ptr [0x89ee80]
// 004033af  2bc6                 sub eax, esi
// 004033b1  50                   push eax
// 004033b2  56                   push esi
// 004033b3  8bcf                 mov ecx, edi
// 004033b5  e846ffffff           call 0x403300
// 004033ba  5f                   pop edi
// 004033bb  5e                   pop esi
// 004033bc  c20400               ret 4
// library atl-8.0/atl.cpp (function ?AddChar@CParseBuffer@CRegParser@ATL@@QAEHPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
