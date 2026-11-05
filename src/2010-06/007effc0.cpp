// from server: 100% by auto
// roc 2010-06 007effc0  unit: CXTPAccessible::XAccessible  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007effc0
//
// 007effc0  8b542410             mov edx, dword ptr [esp + 0x10]
// 007effc4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007effc8  8b41fc               mov eax, dword ptr [ecx - 4]
// 007effcb  8b4048               mov eax, dword ptr [eax + 0x48]
// 007effce  52                   push edx
// 007effcf  8b542410             mov edx, dword ptr [esp + 0x10]
// 007effd3  83c1fc               add ecx, -4
// 007effd6  52                   push edx
// 007effd7  8b542410             mov edx, dword ptr [esp + 0x10]
// 007effdb  52                   push edx
// 007effdc  ffd0                 call eax
// 007effde  c21000               ret 0x10
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accHitTest@XAccessible@CXTPAccessible@@UAGJJJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
