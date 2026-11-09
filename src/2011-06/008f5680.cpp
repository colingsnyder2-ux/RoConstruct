// from server: 100% by auto
// roc 2011-06 008f5680  unit: CXTPTabPaintManager::CColorSetOffice2003  size: 1232 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f5680
//
// 008f5680  83ec08               sub esp, 8
// 008f5683  53                   push ebx
// 008f5684  55                   push ebp
// 008f5685  56                   push esi
// 008f5686  57                   push edi
// 008f5687  8bf1                 mov esi, ecx
// 008f5689  e842f4ffff           call 0x8f4ad0
// 008f568e  e84dfdf4ff           call 0x8453e0
// 008f5693  6a05                 push 5
// 008f5695  8bc8                 mov ecx, eax
// 008f5697  e814f5f4ff           call 0x844bb0
// 008f569c  8bd8                 mov ebx, eax
// 008f569e  e83dfdf4ff           call 0x8453e0
// 008f56a3  6a0f                 push 0xf
// 008f56a5  8bc8                 mov ecx, eax
// 008f56a7  e804f5f4ff           call 0x844bb0
// 008f56ac  8be8                 mov ebp, eax
// 008f56ae  e82dfdf4ff           call 0x8453e0
// 008f56b3  89442410             mov dword ptr [esp + 0x10], eax
// 008f56b7  e824fdf4ff           call 0x8453e0
// 008f56bc  6a0f                 push 0xf
// 008f56be  8bc8                 mov ecx, eax
// 008f56c0  e8ebf4f4ff           call 0x844bb0
// 008f56c5  d905685ba700         fld dword ptr [0xa75b68]
// 008f56cb  51                   push ecx
// 008f56cc  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008f56d0  d91c24               fstp dword ptr [esp]
// 008f56d3  68cd000000           push 0xcd
// 008f56d8  53                   push ebx
// 008f56d9  55                   push ebp
// 008f56da  89442424             mov dword ptr [esp + 0x24], eax
// 008f56de  8d7e04               lea edi, [esi + 4]
// 008f56e1  e81af4f4ff           call 0x844b00
// 008f56e6  50                   push eax
// 008f56e7  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008f56eb  50                   push eax
// 008f56ec  8bcf                 mov ecx, edi
// 008f56ee  e81df2f4ff           call 0x844910
// 008f56f3  e8e8fcf4ff           call 0x8453e0
// 008f56f8  6a24                 push 0x24
// 008f56fa  8bc8                 mov ecx, eax
// 008f56fc  8daee0000000         lea ebp, [esi + 0xe0]
// 008f5702  e8a9f4f4ff           call 0x844bb0
// 008f5707  50                   push eax
// 008f5708  8bcd                 mov ecx, ebp
// 008f570a  e821fcf4ff           call 0x845330
// 008f570f  e8ccfcf4ff           call 0x8453e0
// 008f5714  6a25                 push 0x25
// 008f5716  8bc8                 mov ecx, eax
// 008f5718  8d9e00010000         lea ebx, [esi + 0x100]
// 008f571e  e88df4f4ff           call 0x844bb0
// 008f5723  50                   push eax
// 008f5724  8bcb                 mov ecx, ebx
// 008f5726  e805fcf4ff           call 0x845330
// 008f572b  e8b0fcf4ff           call 0x8453e0
// 008f5730  6a24                 push 0x24
// 008f5732  8bc8                 mov ecx, eax
// 008f5734  e877f4f4ff           call 0x844bb0
// 008f5739  898684000000         mov dword ptr [esi + 0x84], eax
// 008f573f  e89cfcf4ff           call 0x8453e0
// 008f5744  6a21                 push 0x21
// 008f5746  8bc8                 mov ecx, eax
// 008f5748  e863f4f4ff           call 0x844bb0
// 008f574d  898690000000         mov dword ptr [esi + 0x90], eax
// 008f5753  e888fcf4ff           call 0x8453e0
// 008f5758  6a12                 push 0x12
// 008f575a  8bc8                 mov ecx, eax
// 008f575c  e84ff4f4ff           call 0x844bb0
// 008f5761  8986cc000000         mov dword ptr [esi + 0xcc], eax
// 008f5767  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 008f576a  894e30               mov dword ptr [esi + 0x30], ecx
// 008f576d  8b5708               mov edx, dword ptr [edi + 8]
// 008f5770  8d5e24               lea ebx, [esi + 0x24]
// 008f5773  895308               mov dword ptr [ebx + 8], edx
// 008f5776  8b4718               mov eax, dword ptr [edi + 0x18]
// 008f5779  894318               mov dword ptr [ebx + 0x18], eax
// 008f577c  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 008f577f  894b14               mov dword ptr [ebx + 0x14], ecx
// 008f5782  d9471c               fld dword ptr [edi + 0x1c]
// 008f5785  d95b1c               fstp dword ptr [ebx + 0x1c]
// 008f5788  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 008f578e  c7861402000000000000 mov dword ptr [esi + 0x214], 0
// 008f5798  e8f300feff           call 0x8d5890
// 008f579d  85c0                 test eax, eax
// 008f579f  0f856b020000         jne 0x8f5a10
// 008f57a5  e836fcf4ff           call 0x8453e0
// 008f57aa  8bc8                 mov ecx, eax
// 008f57ac  e82ffaf4ff           call 0x8451e0
// 008f57b1  48                   dec eax
// 008f57b2  83f804               cmp eax, 4
// 008f57b5  0f8744020000         ja 0x8f59ff
// 008f57bb  ff24853c5b8f00       jmp dword ptr [eax*4 + 0x8f5b3c]
// 008f57c2  b83b619c00           mov eax, 0x9c613b
// 008f57c7  894648               mov dword ptr [esi + 0x48], eax
// 008f57ca  898654010000         mov dword ptr [esi + 0x154], eax
// 008f57d0  b800359a00           mov eax, 0x9a3500
// 008f57d5  89863c010000         mov dword ptr [esi + 0x13c], eax
// 008f57db  898648010000         mov dword ptr [esi + 0x148], eax
// 008f57e1  b875a6f100           mov eax, 0xf1a675
// 008f57e6  68ffc06f00           push 0x6fc0ff
// 008f57eb  8bcd                 mov ecx, ebp
// 008f57ed  898630010000         mov dword ptr [esi + 0x130], eax
// 008f57f3  898660010000         mov dword ptr [esi + 0x160], eax
// 008f57f9  c7866c010000ffffff00 mov dword ptr [esi + 0x16c], 0xffffff
// 008f5803  e828fbf4ff           call 0x845330
// 008f5808  6800008000           push 0x800000
// 008f580d  8d8e00010000         lea ecx, [esi + 0x100]
// 008f5813  e818fbf4ff           call 0x845330
// 008f5818  d905685ba700         fld dword ptr [0xa75b68]
// 008f581e  51                   push ecx
// 008f581f  d91c24               fstp dword ptr [esp]
// 008f5822  68fcfdfe00           push 0xfefdfc
// 008f5827  68c4dafa00           push 0xfadac4
// 008f582c  8bcf                 mov ecx, edi
// 008f582e  e8ddf0f4ff           call 0x844910
// 008f5833  d905685ba700         fld dword ptr [0xa75b68]
// 008f5839  51                   push ecx
// 008f583a  d91c24               fstp dword ptr [esp]
// 008f583d  68c4dafa00           push 0xfadac4
// 008f5842  689ebef500           push 0xf5be9e
// 008f5847  8bcb                 mov ecx, ebx
// 008f5849  c7869c000000a2c0f600 mov dword ptr [esi + 0x9c], 0xf6c0a2
// 008f5853  c74678ffc27300       mov dword ptr [esi + 0x78], 0x73c2ff
// 008f585a  c78684000000fff0c900 mov dword ptr [esi + 0x84], 0xc9f0ff
// 008f5864  e8a7f0f4ff           call 0x844910
// 008f5869  c7860c02000000008000 mov dword ptr [esi + 0x20c], 0x800000
// 008f5873  c7861402000001000000 mov dword ptr [esi + 0x214], 1
// 008f587d  e98e010000           jmp 0x8f5a10
// 008f5882  b860805800           mov eax, 0x588060
// 008f5887  894648               mov dword ptr [esi + 0x48], eax
// 008f588a  898654010000         mov dword ptr [esi + 0x154], eax
// 008f5890  b860776b00           mov eax, 0x6b7760
// 008f5895  89863c010000         mov dword ptr [esi + 0x13c], eax
// 008f589b  898648010000         mov dword ptr [esi + 0x148], eax
// 008f58a1  b8b0c28c00           mov eax, 0x8cc2b0
// 008f58a6  68ffc06f00           push 0x6fc0ff
// 008f58ab  8bcd                 mov ecx, ebp
// 008f58ad  898630010000         mov dword ptr [esi + 0x130], eax
// 008f58b3  898660010000         mov dword ptr [esi + 0x160], eax
// 008f58b9  c7866c010000ffffff00 mov dword ptr [esi + 0x16c], 0xffffff
// 008f58c3  e868faf4ff           call 0x845330
// 008f58c8  683f5d3800           push 0x385d3f
// 008f58cd  8d8e00010000         lea ecx, [esi + 0x100]
// 008f58d3  e858faf4ff           call 0x845330
// 008f58d8  d905685ba700         fld dword ptr [0xa75b68]
// 008f58de  51                   push ecx
// 008f58df  d91c24               fstp dword ptr [esp]
// 008f58e2  68fcfefe00           push 0xfefefc
// 008f58e7  68f2f1e400           push 0xe4f1f2
// 008f58ec  8bcf                 mov ecx, edi
// 008f58ee  e81df0f4ff           call 0x844910
// 008f58f3  d905685ba700         fld dword ptr [0xa75b68]
// 008f58f9  51                   push ecx
// 008f58fa  d91c24               fstp dword ptr [esp]
// 008f58fd  68f2f1e400           push 0xe4f1f2
// 008f5902  68d9d9a700           push 0xa7d9d9
// 008f5907  8bcb                 mov ecx, ebx
// 008f5909  c7869c000000d0deaa00 mov dword ptr [esi + 0x9c], 0xaaded0
// 008f5913  c74678ffc27300       mov dword ptr [esi + 0x78], 0x73c2ff
// 008f591a  c78684000000fff0c700 mov dword ptr [esi + 0x84], 0xc7f0ff
// 008f5924  e8e7eff4ff           call 0x844910
// 008f5929  c7860c0200003f5d3800 mov dword ptr [esi + 0x20c], 0x385d3f
// 008f5933  c7861402000001000000 mov dword ptr [esi + 0x214], 1
// 008f593d  e9ce000000           jmp 0x8f5a10
// 008f5942  b87c7c9400           mov eax, 0x947c7c
// 008f5947  894648               mov dword ptr [esi + 0x48], eax
// 008f594a  898654010000         mov dword ptr [esi + 0x154], eax
// 008f5950  b876749200           mov eax, 0x927476
// 008f5955  89863c010000         mov dword ptr [esi + 0x13c], eax
// 008f595b  898648010000         mov dword ptr [esi + 0x148], eax
// 008f5961  b8bab9ce00           mov eax, 0xceb9ba
// 008f5966  68ffc06f00           push 0x6fc0ff
// 008f596b  8bcd                 mov ecx, ebp
// 008f596d  898630010000         mov dword ptr [esi + 0x130], eax
// 008f5973  898660010000         mov dword ptr [esi + 0x160], eax
// 008f5979  c7866c010000ffffff00 mov dword ptr [esi + 0x16c], 0xffffff
// 008f5983  e8a8f9f4ff           call 0x845330
// 008f5988  684b4b6f00           push 0x6f4b4b
// 008f598d  8d8e00010000         lea ecx, [esi + 0x100]
// 008f5993  e898f9f4ff           call 0x845330
// 008f5998  d905685ba700         fld dword ptr [0xa75b68]
// 008f599e  51                   push ecx
// 008f599f  d91c24               fstp dword ptr [esp]
// 008f59a2  68fcfefe00           push 0xfefefc
// 008f59a7  68f3f3f700           push 0xf7f3f3
// 008f59ac  8bcf                 mov ecx, edi
// 008f59ae  e85deff4ff           call 0x844910
// 008f59b3  d905685ba700         fld dword ptr [0xa75b68]
// 008f59b9  51                   push ecx
// 008f59ba  d91c24               fstp dword ptr [esp]
// 008f59bd  68f3f3f700           push 0xf7f3f3
// 008f59c2  68d7d7e500           push 0xe5d7d7
// 008f59c7  8bcb                 mov ecx, ebx
// 008f59c9  c7869c000000d9d9e600 mov dword ptr [esi + 0x9c], 0xe6d9d9
// 008f59d3  c74678ffc27300       mov dword ptr [esi + 0x78], 0x73c2ff
// 008f59da  c78684000000ffeec200 mov dword ptr [esi + 0x84], 0xc2eeff
// 008f59e4  e827eff4ff           call 0x844910
// 008f59e9  c7860c0200004b4b6f00 mov dword ptr [esi + 0x20c], 0x6f4b4b
// 008f59f3  c7861402000001000000 mov dword ptr [esi + 0x214], 1
// 008f59fd  eb11                 jmp 0x8f5a10
// 008f59ff  e8dcf9f4ff           call 0x8453e0
// 008f5a04  6a24                 push 0x24
// 008f5a06  8bc8                 mov ecx, eax
// 008f5a08  e8a3f1f4ff           call 0x844bb0
// 008f5a0d  894678               mov dword ptr [esi + 0x78], eax
// 008f5a10  83be1402000000       cmp dword ptr [esi + 0x214], 0
// 008f5a17  740a                 je 0x8f5a23
// 008f5a19  c78690000000fe8e4b00 mov dword ptr [esi + 0x90], 0x4b8efe
// 008f5a23  8b464c               mov eax, dword ptr [esi + 0x4c]
// 008f5a26  83c9ff               or ecx, 0xffffffff
// 008f5a29  3bc1                 cmp eax, ecx
// 008f5a2b  7503                 jne 0x8f5a30
// 008f5a2d  8b4648               mov eax, dword ptr [esi + 0x48]
// 008f5a30  898690010000         mov dword ptr [esi + 0x190], eax
// 008f5a36  8b464c               mov eax, dword ptr [esi + 0x4c]
// 008f5a39  3bc1                 cmp eax, ecx
// 008f5a3b  7503                 jne 0x8f5a40
// 008f5a3d  8b4648               mov eax, dword ptr [esi + 0x48]
// 008f5a40  898678010000         mov dword ptr [esi + 0x178], eax
// 008f5a46  8b464c               mov eax, dword ptr [esi + 0x4c]
// 008f5a49  3bc1                 cmp eax, ecx
// 008f5a4b  7503                 jne 0x8f5a50
// 008f5a4d  8b4648               mov eax, dword ptr [esi + 0x48]
// 008f5a50  898eb4010000         mov dword ptr [esi + 0x1b4], ecx
// 008f5a56  898ea8010000         mov dword ptr [esi + 0x1a8], ecx
// 008f5a5c  898e9c010000         mov dword ptr [esi + 0x19c], ecx
// 008f5a62  898684010000         mov dword ptr [esi + 0x184], eax
// 008f5a68  8b967c010000         mov edx, dword ptr [esi + 0x17c]
// 008f5a6e  8996c4010000         mov dword ptr [esi + 0x1c4], edx
// 008f5a74  8b8678010000         mov eax, dword ptr [esi + 0x178]
// 008f5a7a  8986c0010000         mov dword ptr [esi + 0x1c0], eax
// 008f5a80  8b8e88010000         mov ecx, dword ptr [esi + 0x188]
// 008f5a86  898ed0010000         mov dword ptr [esi + 0x1d0], ecx
// 008f5a8c  8b9684010000         mov edx, dword ptr [esi + 0x184]
// 008f5a92  8996cc010000         mov dword ptr [esi + 0x1cc], edx
// 008f5a98  8b8694010000         mov eax, dword ptr [esi + 0x194]
// 008f5a9e  8986dc010000         mov dword ptr [esi + 0x1dc], eax
// 008f5aa4  8b8e90010000         mov ecx, dword ptr [esi + 0x190]
// 008f5aaa  898ed8010000         mov dword ptr [esi + 0x1d8], ecx
// 008f5ab0  8b96a0010000         mov edx, dword ptr [esi + 0x1a0]
// 008f5ab6  8996e8010000         mov dword ptr [esi + 0x1e8], edx
// 008f5abc  8b869c010000         mov eax, dword ptr [esi + 0x19c]
// 008f5ac2  8986e4010000         mov dword ptr [esi + 0x1e4], eax
// 008f5ac8  8b8eac010000         mov ecx, dword ptr [esi + 0x1ac]
// 008f5ace  898ef4010000         mov dword ptr [esi + 0x1f4], ecx
// 008f5ad4  8b96a8010000         mov edx, dword ptr [esi + 0x1a8]
// 008f5ada  8996f0010000         mov dword ptr [esi + 0x1f0], edx
// 008f5ae0  8b86b8010000         mov eax, dword ptr [esi + 0x1b8]
// 008f5ae6  898600020000         mov dword ptr [esi + 0x200], eax
// 008f5aec  8b8eb4010000         mov ecx, dword ptr [esi + 0x1b4]
// 008f5af2  898efc010000         mov dword ptr [esi + 0x1fc], ecx
// 008f5af8  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 008f5afe  e8bdfefdff           call 0x8d59c0
// 008f5b03  83f804               cmp eax, 4
// 008f5b06  752c                 jne 0x8f5b34
// 008f5b08  e8d3f8f4ff           call 0x8453e0
// 008f5b0d  6a0f                 push 0xf
// 008f5b0f  8bc8                 mov ecx, eax
// 008f5b11  e89af0f4ff           call 0x844bb0
// 008f5b16  50                   push eax
// 008f5b17  8bcb                 mov ecx, ebx
// 008f5b19  e812f8f4ff           call 0x845330
// 008f5b1e  e8bdf8f4ff           call 0x8453e0
// 008f5b23  6a0f                 push 0xf
// 008f5b25  8bc8                 mov ecx, eax
// 008f5b27  e884f0f4ff           call 0x844bb0
// 008f5b2c  50                   push eax
// 008f5b2d  8bcf                 mov ecx, edi
// 008f5b2f  e8fcf7f4ff           call 0x845330
// 008f5b34  5f                   pop edi
// 008f5b35  5e                   pop esi
// 008f5b36  5d                   pop ebp
// 008f5b37  5b                   pop ebx
// 008f5b38  83c408               add esp, 8
// 008f5b3b  c3                   ret 
// 008f5b3c  c2578f               ret 0x8f57
// 008f5b3f  0082588f0042         add byte ptr [edx + 0x42008f58], al
// 008f5b45  59                   pop ecx
// 008f5b46  8f00                 pop dword ptr [eax]
// 008f5b48  c2578f               ret 0x8f57
// 008f5b4b  00c2                 add dl, al
// 008f5b4d  57                   push edi
// 008f5b4e  8f00                 pop dword ptr [eax]
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?RefreshMetrics@CColorSetOffice2003@CXTPTabPaintManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
