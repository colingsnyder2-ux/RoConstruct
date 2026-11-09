// from server: 100% by auto
// roc 2008-06 00402520  unit: std::bad_alloc  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402520
//
// 00402520  8b442408             mov eax, dword ptr [esp + 8]
// 00402524  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00402528  83caff               or edx, 0xffffffff
// 0040252b  2bd0                 sub edx, eax
// 0040252d  3bd1                 cmp edx, ecx
// 0040252f  7306                 jae 0x402537
// 00402531  b857000780           mov eax, 0x80070057
// 00402536  c3                   ret 
// 00402537  03c1                 add eax, ecx
// 00402539  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0040253d  8901                 mov dword ptr [ecx], eax
// 0040253f  33c0                 xor eax, eax
// 00402541  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??$AtlAdd@K@ATL@@YAJPAKKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
