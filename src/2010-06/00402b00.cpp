// from server: 100% by auto
// roc 2010-06 00402b00  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402b00
//
// 00402b00  8b442408             mov eax, dword ptr [esp + 8]
// 00402b04  f764240c             mul dword ptr [esp + 0xc]
// 00402b08  85d2                 test edx, edx
// 00402b0a  7705                 ja 0x402b11
// 00402b0c  83f8ff               cmp eax, -1
// 00402b0f  7606                 jbe 0x402b17
// 00402b11  b857000780           mov eax, 0x80070057
// 00402b16  c3                   ret 
// 00402b17  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00402b1b  8901                 mov dword ptr [ecx], eax
// 00402b1d  33c0                 xor eax, eax
// 00402b1f  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??$AtlMultiply@I@ATL@@YAJPAIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
