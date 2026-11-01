// from server: 100% by auto
// roc 2009-12 00403a80  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00403a80
//
// 00403a80  8b442408             mov eax, dword ptr [esp + 8]
// 00403a84  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00403a88  83caff               or edx, 0xffffffff
// 00403a8b  2bd0                 sub edx, eax
// 00403a8d  3bd1                 cmp edx, ecx
// 00403a8f  7306                 jae 0x403a97
// 00403a91  b857000780           mov eax, 0x80070057
// 00403a96  c3                   ret 
// 00403a97  03c1                 add eax, ecx
// 00403a99  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00403a9d  8901                 mov dword ptr [ecx], eax
// 00403a9f  33c0                 xor eax, eax
// 00403aa1  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??$AtlAdd@K@ATL@@YAJPAKKK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
