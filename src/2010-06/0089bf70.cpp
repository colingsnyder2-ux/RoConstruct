// from server: 100% by auto
// roc 2010-06 0089bf70  unit: CXTPTabPaintManager::CColorSet  size: 792 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089bf70
//
// 0089bf70  56                   push esi
// 0089bf71  57                   push edi
// 0089bf72  8bf1                 mov esi, ecx
// 0089bf74  e87797f4ff           call 0x7e56f0
// 0089bf79  e8a27bf4ff           call 0x7e3b20
// 0089bf7e  6a10                 push 0x10
// 0089bf80  8bc8                 mov ecx, eax
// 0089bf82  e82973f4ff           call 0x7e32b0
// 0089bf87  894648               mov dword ptr [esi + 0x48], eax
// 0089bf8a  e8917bf4ff           call 0x7e3b20
// 0089bf8f  6a0f                 push 0xf
// 0089bf91  8bc8                 mov ecx, eax
// 0089bf93  8d7e04               lea edi, [esi + 4]
// 0089bf96  e81573f4ff           call 0x7e32b0
// 0089bf9b  50                   push eax
// 0089bf9c  8bcf                 mov ecx, edi
// 0089bf9e  e8cd7af4ff           call 0x7e3a70
// 0089bfa3  e8787bf4ff           call 0x7e3b20
// 0089bfa8  6a0f                 push 0xf
// 0089bfaa  8bc8                 mov ecx, eax
// 0089bfac  e8ff72f4ff           call 0x7e32b0
// 0089bfb1  894654               mov dword ptr [esi + 0x54], eax
// 0089bfb4  e8677bf4ff           call 0x7e3b20
// 0089bfb9  6a0f                 push 0xf
// 0089bfbb  8bc8                 mov ecx, eax
// 0089bfbd  e8ee72f4ff           call 0x7e32b0
// 0089bfc2  894660               mov dword ptr [esi + 0x60], eax
// 0089bfc5  e8567bf4ff           call 0x7e3b20
// 0089bfca  6a14                 push 0x14
// 0089bfcc  8bc8                 mov ecx, eax
// 0089bfce  e8dd72f4ff           call 0x7e32b0
// 0089bfd3  89466c               mov dword ptr [esi + 0x6c], eax
// 0089bfd6  e8457bf4ff           call 0x7e3b20
// 0089bfdb  6a12                 push 0x12
// 0089bfdd  8bc8                 mov ecx, eax
// 0089bfdf  e8cc72f4ff           call 0x7e32b0
// 0089bfe4  8986b4000000         mov dword ptr [esi + 0xb4], eax
// 0089bfea  e8317bf4ff           call 0x7e3b20
// 0089bfef  6a12                 push 0x12
// 0089bff1  8bc8                 mov ecx, eax
// 0089bff3  e8b872f4ff           call 0x7e32b0
// 0089bff8  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 0089bffe  e81d7bf4ff           call 0x7e3b20
// 0089c003  6a12                 push 0x12
// 0089c005  8bc8                 mov ecx, eax
// 0089c007  e8a472f4ff           call 0x7e32b0
// 0089c00c  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 0089c012  c786cc00000000008000 mov dword ptr [esi + 0xcc], 0x800000
// 0089c01c  e8ff7af4ff           call 0x7e3b20
// 0089c021  6a11                 push 0x11
// 0089c023  8bc8                 mov ecx, eax
// 0089c025  e88672f4ff           call 0x7e32b0
// 0089c02a  8986d8000000         mov dword ptr [esi + 0xd8], eax
// 0089c030  e8eb7af4ff           call 0x7e3b20
// 0089c035  6a05                 push 5
// 0089c037  8bc8                 mov ecx, eax
// 0089c039  e87272f4ff           call 0x7e32b0
// 0089c03e  50                   push eax
// 0089c03f  8d8ee0000000         lea ecx, [esi + 0xe0]
// 0089c045  e8267af4ff           call 0x7e3a70
// 0089c04a  e8d17af4ff           call 0x7e3b20
// 0089c04f  6a0d                 push 0xd
// 0089c051  8bc8                 mov ecx, eax
// 0089c053  e85872f4ff           call 0x7e32b0
// 0089c058  50                   push eax
// 0089c059  8d8e00010000         lea ecx, [esi + 0x100]
// 0089c05f  e80c7af4ff           call 0x7e3a70
// 0089c064  e8b77af4ff           call 0x7e3b20
// 0089c069  6a10                 push 0x10
// 0089c06b  8bc8                 mov ecx, eax
// 0089c06d  e83e72f4ff           call 0x7e32b0
// 0089c072  898648010000         mov dword ptr [esi + 0x148], eax
// 0089c078  e8a37af4ff           call 0x7e3b20
// 0089c07d  6a10                 push 0x10
// 0089c07f  8bc8                 mov ecx, eax
// 0089c081  e82a72f4ff           call 0x7e32b0
// 0089c086  898654010000         mov dword ptr [esi + 0x154], eax
// 0089c08c  e88f7af4ff           call 0x7e3b20
// 0089c091  6a0f                 push 0xf
// 0089c093  8bc8                 mov ecx, eax
// 0089c095  e81672f4ff           call 0x7e32b0
// 0089c09a  898660010000         mov dword ptr [esi + 0x160], eax
// 0089c0a0  e87b7af4ff           call 0x7e3b20
// 0089c0a5  6a0f                 push 0xf
// 0089c0a7  8bc8                 mov ecx, eax
// 0089c0a9  e80272f4ff           call 0x7e32b0
// 0089c0ae  89866c010000         mov dword ptr [esi + 0x16c], eax
// 0089c0b4  e8677af4ff           call 0x7e3b20
// 0089c0b9  6a14                 push 0x14
// 0089c0bb  8bc8                 mov ecx, eax
// 0089c0bd  e8ee71f4ff           call 0x7e32b0
// 0089c0c2  898624010000         mov dword ptr [esi + 0x124], eax
// 0089c0c8  e8537af4ff           call 0x7e3b20
// 0089c0cd  6a10                 push 0x10
// 0089c0cf  8bc8                 mov ecx, eax
// 0089c0d1  e8da71f4ff           call 0x7e32b0
// 0089c0d6  898630010000         mov dword ptr [esi + 0x130], eax
// 0089c0dc  e83f7af4ff           call 0x7e3b20
// 0089c0e1  6a15                 push 0x15
// 0089c0e3  8bc8                 mov ecx, eax
// 0089c0e5  e8c671f4ff           call 0x7e32b0
// 0089c0ea  89863c010000         mov dword ptr [esi + 0x13c], eax
// 0089c0f0  e82b7af4ff           call 0x7e3b20
// 0089c0f5  6a12                 push 0x12
// 0089c0f7  8bc8                 mov ecx, eax
// 0089c0f9  e8b271f4ff           call 0x7e32b0
// 0089c0fe  898690010000         mov dword ptr [esi + 0x190], eax
// 0089c104  e8177af4ff           call 0x7e3b20
// 0089c109  6a12                 push 0x12
// 0089c10b  8bc8                 mov ecx, eax
// 0089c10d  e89e71f4ff           call 0x7e32b0
// 0089c112  898678010000         mov dword ptr [esi + 0x178], eax
// 0089c118  e8037af4ff           call 0x7e3b20
// 0089c11d  6a10                 push 0x10
// 0089c11f  8bc8                 mov ecx, eax
// 0089c121  e88a71f4ff           call 0x7e32b0
// 0089c126  898684010000         mov dword ptr [esi + 0x184], eax
// 0089c12c  83c8ff               or eax, 0xffffffff
// 0089c12f  89869c010000         mov dword ptr [esi + 0x19c], eax
// 0089c135  8986a8010000         mov dword ptr [esi + 0x1a8], eax
// 0089c13b  8986b4010000         mov dword ptr [esi + 0x1b4], eax
// 0089c141  8b867c010000         mov eax, dword ptr [esi + 0x17c]
// 0089c147  8986c4010000         mov dword ptr [esi + 0x1c4], eax
// 0089c14d  8b8e78010000         mov ecx, dword ptr [esi + 0x178]
// 0089c153  898ec0010000         mov dword ptr [esi + 0x1c0], ecx
// 0089c159  8b9688010000         mov edx, dword ptr [esi + 0x188]
// 0089c15f  8996d0010000         mov dword ptr [esi + 0x1d0], edx
// 0089c165  8b8684010000         mov eax, dword ptr [esi + 0x184]
// 0089c16b  8986cc010000         mov dword ptr [esi + 0x1cc], eax
// 0089c171  8b8e94010000         mov ecx, dword ptr [esi + 0x194]
// 0089c177  898edc010000         mov dword ptr [esi + 0x1dc], ecx
// 0089c17d  8b9690010000         mov edx, dword ptr [esi + 0x190]
// 0089c183  8996d8010000         mov dword ptr [esi + 0x1d8], edx
// 0089c189  8b86a0010000         mov eax, dword ptr [esi + 0x1a0]
// 0089c18f  8986e8010000         mov dword ptr [esi + 0x1e8], eax
// 0089c195  8b8e9c010000         mov ecx, dword ptr [esi + 0x19c]
// 0089c19b  898ee4010000         mov dword ptr [esi + 0x1e4], ecx
// 0089c1a1  8b96ac010000         mov edx, dword ptr [esi + 0x1ac]
// 0089c1a7  8996f4010000         mov dword ptr [esi + 0x1f4], edx
// 0089c1ad  8b86a8010000         mov eax, dword ptr [esi + 0x1a8]
// 0089c1b3  8986f0010000         mov dword ptr [esi + 0x1f0], eax
// 0089c1b9  8b8eb8010000         mov ecx, dword ptr [esi + 0x1b8]
// 0089c1bf  898e00020000         mov dword ptr [esi + 0x200], ecx
// 0089c1c5  8b96b4010000         mov edx, dword ptr [esi + 0x1b4]
// 0089c1cb  8996fc010000         mov dword ptr [esi + 0x1fc], edx
// 0089c1d1  e84a79f4ff           call 0x7e3b20
// 0089c1d6  6a05                 push 5
// 0089c1d8  8bc8                 mov ecx, eax
// 0089c1da  e8d170f4ff           call 0x7e32b0
// 0089c1df  8986e4010000         mov dword ptr [esi + 0x1e4], eax
// 0089c1e5  e83679f4ff           call 0x7e3b20
// 0089c1ea  6a10                 push 0x10
// 0089c1ec  8bc8                 mov ecx, eax
// 0089c1ee  e8bd70f4ff           call 0x7e32b0
// 0089c1f3  8986f0010000         mov dword ptr [esi + 0x1f0], eax
// 0089c1f9  e82279f4ff           call 0x7e3b20
// 0089c1fe  6a0f                 push 0xf
// 0089c200  8bc8                 mov ecx, eax
// 0089c202  e8a970f4ff           call 0x7e32b0
// 0089c207  894678               mov dword ptr [esi + 0x78], eax
// 0089c20a  e81179f4ff           call 0x7e3b20
// 0089c20f  6a0f                 push 0xf
// 0089c211  8bc8                 mov ecx, eax
// 0089c213  e89870f4ff           call 0x7e32b0
// 0089c218  89869c000000         mov dword ptr [esi + 0x9c], eax
// 0089c21e  e8fd78f4ff           call 0x7e3b20
// 0089c223  6a0f                 push 0xf
// 0089c225  8bc8                 mov ecx, eax
// 0089c227  e88470f4ff           call 0x7e32b0
// 0089c22c  898684000000         mov dword ptr [esi + 0x84], eax
// 0089c232  e8e978f4ff           call 0x7e3b20
// 0089c237  6a0f                 push 0xf
// 0089c239  8bc8                 mov ecx, eax
// 0089c23b  e87070f4ff           call 0x7e32b0
// 0089c240  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 0089c246  898690000000         mov dword ptr [esi + 0x90], eax
// 0089c24c  e88fa4c3ff           call 0x4d66e0
// 0089c251  83f807               cmp eax, 7
// 0089c254  7511                 jne 0x89c267
// 0089c256  e8c578f4ff           call 0x7e3b20
// 0089c25b  6a05                 push 5
// 0089c25d  8bc8                 mov ecx, eax
// 0089c25f  e84c70f4ff           call 0x7e32b0
// 0089c264  894678               mov dword ptr [esi + 0x78], eax
// 0089c267  8b470c               mov eax, dword ptr [edi + 0xc]
// 0089c26a  894630               mov dword ptr [esi + 0x30], eax
// 0089c26d  8b4f08               mov ecx, dword ptr [edi + 8]
// 0089c270  894e2c               mov dword ptr [esi + 0x2c], ecx
// 0089c273  8b5718               mov edx, dword ptr [edi + 0x18]
// 0089c276  89563c               mov dword ptr [esi + 0x3c], edx
// 0089c279  8b4714               mov eax, dword ptr [edi + 0x14]
// 0089c27c  894638               mov dword ptr [esi + 0x38], eax
// 0089c27f  d9471c               fld dword ptr [edi + 0x1c]
// 0089c282  5f                   pop edi
// 0089c283  d95e40               fstp dword ptr [esi + 0x40]
// 0089c286  5e                   pop esi
// 0089c287  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?RefreshMetrics@CColorSet@CXTPTabPaintManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
