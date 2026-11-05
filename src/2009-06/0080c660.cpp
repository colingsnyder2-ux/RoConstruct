// from server: 100% by auto
// roc 2009-06 0080c660  unit: CXTPTabPaintManager::CColorSet  size: 792 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080c660
//
// 0080c660  56                   push esi
// 0080c661  57                   push edi
// 0080c662  8bf1                 mov esi, ecx
// 0080c664  e887a0f4ff           call 0x7566f0
// 0080c669  e8b284f4ff           call 0x754b20
// 0080c66e  6a10                 push 0x10
// 0080c670  8bc8                 mov ecx, eax
// 0080c672  e8297cf4ff           call 0x7542a0
// 0080c677  894648               mov dword ptr [esi + 0x48], eax
// 0080c67a  e8a184f4ff           call 0x754b20
// 0080c67f  6a0f                 push 0xf
// 0080c681  8bc8                 mov ecx, eax
// 0080c683  8d7e04               lea edi, [esi + 4]
// 0080c686  e8157cf4ff           call 0x7542a0
// 0080c68b  50                   push eax
// 0080c68c  8bcf                 mov ecx, edi
// 0080c68e  e8dd83f4ff           call 0x754a70
// 0080c693  e88884f4ff           call 0x754b20
// 0080c698  6a0f                 push 0xf
// 0080c69a  8bc8                 mov ecx, eax
// 0080c69c  e8ff7bf4ff           call 0x7542a0
// 0080c6a1  894654               mov dword ptr [esi + 0x54], eax
// 0080c6a4  e87784f4ff           call 0x754b20
// 0080c6a9  6a0f                 push 0xf
// 0080c6ab  8bc8                 mov ecx, eax
// 0080c6ad  e8ee7bf4ff           call 0x7542a0
// 0080c6b2  894660               mov dword ptr [esi + 0x60], eax
// 0080c6b5  e86684f4ff           call 0x754b20
// 0080c6ba  6a14                 push 0x14
// 0080c6bc  8bc8                 mov ecx, eax
// 0080c6be  e8dd7bf4ff           call 0x7542a0
// 0080c6c3  89466c               mov dword ptr [esi + 0x6c], eax
// 0080c6c6  e85584f4ff           call 0x754b20
// 0080c6cb  6a12                 push 0x12
// 0080c6cd  8bc8                 mov ecx, eax
// 0080c6cf  e8cc7bf4ff           call 0x7542a0
// 0080c6d4  8986b4000000         mov dword ptr [esi + 0xb4], eax
// 0080c6da  e84184f4ff           call 0x754b20
// 0080c6df  6a12                 push 0x12
// 0080c6e1  8bc8                 mov ecx, eax
// 0080c6e3  e8b87bf4ff           call 0x7542a0
// 0080c6e8  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 0080c6ee  e82d84f4ff           call 0x754b20
// 0080c6f3  6a12                 push 0x12
// 0080c6f5  8bc8                 mov ecx, eax
// 0080c6f7  e8a47bf4ff           call 0x7542a0
// 0080c6fc  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 0080c702  c786cc00000000008000 mov dword ptr [esi + 0xcc], 0x800000
// 0080c70c  e80f84f4ff           call 0x754b20
// 0080c711  6a11                 push 0x11
// 0080c713  8bc8                 mov ecx, eax
// 0080c715  e8867bf4ff           call 0x7542a0
// 0080c71a  8986d8000000         mov dword ptr [esi + 0xd8], eax
// 0080c720  e8fb83f4ff           call 0x754b20
// 0080c725  6a05                 push 5
// 0080c727  8bc8                 mov ecx, eax
// 0080c729  e8727bf4ff           call 0x7542a0
// 0080c72e  50                   push eax
// 0080c72f  8d8ee0000000         lea ecx, [esi + 0xe0]
// 0080c735  e83683f4ff           call 0x754a70
// 0080c73a  e8e183f4ff           call 0x754b20
// 0080c73f  6a0d                 push 0xd
// 0080c741  8bc8                 mov ecx, eax
// 0080c743  e8587bf4ff           call 0x7542a0
// 0080c748  50                   push eax
// 0080c749  8d8e00010000         lea ecx, [esi + 0x100]
// 0080c74f  e81c83f4ff           call 0x754a70
// 0080c754  e8c783f4ff           call 0x754b20
// 0080c759  6a10                 push 0x10
// 0080c75b  8bc8                 mov ecx, eax
// 0080c75d  e83e7bf4ff           call 0x7542a0
// 0080c762  898648010000         mov dword ptr [esi + 0x148], eax
// 0080c768  e8b383f4ff           call 0x754b20
// 0080c76d  6a10                 push 0x10
// 0080c76f  8bc8                 mov ecx, eax
// 0080c771  e82a7bf4ff           call 0x7542a0
// 0080c776  898654010000         mov dword ptr [esi + 0x154], eax
// 0080c77c  e89f83f4ff           call 0x754b20
// 0080c781  6a0f                 push 0xf
// 0080c783  8bc8                 mov ecx, eax
// 0080c785  e8167bf4ff           call 0x7542a0
// 0080c78a  898660010000         mov dword ptr [esi + 0x160], eax
// 0080c790  e88b83f4ff           call 0x754b20
// 0080c795  6a0f                 push 0xf
// 0080c797  8bc8                 mov ecx, eax
// 0080c799  e8027bf4ff           call 0x7542a0
// 0080c79e  89866c010000         mov dword ptr [esi + 0x16c], eax
// 0080c7a4  e87783f4ff           call 0x754b20
// 0080c7a9  6a14                 push 0x14
// 0080c7ab  8bc8                 mov ecx, eax
// 0080c7ad  e8ee7af4ff           call 0x7542a0
// 0080c7b2  898624010000         mov dword ptr [esi + 0x124], eax
// 0080c7b8  e86383f4ff           call 0x754b20
// 0080c7bd  6a10                 push 0x10
// 0080c7bf  8bc8                 mov ecx, eax
// 0080c7c1  e8da7af4ff           call 0x7542a0
// 0080c7c6  898630010000         mov dword ptr [esi + 0x130], eax
// 0080c7cc  e84f83f4ff           call 0x754b20
// 0080c7d1  6a15                 push 0x15
// 0080c7d3  8bc8                 mov ecx, eax
// 0080c7d5  e8c67af4ff           call 0x7542a0
// 0080c7da  89863c010000         mov dword ptr [esi + 0x13c], eax
// 0080c7e0  e83b83f4ff           call 0x754b20
// 0080c7e5  6a12                 push 0x12
// 0080c7e7  8bc8                 mov ecx, eax
// 0080c7e9  e8b27af4ff           call 0x7542a0
// 0080c7ee  898690010000         mov dword ptr [esi + 0x190], eax
// 0080c7f4  e82783f4ff           call 0x754b20
// 0080c7f9  6a12                 push 0x12
// 0080c7fb  8bc8                 mov ecx, eax
// 0080c7fd  e89e7af4ff           call 0x7542a0
// 0080c802  898678010000         mov dword ptr [esi + 0x178], eax
// 0080c808  e81383f4ff           call 0x754b20
// 0080c80d  6a10                 push 0x10
// 0080c80f  8bc8                 mov ecx, eax
// 0080c811  e88a7af4ff           call 0x7542a0
// 0080c816  898684010000         mov dword ptr [esi + 0x184], eax
// 0080c81c  83c8ff               or eax, 0xffffffff
// 0080c81f  89869c010000         mov dword ptr [esi + 0x19c], eax
// 0080c825  8986a8010000         mov dword ptr [esi + 0x1a8], eax
// 0080c82b  8986b4010000         mov dword ptr [esi + 0x1b4], eax
// 0080c831  8b867c010000         mov eax, dword ptr [esi + 0x17c]
// 0080c837  8986c4010000         mov dword ptr [esi + 0x1c4], eax
// 0080c83d  8b8e78010000         mov ecx, dword ptr [esi + 0x178]
// 0080c843  898ec0010000         mov dword ptr [esi + 0x1c0], ecx
// 0080c849  8b9688010000         mov edx, dword ptr [esi + 0x188]
// 0080c84f  8996d0010000         mov dword ptr [esi + 0x1d0], edx
// 0080c855  8b8684010000         mov eax, dword ptr [esi + 0x184]
// 0080c85b  8986cc010000         mov dword ptr [esi + 0x1cc], eax
// 0080c861  8b8e94010000         mov ecx, dword ptr [esi + 0x194]
// 0080c867  898edc010000         mov dword ptr [esi + 0x1dc], ecx
// 0080c86d  8b9690010000         mov edx, dword ptr [esi + 0x190]
// 0080c873  8996d8010000         mov dword ptr [esi + 0x1d8], edx
// 0080c879  8b86a0010000         mov eax, dword ptr [esi + 0x1a0]
// 0080c87f  8986e8010000         mov dword ptr [esi + 0x1e8], eax
// 0080c885  8b8e9c010000         mov ecx, dword ptr [esi + 0x19c]
// 0080c88b  898ee4010000         mov dword ptr [esi + 0x1e4], ecx
// 0080c891  8b96ac010000         mov edx, dword ptr [esi + 0x1ac]
// 0080c897  8996f4010000         mov dword ptr [esi + 0x1f4], edx
// 0080c89d  8b86a8010000         mov eax, dword ptr [esi + 0x1a8]
// 0080c8a3  8986f0010000         mov dword ptr [esi + 0x1f0], eax
// 0080c8a9  8b8eb8010000         mov ecx, dword ptr [esi + 0x1b8]
// 0080c8af  898e00020000         mov dword ptr [esi + 0x200], ecx
// 0080c8b5  8b96b4010000         mov edx, dword ptr [esi + 0x1b4]
// 0080c8bb  8996fc010000         mov dword ptr [esi + 0x1fc], edx
// 0080c8c1  e85a82f4ff           call 0x754b20
// 0080c8c6  6a05                 push 5
// 0080c8c8  8bc8                 mov ecx, eax
// 0080c8ca  e8d179f4ff           call 0x7542a0
// 0080c8cf  8986e4010000         mov dword ptr [esi + 0x1e4], eax
// 0080c8d5  e84682f4ff           call 0x754b20
// 0080c8da  6a10                 push 0x10
// 0080c8dc  8bc8                 mov ecx, eax
// 0080c8de  e8bd79f4ff           call 0x7542a0
// 0080c8e3  8986f0010000         mov dword ptr [esi + 0x1f0], eax
// 0080c8e9  e83282f4ff           call 0x754b20
// 0080c8ee  6a0f                 push 0xf
// 0080c8f0  8bc8                 mov ecx, eax
// 0080c8f2  e8a979f4ff           call 0x7542a0
// 0080c8f7  894678               mov dword ptr [esi + 0x78], eax
// 0080c8fa  e82182f4ff           call 0x754b20
// 0080c8ff  6a0f                 push 0xf
// 0080c901  8bc8                 mov ecx, eax
// 0080c903  e89879f4ff           call 0x7542a0
// 0080c908  89869c000000         mov dword ptr [esi + 0x9c], eax
// 0080c90e  e80d82f4ff           call 0x754b20
// 0080c913  6a0f                 push 0xf
// 0080c915  8bc8                 mov ecx, eax
// 0080c917  e88479f4ff           call 0x7542a0
// 0080c91c  898684000000         mov dword ptr [esi + 0x84], eax
// 0080c922  e8f981f4ff           call 0x754b20
// 0080c927  6a0f                 push 0xf
// 0080c929  8bc8                 mov ecx, eax
// 0080c92b  e87079f4ff           call 0x7542a0
// 0080c930  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 0080c936  898690000000         mov dword ptr [esi + 0x90], eax
// 0080c93c  e8df93feff           call 0x7f5d20
// 0080c941  83f807               cmp eax, 7
// 0080c944  7511                 jne 0x80c957
// 0080c946  e8d581f4ff           call 0x754b20
// 0080c94b  6a05                 push 5
// 0080c94d  8bc8                 mov ecx, eax
// 0080c94f  e84c79f4ff           call 0x7542a0
// 0080c954  894678               mov dword ptr [esi + 0x78], eax
// 0080c957  8b470c               mov eax, dword ptr [edi + 0xc]
// 0080c95a  894630               mov dword ptr [esi + 0x30], eax
// 0080c95d  8b4f08               mov ecx, dword ptr [edi + 8]
// 0080c960  894e2c               mov dword ptr [esi + 0x2c], ecx
// 0080c963  8b5718               mov edx, dword ptr [edi + 0x18]
// 0080c966  89563c               mov dword ptr [esi + 0x3c], edx
// 0080c969  8b4714               mov eax, dword ptr [edi + 0x14]
// 0080c96c  894638               mov dword ptr [esi + 0x38], eax
// 0080c96f  d9471c               fld dword ptr [edi + 0x1c]
// 0080c972  5f                   pop edi
// 0080c973  d95e40               fstp dword ptr [esi + 0x40]
// 0080c976  5e                   pop esi
// 0080c977  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?RefreshMetrics@CColorSet@CXTPTabPaintManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
