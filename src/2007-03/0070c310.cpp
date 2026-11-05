// from server: 100% by auto
// roc 2007-03 0070c310  unit: seg_00700000  size: 792 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0070c310
//
// 0070c310  56                   push esi
// 0070c311  57                   push edi
// 0070c312  8bf1                 mov esi, ecx
// 0070c314  e8b7a7f4ff           call 0x656ad0
// 0070c319  e8828cf4ff           call 0x654fa0
// 0070c31e  6a10                 push 0x10
// 0070c320  8bc8                 mov ecx, eax
// 0070c322  e88984f4ff           call 0x6547b0
// 0070c327  894648               mov dword ptr [esi + 0x48], eax
// 0070c32a  e8718cf4ff           call 0x654fa0
// 0070c32f  6a0f                 push 0xf
// 0070c331  8bc8                 mov ecx, eax
// 0070c333  8d7e04               lea edi, [esi + 4]
// 0070c336  e87584f4ff           call 0x6547b0
// 0070c33b  50                   push eax
// 0070c33c  8bcf                 mov ecx, edi
// 0070c33e  e8cd8bf4ff           call 0x654f10
// 0070c343  e8588cf4ff           call 0x654fa0
// 0070c348  6a0f                 push 0xf
// 0070c34a  8bc8                 mov ecx, eax
// 0070c34c  e85f84f4ff           call 0x6547b0
// 0070c351  894654               mov dword ptr [esi + 0x54], eax
// 0070c354  e8478cf4ff           call 0x654fa0
// 0070c359  6a0f                 push 0xf
// 0070c35b  8bc8                 mov ecx, eax
// 0070c35d  e84e84f4ff           call 0x6547b0
// 0070c362  894660               mov dword ptr [esi + 0x60], eax
// 0070c365  e8368cf4ff           call 0x654fa0
// 0070c36a  6a14                 push 0x14
// 0070c36c  8bc8                 mov ecx, eax
// 0070c36e  e83d84f4ff           call 0x6547b0
// 0070c373  89466c               mov dword ptr [esi + 0x6c], eax
// 0070c376  e8258cf4ff           call 0x654fa0
// 0070c37b  6a12                 push 0x12
// 0070c37d  8bc8                 mov ecx, eax
// 0070c37f  e82c84f4ff           call 0x6547b0
// 0070c384  8986b4000000         mov dword ptr [esi + 0xb4], eax
// 0070c38a  e8118cf4ff           call 0x654fa0
// 0070c38f  6a12                 push 0x12
// 0070c391  8bc8                 mov ecx, eax
// 0070c393  e81884f4ff           call 0x6547b0
// 0070c398  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 0070c39e  e8fd8bf4ff           call 0x654fa0
// 0070c3a3  6a12                 push 0x12
// 0070c3a5  8bc8                 mov ecx, eax
// 0070c3a7  e80484f4ff           call 0x6547b0
// 0070c3ac  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 0070c3b2  c786cc00000000008000 mov dword ptr [esi + 0xcc], 0x800000
// 0070c3bc  e8df8bf4ff           call 0x654fa0
// 0070c3c1  6a11                 push 0x11
// 0070c3c3  8bc8                 mov ecx, eax
// 0070c3c5  e8e683f4ff           call 0x6547b0
// 0070c3ca  8986d8000000         mov dword ptr [esi + 0xd8], eax
// 0070c3d0  e8cb8bf4ff           call 0x654fa0
// 0070c3d5  6a05                 push 5
// 0070c3d7  8bc8                 mov ecx, eax
// 0070c3d9  e8d283f4ff           call 0x6547b0
// 0070c3de  50                   push eax
// 0070c3df  8d8ee0000000         lea ecx, [esi + 0xe0]
// 0070c3e5  e8268bf4ff           call 0x654f10
// 0070c3ea  e8b18bf4ff           call 0x654fa0
// 0070c3ef  6a0d                 push 0xd
// 0070c3f1  8bc8                 mov ecx, eax
// 0070c3f3  e8b883f4ff           call 0x6547b0
// 0070c3f8  50                   push eax
// 0070c3f9  8d8e00010000         lea ecx, [esi + 0x100]
// 0070c3ff  e80c8bf4ff           call 0x654f10
// 0070c404  e8978bf4ff           call 0x654fa0
// 0070c409  6a10                 push 0x10
// 0070c40b  8bc8                 mov ecx, eax
// 0070c40d  e89e83f4ff           call 0x6547b0
// 0070c412  898648010000         mov dword ptr [esi + 0x148], eax
// 0070c418  e8838bf4ff           call 0x654fa0
// 0070c41d  6a10                 push 0x10
// 0070c41f  8bc8                 mov ecx, eax
// 0070c421  e88a83f4ff           call 0x6547b0
// 0070c426  898654010000         mov dword ptr [esi + 0x154], eax
// 0070c42c  e86f8bf4ff           call 0x654fa0
// 0070c431  6a0f                 push 0xf
// 0070c433  8bc8                 mov ecx, eax
// 0070c435  e87683f4ff           call 0x6547b0
// 0070c43a  898660010000         mov dword ptr [esi + 0x160], eax
// 0070c440  e85b8bf4ff           call 0x654fa0
// 0070c445  6a0f                 push 0xf
// 0070c447  8bc8                 mov ecx, eax
// 0070c449  e86283f4ff           call 0x6547b0
// 0070c44e  89866c010000         mov dword ptr [esi + 0x16c], eax
// 0070c454  e8478bf4ff           call 0x654fa0
// 0070c459  6a14                 push 0x14
// 0070c45b  8bc8                 mov ecx, eax
// 0070c45d  e84e83f4ff           call 0x6547b0
// 0070c462  898624010000         mov dword ptr [esi + 0x124], eax
// 0070c468  e8338bf4ff           call 0x654fa0
// 0070c46d  6a10                 push 0x10
// 0070c46f  8bc8                 mov ecx, eax
// 0070c471  e83a83f4ff           call 0x6547b0
// 0070c476  898630010000         mov dword ptr [esi + 0x130], eax
// 0070c47c  e81f8bf4ff           call 0x654fa0
// 0070c481  6a15                 push 0x15
// 0070c483  8bc8                 mov ecx, eax
// 0070c485  e82683f4ff           call 0x6547b0
// 0070c48a  89863c010000         mov dword ptr [esi + 0x13c], eax
// 0070c490  e80b8bf4ff           call 0x654fa0
// 0070c495  6a12                 push 0x12
// 0070c497  8bc8                 mov ecx, eax
// 0070c499  e81283f4ff           call 0x6547b0
// 0070c49e  898690010000         mov dword ptr [esi + 0x190], eax
// 0070c4a4  e8f78af4ff           call 0x654fa0
// 0070c4a9  6a12                 push 0x12
// 0070c4ab  8bc8                 mov ecx, eax
// 0070c4ad  e8fe82f4ff           call 0x6547b0
// 0070c4b2  898678010000         mov dword ptr [esi + 0x178], eax
// 0070c4b8  e8e38af4ff           call 0x654fa0
// 0070c4bd  6a10                 push 0x10
// 0070c4bf  8bc8                 mov ecx, eax
// 0070c4c1  e8ea82f4ff           call 0x6547b0
// 0070c4c6  898684010000         mov dword ptr [esi + 0x184], eax
// 0070c4cc  83c8ff               or eax, 0xffffffff
// 0070c4cf  89869c010000         mov dword ptr [esi + 0x19c], eax
// 0070c4d5  8986a8010000         mov dword ptr [esi + 0x1a8], eax
// 0070c4db  8986b4010000         mov dword ptr [esi + 0x1b4], eax
// 0070c4e1  8b867c010000         mov eax, dword ptr [esi + 0x17c]
// 0070c4e7  8986c4010000         mov dword ptr [esi + 0x1c4], eax
// 0070c4ed  8b8e78010000         mov ecx, dword ptr [esi + 0x178]
// 0070c4f3  898ec0010000         mov dword ptr [esi + 0x1c0], ecx
// 0070c4f9  8b9688010000         mov edx, dword ptr [esi + 0x188]
// 0070c4ff  8996d0010000         mov dword ptr [esi + 0x1d0], edx
// 0070c505  8b8684010000         mov eax, dword ptr [esi + 0x184]
// 0070c50b  8986cc010000         mov dword ptr [esi + 0x1cc], eax
// 0070c511  8b8e94010000         mov ecx, dword ptr [esi + 0x194]
// 0070c517  898edc010000         mov dword ptr [esi + 0x1dc], ecx
// 0070c51d  8b9690010000         mov edx, dword ptr [esi + 0x190]
// 0070c523  8996d8010000         mov dword ptr [esi + 0x1d8], edx
// 0070c529  8b86a0010000         mov eax, dword ptr [esi + 0x1a0]
// 0070c52f  8986e8010000         mov dword ptr [esi + 0x1e8], eax
// 0070c535  8b8e9c010000         mov ecx, dword ptr [esi + 0x19c]
// 0070c53b  898ee4010000         mov dword ptr [esi + 0x1e4], ecx
// 0070c541  8b96ac010000         mov edx, dword ptr [esi + 0x1ac]
// 0070c547  8996f4010000         mov dword ptr [esi + 0x1f4], edx
// 0070c54d  8b86a8010000         mov eax, dword ptr [esi + 0x1a8]
// 0070c553  8986f0010000         mov dword ptr [esi + 0x1f0], eax
// 0070c559  8b8eb8010000         mov ecx, dword ptr [esi + 0x1b8]
// 0070c55f  898e00020000         mov dword ptr [esi + 0x200], ecx
// 0070c565  8b96b4010000         mov edx, dword ptr [esi + 0x1b4]
// 0070c56b  8996fc010000         mov dword ptr [esi + 0x1fc], edx
// 0070c571  e82a8af4ff           call 0x654fa0
// 0070c576  6a05                 push 5
// 0070c578  8bc8                 mov ecx, eax
// 0070c57a  e83182f4ff           call 0x6547b0
// 0070c57f  8986e4010000         mov dword ptr [esi + 0x1e4], eax
// 0070c585  e8168af4ff           call 0x654fa0
// 0070c58a  6a10                 push 0x10
// 0070c58c  8bc8                 mov ecx, eax
// 0070c58e  e81d82f4ff           call 0x6547b0
// 0070c593  8986f0010000         mov dword ptr [esi + 0x1f0], eax
// 0070c599  e8028af4ff           call 0x654fa0
// 0070c59e  6a0f                 push 0xf
// 0070c5a0  8bc8                 mov ecx, eax
// 0070c5a2  e80982f4ff           call 0x6547b0
// 0070c5a7  894678               mov dword ptr [esi + 0x78], eax
// 0070c5aa  e8f189f4ff           call 0x654fa0
// 0070c5af  6a0f                 push 0xf
// 0070c5b1  8bc8                 mov ecx, eax
// 0070c5b3  e8f881f4ff           call 0x6547b0
// 0070c5b8  89869c000000         mov dword ptr [esi + 0x9c], eax
// 0070c5be  e8dd89f4ff           call 0x654fa0
// 0070c5c3  6a0f                 push 0xf
// 0070c5c5  8bc8                 mov ecx, eax
// 0070c5c7  e8e481f4ff           call 0x6547b0
// 0070c5cc  898684000000         mov dword ptr [esi + 0x84], eax
// 0070c5d2  e8c989f4ff           call 0x654fa0
// 0070c5d7  6a0f                 push 0xf
// 0070c5d9  8bc8                 mov ecx, eax
// 0070c5db  e8d081f4ff           call 0x6547b0
// 0070c5e0  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 0070c5e6  898690000000         mov dword ptr [esi + 0x90], eax
// 0070c5ec  e8dfb6fdff           call 0x6e7cd0
// 0070c5f1  83f807               cmp eax, 7
// 0070c5f4  7511                 jne 0x70c607
// 0070c5f6  e8a589f4ff           call 0x654fa0
// 0070c5fb  6a05                 push 5
// 0070c5fd  8bc8                 mov ecx, eax
// 0070c5ff  e8ac81f4ff           call 0x6547b0
// 0070c604  894678               mov dword ptr [esi + 0x78], eax
// 0070c607  8b470c               mov eax, dword ptr [edi + 0xc]
// 0070c60a  894630               mov dword ptr [esi + 0x30], eax
// 0070c60d  8b4f08               mov ecx, dword ptr [edi + 8]
// 0070c610  894e2c               mov dword ptr [esi + 0x2c], ecx
// 0070c613  8b5718               mov edx, dword ptr [edi + 0x18]
// 0070c616  89563c               mov dword ptr [esi + 0x3c], edx
// 0070c619  8b4714               mov eax, dword ptr [edi + 0x14]
// 0070c61c  894638               mov dword ptr [esi + 0x38], eax
// 0070c61f  d9471c               fld dword ptr [edi + 0x1c]
// 0070c622  5f                   pop edi
// 0070c623  d95e40               fstp dword ptr [esi + 0x40]
// 0070c626  5e                   pop esi
// 0070c627  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?RefreshMetrics@CColorSet@CXTPTabPaintManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
