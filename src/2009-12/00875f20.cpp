// from server: 100% by auto
// roc 2009-12 00875f20  unit: CXTPRibbonTheme  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00875f20
//
// 00875f20  83ec20               sub esp, 0x20
// 00875f23  53                   push ebx
// 00875f24  55                   push ebp
// 00875f25  56                   push esi
// 00875f26  57                   push edi
// 00875f27  68ac17a000           push 0xa017ac
// 00875f2c  e8cf8d0000           call 0x87ed00
// 00875f31  8bf0                 mov esi, eax
// 00875f33  85f6                 test esi, esi
// 00875f35  7479                 je 0x875fb0
// 00875f37  8bce                 mov ecx, esi
// 00875f39  e802aa0600           call 0x8e0940
// 00875f3e  8bce                 mov ecx, esi
// 00875f40  8bf8                 mov edi, eax
// 00875f42  33db                 xor ebx, ebx
// 00875f44  33ed                 xor ebp, ebp
// 00875f46  e815aa0600           call 0x8e0960
// 00875f4b  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00875f4f  8bd1                 mov edx, ecx
// 00875f51  2bd0                 sub edx, eax
// 00875f53  89542420             mov dword ptr [esp + 0x20], edx
// 00875f57  8b542444             mov edx, dword ptr [esp + 0x44]
// 00875f5b  894c2428             mov dword ptr [esp + 0x28], ecx
// 00875f5f  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00875f63  2bd7                 sub edx, edi
// 00875f65  83ea04               sub edx, 4
// 00875f68  83c1fc               add ecx, -4
// 00875f6b  68ff00ff00           push 0xff00ff
// 00875f70  89542428             mov dword ptr [esp + 0x28], edx
// 00875f74  894c2430             mov dword ptr [esp + 0x30], ecx
// 00875f78  33c9                 xor ecx, ecx
// 00875f7a  8d542414             lea edx, [esp + 0x14]
// 00875f7e  52                   push edx
// 00875f7f  83ec10               sub esp, 0x10
// 00875f82  894c2428             mov dword ptr [esp + 0x28], ecx
// 00875f86  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00875f8a  894c2430             mov dword ptr [esp + 0x30], ecx
// 00875f8e  894c2434             mov dword ptr [esp + 0x34], ecx
// 00875f92  8bcc                 mov ecx, esp
// 00875f94  8919                 mov dword ptr [ecx], ebx
// 00875f96  896904               mov dword ptr [ecx + 4], ebp
// 00875f99  894108               mov dword ptr [ecx + 8], eax
// 00875f9c  89790c               mov dword ptr [ecx + 0xc], edi
// 00875f9f  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00875fa3  8d442438             lea eax, [esp + 0x38]
// 00875fa7  50                   push eax
// 00875fa8  51                   push ecx
// 00875fa9  8bce                 mov ecx, esi
// 00875fab  e850ae0600           call 0x8e0e00
// 00875fb0  5f                   pop edi
// 00875fb1  5e                   pop esi
// 00875fb2  5d                   pop ebp
// 00875fb3  5b                   pop ebx
// 00875fb4  83c420               add esp, 0x20
// 00875fb7  c21400               ret 0x14
// library xtp-15.2.1/Source\Ribbon\XTPRibbonTheme.cpp (function ?DrawStatusBarGripper@CXTPRibbonTheme@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonTheme.cpp
