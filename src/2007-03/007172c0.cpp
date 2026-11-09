// from server: 100% by auto
// roc 2007-03 007172c0  unit: seg_00710000  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007172c0
//
// 007172c0  8b4158               mov eax, dword ptr [ecx + 0x58]
// 007172c3  83ec38               sub esp, 0x38
// 007172c6  81780400000600       cmp dword ptr [eax + 4], 0x60000
// 007172cd  7308                 jae 0x7172d7
// 007172cf  33c0                 xor eax, eax
// 007172d1  83c438               add esp, 0x38
// 007172d4  c20400               ret 4
// 007172d7  56                   push esi
// 007172d8  8b742440             mov esi, dword ptr [esp + 0x40]
// 007172dc  8d4c241c             lea ecx, [esp + 0x1c]
// 007172e0  51                   push ecx
// 007172e1  6a00                 push 0
// 007172e3  56                   push esi
// 007172e4  ff1554d07700         call dword ptr [0x77d054]
// 007172ea  85c0                 test eax, eax
// 007172ec  741a                 je 0x717308
// 007172ee  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007172f2  8d542404             lea edx, [esp + 4]
// 007172f6  52                   push edx
// 007172f7  6a18                 push 0x18
// 007172f9  50                   push eax
// 007172fa  ff15d0d07700         call dword ptr [0x77d0d0]
// 00717300  66837c241620         cmp word ptr [esp + 0x16], 0x20
// 00717306  7409                 je 0x717311
// 00717308  33c0                 xor eax, eax
// 0071730a  5e                   pop esi
// 0071730b  83c438               add esp, 0x38
// 0071730e  c20400               ret 4
// 00717311  56                   push esi
// 00717312  ff1550d07700         call dword ptr [0x77d050]
// 00717318  33c9                 xor ecx, ecx
// 0071731a  83f8ff               cmp eax, -1
// 0071731d  0f94c1               sete cl
// 00717320  5e                   pop esi
// 00717321  8bc1                 mov eax, ecx
// 00717323  83c438               add esp, 0x38
// 00717326  c20400               ret 4
// library xtp-13.2.1/Source\SkinFramework\XTPSkinObjectToolBar.cpp (function ?IsAlphaImageList@CXTPSkinObjectToolBar@@IAEHPAU_IMAGELIST@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SkinFramework/XTPSkinObjectToolBar.cpp
