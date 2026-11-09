// from server: 100% by auto
// roc 2012-06 00404600  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404600
//
// 00404600  56                   push esi
// 00404601  8b742408             mov esi, dword ptr [esp + 8]
// 00404605  57                   push edi
// 00404606  56                   push esi
// 00404607  8bf9                 mov edi, ecx
// 00404609  ff15183cb200         call dword ptr [0xb23c18]
// 0040460f  2bc6                 sub eax, esi
// 00404611  50                   push eax
// 00404612  56                   push esi
// 00404613  8bcf                 mov ecx, edi
// 00404615  e846ffffff           call 0x404560
// 0040461a  5f                   pop edi
// 0040461b  5e                   pop esi
// 0040461c  c20400               ret 4
// library atl-8.0/atl.cpp (function ?AddChar@CParseBuffer@CRegParser@ATL@@QAEHPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
