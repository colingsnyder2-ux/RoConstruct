// from server: 100% by auto
// roc 2009-12 00402ab0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402ab0
//
// 00402ab0  8b442408             mov eax, dword ptr [esp + 8]
// 00402ab4  f764240c             mul dword ptr [esp + 0xc]
// 00402ab8  85d2                 test edx, edx
// 00402aba  7705                 ja 0x402ac1
// 00402abc  83f8ff               cmp eax, -1
// 00402abf  7606                 jbe 0x402ac7
// 00402ac1  b857000780           mov eax, 0x80070057
// 00402ac6  c3                   ret 
// 00402ac7  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00402acb  8901                 mov dword ptr [ecx], eax
// 00402acd  33c0                 xor eax, eax
// 00402acf  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??$AtlMultiply@I@ATL@@YAJPAIII@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
