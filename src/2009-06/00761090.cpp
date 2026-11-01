// from server: 100% by auto
// roc 2009-06 00761090  unit: CXTPAccessible::XAccessible  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00761090
//
// 00761090  8b542410             mov edx, dword ptr [esp + 0x10]
// 00761094  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00761098  8b41fc               mov eax, dword ptr [ecx - 4]
// 0076109b  8b4048               mov eax, dword ptr [eax + 0x48]
// 0076109e  52                   push edx
// 0076109f  8b542410             mov edx, dword ptr [esp + 0x10]
// 007610a3  83c1fc               add ecx, -4
// 007610a6  52                   push edx
// 007610a7  8b542410             mov edx, dword ptr [esp + 0x10]
// 007610ab  52                   push edx
// 007610ac  ffd0                 call eax
// 007610ae  c21000               ret 0x10
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accHitTest@XAccessible@CXTPAccessible@@UAGJJJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
