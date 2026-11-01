// from server: 100% by auto
// roc 2007-03 00686320  unit: seg_00680000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686320
//
// 00686320  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00686324  8b41fc               mov eax, dword ptr [ecx - 4]
// 00686327  8b542408             mov edx, dword ptr [esp + 8]
// 0068632b  8b4030               mov eax, dword ptr [eax + 0x30]
// 0068632e  83c1fc               add ecx, -4
// 00686331  52                   push edx
// 00686332  ffd0                 call eax
// 00686334  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accFocus@XAccessible@CXTPAccessible@@UAGJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
