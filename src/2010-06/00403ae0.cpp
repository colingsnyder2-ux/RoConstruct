// from server: 100% by auto
// roc 2010-06 00403ae0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00403ae0
//
// 00403ae0  8b442408             mov eax, dword ptr [esp + 8]
// 00403ae4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00403ae8  83caff               or edx, 0xffffffff
// 00403aeb  2bd0                 sub edx, eax
// 00403aed  3bd1                 cmp edx, ecx
// 00403aef  7306                 jae 0x403af7
// 00403af1  b857000780           mov eax, 0x80070057
// 00403af6  c3                   ret 
// 00403af7  03c1                 add eax, ecx
// 00403af9  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00403afd  8901                 mov dword ptr [ecx], eax
// 00403aff  33c0                 xor eax, eax
// 00403b01  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??$AtlAdd@K@ATL@@YAJPAKKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
