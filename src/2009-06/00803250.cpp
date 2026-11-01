// from server: 100% by auto
// roc 2009-06 00803250  unit: CXTColorWnd  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00803250
//
// 00803250  83ec14               sub esp, 0x14
// 00803253  dd442418             fld qword ptr [esp + 0x18]
// 00803257  53                   push ebx
// 00803258  56                   push esi
// 00803259  57                   push edi
// 0080325a  8bf1                 mov esi, ecx
// 0080325c  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0080325f  dd5e60               fstp qword ptr [esi + 0x60]
// 00803262  8d442410             lea eax, [esp + 0x10]
// 00803266  50                   push eax
// 00803267  51                   push ecx
// 00803268  ff1514ee8900         call dword ptr [0x89ee14]
// 0080326e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00803272  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00803276  8bd7                 mov edx, edi
// 00803278  2bd3                 sub edx, ebx
// 0080327a  8954240c             mov dword ptr [esp + 0xc], edx
// 0080327e  db44240c             fild dword ptr [esp + 0xc]
// 00803282  dc4c2424             fmul qword ptr [esp + 0x24]
// 00803286  e8356cf1ff           call 0x719ec0
// 0080328b  6a00                 push 0
// 0080328d  2bf8                 sub edi, eax
// 0080328f  8b4620               mov eax, dword ptr [esi + 0x20]
// 00803292  6a00                 push 0
// 00803294  2bfb                 sub edi, ebx
// 00803296  50                   push eax
// 00803297  897e74               mov dword ptr [esi + 0x74], edi
// 0080329a  ff157cee8900         call dword ptr [0x89ee7c]
// 008032a0  5f                   pop edi
// 008032a1  5e                   pop esi
// 008032a2  5b                   pop ebx
// 008032a3  83c414               add esp, 0x14
// 008032a6  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?SetSaturation@CXTPColorWnd@@QAEXN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
