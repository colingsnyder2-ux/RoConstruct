// from server: 100% by auto
// roc 2007-03 00686470  unit: seg_00680000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686470
//
// 00686470  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686474  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00686478  8b41fc               mov eax, dword ptr [ecx - 4]
// 0068647b  8b4048               mov eax, dword ptr [eax + 0x48]
// 0068647e  52                   push edx
// 0068647f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686483  83c1fc               add ecx, -4
// 00686486  52                   push edx
// 00686487  8b542410             mov edx, dword ptr [esp + 0x10]
// 0068648b  52                   push edx
// 0068648c  ffd0                 call eax
// 0068648e  c21000               ret 0x10
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accHitTest@XAccessible@CXTPAccessible@@UAGJJJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
