// from server: 100% by auto
// roc 2009-12 008923e0  unit: CXTPDockBar  size: 354 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008923e0
//
// 008923e0  83ec20               sub esp, 0x20
// 008923e3  894c2404             mov dword ptr [esp + 4], ecx
// 008923e7  e886400900           call 0x926472
// 008923ec  890424               mov dword ptr [esp], eax
// 008923ef  a900000010           test eax, 0x10000000
// 008923f4  0f8440010000         je 0x89253a
// 008923fa  53                   push ebx
// 008923fb  55                   push ebp
// 008923fc  56                   push esi
// 008923fd  8b742434             mov esi, dword ptr [esp + 0x34]
// 00892401  57                   push edi
// 00892402  8d6e04               lea ebp, [esi + 4]
// 00892405  55                   push ebp
// 00892406  8d442424             lea eax, [esp + 0x24]
// 0089240a  50                   push eax
// 0089240b  ff1564cc9800         call dword ptr [0x98cc64]
// 00892411  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00892415  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 00892419  2b7c2420             sub edi, dword ptr [esp + 0x20]
// 0089241d  2b5c2424             sub ebx, dword ptr [esp + 0x24]
// 00892421  8b542414             mov edx, dword ptr [esp + 0x14]
// 00892425  8b4254               mov eax, dword ptr [edx + 0x54]
// 00892428  33c9                 xor ecx, ecx
// 0089242a  394e1c               cmp dword ptr [esi + 0x1c], ecx
// 0089242d  0f95c1               setne cl
// 00892430  a804                 test al, 4
// 00892432  7409                 je 0x89243d
// 00892434  a801                 test al, 1
// 00892436  7405                 je 0x89243d
// 00892438  83c906               or ecx, 6
// 0089243b  eb12                 jmp 0x89244f
// 0089243d  f744241000a00000     test dword ptr [esp + 0x10], 0xa000
// 00892445  7405                 je 0x89244c
// 00892447  83c90a               or ecx, 0xa
// 0089244a  eb03                 jmp 0x89244f
// 0089244c  83c910               or ecx, 0x10
// 0089244f  8b442410             mov eax, dword ptr [esp + 0x10]
// 00892453  2500a00000           and eax, 0xa000
// 00892458  89442438             mov dword ptr [esp + 0x38], eax
// 0089245c  8bc7                 mov eax, edi
// 0089245e  7502                 jne 0x892462
// 00892460  8bc3                 mov eax, ebx
// 00892462  56                   push esi
// 00892463  51                   push ecx
// 00892464  50                   push eax
// 00892465  8d4c2424             lea ecx, [esp + 0x24]
// 00892469  51                   push ecx
// 0089246a  8bca                 mov ecx, edx
// 0089246c  e8affdffff           call 0x892220
// 00892471  8b442418             mov eax, dword ptr [esp + 0x18]
// 00892475  3bc7                 cmp eax, edi
// 00892477  7c02                 jl 0x89247b
// 00892479  8bc7                 mov eax, edi
// 0089247b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0089247f  3bcb                 cmp ecx, ebx
// 00892481  7c02                 jl 0x892485
// 00892483  8bcb                 mov ecx, ebx
// 00892485  837c243800           cmp dword ptr [esp + 0x38], 0
// 0089248a  7437                 je 0x8924c3
// 0089248c  8b5614               mov edx, dword ptr [esi + 0x14]
// 0089248f  014e18               add dword ptr [esi + 0x18], ecx
// 00892492  3bd0                 cmp edx, eax
// 00892494  7f02                 jg 0x892498
// 00892496  8bd0                 mov edx, eax
// 00892498  895614               mov dword ptr [esi + 0x14], edx
// 0089249b  8b542410             mov edx, dword ptr [esp + 0x10]
// 0089249f  f7c200200000         test edx, 0x2000
// 008924a5  7405                 je 0x8924ac
// 008924a7  014e08               add dword ptr [esi + 8], ecx
// 008924aa  eb4c                 jmp 0x8924f8
// 008924ac  f7c200800000         test edx, 0x8000
// 008924b2  7444                 je 0x8924f8
// 008924b4  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 008924b8  2bd1                 sub edx, ecx
// 008924ba  294e10               sub dword ptr [esi + 0x10], ecx
// 008924bd  89542424             mov dword ptr [esp + 0x24], edx
// 008924c1  eb35                 jmp 0x8924f8
// 008924c3  8b5618               mov edx, dword ptr [esi + 0x18]
// 008924c6  014614               add dword ptr [esi + 0x14], eax
// 008924c9  3bd1                 cmp edx, ecx
// 008924cb  7f02                 jg 0x8924cf
// 008924cd  8bd1                 mov edx, ecx
// 008924cf  895618               mov dword ptr [esi + 0x18], edx
// 008924d2  8b542410             mov edx, dword ptr [esp + 0x10]
// 008924d6  f7c200100000         test edx, 0x1000
// 008924dc  7405                 je 0x8924e3
// 008924de  014500               add dword ptr [ebp], eax
// 008924e1  eb15                 jmp 0x8924f8
// 008924e3  f7c200400000         test edx, 0x4000
// 008924e9  740d                 je 0x8924f8
// 008924eb  8b542428             mov edx, dword ptr [esp + 0x28]
// 008924ef  2bd0                 sub edx, eax
// 008924f1  29460c               sub dword ptr [esi + 0xc], eax
// 008924f4  89542420             mov dword ptr [esp + 0x20], edx
// 008924f8  8b542420             mov edx, dword ptr [esp + 0x20]
// 008924fc  03d0                 add edx, eax
// 008924fe  8b442424             mov eax, dword ptr [esp + 0x24]
// 00892502  03c1                 add eax, ecx
// 00892504  833e00               cmp dword ptr [esi], 0
// 00892507  89542428             mov dword ptr [esp + 0x28], edx
// 0089250b  8944242c             mov dword ptr [esp + 0x2c], eax
// 0089250f  7413                 je 0x892524
// 00892511  8b542414             mov edx, dword ptr [esp + 0x14]
// 00892515  8b4220               mov eax, dword ptr [edx + 0x20]
// 00892518  8d4c2420             lea ecx, [esp + 0x20]
// 0089251c  51                   push ecx
// 0089251d  50                   push eax
// 0089251e  56                   push esi
// 0089251f  e89e400900           call 0x9265c2
// 00892524  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00892528  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0089252b  6a00                 push 0
// 0089252d  6a00                 push 0
// 0089252f  52                   push edx
// 00892530  ff15e8cb9800         call dword ptr [0x98cbe8]
// 00892536  5f                   pop edi
// 00892537  5e                   pop esi
// 00892538  5d                   pop ebp
// 00892539  5b                   pop ebx
// 0089253a  33c0                 xor eax, eax
// 0089253c  83c420               add esp, 0x20
// 0089253f  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ?OnSizeParent@CXTPDockBar@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp
