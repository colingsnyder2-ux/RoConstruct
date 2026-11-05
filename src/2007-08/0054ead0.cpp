// from server: 100% by auto
// roc 2007-08 0054ead0  unit: std::D::V?$allocator::V?$basic_gzip_decompressor::?$stream_buffer  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054ead0
//
// 0054ead0  8b542404             mov edx, dword ptr [esp + 4]
// 0054ead4  85d2                 test edx, edx
// 0054ead6  57                   push edi
// 0054ead7  8bf9                 mov edi, ecx
// 0054ead9  750f                 jne 0x54eaea
// 0054eadb  33c0                 xor eax, eax
// 0054eadd  50                   push eax
// 0054eade  52                   push edx
// 0054eadf  e8fccdffff           call 0x54b8e0
// 0054eae4  8bc7                 mov eax, edi
// 0054eae6  5f                   pop edi
// 0054eae7  c20400               ret 4
// 0054eaea  8bc2                 mov eax, edx
// 0054eaec  56                   push esi
// 0054eaed  8d7001               lea esi, [eax + 1]
// 0054eaf0  8a08                 mov cl, byte ptr [eax]
// 0054eaf2  83c001               add eax, 1
// 0054eaf5  84c9                 test cl, cl
// 0054eaf7  75f7                 jne 0x54eaf0
// 0054eaf9  2bc6                 sub eax, esi
// 0054eafb  5e                   pop esi
// 0054eafc  50                   push eax
// 0054eafd  52                   push edx
// 0054eafe  8bcf                 mov ecx, edi
// 0054eb00  e8dbcdffff           call 0x54b8e0
// 0054eb05  8bc7                 mov eax, edi
// 0054eb07  5f                   pop edi
// 0054eb08  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??4?$CSimpleStringT@D$0A@@ATL@@QAEAAV01@PBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
