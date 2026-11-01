// from server: 100% by auto
// roc 2009-12 008e2f30  unit: CXTShadowHook  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e2f30
//
// 008e2f30  8b442404             mov eax, dword ptr [esp + 4]
// 008e2f34  db00                 fild dword ptr [eax]
// 008e2f36  56                   push esi
// 008e2f37  dd442414             fld qword ptr [esp + 0x14]
// 008e2f3b  dcc9                 fmul st(1), st(0)
// 008e2f3d  d9c9                 fxch st(1)
// 008e2f3f  e8ac1df1ff           call 0x7f4cf0
// 008e2f44  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008e2f48  db01                 fild dword ptr [ecx]
// 008e2f4a  8bf0                 mov esi, eax
// 008e2f4c  c1e608               shl esi, 8
// 008e2f4f  d8c9                 fmul st(1)
// 008e2f51  e89a1df1ff           call 0x7f4cf0
// 008e2f56  8b542410             mov edx, dword ptr [esp + 0x10]
// 008e2f5a  da0a                 fimul dword ptr [edx]
// 008e2f5c  03f0                 add esi, eax
// 008e2f5e  c1e608               shl esi, 8
// 008e2f61  e88a1df1ff           call 0x7f4cf0
// 008e2f66  03c6                 add eax, esi
// 008e2f68  5e                   pop esi
// 008e2f69  c21400               ret 0x14
// library xtp-15.2.1/Source\Common\XTPHookManager.cpp (function ?Factor@CShadowWnd@CXTPShadowManager@@AAEIAAH00N@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPHookManager.cpp
