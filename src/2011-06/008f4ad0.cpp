// from server: 100% by auto
// roc 2011-06 008f4ad0  unit: CXTPTabPaintManager::CColorSet  size: 792 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f4ad0
//
// 008f4ad0  56                   push esi
// 008f4ad1  57                   push edi
// 008f4ad2  8bf1                 mov esi, ecx
// 008f4ad4  e8d724f5ff           call 0x846fb0
// 008f4ad9  e80209f5ff           call 0x8453e0
// 008f4ade  6a10                 push 0x10
// 008f4ae0  8bc8                 mov ecx, eax
// 008f4ae2  e8c900f5ff           call 0x844bb0
// 008f4ae7  894648               mov dword ptr [esi + 0x48], eax
// 008f4aea  e8f108f5ff           call 0x8453e0
// 008f4aef  6a0f                 push 0xf
// 008f4af1  8bc8                 mov ecx, eax
// 008f4af3  8d7e04               lea edi, [esi + 4]
// 008f4af6  e8b500f5ff           call 0x844bb0
// 008f4afb  50                   push eax
// 008f4afc  8bcf                 mov ecx, edi
// 008f4afe  e82d08f5ff           call 0x845330
// 008f4b03  e8d808f5ff           call 0x8453e0
// 008f4b08  6a0f                 push 0xf
// 008f4b0a  8bc8                 mov ecx, eax
// 008f4b0c  e89f00f5ff           call 0x844bb0
// 008f4b11  894654               mov dword ptr [esi + 0x54], eax
// 008f4b14  e8c708f5ff           call 0x8453e0
// 008f4b19  6a0f                 push 0xf
// 008f4b1b  8bc8                 mov ecx, eax
// 008f4b1d  e88e00f5ff           call 0x844bb0
// 008f4b22  894660               mov dword ptr [esi + 0x60], eax
// 008f4b25  e8b608f5ff           call 0x8453e0
// 008f4b2a  6a14                 push 0x14
// 008f4b2c  8bc8                 mov ecx, eax
// 008f4b2e  e87d00f5ff           call 0x844bb0
// 008f4b33  89466c               mov dword ptr [esi + 0x6c], eax
// 008f4b36  e8a508f5ff           call 0x8453e0
// 008f4b3b  6a12                 push 0x12
// 008f4b3d  8bc8                 mov ecx, eax
// 008f4b3f  e86c00f5ff           call 0x844bb0
// 008f4b44  8986b4000000         mov dword ptr [esi + 0xb4], eax
// 008f4b4a  e89108f5ff           call 0x8453e0
// 008f4b4f  6a12                 push 0x12
// 008f4b51  8bc8                 mov ecx, eax
// 008f4b53  e85800f5ff           call 0x844bb0
// 008f4b58  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 008f4b5e  e87d08f5ff           call 0x8453e0
// 008f4b63  6a12                 push 0x12
// 008f4b65  8bc8                 mov ecx, eax
// 008f4b67  e84400f5ff           call 0x844bb0
// 008f4b6c  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 008f4b72  c786cc00000000008000 mov dword ptr [esi + 0xcc], 0x800000
// 008f4b7c  e85f08f5ff           call 0x8453e0
// 008f4b81  6a11                 push 0x11
// 008f4b83  8bc8                 mov ecx, eax
// 008f4b85  e82600f5ff           call 0x844bb0
// 008f4b8a  8986d8000000         mov dword ptr [esi + 0xd8], eax
// 008f4b90  e84b08f5ff           call 0x8453e0
// 008f4b95  6a05                 push 5
// 008f4b97  8bc8                 mov ecx, eax
// 008f4b99  e81200f5ff           call 0x844bb0
// 008f4b9e  50                   push eax
// 008f4b9f  8d8ee0000000         lea ecx, [esi + 0xe0]
// 008f4ba5  e88607f5ff           call 0x845330
// 008f4baa  e83108f5ff           call 0x8453e0
// 008f4baf  6a0d                 push 0xd
// 008f4bb1  8bc8                 mov ecx, eax
// 008f4bb3  e8f8fff4ff           call 0x844bb0
// 008f4bb8  50                   push eax
// 008f4bb9  8d8e00010000         lea ecx, [esi + 0x100]
// 008f4bbf  e86c07f5ff           call 0x845330
// 008f4bc4  e81708f5ff           call 0x8453e0
// 008f4bc9  6a10                 push 0x10
// 008f4bcb  8bc8                 mov ecx, eax
// 008f4bcd  e8defff4ff           call 0x844bb0
// 008f4bd2  898648010000         mov dword ptr [esi + 0x148], eax
// 008f4bd8  e80308f5ff           call 0x8453e0
// 008f4bdd  6a10                 push 0x10
// 008f4bdf  8bc8                 mov ecx, eax
// 008f4be1  e8cafff4ff           call 0x844bb0
// 008f4be6  898654010000         mov dword ptr [esi + 0x154], eax
// 008f4bec  e8ef07f5ff           call 0x8453e0
// 008f4bf1  6a0f                 push 0xf
// 008f4bf3  8bc8                 mov ecx, eax
// 008f4bf5  e8b6fff4ff           call 0x844bb0
// 008f4bfa  898660010000         mov dword ptr [esi + 0x160], eax
// 008f4c00  e8db07f5ff           call 0x8453e0
// 008f4c05  6a0f                 push 0xf
// 008f4c07  8bc8                 mov ecx, eax
// 008f4c09  e8a2fff4ff           call 0x844bb0
// 008f4c0e  89866c010000         mov dword ptr [esi + 0x16c], eax
// 008f4c14  e8c707f5ff           call 0x8453e0
// 008f4c19  6a14                 push 0x14
// 008f4c1b  8bc8                 mov ecx, eax
// 008f4c1d  e88efff4ff           call 0x844bb0
// 008f4c22  898624010000         mov dword ptr [esi + 0x124], eax
// 008f4c28  e8b307f5ff           call 0x8453e0
// 008f4c2d  6a10                 push 0x10
// 008f4c2f  8bc8                 mov ecx, eax
// 008f4c31  e87afff4ff           call 0x844bb0
// 008f4c36  898630010000         mov dword ptr [esi + 0x130], eax
// 008f4c3c  e89f07f5ff           call 0x8453e0
// 008f4c41  6a15                 push 0x15
// 008f4c43  8bc8                 mov ecx, eax
// 008f4c45  e866fff4ff           call 0x844bb0
// 008f4c4a  89863c010000         mov dword ptr [esi + 0x13c], eax
// 008f4c50  e88b07f5ff           call 0x8453e0
// 008f4c55  6a12                 push 0x12
// 008f4c57  8bc8                 mov ecx, eax
// 008f4c59  e852fff4ff           call 0x844bb0
// 008f4c5e  898690010000         mov dword ptr [esi + 0x190], eax
// 008f4c64  e87707f5ff           call 0x8453e0
// 008f4c69  6a12                 push 0x12
// 008f4c6b  8bc8                 mov ecx, eax
// 008f4c6d  e83efff4ff           call 0x844bb0
// 008f4c72  898678010000         mov dword ptr [esi + 0x178], eax
// 008f4c78  e86307f5ff           call 0x8453e0
// 008f4c7d  6a10                 push 0x10
// 008f4c7f  8bc8                 mov ecx, eax
// 008f4c81  e82afff4ff           call 0x844bb0
// 008f4c86  898684010000         mov dword ptr [esi + 0x184], eax
// 008f4c8c  83c8ff               or eax, 0xffffffff
// 008f4c8f  89869c010000         mov dword ptr [esi + 0x19c], eax
// 008f4c95  8986a8010000         mov dword ptr [esi + 0x1a8], eax
// 008f4c9b  8986b4010000         mov dword ptr [esi + 0x1b4], eax
// 008f4ca1  8b867c010000         mov eax, dword ptr [esi + 0x17c]
// 008f4ca7  8986c4010000         mov dword ptr [esi + 0x1c4], eax
// 008f4cad  8b8e78010000         mov ecx, dword ptr [esi + 0x178]
// 008f4cb3  898ec0010000         mov dword ptr [esi + 0x1c0], ecx
// 008f4cb9  8b9688010000         mov edx, dword ptr [esi + 0x188]
// 008f4cbf  8996d0010000         mov dword ptr [esi + 0x1d0], edx
// 008f4cc5  8b8684010000         mov eax, dword ptr [esi + 0x184]
// 008f4ccb  8986cc010000         mov dword ptr [esi + 0x1cc], eax
// 008f4cd1  8b8e94010000         mov ecx, dword ptr [esi + 0x194]
// 008f4cd7  898edc010000         mov dword ptr [esi + 0x1dc], ecx
// 008f4cdd  8b9690010000         mov edx, dword ptr [esi + 0x190]
// 008f4ce3  8996d8010000         mov dword ptr [esi + 0x1d8], edx
// 008f4ce9  8b86a0010000         mov eax, dword ptr [esi + 0x1a0]
// 008f4cef  8986e8010000         mov dword ptr [esi + 0x1e8], eax
// 008f4cf5  8b8e9c010000         mov ecx, dword ptr [esi + 0x19c]
// 008f4cfb  898ee4010000         mov dword ptr [esi + 0x1e4], ecx
// 008f4d01  8b96ac010000         mov edx, dword ptr [esi + 0x1ac]
// 008f4d07  8996f4010000         mov dword ptr [esi + 0x1f4], edx
// 008f4d0d  8b86a8010000         mov eax, dword ptr [esi + 0x1a8]
// 008f4d13  8986f0010000         mov dword ptr [esi + 0x1f0], eax
// 008f4d19  8b8eb8010000         mov ecx, dword ptr [esi + 0x1b8]
// 008f4d1f  898e00020000         mov dword ptr [esi + 0x200], ecx
// 008f4d25  8b96b4010000         mov edx, dword ptr [esi + 0x1b4]
// 008f4d2b  8996fc010000         mov dword ptr [esi + 0x1fc], edx
// 008f4d31  e8aa06f5ff           call 0x8453e0
// 008f4d36  6a05                 push 5
// 008f4d38  8bc8                 mov ecx, eax
// 008f4d3a  e871fef4ff           call 0x844bb0
// 008f4d3f  8986e4010000         mov dword ptr [esi + 0x1e4], eax
// 008f4d45  e89606f5ff           call 0x8453e0
// 008f4d4a  6a10                 push 0x10
// 008f4d4c  8bc8                 mov ecx, eax
// 008f4d4e  e85dfef4ff           call 0x844bb0
// 008f4d53  8986f0010000         mov dword ptr [esi + 0x1f0], eax
// 008f4d59  e88206f5ff           call 0x8453e0
// 008f4d5e  6a0f                 push 0xf
// 008f4d60  8bc8                 mov ecx, eax
// 008f4d62  e849fef4ff           call 0x844bb0
// 008f4d67  894678               mov dword ptr [esi + 0x78], eax
// 008f4d6a  e87106f5ff           call 0x8453e0
// 008f4d6f  6a0f                 push 0xf
// 008f4d71  8bc8                 mov ecx, eax
// 008f4d73  e838fef4ff           call 0x844bb0
// 008f4d78  89869c000000         mov dword ptr [esi + 0x9c], eax
// 008f4d7e  e85d06f5ff           call 0x8453e0
// 008f4d83  6a0f                 push 0xf
// 008f4d85  8bc8                 mov ecx, eax
// 008f4d87  e824fef4ff           call 0x844bb0
// 008f4d8c  898684000000         mov dword ptr [esi + 0x84], eax
// 008f4d92  e84906f5ff           call 0x8453e0
// 008f4d97  6a0f                 push 0xf
// 008f4d99  8bc8                 mov ecx, eax
// 008f4d9b  e810fef4ff           call 0x844bb0
// 008f4da0  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 008f4da6  898690000000         mov dword ptr [esi + 0x90], eax
// 008f4dac  e80f0cfeff           call 0x8d59c0
// 008f4db1  83f807               cmp eax, 7
// 008f4db4  7511                 jne 0x8f4dc7
// 008f4db6  e82506f5ff           call 0x8453e0
// 008f4dbb  6a05                 push 5
// 008f4dbd  8bc8                 mov ecx, eax
// 008f4dbf  e8ecfdf4ff           call 0x844bb0
// 008f4dc4  894678               mov dword ptr [esi + 0x78], eax
// 008f4dc7  8b470c               mov eax, dword ptr [edi + 0xc]
// 008f4dca  894630               mov dword ptr [esi + 0x30], eax
// 008f4dcd  8b4f08               mov ecx, dword ptr [edi + 8]
// 008f4dd0  894e2c               mov dword ptr [esi + 0x2c], ecx
// 008f4dd3  8b5718               mov edx, dword ptr [edi + 0x18]
// 008f4dd6  89563c               mov dword ptr [esi + 0x3c], edx
// 008f4dd9  8b4714               mov eax, dword ptr [edi + 0x14]
// 008f4ddc  894638               mov dword ptr [esi + 0x38], eax
// 008f4ddf  d9471c               fld dword ptr [edi + 0x1c]
// 008f4de2  5f                   pop edi
// 008f4de3  d95e40               fstp dword ptr [esi + 0x40]
// 008f4de6  5e                   pop esi
// 008f4de7  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?RefreshMetrics@CColorSet@CXTPTabPaintManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
