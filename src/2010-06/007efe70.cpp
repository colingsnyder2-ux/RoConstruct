// from server: 100% by auto
// roc 2010-06 007efe70  unit: CXTPAccessible::XAccessible  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efe70
//
// 007efe70  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efe74  8b41fc               mov eax, dword ptr [ecx - 4]
// 007efe77  8b542408             mov edx, dword ptr [esp + 8]
// 007efe7b  8b4030               mov eax, dword ptr [eax + 0x30]
// 007efe7e  83c1fc               add ecx, -4
// 007efe81  52                   push edx
// 007efe82  ffd0                 call eax
// 007efe84  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accFocus@XAccessible@CXTPAccessible@@UAGJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
