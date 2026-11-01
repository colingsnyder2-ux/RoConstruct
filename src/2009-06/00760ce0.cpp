// from server: 100% by auto
// roc 2009-06 00760ce0  unit: CXTPAccessible::XAccessible  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760ce0
//
// 00760ce0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00760ce4  8b41fc               mov eax, dword ptr [ecx - 4]
// 00760ce7  8b542408             mov edx, dword ptr [esp + 8]
// 00760ceb  8b4008               mov eax, dword ptr [eax + 8]
// 00760cee  83c1fc               add ecx, -4
// 00760cf1  52                   push edx
// 00760cf2  ffd0                 call eax
// 00760cf4  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accChildCount@XAccessible@CXTPAccessible@@UAGJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
