// from server: 100% by auto
// roc 2010-06 00874210  unit: CXTPDockingPaneContext  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00874210
//
// 00874210  8b442404             mov eax, dword ptr [esp + 4]
// 00874214  db00                 fild dword ptr [eax]
// 00874216  56                   push esi
// 00874217  dd442414             fld qword ptr [esp + 0x14]
// 0087421b  dcc9                 fmul st(1), st(0)
// 0087421d  d9c9                 fxch st(1)
// 0087421f  e80c4cf3ff           call 0x7a8e30
// 00874224  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00874228  db01                 fild dword ptr [ecx]
// 0087422a  8bf0                 mov esi, eax
// 0087422c  c1e608               shl esi, 8
// 0087422f  d8c9                 fmul st(1)
// 00874231  e8fa4bf3ff           call 0x7a8e30
// 00874236  8b542410             mov edx, dword ptr [esp + 0x10]
// 0087423a  da0a                 fimul dword ptr [edx]
// 0087423c  03f0                 add esi, eax
// 0087423e  c1e608               shl esi, 8
// 00874241  e8ea4bf3ff           call 0x7a8e30
// 00874246  03c6                 add eax, esi
// 00874248  5e                   pop esi
// 00874249  c21400               ret 0x14
// library xtp-13.2.1/Source\Common\XTPHookManager.cpp (function ?Factor@CShadowWnd@CXTPShadowManager@@AAEIAAH00N@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPHookManager.cpp
