// from server: 100% by auto
// roc 2011-06 004034d0  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004034d0
//
// 004034d0  8b442408             mov eax, dword ptr [esp + 8]
// 004034d4  f764240c             mul dword ptr [esp + 0xc]
// 004034d8  85d2                 test edx, edx
// 004034da  7705                 ja 0x4034e1
// 004034dc  83f8ff               cmp eax, -1
// 004034df  7606                 jbe 0x4034e7
// 004034e1  b857000780           mov eax, 0x80070057
// 004034e6  c3                   ret 
// 004034e7  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004034eb  8901                 mov dword ptr [ecx], eax
// 004034ed  33c0                 xor eax, eax
// 004034ef  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??$AtlMultiply@I@ATL@@YAJPAIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
