// from server: 100% by auto
// roc 2007-03 00698760  unit: seg_00690000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00698760
//
// 00698760  56                   push esi
// 00698761  8bf1                 mov esi, ecx
// 00698763  e866230a00           call 0x73aace
// 00698768  6a0a                 push 0xa
// 0069876a  8d4e20               lea ecx, [esi + 0x20]
// 0069876d  c7064c1a7d00         mov dword ptr [esi], 0x7d1a4c
// 00698773  e888ffffff           call 0x698700
// 00698778  8b442408             mov eax, dword ptr [esp + 8]
// 0069877c  89463c               mov dword ptr [esi + 0x3c], eax
// 0069877f  8bc6                 mov eax, esi
// 00698781  5e                   pop esi
// 00698782  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ??0CXTPMenuBarMDIMenus@@QAE@PAVCXTPMenuBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
