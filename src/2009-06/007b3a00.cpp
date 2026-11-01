// from server: 100% by auto
// roc 2009-06 007b3a00  unit: CXTPDockBar  size: 354 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b3a00
//
// 007b3a00  83ec20               sub esp, 0x20
// 007b3a03  894c2404             mov dword ptr [esp + 4], ecx
// 007b3a07  e8d0840900           call 0x84bedc
// 007b3a0c  890424               mov dword ptr [esp], eax
// 007b3a0f  a900000010           test eax, 0x10000000
// 007b3a14  0f8440010000         je 0x7b3b5a
// 007b3a1a  53                   push ebx
// 007b3a1b  55                   push ebp
// 007b3a1c  56                   push esi
// 007b3a1d  8b742434             mov esi, dword ptr [esp + 0x34]
// 007b3a21  57                   push edi
// 007b3a22  8d6e04               lea ebp, [esi + 4]
// 007b3a25  55                   push ebp
// 007b3a26  8d442424             lea eax, [esp + 0x24]
// 007b3a2a  50                   push eax
// 007b3a2b  ff1500ee8900         call dword ptr [0x89ee00]
// 007b3a31  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007b3a35  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 007b3a39  2b7c2420             sub edi, dword ptr [esp + 0x20]
// 007b3a3d  2b5c2424             sub ebx, dword ptr [esp + 0x24]
// 007b3a41  8b542414             mov edx, dword ptr [esp + 0x14]
// 007b3a45  8b4254               mov eax, dword ptr [edx + 0x54]
// 007b3a48  33c9                 xor ecx, ecx
// 007b3a4a  394e1c               cmp dword ptr [esi + 0x1c], ecx
// 007b3a4d  0f95c1               setne cl
// 007b3a50  a804                 test al, 4
// 007b3a52  7409                 je 0x7b3a5d
// 007b3a54  a801                 test al, 1
// 007b3a56  7405                 je 0x7b3a5d
// 007b3a58  83c906               or ecx, 6
// 007b3a5b  eb12                 jmp 0x7b3a6f
// 007b3a5d  f744241000a00000     test dword ptr [esp + 0x10], 0xa000
// 007b3a65  7405                 je 0x7b3a6c
// 007b3a67  83c90a               or ecx, 0xa
// 007b3a6a  eb03                 jmp 0x7b3a6f
// 007b3a6c  83c910               or ecx, 0x10
// 007b3a6f  8b442410             mov eax, dword ptr [esp + 0x10]
// 007b3a73  2500a00000           and eax, 0xa000
// 007b3a78  89442438             mov dword ptr [esp + 0x38], eax
// 007b3a7c  8bc7                 mov eax, edi
// 007b3a7e  7502                 jne 0x7b3a82
// 007b3a80  8bc3                 mov eax, ebx
// 007b3a82  56                   push esi
// 007b3a83  51                   push ecx
// 007b3a84  50                   push eax
// 007b3a85  8d4c2424             lea ecx, [esp + 0x24]
// 007b3a89  51                   push ecx
// 007b3a8a  8bca                 mov ecx, edx
// 007b3a8c  e8affdffff           call 0x7b3840
// 007b3a91  8b442418             mov eax, dword ptr [esp + 0x18]
// 007b3a95  3bc7                 cmp eax, edi
// 007b3a97  7c02                 jl 0x7b3a9b
// 007b3a99  8bc7                 mov eax, edi
// 007b3a9b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007b3a9f  3bcb                 cmp ecx, ebx
// 007b3aa1  7c02                 jl 0x7b3aa5
// 007b3aa3  8bcb                 mov ecx, ebx
// 007b3aa5  837c243800           cmp dword ptr [esp + 0x38], 0
// 007b3aaa  7437                 je 0x7b3ae3
// 007b3aac  8b5614               mov edx, dword ptr [esi + 0x14]
// 007b3aaf  014e18               add dword ptr [esi + 0x18], ecx
// 007b3ab2  3bd0                 cmp edx, eax
// 007b3ab4  7f02                 jg 0x7b3ab8
// 007b3ab6  8bd0                 mov edx, eax
// 007b3ab8  895614               mov dword ptr [esi + 0x14], edx
// 007b3abb  8b542410             mov edx, dword ptr [esp + 0x10]
// 007b3abf  f7c200200000         test edx, 0x2000
// 007b3ac5  7405                 je 0x7b3acc
// 007b3ac7  014e08               add dword ptr [esi + 8], ecx
// 007b3aca  eb4c                 jmp 0x7b3b18
// 007b3acc  f7c200800000         test edx, 0x8000
// 007b3ad2  7444                 je 0x7b3b18
// 007b3ad4  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007b3ad8  2bd1                 sub edx, ecx
// 007b3ada  294e10               sub dword ptr [esi + 0x10], ecx
// 007b3add  89542424             mov dword ptr [esp + 0x24], edx
// 007b3ae1  eb35                 jmp 0x7b3b18
// 007b3ae3  8b5618               mov edx, dword ptr [esi + 0x18]
// 007b3ae6  014614               add dword ptr [esi + 0x14], eax
// 007b3ae9  3bd1                 cmp edx, ecx
// 007b3aeb  7f02                 jg 0x7b3aef
// 007b3aed  8bd1                 mov edx, ecx
// 007b3aef  895618               mov dword ptr [esi + 0x18], edx
// 007b3af2  8b542410             mov edx, dword ptr [esp + 0x10]
// 007b3af6  f7c200100000         test edx, 0x1000
// 007b3afc  7405                 je 0x7b3b03
// 007b3afe  014500               add dword ptr [ebp], eax
// 007b3b01  eb15                 jmp 0x7b3b18
// 007b3b03  f7c200400000         test edx, 0x4000
// 007b3b09  740d                 je 0x7b3b18
// 007b3b0b  8b542428             mov edx, dword ptr [esp + 0x28]
// 007b3b0f  2bd0                 sub edx, eax
// 007b3b11  29460c               sub dword ptr [esi + 0xc], eax
// 007b3b14  89542420             mov dword ptr [esp + 0x20], edx
// 007b3b18  8b542420             mov edx, dword ptr [esp + 0x20]
// 007b3b1c  03d0                 add edx, eax
// 007b3b1e  8b442424             mov eax, dword ptr [esp + 0x24]
// 007b3b22  03c1                 add eax, ecx
// 007b3b24  833e00               cmp dword ptr [esi], 0
// 007b3b27  89542428             mov dword ptr [esp + 0x28], edx
// 007b3b2b  8944242c             mov dword ptr [esp + 0x2c], eax
// 007b3b2f  7413                 je 0x7b3b44
// 007b3b31  8b542414             mov edx, dword ptr [esp + 0x14]
// 007b3b35  8b4220               mov eax, dword ptr [edx + 0x20]
// 007b3b38  8d4c2420             lea ecx, [esp + 0x20]
// 007b3b3c  51                   push ecx
// 007b3b3d  50                   push eax
// 007b3b3e  56                   push esi
// 007b3b3f  e842850900           call 0x84c086
// 007b3b44  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007b3b48  8b5120               mov edx, dword ptr [ecx + 0x20]
// 007b3b4b  6a00                 push 0
// 007b3b4d  6a00                 push 0
// 007b3b4f  52                   push edx
// 007b3b50  ff157cee8900         call dword ptr [0x89ee7c]
// 007b3b56  5f                   pop edi
// 007b3b57  5e                   pop esi
// 007b3b58  5d                   pop ebp
// 007b3b59  5b                   pop ebx
// 007b3b5a  33c0                 xor eax, eax
// 007b3b5c  83c420               add esp, 0x20
// 007b3b5f  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ?OnSizeParent@CXTPDockBar@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp
