// from server: 100% by auto
// roc 2009-12 00403070  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00403070
//
// 00403070  56                   push esi
// 00403071  8b742408             mov esi, dword ptr [esp + 8]
// 00403075  57                   push edi
// 00403076  56                   push esi
// 00403077  8bf9                 mov edi, ecx
// 00403079  ff15d4cb9800         call dword ptr [0x98cbd4]
// 0040307f  2bc6                 sub eax, esi
// 00403081  50                   push eax
// 00403082  56                   push esi
// 00403083  8bcf                 mov ecx, edi
// 00403085  e846ffffff           call 0x402fd0
// 0040308a  5f                   pop edi
// 0040308b  5e                   pop esi
// 0040308c  c20400               ret 4
// library atl-8.0/atl.cpp (function ?AddChar@CParseBuffer@CRegParser@ATL@@QAEHPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
