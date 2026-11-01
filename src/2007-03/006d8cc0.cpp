// from server: 100% by auto
// roc 2007-03 006d8cc0  unit: seg_006d0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006d8cc0
//
// 006d8cc0  56                   push esi
// 006d8cc1  8bf1                 mov esi, ecx
// 006d8cc3  e8061e0600           call 0x73aace
// 006d8cc8  8d4e20               lea ecx, [esi + 0x20]
// 006d8ccb  c7069c7d7d00         mov dword ptr [esi], 0x7d7d9c
// 006d8cd1  e88affffff           call 0x6d8c60
// 006d8cd6  8b442408             mov eax, dword ptr [esp + 8]
// 006d8cda  894634               mov dword ptr [esi + 0x34], eax
// 006d8cdd  8bc6                 mov eax, esi
// 006d8cdf  5e                   pop esi
// 006d8ce0  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ??0CXTPControlActions@@IAE@PAVCXTPCommandBars@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
