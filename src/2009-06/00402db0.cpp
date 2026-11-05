// from server: 100% by auto
// roc 2009-06 00402db0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00402db0
//
// 00402db0  8b442408             mov eax, dword ptr [esp + 8]
// 00402db4  f76c240c             imul dword ptr [esp + 0xc]
// 00402db8  8bc8                 mov ecx, eax
// 00402dba  81c100000080         add ecx, 0x80000000
// 00402dc0  83d200               adc edx, 0
// 00402dc3  85d2                 test edx, edx
// 00402dc5  7710                 ja 0x402dd7
// 00402dc7  7205                 jb 0x402dce
// 00402dc9  83f9ff               cmp ecx, -1
// 00402dcc  7709                 ja 0x402dd7
// 00402dce  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00402dd2  8901                 mov dword ptr [ecx], eax
// 00402dd4  33c0                 xor eax, eax
// 00402dd6  c3                   ret 
// 00402dd7  b857000780           mov eax, 0x80070057
// 00402ddc  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??$AtlMultiply@H@ATL@@YAJPAHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
