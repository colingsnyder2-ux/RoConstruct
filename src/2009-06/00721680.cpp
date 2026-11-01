// from server: 100% by auto
// roc 2009-06 00721680  unit: PAVCXTPControlAction::?$CArray  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00721680
//
// 00721680  56                   push esi
// 00721681  8bf1                 mov esi, ecx
// 00721683  e8a2a81200           call 0x84bf2a
// 00721688  8d4e20               lea ecx, [esi + 0x20]
// 0072168b  c70624228f00         mov dword ptr [esi], 0x8f2224
// 00721691  e81afbffff           call 0x7211b0
// 00721696  8b442408             mov eax, dword ptr [esp + 8]
// 0072169a  894634               mov dword ptr [esi + 0x34], eax
// 0072169d  8bc6                 mov eax, esi
// 0072169f  5e                   pop esi
// 007216a0  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ??0CXTPControlActions@@IAE@PAVCXTPCommandBars@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
