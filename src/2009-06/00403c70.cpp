// from server: 100% by auto
// roc 2009-06 00403c70  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00403c70
//
// 00403c70  8b442408             mov eax, dword ptr [esp + 8]
// 00403c74  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00403c78  83caff               or edx, 0xffffffff
// 00403c7b  2bd0                 sub edx, eax
// 00403c7d  3bd1                 cmp edx, ecx
// 00403c7f  7306                 jae 0x403c87
// 00403c81  b857000780           mov eax, 0x80070057
// 00403c86  c3                   ret 
// 00403c87  03c1                 add eax, ecx
// 00403c89  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00403c8d  8901                 mov dword ptr [ecx], eax
// 00403c8f  33c0                 xor eax, eax
// 00403c91  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??$AtlAdd@K@ATL@@YAJPAKKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
