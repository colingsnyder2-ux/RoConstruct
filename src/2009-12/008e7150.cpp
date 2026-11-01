// from server: 100% by auto
// roc 2009-12 008e7150  unit: CXTPTabPaintManager::CColorSet  size: 792 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e7150
//
// 008e7150  56                   push esi
// 008e7151  57                   push edi
// 008e7152  8bf1                 mov esi, ecx
// 008e7154  e847a4f4ff           call 0x8315a0
// 008e7159  e87288f4ff           call 0x82f9d0
// 008e715e  6a10                 push 0x10
// 008e7160  8bc8                 mov ecx, eax
// 008e7162  e8997ff4ff           call 0x82f100
// 008e7167  894648               mov dword ptr [esi + 0x48], eax
// 008e716a  e86188f4ff           call 0x82f9d0
// 008e716f  6a0f                 push 0xf
// 008e7171  8bc8                 mov ecx, eax
// 008e7173  8d7e04               lea edi, [esi + 4]
// 008e7176  e8857ff4ff           call 0x82f100
// 008e717b  50                   push eax
// 008e717c  8bcf                 mov ecx, edi
// 008e717e  e89d87f4ff           call 0x82f920
// 008e7183  e84888f4ff           call 0x82f9d0
// 008e7188  6a0f                 push 0xf
// 008e718a  8bc8                 mov ecx, eax
// 008e718c  e86f7ff4ff           call 0x82f100
// 008e7191  894654               mov dword ptr [esi + 0x54], eax
// 008e7194  e83788f4ff           call 0x82f9d0
// 008e7199  6a0f                 push 0xf
// 008e719b  8bc8                 mov ecx, eax
// 008e719d  e85e7ff4ff           call 0x82f100
// 008e71a2  894660               mov dword ptr [esi + 0x60], eax
// 008e71a5  e82688f4ff           call 0x82f9d0
// 008e71aa  6a14                 push 0x14
// 008e71ac  8bc8                 mov ecx, eax
// 008e71ae  e84d7ff4ff           call 0x82f100
// 008e71b3  89466c               mov dword ptr [esi + 0x6c], eax
// 008e71b6  e81588f4ff           call 0x82f9d0
// 008e71bb  6a12                 push 0x12
// 008e71bd  8bc8                 mov ecx, eax
// 008e71bf  e83c7ff4ff           call 0x82f100
// 008e71c4  8986b4000000         mov dword ptr [esi + 0xb4], eax
// 008e71ca  e80188f4ff           call 0x82f9d0
// 008e71cf  6a12                 push 0x12
// 008e71d1  8bc8                 mov ecx, eax
// 008e71d3  e8287ff4ff           call 0x82f100
// 008e71d8  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 008e71de  e8ed87f4ff           call 0x82f9d0
// 008e71e3  6a12                 push 0x12
// 008e71e5  8bc8                 mov ecx, eax
// 008e71e7  e8147ff4ff           call 0x82f100
// 008e71ec  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 008e71f2  c786cc00000000008000 mov dword ptr [esi + 0xcc], 0x800000
// 008e71fc  e8cf87f4ff           call 0x82f9d0
// 008e7201  6a11                 push 0x11
// 008e7203  8bc8                 mov ecx, eax
// 008e7205  e8f67ef4ff           call 0x82f100
// 008e720a  8986d8000000         mov dword ptr [esi + 0xd8], eax
// 008e7210  e8bb87f4ff           call 0x82f9d0
// 008e7215  6a05                 push 5
// 008e7217  8bc8                 mov ecx, eax
// 008e7219  e8e27ef4ff           call 0x82f100
// 008e721e  50                   push eax
// 008e721f  8d8ee0000000         lea ecx, [esi + 0xe0]
// 008e7225  e8f686f4ff           call 0x82f920
// 008e722a  e8a187f4ff           call 0x82f9d0
// 008e722f  6a0d                 push 0xd
// 008e7231  8bc8                 mov ecx, eax
// 008e7233  e8c87ef4ff           call 0x82f100
// 008e7238  50                   push eax
// 008e7239  8d8e00010000         lea ecx, [esi + 0x100]
// 008e723f  e8dc86f4ff           call 0x82f920
// 008e7244  e88787f4ff           call 0x82f9d0
// 008e7249  6a10                 push 0x10
// 008e724b  8bc8                 mov ecx, eax
// 008e724d  e8ae7ef4ff           call 0x82f100
// 008e7252  898648010000         mov dword ptr [esi + 0x148], eax
// 008e7258  e87387f4ff           call 0x82f9d0
// 008e725d  6a10                 push 0x10
// 008e725f  8bc8                 mov ecx, eax
// 008e7261  e89a7ef4ff           call 0x82f100
// 008e7266  898654010000         mov dword ptr [esi + 0x154], eax
// 008e726c  e85f87f4ff           call 0x82f9d0
// 008e7271  6a0f                 push 0xf
// 008e7273  8bc8                 mov ecx, eax
// 008e7275  e8867ef4ff           call 0x82f100
// 008e727a  898660010000         mov dword ptr [esi + 0x160], eax
// 008e7280  e84b87f4ff           call 0x82f9d0
// 008e7285  6a0f                 push 0xf
// 008e7287  8bc8                 mov ecx, eax
// 008e7289  e8727ef4ff           call 0x82f100
// 008e728e  89866c010000         mov dword ptr [esi + 0x16c], eax
// 008e7294  e83787f4ff           call 0x82f9d0
// 008e7299  6a14                 push 0x14
// 008e729b  8bc8                 mov ecx, eax
// 008e729d  e85e7ef4ff           call 0x82f100
// 008e72a2  898624010000         mov dword ptr [esi + 0x124], eax
// 008e72a8  e82387f4ff           call 0x82f9d0
// 008e72ad  6a10                 push 0x10
// 008e72af  8bc8                 mov ecx, eax
// 008e72b1  e84a7ef4ff           call 0x82f100
// 008e72b6  898630010000         mov dword ptr [esi + 0x130], eax
// 008e72bc  e80f87f4ff           call 0x82f9d0
// 008e72c1  6a15                 push 0x15
// 008e72c3  8bc8                 mov ecx, eax
// 008e72c5  e8367ef4ff           call 0x82f100
// 008e72ca  89863c010000         mov dword ptr [esi + 0x13c], eax
// 008e72d0  e8fb86f4ff           call 0x82f9d0
// 008e72d5  6a12                 push 0x12
// 008e72d7  8bc8                 mov ecx, eax
// 008e72d9  e8227ef4ff           call 0x82f100
// 008e72de  898690010000         mov dword ptr [esi + 0x190], eax
// 008e72e4  e8e786f4ff           call 0x82f9d0
// 008e72e9  6a12                 push 0x12
// 008e72eb  8bc8                 mov ecx, eax
// 008e72ed  e80e7ef4ff           call 0x82f100
// 008e72f2  898678010000         mov dword ptr [esi + 0x178], eax
// 008e72f8  e8d386f4ff           call 0x82f9d0
// 008e72fd  6a10                 push 0x10
// 008e72ff  8bc8                 mov ecx, eax
// 008e7301  e8fa7df4ff           call 0x82f100
// 008e7306  898684010000         mov dword ptr [esi + 0x184], eax
// 008e730c  83c8ff               or eax, 0xffffffff
// 008e730f  89869c010000         mov dword ptr [esi + 0x19c], eax
// 008e7315  8986a8010000         mov dword ptr [esi + 0x1a8], eax
// 008e731b  8986b4010000         mov dword ptr [esi + 0x1b4], eax
// 008e7321  8b867c010000         mov eax, dword ptr [esi + 0x17c]
// 008e7327  8986c4010000         mov dword ptr [esi + 0x1c4], eax
// 008e732d  8b8e78010000         mov ecx, dword ptr [esi + 0x178]
// 008e7333  898ec0010000         mov dword ptr [esi + 0x1c0], ecx
// 008e7339  8b9688010000         mov edx, dword ptr [esi + 0x188]
// 008e733f  8996d0010000         mov dword ptr [esi + 0x1d0], edx
// 008e7345  8b8684010000         mov eax, dword ptr [esi + 0x184]
// 008e734b  8986cc010000         mov dword ptr [esi + 0x1cc], eax
// 008e7351  8b8e94010000         mov ecx, dword ptr [esi + 0x194]
// 008e7357  898edc010000         mov dword ptr [esi + 0x1dc], ecx
// 008e735d  8b9690010000         mov edx, dword ptr [esi + 0x190]
// 008e7363  8996d8010000         mov dword ptr [esi + 0x1d8], edx
// 008e7369  8b86a0010000         mov eax, dword ptr [esi + 0x1a0]
// 008e736f  8986e8010000         mov dword ptr [esi + 0x1e8], eax
// 008e7375  8b8e9c010000         mov ecx, dword ptr [esi + 0x19c]
// 008e737b  898ee4010000         mov dword ptr [esi + 0x1e4], ecx
// 008e7381  8b96ac010000         mov edx, dword ptr [esi + 0x1ac]
// 008e7387  8996f4010000         mov dword ptr [esi + 0x1f4], edx
// 008e738d  8b86a8010000         mov eax, dword ptr [esi + 0x1a8]
// 008e7393  8986f0010000         mov dword ptr [esi + 0x1f0], eax
// 008e7399  8b8eb8010000         mov ecx, dword ptr [esi + 0x1b8]
// 008e739f  898e00020000         mov dword ptr [esi + 0x200], ecx
// 008e73a5  8b96b4010000         mov edx, dword ptr [esi + 0x1b4]
// 008e73ab  8996fc010000         mov dword ptr [esi + 0x1fc], edx
// 008e73b1  e81a86f4ff           call 0x82f9d0
// 008e73b6  6a05                 push 5
// 008e73b8  8bc8                 mov ecx, eax
// 008e73ba  e8417df4ff           call 0x82f100
// 008e73bf  8986e4010000         mov dword ptr [esi + 0x1e4], eax
// 008e73c5  e80686f4ff           call 0x82f9d0
// 008e73ca  6a10                 push 0x10
// 008e73cc  8bc8                 mov ecx, eax
// 008e73ce  e82d7df4ff           call 0x82f100
// 008e73d3  8986f0010000         mov dword ptr [esi + 0x1f0], eax
// 008e73d9  e8f285f4ff           call 0x82f9d0
// 008e73de  6a0f                 push 0xf
// 008e73e0  8bc8                 mov ecx, eax
// 008e73e2  e8197df4ff           call 0x82f100
// 008e73e7  894678               mov dword ptr [esi + 0x78], eax
// 008e73ea  e8e185f4ff           call 0x82f9d0
// 008e73ef  6a0f                 push 0xf
// 008e73f1  8bc8                 mov ecx, eax
// 008e73f3  e8087df4ff           call 0x82f100
// 008e73f8  89869c000000         mov dword ptr [esi + 0x9c], eax
// 008e73fe  e8cd85f4ff           call 0x82f9d0
// 008e7403  6a0f                 push 0xf
// 008e7405  8bc8                 mov ecx, eax
// 008e7407  e8f47cf4ff           call 0x82f100
// 008e740c  898684000000         mov dword ptr [esi + 0x84], eax
// 008e7412  e8b985f4ff           call 0x82f9d0
// 008e7417  6a0f                 push 0xf
// 008e7419  8bc8                 mov ecx, eax
// 008e741b  e8e07cf4ff           call 0x82f100
// 008e7420  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 008e7426  898690000000         mov dword ptr [esi + 0x90], eax
// 008e742c  e8afd4f7ff           call 0x8648e0
// 008e7431  83f807               cmp eax, 7
// 008e7434  7511                 jne 0x8e7447
// 008e7436  e89585f4ff           call 0x82f9d0
// 008e743b  6a05                 push 5
// 008e743d  8bc8                 mov ecx, eax
// 008e743f  e8bc7cf4ff           call 0x82f100
// 008e7444  894678               mov dword ptr [esi + 0x78], eax
// 008e7447  8b470c               mov eax, dword ptr [edi + 0xc]
// 008e744a  894630               mov dword ptr [esi + 0x30], eax
// 008e744d  8b4f08               mov ecx, dword ptr [edi + 8]
// 008e7450  894e2c               mov dword ptr [esi + 0x2c], ecx
// 008e7453  8b5718               mov edx, dword ptr [edi + 0x18]
// 008e7456  89563c               mov dword ptr [esi + 0x3c], edx
// 008e7459  8b4714               mov eax, dword ptr [edi + 0x14]
// 008e745c  894638               mov dword ptr [esi + 0x38], eax
// 008e745f  d9471c               fld dword ptr [edi + 0x1c]
// 008e7462  5f                   pop edi
// 008e7463  d95e40               fstp dword ptr [esi + 0x40]
// 008e7466  5e                   pop esi
// 008e7467  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?RefreshMetrics@CColorSet@CXTPTabPaintManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
