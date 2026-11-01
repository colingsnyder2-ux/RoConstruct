// from server: 100% by auto
// roc 2009-06 007b6710  unit: IIPAVCXTPMenuBarMDIMenuInfo::?$CMap  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b6710
//
// 007b6710  56                   push esi
// 007b6711  8bf1                 mov esi, ecx
// 007b6713  e812580900           call 0x84bf2a
// 007b6718  6a0a                 push 0xa
// 007b671a  8d4e20               lea ecx, [esi + 0x20]
// 007b671d  c706143b9000         mov dword ptr [esi], 0x903b14
// 007b6723  e888ffffff           call 0x7b66b0
// 007b6728  8b442408             mov eax, dword ptr [esp + 8]
// 007b672c  89463c               mov dword ptr [esi + 0x3c], eax
// 007b672f  8bc6                 mov eax, esi
// 007b6731  5e                   pop esi
// 007b6732  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ??0CXTPMenuBarMDIMenus@@QAE@PAVCXTPMenuBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
