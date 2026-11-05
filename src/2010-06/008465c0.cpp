// from server: 100% by auto
// roc 2010-06 008465c0  unit: CXTPDockBar  size: 354 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008465c0
//
// 008465c0  83ec20               sub esp, 0x20
// 008465c3  894c2404             mov dword ptr [esp + 4], ecx
// 008465c7  e812681300           call 0x97cdde
// 008465cc  890424               mov dword ptr [esp], eax
// 008465cf  a900000010           test eax, 0x10000000
// 008465d4  0f8440010000         je 0x84671a
// 008465da  53                   push ebx
// 008465db  55                   push ebp
// 008465dc  56                   push esi
// 008465dd  8b742434             mov esi, dword ptr [esp + 0x34]
// 008465e1  57                   push edi
// 008465e2  8d6e04               lea ebp, [esi + 4]
// 008465e5  55                   push ebp
// 008465e6  8d442424             lea eax, [esp + 0x24]
// 008465ea  50                   push eax
// 008465eb  ff1548bc9e00         call dword ptr [0x9ebc48]
// 008465f1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 008465f5  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 008465f9  2b7c2420             sub edi, dword ptr [esp + 0x20]
// 008465fd  2b5c2424             sub ebx, dword ptr [esp + 0x24]
// 00846601  8b542414             mov edx, dword ptr [esp + 0x14]
// 00846605  8b4254               mov eax, dword ptr [edx + 0x54]
// 00846608  33c9                 xor ecx, ecx
// 0084660a  394e1c               cmp dword ptr [esi + 0x1c], ecx
// 0084660d  0f95c1               setne cl
// 00846610  a804                 test al, 4
// 00846612  7409                 je 0x84661d
// 00846614  a801                 test al, 1
// 00846616  7405                 je 0x84661d
// 00846618  83c906               or ecx, 6
// 0084661b  eb12                 jmp 0x84662f
// 0084661d  f744241000a00000     test dword ptr [esp + 0x10], 0xa000
// 00846625  7405                 je 0x84662c
// 00846627  83c90a               or ecx, 0xa
// 0084662a  eb03                 jmp 0x84662f
// 0084662c  83c910               or ecx, 0x10
// 0084662f  8b442410             mov eax, dword ptr [esp + 0x10]
// 00846633  2500a00000           and eax, 0xa000
// 00846638  89442438             mov dword ptr [esp + 0x38], eax
// 0084663c  8bc7                 mov eax, edi
// 0084663e  7502                 jne 0x846642
// 00846640  8bc3                 mov eax, ebx
// 00846642  56                   push esi
// 00846643  51                   push ecx
// 00846644  50                   push eax
// 00846645  8d4c2424             lea ecx, [esp + 0x24]
// 00846649  51                   push ecx
// 0084664a  8bca                 mov ecx, edx
// 0084664c  e8affdffff           call 0x846400
// 00846651  8b442418             mov eax, dword ptr [esp + 0x18]
// 00846655  3bc7                 cmp eax, edi
// 00846657  7c02                 jl 0x84665b
// 00846659  8bc7                 mov eax, edi
// 0084665b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0084665f  3bcb                 cmp ecx, ebx
// 00846661  7c02                 jl 0x846665
// 00846663  8bcb                 mov ecx, ebx
// 00846665  837c243800           cmp dword ptr [esp + 0x38], 0
// 0084666a  7437                 je 0x8466a3
// 0084666c  8b5614               mov edx, dword ptr [esi + 0x14]
// 0084666f  014e18               add dword ptr [esi + 0x18], ecx
// 00846672  3bd0                 cmp edx, eax
// 00846674  7f02                 jg 0x846678
// 00846676  8bd0                 mov edx, eax
// 00846678  895614               mov dword ptr [esi + 0x14], edx
// 0084667b  8b542410             mov edx, dword ptr [esp + 0x10]
// 0084667f  f7c200200000         test edx, 0x2000
// 00846685  7405                 je 0x84668c
// 00846687  014e08               add dword ptr [esi + 8], ecx
// 0084668a  eb4c                 jmp 0x8466d8
// 0084668c  f7c200800000         test edx, 0x8000
// 00846692  7444                 je 0x8466d8
// 00846694  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00846698  2bd1                 sub edx, ecx
// 0084669a  294e10               sub dword ptr [esi + 0x10], ecx
// 0084669d  89542424             mov dword ptr [esp + 0x24], edx
// 008466a1  eb35                 jmp 0x8466d8
// 008466a3  8b5618               mov edx, dword ptr [esi + 0x18]
// 008466a6  014614               add dword ptr [esi + 0x14], eax
// 008466a9  3bd1                 cmp edx, ecx
// 008466ab  7f02                 jg 0x8466af
// 008466ad  8bd1                 mov edx, ecx
// 008466af  895618               mov dword ptr [esi + 0x18], edx
// 008466b2  8b542410             mov edx, dword ptr [esp + 0x10]
// 008466b6  f7c200100000         test edx, 0x1000
// 008466bc  7405                 je 0x8466c3
// 008466be  014500               add dword ptr [ebp], eax
// 008466c1  eb15                 jmp 0x8466d8
// 008466c3  f7c200400000         test edx, 0x4000
// 008466c9  740d                 je 0x8466d8
// 008466cb  8b542428             mov edx, dword ptr [esp + 0x28]
// 008466cf  2bd0                 sub edx, eax
// 008466d1  29460c               sub dword ptr [esi + 0xc], eax
// 008466d4  89542420             mov dword ptr [esp + 0x20], edx
// 008466d8  8b542420             mov edx, dword ptr [esp + 0x20]
// 008466dc  03d0                 add edx, eax
// 008466de  8b442424             mov eax, dword ptr [esp + 0x24]
// 008466e2  03c1                 add eax, ecx
// 008466e4  833e00               cmp dword ptr [esi], 0
// 008466e7  89542428             mov dword ptr [esp + 0x28], edx
// 008466eb  8944242c             mov dword ptr [esp + 0x2c], eax
// 008466ef  7413                 je 0x846704
// 008466f1  8b542414             mov edx, dword ptr [esp + 0x14]
// 008466f5  8b4220               mov eax, dword ptr [edx + 0x20]
// 008466f8  8d4c2420             lea ecx, [esp + 0x20]
// 008466fc  51                   push ecx
// 008466fd  50                   push eax
// 008466fe  56                   push esi
// 008466ff  e8fa671300           call 0x97cefe
// 00846704  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00846708  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0084670b  6a00                 push 0
// 0084670d  6a00                 push 0
// 0084670f  52                   push edx
// 00846710  ff1578ba9e00         call dword ptr [0x9eba78]
// 00846716  5f                   pop edi
// 00846717  5e                   pop esi
// 00846718  5d                   pop ebp
// 00846719  5b                   pop ebx
// 0084671a  33c0                 xor eax, eax
// 0084671c  83c420               add esp, 0x20
// 0084671f  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPDockBar.cpp (function ?OnSizeParent@CXTPDockBar@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDockBar.cpp
