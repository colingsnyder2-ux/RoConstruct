// from server: 100% by auto
// roc 2009-06 00808430  unit: CXTShadowHook  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00808430
//
// 00808430  8b442404             mov eax, dword ptr [esp + 4]
// 00808434  db00                 fild dword ptr [eax]
// 00808436  56                   push esi
// 00808437  dd442414             fld qword ptr [esp + 0x14]
// 0080843b  dcc9                 fmul st(1), st(0)
// 0080843d  d9c9                 fxch st(1)
// 0080843f  e87c1af1ff           call 0x719ec0
// 00808444  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00808448  db01                 fild dword ptr [ecx]
// 0080844a  8bf0                 mov esi, eax
// 0080844c  c1e608               shl esi, 8
// 0080844f  d8c9                 fmul st(1)
// 00808451  e86a1af1ff           call 0x719ec0
// 00808456  8b542410             mov edx, dword ptr [esp + 0x10]
// 0080845a  da0a                 fimul dword ptr [edx]
// 0080845c  03f0                 add esi, eax
// 0080845e  c1e608               shl esi, 8
// 00808461  e85a1af1ff           call 0x719ec0
// 00808466  03c6                 add eax, esi
// 00808468  5e                   pop esi
// 00808469  c21400               ret 0x14
// library xtp-15.2.1/Source\Common\XTPHookManager.cpp (function ?Factor@CShadowWnd@CXTPShadowManager@@AAEIAAH00N@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPHookManager.cpp
