// from server: 100% by auto
// roc 2010-06 007efbf0  unit: CXTPAccessible::XAccessible  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efbf0
//
// 007efbf0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efbf4  8b41fc               mov eax, dword ptr [ecx - 4]
// 007efbf7  8b542408             mov edx, dword ptr [esp + 8]
// 007efbfb  8b4004               mov eax, dword ptr [eax + 4]
// 007efbfe  83c1fc               add ecx, -4
// 007efc01  52                   push edx
// 007efc02  ffd0                 call eax
// 007efc04  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accParent@XAccessible@CXTPAccessible@@UAGJPAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
