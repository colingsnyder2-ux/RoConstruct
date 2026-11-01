// from server: 100% by auto
// roc 2009-12 0083bab0  unit: CXTPAccessible::XAccessible  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bab0
//
// 0083bab0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083bab4  8b41fc               mov eax, dword ptr [ecx - 4]
// 0083bab7  8b542408             mov edx, dword ptr [esp + 8]
// 0083babb  8b4004               mov eax, dword ptr [eax + 4]
// 0083babe  83c1fc               add ecx, -4
// 0083bac1  52                   push edx
// 0083bac2  ffd0                 call eax
// 0083bac4  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accParent@XAccessible@CXTPAccessible@@UAGJPAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
