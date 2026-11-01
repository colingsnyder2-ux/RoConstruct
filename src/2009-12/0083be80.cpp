// from server: 100% by auto
// roc 2009-12 0083be80  unit: CXTPAccessible::XAccessible  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083be80
//
// 0083be80  8b542410             mov edx, dword ptr [esp + 0x10]
// 0083be84  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083be88  8b41fc               mov eax, dword ptr [ecx - 4]
// 0083be8b  8b4048               mov eax, dword ptr [eax + 0x48]
// 0083be8e  52                   push edx
// 0083be8f  8b542410             mov edx, dword ptr [esp + 0x10]
// 0083be93  83c1fc               add ecx, -4
// 0083be96  52                   push edx
// 0083be97  8b542410             mov edx, dword ptr [esp + 0x10]
// 0083be9b  52                   push edx
// 0083be9c  ffd0                 call eax
// 0083be9e  c21000               ret 0x10
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accHitTest@XAccessible@CXTPAccessible@@UAGJJJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
