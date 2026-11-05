// from server: 100% by auto
// roc 2011-06 00404380  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00404380
//
// 00404380  8b442408             mov eax, dword ptr [esp + 8]
// 00404384  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00404388  83caff               or edx, 0xffffffff
// 0040438b  2bd0                 sub edx, eax
// 0040438d  3bd1                 cmp edx, ecx
// 0040438f  7306                 jae 0x404397
// 00404391  b857000780           mov eax, 0x80070057
// 00404396  c3                   ret 
// 00404397  03c1                 add eax, ecx
// 00404399  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0040439d  8901                 mov dword ptr [ecx], eax
// 0040439f  33c0                 xor eax, eax
// 004043a1  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??$AtlAdd@K@ATL@@YAJPAKKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
