// from server: 100% by auto
// roc 2010-06 00847b10  unit: IIPAVCXTPMenuBarMDIMenuInfo::?$CMap  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00847b10
//
// 00847b10  56                   push esi
// 00847b11  8bf1                 mov esi, ecx
// 00847b13  e866521300           call 0x97cd7e
// 00847b18  6a0a                 push 0xa
// 00847b1a  8d4e20               lea ecx, [esi + 0x20]
// 00847b1d  c706ac84a600         mov dword ptr [esi], 0xa684ac
// 00847b23  e818ffffff           call 0x847a40
// 00847b28  8b442408             mov eax, dword ptr [esp + 8]
// 00847b2c  89463c               mov dword ptr [esi + 0x3c], eax
// 00847b2f  8bc6                 mov eax, esi
// 00847b31  5e                   pop esi
// 00847b32  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPMenuBar.cpp (function ??0CXTPMenuBarMDIMenus@@QAE@PAVCXTPMenuBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMenuBar.cpp
