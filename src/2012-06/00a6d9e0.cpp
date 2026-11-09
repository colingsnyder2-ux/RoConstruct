// roc 2012-06 00a6d9e0  unit: CXTPTabPaintManager::CColorSetOffice2003  size: 1232 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a6d9e0
//
// 00a6d9e0  83ec08               sub esp, 8
// 00a6d9e3  53                   push ebx
// 00a6d9e4  55                   push ebp
// 00a6d9e5  56                   push esi
// 00a6d9e6  57                   push edi
// 00a6d9e7  8bf1                 mov esi, ecx
// 00a6d9e9  e842f4ffff           call 0xa6ce30
// 00a6d9ee  e86dfef4ff           call 0x9bd860
// 00a6d9f3  6a05                 push 5
// 00a6d9f5  8bc8                 mov ecx, eax
// 00a6d9f7  e8e4f5f4ff           call 0x9bcfe0
// 00a6d9fc  8bd8                 mov ebx, eax
// 00a6d9fe  e85dfef4ff           call 0x9bd860
// 00a6da03  6a0f                 push 0xf
// 00a6da05  8bc8                 mov ecx, eax
// 00a6da07  e8d4f5f4ff           call 0x9bcfe0
// 00a6da0c  8be8                 mov ebp, eax
// 00a6da0e  e84dfef4ff           call 0x9bd860
// 00a6da13  89442410             mov dword ptr [esp + 0x10], eax
// 00a6da17  e844fef4ff           call 0x9bd860
// 00a6da1c  6a0f                 push 0xf
// 00a6da1e  8bc8                 mov ecx, eax
// 00a6da20  e8bbf5f4ff           call 0x9bcfe0
// 00a6da25  d9057027b600         fld dword ptr [0xb62770]
// 00a6da2b  51                   push ecx
// 00a6da2c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00a6da30  d91c24               fstp dword ptr [esp]
// 00a6da33  68cd000000           push 0xcd
// 00a6da38  53                   push ebx
// 00a6da39  55                   push ebp
// 00a6da3a  89442424             mov dword ptr [esp + 0x24], eax
// 00a6da3e  8d7e04               lea edi, [esi + 4]
// 00a6da41  e8eaf4f4ff           call 0x9bcf30
// 00a6da46  50                   push eax
// 00a6da47  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00a6da4b  50                   push eax
// 00a6da4c  8bcf                 mov ecx, edi
// 00a6da4e  e8edf2f4ff           call 0x9bcd40
// 00a6da53  e808fef4ff           call 0x9bd860
// 00a6da58  6a24                 push 0x24
// 00a6da5a  8bc8                 mov ecx, eax
// 00a6da5c  8daee0000000         lea ebp, [esi + 0xe0]
// 00a6da62  e879f5f4ff           call 0x9bcfe0
// 00a6da67  50                   push eax
// 00a6da68  8bcd                 mov ecx, ebp
// 00a6da6a  e841fdf4ff           call 0x9bd7b0
// 00a6da6f  e8ecfdf4ff           call 0x9bd860
// 00a6da74  6a25                 push 0x25
// 00a6da76  8bc8                 mov ecx, eax
// 00a6da78  8d9e00010000         lea ebx, [esi + 0x100]
// 00a6da7e  e85df5f4ff           call 0x9bcfe0
// 00a6da83  50                   push eax
// 00a6da84  8bcb                 mov ecx, ebx
// 00a6da86  e825fdf4ff           call 0x9bd7b0
// 00a6da8b  e8d0fdf4ff           call 0x9bd860
// 00a6da90  6a24                 push 0x24
// 00a6da92  8bc8                 mov ecx, eax
// 00a6da94  e847f5f4ff           call 0x9bcfe0
// 00a6da99  898684000000         mov dword ptr [esi + 0x84], eax
// 00a6da9f  e8bcfdf4ff           call 0x9bd860
// 00a6daa4  6a21                 push 0x21
// 00a6daa6  8bc8                 mov ecx, eax
// 00a6daa8  e833f5f4ff           call 0x9bcfe0
// 00a6daad  898690000000         mov dword ptr [esi + 0x90], eax
// 00a6dab3  e8a8fdf4ff           call 0x9bd860
// 00a6dab8  6a12                 push 0x12
// 00a6daba  8bc8                 mov ecx, eax
// 00a6dabc  e81ff5f4ff           call 0x9bcfe0
// 00a6dac1  8986cc000000         mov dword ptr [esi + 0xcc], eax
// 00a6dac7  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00a6daca  894e30               mov dword ptr [esi + 0x30], ecx
// 00a6dacd  8b5708               mov edx, dword ptr [edi + 8]
// 00a6dad0  8d5e24               lea ebx, [esi + 0x24]
// 00a6dad3  895308               mov dword ptr [ebx + 8], edx
// 00a6dad6  8b4718               mov eax, dword ptr [edi + 0x18]
// 00a6dad9  894318               mov dword ptr [ebx + 0x18], eax
// 00a6dadc  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 00a6dadf  894b14               mov dword ptr [ebx + 0x14], ecx
// 00a6dae2  d9471c               fld dword ptr [edi + 0x1c]
// 00a6dae5  d95b1c               fstp dword ptr [ebx + 0x1c]
// 00a6dae8  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 00a6daee  c7861402000000000000 mov dword ptr [esi + 0x214], 0
// 00a6daf8  e8e300feff           call 0xa4dbe0
// 00a6dafd  85c0                 test eax, eax
// 00a6daff  0f856b020000         jne 0xa6dd70
// 00a6db05  e856fdf4ff           call 0x9bd860
// 00a6db0a  8bc8                 mov ecx, eax
// 00a6db0c  e8fffaf4ff           call 0x9bd610
// 00a6db11  48                   dec eax
// 00a6db12  83f804               cmp eax, 4
// 00a6db15  0f8744020000         ja 0xa6dd5f
// 00a6db1b  ff24859cdea600       jmp dword ptr [eax*4 + 0xa6de9c]
// 00a6db22  b83b619c00           mov eax, 0x9c613b
// 00a6db27  894648               mov dword ptr [esi + 0x48], eax
// 00a6db2a  898654010000         mov dword ptr [esi + 0x154], eax
// 00a6db30  b800359a00           mov eax, 0x9a3500
// 00a6db35  89863c010000         mov dword ptr [esi + 0x13c], eax
// 00a6db3b  898648010000         mov dword ptr [esi + 0x148], eax
// 00a6db41  b875a6f100           mov eax, 0xf1a675
// 00a6db46  68ffc06f00           push 0x6fc0ff
// 00a6db4b  8bcd                 mov ecx, ebp
// 00a6db4d  898630010000         mov dword ptr [esi + 0x130], eax
// 00a6db53  898660010000         mov dword ptr [esi + 0x160], eax
// 00a6db59  c7866c010000ffffff00 mov dword ptr [esi + 0x16c], 0xffffff
// 00a6db63  e848fcf4ff           call 0x9bd7b0
// 00a6db68  6800008000           push 0x800000
// 00a6db6d  8d8e00010000         lea ecx, [esi + 0x100]
// 00a6db73  e838fcf4ff           call 0x9bd7b0
// 00a6db78  d9057027b600         fld dword ptr [0xb62770]
// 00a6db7e  51                   push ecx
// 00a6db7f  d91c24               fstp dword ptr [esp]
// 00a6db82  68fcfdfe00           push 0xfefdfc
// 00a6db87  68c4dafa00           push 0xfadac4
// 00a6db8c  8bcf                 mov ecx, edi
// 00a6db8e  e8adf1f4ff           call 0x9bcd40
// 00a6db93  d9057027b600         fld dword ptr [0xb62770]
// 00a6db99  51                   push ecx
// 00a6db9a  d91c24               fstp dword ptr [esp]
// 00a6db9d  68c4dafa00           push 0xfadac4
// 00a6dba2  689ebef500           push 0xf5be9e
// 00a6dba7  8bcb                 mov ecx, ebx
// 00a6dba9  c7869c000000a2c0f600 mov dword ptr [esi + 0x9c], 0xf6c0a2
// 00a6dbb3  c74678ffc27300       mov dword ptr [esi + 0x78], 0x73c2ff
// 00a6dbba  c78684000000fff0c900 mov dword ptr [esi + 0x84], 0xc9f0ff
// 00a6dbc4  e877f1f4ff           call 0x9bcd40
// 00a6dbc9  c7860c02000000008000 mov dword ptr [esi + 0x20c], 0x800000
// 00a6dbd3  c7861402000001000000 mov dword ptr [esi + 0x214], 1
// 00a6dbdd  e98e010000           jmp 0xa6dd70
// 00a6dbe2  b860805800           mov eax, 0x588060
// 00a6dbe7  894648               mov dword ptr [esi + 0x48], eax
// 00a6dbea  898654010000         mov dword ptr [esi + 0x154], eax
// 00a6dbf0  b860776b00           mov eax, 0x6b7760
// 00a6dbf5  89863c010000         mov dword ptr [esi + 0x13c], eax
// 00a6dbfb  898648010000         mov dword ptr [esi + 0x148], eax
// 00a6dc01  b8b0c28c00           mov eax, 0x8cc2b0
// 00a6dc06  68ffc06f00           push 0x6fc0ff
// 00a6dc0b  8bcd                 mov ecx, ebp
// 00a6dc0d  898630010000         mov dword ptr [esi + 0x130], eax
// 00a6dc13  898660010000         mov dword ptr [esi + 0x160], eax
// 00a6dc19  c7866c010000ffffff00 mov dword ptr [esi + 0x16c], 0xffffff
// 00a6dc23  e888fbf4ff           call 0x9bd7b0
// 00a6dc28  683f5d3800           push 0x385d3f
// 00a6dc2d  8d8e00010000         lea ecx, [esi + 0x100]
// 00a6dc33  e878fbf4ff           call 0x9bd7b0
// 00a6dc38  d9057027b600         fld dword ptr [0xb62770]
// 00a6dc3e  51                   push ecx
// 00a6dc3f  d91c24               fstp dword ptr [esp]
// 00a6dc42  68fcfefe00           push 0xfefefc
// 00a6dc47  68f2f1e400           push 0xe4f1f2
// 00a6dc4c  8bcf                 mov ecx, edi
// 00a6dc4e  e8edf0f4ff           call 0x9bcd40
// 00a6dc53  d9057027b600         fld dword ptr [0xb62770]
// 00a6dc59  51                   push ecx
// 00a6dc5a  d91c24               fstp dword ptr [esp]
// 00a6dc5d  68f2f1e400           push 0xe4f1f2
// 00a6dc62  68d9d9a700           push 0xa7d9d9
// 00a6dc67  8bcb                 mov ecx, ebx
// 00a6dc69  c7869c000000d0deaa00 mov dword ptr [esi + 0x9c], 0xaaded0
// 00a6dc73  c74678ffc27300       mov dword ptr [esi + 0x78], 0x73c2ff
// 00a6dc7a  c78684000000fff0c700 mov dword ptr [esi + 0x84], 0xc7f0ff
// 00a6dc84  e8b7f0f4ff           call 0x9bcd40
// 00a6dc89  c7860c0200003f5d3800 mov dword ptr [esi + 0x20c], 0x385d3f
// 00a6dc93  c7861402000001000000 mov dword ptr [esi + 0x214], 1
// 00a6dc9d  e9ce000000           jmp 0xa6dd70
// 00a6dca2  b87c7c9400           mov eax, 0x947c7c
// 00a6dca7  894648               mov dword ptr [esi + 0x48], eax
// 00a6dcaa  898654010000         mov dword ptr [esi + 0x154], eax
// 00a6dcb0  b876749200           mov eax, 0x927476
// 00a6dcb5  89863c010000         mov dword ptr [esi + 0x13c], eax
// 00a6dcbb  898648010000         mov dword ptr [esi + 0x148], eax
// 00a6dcc1  b8bab9ce00           mov eax, 0xceb9ba
// 00a6dcc6  68ffc06f00           push 0x6fc0ff
// 00a6dccb  8bcd                 mov ecx, ebp
// 00a6dccd  898630010000         mov dword ptr [esi + 0x130], eax
// 00a6dcd3  898660010000         mov dword ptr [esi + 0x160], eax
// 00a6dcd9  c7866c010000ffffff00 mov dword ptr [esi + 0x16c], 0xffffff
// 00a6dce3  e8c8faf4ff           call 0x9bd7b0
// 00a6dce8  684b4b6f00           push 0x6f4b4b
// 00a6dced  8d8e00010000         lea ecx, [esi + 0x100]
// 00a6dcf3  e8b8faf4ff           call 0x9bd7b0
// 00a6dcf8  d9057027b600         fld dword ptr [0xb62770]
// 00a6dcfe  51                   push ecx
// 00a6dcff  d91c24               fstp dword ptr [esp]
// 00a6dd02  68fcfefe00           push 0xfefefc
// 00a6dd07  68f3f3f700           push 0xf7f3f3
// 00a6dd0c  8bcf                 mov ecx, edi
// 00a6dd0e  e82df0f4ff           call 0x9bcd40
// 00a6dd13  d9057027b600         fld dword ptr [0xb62770]
// 00a6dd19  51                   push ecx
// 00a6dd1a  d91c24               fstp dword ptr [esp]
// 00a6dd1d  68f3f3f700           push 0xf7f3f3
// 00a6dd22  68d7d7e500           push 0xe5d7d7
// 00a6dd27  8bcb                 mov ecx, ebx
// 00a6dd29  c7869c000000d9d9e600 mov dword ptr [esi + 0x9c], 0xe6d9d9
// 00a6dd33  c74678ffc27300       mov dword ptr [esi + 0x78], 0x73c2ff
// 00a6dd3a  c78684000000ffeec200 mov dword ptr [esi + 0x84], 0xc2eeff
// 00a6dd44  e8f7eff4ff           call 0x9bcd40
// 00a6dd49  c7860c0200004b4b6f00 mov dword ptr [esi + 0x20c], 0x6f4b4b
// 00a6dd53  c7861402000001000000 mov dword ptr [esi + 0x214], 1
// 00a6dd5d  eb11                 jmp 0xa6dd70
// 00a6dd5f  e8fcfaf4ff           call 0x9bd860
// 00a6dd64  6a24                 push 0x24
// 00a6dd66  8bc8                 mov ecx, eax
// 00a6dd68  e873f2f4ff           call 0x9bcfe0
// 00a6dd6d  894678               mov dword ptr [esi + 0x78], eax
// 00a6dd70  83be1402000000       cmp dword ptr [esi + 0x214], 0
// 00a6dd77  740a                 je 0xa6dd83
// 00a6dd79  c78690000000fe8e4b00 mov dword ptr [esi + 0x90], 0x4b8efe
// 00a6dd83  8b464c               mov eax, dword ptr [esi + 0x4c]
// 00a6dd86  83c9ff               or ecx, 0xffffffff
// 00a6dd89  3bc1                 cmp eax, ecx
// 00a6dd8b  7503                 jne 0xa6dd90
// 00a6dd8d  8b4648               mov eax, dword ptr [esi + 0x48]
// 00a6dd90  898690010000         mov dword ptr [esi + 0x190], eax
// 00a6dd96  8b464c               mov eax, dword ptr [esi + 0x4c]
// 00a6dd99  3bc1                 cmp eax, ecx
// 00a6dd9b  7503                 jne 0xa6dda0
// 00a6dd9d  8b4648               mov eax, dword ptr [esi + 0x48]
// 00a6dda0  898678010000         mov dword ptr [esi + 0x178], eax
// 00a6dda6  8b464c               mov eax, dword ptr [esi + 0x4c]
// 00a6dda9  3bc1                 cmp eax, ecx
// 00a6ddab  7503                 jne 0xa6ddb0
// 00a6ddad  8b4648               mov eax, dword ptr [esi + 0x48]
// 00a6ddb0  898eb4010000         mov dword ptr [esi + 0x1b4], ecx
// 00a6ddb6  898ea8010000         mov dword ptr [esi + 0x1a8], ecx
// 00a6ddbc  898e9c010000         mov dword ptr [esi + 0x19c], ecx
// 00a6ddc2  898684010000         mov dword ptr [esi + 0x184], eax
// 00a6ddc8  8b967c010000         mov edx, dword ptr [esi + 0x17c]
// 00a6ddce  8996c4010000         mov dword ptr [esi + 0x1c4], edx
// 00a6ddd4  8b8678010000         mov eax, dword ptr [esi + 0x178]
// 00a6ddda  8986c0010000         mov dword ptr [esi + 0x1c0], eax
// 00a6dde0  8b8e88010000         mov ecx, dword ptr [esi + 0x188]
// 00a6dde6  898ed0010000         mov dword ptr [esi + 0x1d0], ecx
// 00a6ddec  8b9684010000         mov edx, dword ptr [esi + 0x184]
// 00a6ddf2  8996cc010000         mov dword ptr [esi + 0x1cc], edx
// 00a6ddf8  8b8694010000         mov eax, dword ptr [esi + 0x194]
// 00a6ddfe  8986dc010000         mov dword ptr [esi + 0x1dc], eax
// 00a6de04  8b8e90010000         mov ecx, dword ptr [esi + 0x190]
// 00a6de0a  898ed8010000         mov dword ptr [esi + 0x1d8], ecx
// 00a6de10  8b96a0010000         mov edx, dword ptr [esi + 0x1a0]
// 00a6de16  8996e8010000         mov dword ptr [esi + 0x1e8], edx
// 00a6de1c  8b869c010000         mov eax, dword ptr [esi + 0x19c]
// 00a6de22  8986e4010000         mov dword ptr [esi + 0x1e4], eax
// 00a6de28  8b8eac010000         mov ecx, dword ptr [esi + 0x1ac]
// 00a6de2e  898ef4010000         mov dword ptr [esi + 0x1f4], ecx
// 00a6de34  8b96a8010000         mov edx, dword ptr [esi + 0x1a8]
// 00a6de3a  8996f0010000         mov dword ptr [esi + 0x1f0], edx
// 00a6de40  8b86b8010000         mov eax, dword ptr [esi + 0x1b8]
// 00a6de46  898600020000         mov dword ptr [esi + 0x200], eax
// 00a6de4c  8b8eb4010000         mov ecx, dword ptr [esi + 0x1b4]
// 00a6de52  898efc010000         mov dword ptr [esi + 0x1fc], ecx
// 00a6de58  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 00a6de5e  e8dd37f8ff           call 0x9f1640
// 00a6de63  83f804               cmp eax, 4
// 00a6de66  752c                 jne 0xa6de94
// 00a6de68  e8f3f9f4ff           call 0x9bd860
// 00a6de6d  6a0f                 push 0xf
// 00a6de6f  8bc8                 mov ecx, eax
// 00a6de71  e86af1f4ff           call 0x9bcfe0
// 00a6de76  50                   push eax
// 00a6de77  8bcb                 mov ecx, ebx
// 00a6de79  e832f9f4ff           call 0x9bd7b0
// 00a6de7e  e8ddf9f4ff           call 0x9bd860
// 00a6de83  6a0f                 push 0xf
// 00a6de85  8bc8                 mov ecx, eax
// 00a6de87  e854f1f4ff           call 0x9bcfe0
// 00a6de8c  50                   push eax
// 00a6de8d  8bcf                 mov ecx, edi
// 00a6de8f  e81cf9f4ff           call 0x9bd7b0
// 00a6de94  5f                   pop edi
// 00a6de95  5e                   pop esi
// 00a6de96  5d                   pop ebp
// 00a6de97  5b                   pop ebx
// 00a6de98  83c408               add esp, 8
// 00a6de9b  c3                   ret 
// 00a6de9c  22db                 and bl, bl
// 00a6de9e  a6                   cmpsb byte ptr [esi], byte ptr es:[edi]
// 00a6de9f  00e2                 add dl, ah
// copied from an identical function in another client (function ?RefreshMetrics@CColorSetOffice2003@CXTPTabPaintManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp