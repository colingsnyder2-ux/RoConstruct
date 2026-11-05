// from server: 100% by auto
// roc 2009-06 0080c4f0  unit: CXTPTabPaintManager::CColorSetWinXP  size: 362 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080c4f0
//
// 0080c4f0  56                   push esi
// 0080c4f1  8bf1                 mov esi, ecx
// 0080c4f3  57                   push edi
// 0080c4f4  8d4e04               lea ecx, [esi + 4]
// 0080c4f7  c70644c79000         mov dword ptr [esi], 0x90c744
// 0080c4fd  e8ce7af4ff           call 0x753fd0
// 0080c502  8d4e24               lea ecx, [esi + 0x24]
// 0080c505  e8c67af4ff           call 0x753fd0
// 0080c50a  8d4e44               lea ecx, [esi + 0x44]
// 0080c50d  e89e7af4ff           call 0x753fb0
// 0080c512  8d4e50               lea ecx, [esi + 0x50]
// 0080c515  e8967af4ff           call 0x753fb0
// 0080c51a  8d4e5c               lea ecx, [esi + 0x5c]
// 0080c51d  e88e7af4ff           call 0x753fb0
// 0080c522  8d4e68               lea ecx, [esi + 0x68]
// 0080c525  e8867af4ff           call 0x753fb0
// 0080c52a  8d4e74               lea ecx, [esi + 0x74]
// 0080c52d  e87e7af4ff           call 0x753fb0
// 0080c532  8d8e80000000         lea ecx, [esi + 0x80]
// 0080c538  e8737af4ff           call 0x753fb0
// 0080c53d  8d8e8c000000         lea ecx, [esi + 0x8c]
// 0080c543  e8687af4ff           call 0x753fb0
// 0080c548  8d8e98000000         lea ecx, [esi + 0x98]
// 0080c54e  e85d7af4ff           call 0x753fb0
// 0080c553  8d8ea4000000         lea ecx, [esi + 0xa4]
// 0080c559  e8527af4ff           call 0x753fb0
// 0080c55e  8d8eb0000000         lea ecx, [esi + 0xb0]
// 0080c564  e8477af4ff           call 0x753fb0
// 0080c569  8d8ebc000000         lea ecx, [esi + 0xbc]
// 0080c56f  e83c7af4ff           call 0x753fb0
// 0080c574  8d8ec8000000         lea ecx, [esi + 0xc8]
// 0080c57a  e8317af4ff           call 0x753fb0
// 0080c57f  8d8ed4000000         lea ecx, [esi + 0xd4]
// 0080c585  e8267af4ff           call 0x753fb0
// 0080c58a  8dbee0000000         lea edi, [esi + 0xe0]
// 0080c590  8bcf                 mov ecx, edi
// 0080c592  e8397af4ff           call 0x753fd0
// 0080c597  8d4f20               lea ecx, [edi + 0x20]
// 0080c59a  e8317af4ff           call 0x753fd0
// 0080c59f  8dbe20010000         lea edi, [esi + 0x120]
// 0080c5a5  8bcf                 mov ecx, edi
// 0080c5a7  e8047af4ff           call 0x753fb0
// 0080c5ac  8d4f0c               lea ecx, [edi + 0xc]
// 0080c5af  e8fc79f4ff           call 0x753fb0
// 0080c5b4  8d4f18               lea ecx, [edi + 0x18]
// 0080c5b7  e8f479f4ff           call 0x753fb0
// 0080c5bc  8dbe44010000         lea edi, [esi + 0x144]
// 0080c5c2  8bcf                 mov ecx, edi
// 0080c5c4  e8e779f4ff           call 0x753fb0
// 0080c5c9  8d4f0c               lea ecx, [edi + 0xc]
// 0080c5cc  e8df79f4ff           call 0x753fb0
// 0080c5d1  8d4f18               lea ecx, [edi + 0x18]
// 0080c5d4  e8d779f4ff           call 0x753fb0
// 0080c5d9  8d4f24               lea ecx, [edi + 0x24]
// 0080c5dc  e8cf79f4ff           call 0x753fb0
// 0080c5e1  8dbe74010000         lea edi, [esi + 0x174]
// 0080c5e7  8bcf                 mov ecx, edi
// 0080c5e9  e8c279f4ff           call 0x753fb0
// 0080c5ee  8d4f0c               lea ecx, [edi + 0xc]
// 0080c5f1  e8ba79f4ff           call 0x753fb0
// 0080c5f6  8d4f18               lea ecx, [edi + 0x18]
// 0080c5f9  e8b279f4ff           call 0x753fb0
// 0080c5fe  8d4f24               lea ecx, [edi + 0x24]
// 0080c601  e8aa79f4ff           call 0x753fb0
// 0080c606  8d4f30               lea ecx, [edi + 0x30]
// 0080c609  e8a279f4ff           call 0x753fb0
// 0080c60e  8d4f3c               lea ecx, [edi + 0x3c]
// 0080c611  e89a79f4ff           call 0x753fb0
// 0080c616  8dbebc010000         lea edi, [esi + 0x1bc]
// 0080c61c  8bcf                 mov ecx, edi
// 0080c61e  e88d79f4ff           call 0x753fb0
// 0080c623  8d4f0c               lea ecx, [edi + 0xc]
// 0080c626  e88579f4ff           call 0x753fb0
// 0080c62b  8d4f18               lea ecx, [edi + 0x18]
// 0080c62e  e87d79f4ff           call 0x753fb0
// 0080c633  8d4f24               lea ecx, [edi + 0x24]
// 0080c636  e87579f4ff           call 0x753fb0
// 0080c63b  8d4f30               lea ecx, [edi + 0x30]
// 0080c63e  e86d79f4ff           call 0x753fb0
// 0080c643  8d4f3c               lea ecx, [edi + 0x3c]
// 0080c646  e86579f4ff           call 0x753fb0
// 0080c64b  5f                   pop edi
// 0080c64c  c7860402000000000000 mov dword ptr [esi + 0x204], 0
// 0080c656  8bc6                 mov eax, esi
// 0080c658  5e                   pop esi
// 0080c659  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ??0CColorSet@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
