// from server: 100% by auto
// roc 2009-06 00402de0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00402de0
//
// 00402de0  8b442408             mov eax, dword ptr [esp + 8]
// 00402de4  f764240c             mul dword ptr [esp + 0xc]
// 00402de8  85d2                 test edx, edx
// 00402dea  7705                 ja 0x402df1
// 00402dec  83f8ff               cmp eax, -1
// 00402def  7606                 jbe 0x402df7
// 00402df1  b857000780           mov eax, 0x80070057
// 00402df6  c3                   ret 
// 00402df7  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00402dfb  8901                 mov dword ptr [ecx], eax
// 00402dfd  33c0                 xor eax, eax
// 00402dff  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??$AtlMultiply@I@ATL@@YAJPAIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
