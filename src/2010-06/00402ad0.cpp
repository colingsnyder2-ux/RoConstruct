// from server: 100% by auto
// roc 2010-06 00402ad0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402ad0
//
// 00402ad0  8b442408             mov eax, dword ptr [esp + 8]
// 00402ad4  f76c240c             imul dword ptr [esp + 0xc]
// 00402ad8  8bc8                 mov ecx, eax
// 00402ada  81c100000080         add ecx, 0x80000000
// 00402ae0  83d200               adc edx, 0
// 00402ae3  85d2                 test edx, edx
// 00402ae5  7710                 ja 0x402af7
// 00402ae7  7205                 jb 0x402aee
// 00402ae9  83f9ff               cmp ecx, -1
// 00402aec  7709                 ja 0x402af7
// 00402aee  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00402af2  8901                 mov dword ptr [ecx], eax
// 00402af4  33c0                 xor eax, eax
// 00402af6  c3                   ret 
// 00402af7  b857000780           mov eax, 0x80070057
// 00402afc  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??$AtlMultiply@H@ATL@@YAJPAHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
