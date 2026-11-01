// from server: 100% by auto
// roc 2007-03 006e4620  unit: seg_006e0000  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e4620
//
// 006e4620  8b442404             mov eax, dword ptr [esp + 4]
// 006e4624  db00                 fild dword ptr [eax]
// 006e4626  56                   push esi
// 006e4627  dd442414             fld qword ptr [esp + 0x14]
// 006e462b  dcc9                 fmul st(1), st(0)
// 006e462d  d9c9                 fxch st(1)
// 006e462f  e8ccabf3ff           call 0x61f200
// 006e4634  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006e4638  db01                 fild dword ptr [ecx]
// 006e463a  8bf0                 mov esi, eax
// 006e463c  c1e608               shl esi, 8
// 006e463f  d8c9                 fmul st(1)
// 006e4641  e8baabf3ff           call 0x61f200
// 006e4646  8b542410             mov edx, dword ptr [esp + 0x10]
// 006e464a  da0a                 fimul dword ptr [edx]
// 006e464c  03f0                 add esi, eax
// 006e464e  c1e608               shl esi, 8
// 006e4651  e8aaabf3ff           call 0x61f200
// 006e4656  03c6                 add eax, esi
// 006e4658  5e                   pop esi
// 006e4659  c21400               ret 0x14
// library xtp-15.2.1/Source\Common\XTPHookManager.cpp (function ?Factor@CShadowWnd@CXTPShadowManager@@AAEIAAH00N@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPHookManager.cpp
