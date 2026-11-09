// from server: 100% by auto
// roc 2011-06 004034a0  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004034a0
//
// 004034a0  8b442408             mov eax, dword ptr [esp + 8]
// 004034a4  f76c240c             imul dword ptr [esp + 0xc]
// 004034a8  8bc8                 mov ecx, eax
// 004034aa  81c100000080         add ecx, 0x80000000
// 004034b0  83d200               adc edx, 0
// 004034b3  85d2                 test edx, edx
// 004034b5  7710                 ja 0x4034c7
// 004034b7  7205                 jb 0x4034be
// 004034b9  83f9ff               cmp ecx, -1
// 004034bc  7709                 ja 0x4034c7
// 004034be  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004034c2  8901                 mov dword ptr [ecx], eax
// 004034c4  33c0                 xor eax, eax
// 004034c6  c3                   ret 
// 004034c7  b857000780           mov eax, 0x80070057
// 004034cc  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??$AtlMultiply@H@ATL@@YAJPAHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
