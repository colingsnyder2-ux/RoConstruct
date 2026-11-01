// from server: 100% by auto
// roc 2007-03 006860a0  unit: seg_00680000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006860a0
//
// 006860a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006860a4  8b41fc               mov eax, dword ptr [ecx - 4]
// 006860a7  8b542408             mov edx, dword ptr [esp + 8]
// 006860ab  8b4004               mov eax, dword ptr [eax + 4]
// 006860ae  83c1fc               add ecx, -4
// 006860b1  52                   push edx
// 006860b2  ffd0                 call eax
// 006860b4  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accParent@XAccessible@CXTPAccessible@@UAGJPAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
