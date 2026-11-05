// from server: 100% by auto
// roc 2010-06 007efe90  unit: CXTPAccessible::XAccessible  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efe90
//
// 007efe90  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efe94  8b41fc               mov eax, dword ptr [ecx - 4]
// 007efe97  8b542408             mov edx, dword ptr [esp + 8]
// 007efe9b  8b4034               mov eax, dword ptr [eax + 0x34]
// 007efe9e  83c1fc               add ecx, -4
// 007efea1  52                   push edx
// 007efea2  ffd0                 call eax
// 007efea4  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accSelection@XAccessible@CXTPAccessible@@UAGJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
