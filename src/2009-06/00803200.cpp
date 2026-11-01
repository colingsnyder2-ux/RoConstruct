// from server: 100% by auto
// roc 2009-06 00803200  unit: CXTColorWnd  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00803200
//
// 00803200  83ec14               sub esp, 0x14
// 00803203  dd442418             fld qword ptr [esp + 0x18]
// 00803207  56                   push esi
// 00803208  8bf1                 mov esi, ecx
// 0080320a  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0080320d  dd5e68               fstp qword ptr [esi + 0x68]
// 00803210  8d442408             lea eax, [esp + 8]
// 00803214  50                   push eax
// 00803215  51                   push ecx
// 00803216  ff1514ee8900         call dword ptr [0x89ee14]
// 0080321c  8b542410             mov edx, dword ptr [esp + 0x10]
// 00803220  2b542408             sub edx, dword ptr [esp + 8]
// 00803224  89542404             mov dword ptr [esp + 4], edx
// 00803228  db442404             fild dword ptr [esp + 4]
// 0080322c  dc4c241c             fmul qword ptr [esp + 0x1c]
// 00803230  e88b6cf1ff           call 0x719ec0
// 00803235  6a00                 push 0
// 00803237  894670               mov dword ptr [esi + 0x70], eax
// 0080323a  8b4620               mov eax, dword ptr [esi + 0x20]
// 0080323d  6a00                 push 0
// 0080323f  50                   push eax
// 00803240  ff157cee8900         call dword ptr [0x89ee7c]
// 00803246  5e                   pop esi
// 00803247  83c414               add esp, 0x14
// 0080324a  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?SetHue@CXTPColorWnd@@QAEXN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
