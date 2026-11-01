// from server: 100% by auto
// roc 2007-03 00686340  unit: seg_00680000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686340
//
// 00686340  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00686344  8b41fc               mov eax, dword ptr [ecx - 4]
// 00686347  8b542408             mov edx, dword ptr [esp + 8]
// 0068634b  8b4034               mov eax, dword ptr [eax + 0x34]
// 0068634e  83c1fc               add ecx, -4
// 00686351  52                   push edx
// 00686352  ffd0                 call eax
// 00686354  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accSelection@XAccessible@CXTPAccessible@@UAGJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
