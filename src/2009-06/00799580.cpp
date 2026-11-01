// from server: 100% by auto
// roc 2009-06 00799580  unit: CXTPRibbonTheme  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00799580
//
// 00799580  83ec20               sub esp, 0x20
// 00799583  53                   push ebx
// 00799584  55                   push ebp
// 00799585  56                   push esi
// 00799586  57                   push edi
// 00799587  68cc0b9000           push 0x900bcc
// 0079958c  e82fa80000           call 0x7a3dc0
// 00799591  8bf0                 mov esi, eax
// 00799593  85f6                 test esi, esi
// 00799595  7479                 je 0x799610
// 00799597  8bce                 mov ecx, esi
// 00799599  e8a2c80600           call 0x805e40
// 0079959e  8bce                 mov ecx, esi
// 007995a0  8bf8                 mov edi, eax
// 007995a2  33db                 xor ebx, ebx
// 007995a4  33ed                 xor ebp, ebp
// 007995a6  e8b5c80600           call 0x805e60
// 007995ab  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007995af  8bd1                 mov edx, ecx
// 007995b1  2bd0                 sub edx, eax
// 007995b3  89542420             mov dword ptr [esp + 0x20], edx
// 007995b7  8b542444             mov edx, dword ptr [esp + 0x44]
// 007995bb  894c2428             mov dword ptr [esp + 0x28], ecx
// 007995bf  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 007995c3  2bd7                 sub edx, edi
// 007995c5  83ea04               sub edx, 4
// 007995c8  83c1fc               add ecx, -4
// 007995cb  68ff00ff00           push 0xff00ff
// 007995d0  89542428             mov dword ptr [esp + 0x28], edx
// 007995d4  894c2430             mov dword ptr [esp + 0x30], ecx
// 007995d8  33c9                 xor ecx, ecx
// 007995da  8d542414             lea edx, [esp + 0x14]
// 007995de  52                   push edx
// 007995df  83ec10               sub esp, 0x10
// 007995e2  894c2428             mov dword ptr [esp + 0x28], ecx
// 007995e6  894c242c             mov dword ptr [esp + 0x2c], ecx
// 007995ea  894c2430             mov dword ptr [esp + 0x30], ecx
// 007995ee  894c2434             mov dword ptr [esp + 0x34], ecx
// 007995f2  8bcc                 mov ecx, esp
// 007995f4  8919                 mov dword ptr [ecx], ebx
// 007995f6  896904               mov dword ptr [ecx + 4], ebp
// 007995f9  894108               mov dword ptr [ecx + 8], eax
// 007995fc  89790c               mov dword ptr [ecx + 0xc], edi
// 007995ff  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00799603  8d442438             lea eax, [esp + 0x38]
// 00799607  50                   push eax
// 00799608  51                   push ecx
// 00799609  8bce                 mov ecx, esi
// 0079960b  e8f0cc0600           call 0x806300
// 00799610  5f                   pop edi
// 00799611  5e                   pop esi
// 00799612  5d                   pop ebp
// 00799613  5b                   pop ebx
// 00799614  83c420               add esp, 0x20
// 00799617  c21400               ret 0x14
// library xtp-15.2.1/Source\Ribbon\XTPRibbonTheme.cpp (function ?DrawStatusBarGripper@CXTPRibbonTheme@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonTheme.cpp
