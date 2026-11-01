// from server: 100% by auto
// roc 2009-12 008e6fe0  unit: CXTPTabPaintManager::CColorSetWinXP  size: 362 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e6fe0
//
// 008e6fe0  56                   push esi
// 008e6fe1  8bf1                 mov esi, ecx
// 008e6fe3  57                   push edi
// 008e6fe4  8d4e04               lea ecx, [esi + 4]
// 008e6fe7  c706b4cba000         mov dword ptr [esi], 0xa0cbb4
// 008e6fed  e83e7ef4ff           call 0x82ee30
// 008e6ff2  8d4e24               lea ecx, [esi + 0x24]
// 008e6ff5  e8367ef4ff           call 0x82ee30
// 008e6ffa  8d4e44               lea ecx, [esi + 0x44]
// 008e6ffd  e80e7ef4ff           call 0x82ee10
// 008e7002  8d4e50               lea ecx, [esi + 0x50]
// 008e7005  e8067ef4ff           call 0x82ee10
// 008e700a  8d4e5c               lea ecx, [esi + 0x5c]
// 008e700d  e8fe7df4ff           call 0x82ee10
// 008e7012  8d4e68               lea ecx, [esi + 0x68]
// 008e7015  e8f67df4ff           call 0x82ee10
// 008e701a  8d4e74               lea ecx, [esi + 0x74]
// 008e701d  e8ee7df4ff           call 0x82ee10
// 008e7022  8d8e80000000         lea ecx, [esi + 0x80]
// 008e7028  e8e37df4ff           call 0x82ee10
// 008e702d  8d8e8c000000         lea ecx, [esi + 0x8c]
// 008e7033  e8d87df4ff           call 0x82ee10
// 008e7038  8d8e98000000         lea ecx, [esi + 0x98]
// 008e703e  e8cd7df4ff           call 0x82ee10
// 008e7043  8d8ea4000000         lea ecx, [esi + 0xa4]
// 008e7049  e8c27df4ff           call 0x82ee10
// 008e704e  8d8eb0000000         lea ecx, [esi + 0xb0]
// 008e7054  e8b77df4ff           call 0x82ee10
// 008e7059  8d8ebc000000         lea ecx, [esi + 0xbc]
// 008e705f  e8ac7df4ff           call 0x82ee10
// 008e7064  8d8ec8000000         lea ecx, [esi + 0xc8]
// 008e706a  e8a17df4ff           call 0x82ee10
// 008e706f  8d8ed4000000         lea ecx, [esi + 0xd4]
// 008e7075  e8967df4ff           call 0x82ee10
// 008e707a  8dbee0000000         lea edi, [esi + 0xe0]
// 008e7080  8bcf                 mov ecx, edi
// 008e7082  e8a97df4ff           call 0x82ee30
// 008e7087  8d4f20               lea ecx, [edi + 0x20]
// 008e708a  e8a17df4ff           call 0x82ee30
// 008e708f  8dbe20010000         lea edi, [esi + 0x120]
// 008e7095  8bcf                 mov ecx, edi
// 008e7097  e8747df4ff           call 0x82ee10
// 008e709c  8d4f0c               lea ecx, [edi + 0xc]
// 008e709f  e86c7df4ff           call 0x82ee10
// 008e70a4  8d4f18               lea ecx, [edi + 0x18]
// 008e70a7  e8647df4ff           call 0x82ee10
// 008e70ac  8dbe44010000         lea edi, [esi + 0x144]
// 008e70b2  8bcf                 mov ecx, edi
// 008e70b4  e8577df4ff           call 0x82ee10
// 008e70b9  8d4f0c               lea ecx, [edi + 0xc]
// 008e70bc  e84f7df4ff           call 0x82ee10
// 008e70c1  8d4f18               lea ecx, [edi + 0x18]
// 008e70c4  e8477df4ff           call 0x82ee10
// 008e70c9  8d4f24               lea ecx, [edi + 0x24]
// 008e70cc  e83f7df4ff           call 0x82ee10
// 008e70d1  8dbe74010000         lea edi, [esi + 0x174]
// 008e70d7  8bcf                 mov ecx, edi
// 008e70d9  e8327df4ff           call 0x82ee10
// 008e70de  8d4f0c               lea ecx, [edi + 0xc]
// 008e70e1  e82a7df4ff           call 0x82ee10
// 008e70e6  8d4f18               lea ecx, [edi + 0x18]
// 008e70e9  e8227df4ff           call 0x82ee10
// 008e70ee  8d4f24               lea ecx, [edi + 0x24]
// 008e70f1  e81a7df4ff           call 0x82ee10
// 008e70f6  8d4f30               lea ecx, [edi + 0x30]
// 008e70f9  e8127df4ff           call 0x82ee10
// 008e70fe  8d4f3c               lea ecx, [edi + 0x3c]
// 008e7101  e80a7df4ff           call 0x82ee10
// 008e7106  8dbebc010000         lea edi, [esi + 0x1bc]
// 008e710c  8bcf                 mov ecx, edi
// 008e710e  e8fd7cf4ff           call 0x82ee10
// 008e7113  8d4f0c               lea ecx, [edi + 0xc]
// 008e7116  e8f57cf4ff           call 0x82ee10
// 008e711b  8d4f18               lea ecx, [edi + 0x18]
// 008e711e  e8ed7cf4ff           call 0x82ee10
// 008e7123  8d4f24               lea ecx, [edi + 0x24]
// 008e7126  e8e57cf4ff           call 0x82ee10
// 008e712b  8d4f30               lea ecx, [edi + 0x30]
// 008e712e  e8dd7cf4ff           call 0x82ee10
// 008e7133  8d4f3c               lea ecx, [edi + 0x3c]
// 008e7136  e8d57cf4ff           call 0x82ee10
// 008e713b  5f                   pop edi
// 008e713c  c7860402000000000000 mov dword ptr [esi + 0x204], 0
// 008e7146  8bc6                 mov eax, esi
// 008e7148  5e                   pop esi
// 008e7149  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ??0CColorSet@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
