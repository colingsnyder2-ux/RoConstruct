// from server: 100% by auto
// roc 2008-06 00401e80  unit: VCWorkspace::?$CComObject  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401e80
//
// 00401e80  56                   push esi
// 00401e81  8b742408             mov esi, dword ptr [esp + 8]
// 00401e85  57                   push edi
// 00401e86  56                   push esi
// 00401e87  8bf9                 mov edi, ecx
// 00401e89  ff152c2e8000         call dword ptr [0x802e2c]
// 00401e8f  2bc6                 sub eax, esi
// 00401e91  50                   push eax
// 00401e92  56                   push esi
// 00401e93  8bcf                 mov ecx, edi
// 00401e95  e846ffffff           call 0x401de0
// 00401e9a  5f                   pop edi
// 00401e9b  5e                   pop esi
// 00401e9c  c20400               ret 4
// library atl-8.0/atl.cpp (function ?AddChar@CParseBuffer@CRegParser@ATL@@QAEHPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
