// from server: 100% by auto
// roc 2010-06 00830e50  unit: CXTPRibbonTheme  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00830e50
//
// 00830e50  83ec20               sub esp, 0x20
// 00830e53  53                   push ebx
// 00830e54  55                   push ebp
// 00830e55  56                   push esi
// 00830e56  57                   push edi
// 00830e57  68ec60a600           push 0xa660ec
// 00830e5c  e89f130000           call 0x832200
// 00830e61  8bf0                 mov esi, eax
// 00830e63  85f6                 test esi, esi
// 00830e65  7479                 je 0x830ee0
// 00830e67  8bce                 mov ecx, esi
// 00830e69  e8423d0600           call 0x894bb0
// 00830e6e  8bce                 mov ecx, esi
// 00830e70  8bf8                 mov edi, eax
// 00830e72  33db                 xor ebx, ebx
// 00830e74  33ed                 xor ebp, ebp
// 00830e76  e8553d0600           call 0x894bd0
// 00830e7b  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00830e7f  8bd1                 mov edx, ecx
// 00830e81  2bd0                 sub edx, eax
// 00830e83  89542420             mov dword ptr [esp + 0x20], edx
// 00830e87  8b542444             mov edx, dword ptr [esp + 0x44]
// 00830e8b  894c2428             mov dword ptr [esp + 0x28], ecx
// 00830e8f  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00830e93  2bd7                 sub edx, edi
// 00830e95  83ea04               sub edx, 4
// 00830e98  83c1fc               add ecx, -4
// 00830e9b  68ff00ff00           push 0xff00ff
// 00830ea0  89542428             mov dword ptr [esp + 0x28], edx
// 00830ea4  894c2430             mov dword ptr [esp + 0x30], ecx
// 00830ea8  33c9                 xor ecx, ecx
// 00830eaa  8d542414             lea edx, [esp + 0x14]
// 00830eae  52                   push edx
// 00830eaf  83ec10               sub esp, 0x10
// 00830eb2  894c2428             mov dword ptr [esp + 0x28], ecx
// 00830eb6  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00830eba  894c2430             mov dword ptr [esp + 0x30], ecx
// 00830ebe  894c2434             mov dword ptr [esp + 0x34], ecx
// 00830ec2  8bcc                 mov ecx, esp
// 00830ec4  8919                 mov dword ptr [ecx], ebx
// 00830ec6  896904               mov dword ptr [ecx + 4], ebp
// 00830ec9  894108               mov dword ptr [ecx + 8], eax
// 00830ecc  89790c               mov dword ptr [ecx + 0xc], edi
// 00830ecf  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00830ed3  8d442438             lea eax, [esp + 0x38]
// 00830ed7  50                   push eax
// 00830ed8  51                   push ecx
// 00830ed9  8bce                 mov ecx, esi
// 00830edb  e890410600           call 0x895070
// 00830ee0  5f                   pop edi
// 00830ee1  5e                   pop esi
// 00830ee2  5d                   pop ebp
// 00830ee3  5b                   pop ebx
// 00830ee4  83c420               add esp, 0x20
// 00830ee7  c21400               ret 0x14
// library xtp-13.2.1/Source\Ribbon\XTPRibbonTheme.cpp (function ?DrawStatusBarGripper@CXTPRibbonTheme@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonTheme.cpp
