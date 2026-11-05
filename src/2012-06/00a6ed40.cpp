// roc 2012-06 00a6ed40  unit: CXTPTabPaintManager::CColorSetWhidbey  size: 253 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a6ed40
//
// 00a6ed40  56                   push esi
// 00a6ed41  8bf1                 mov esi, ecx
// 00a6ed43  e8e8e0ffff           call 0xa6ce30
// 00a6ed48  e813ebf4ff           call 0x9bd860
// 00a6ed4d  6a05                 push 5
// 00a6ed4f  8bc8                 mov ecx, eax
// 00a6ed51  e88ae2f4ff           call 0x9bcfe0
// 00a6ed56  894678               mov dword ptr [esi + 0x78], eax
// 00a6ed59  e802ebf4ff           call 0x9bd860
// 00a6ed5e  6a08                 push 8
// 00a6ed60  8bc8                 mov ecx, eax
// 00a6ed62  e879e2f4ff           call 0x9bcfe0
// 00a6ed67  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 00a6ed6d  c7861402000000000000 mov dword ptr [esi + 0x214], 0
// 00a6ed77  c7861802000000000000 mov dword ptr [esi + 0x218], 0
// 00a6ed81  e8daeaf4ff           call 0x9bd860
// 00a6ed86  6a24                 push 0x24
// 00a6ed88  8bc8                 mov ecx, eax
// 00a6ed8a  e851e2f4ff           call 0x9bcfe0
// 00a6ed8f  898684000000         mov dword ptr [esi + 0x84], eax
// 00a6ed95  e8c6eaf4ff           call 0x9bd860
// 00a6ed9a  6a21                 push 0x21
// 00a6ed9c  8bc8                 mov ecx, eax
// 00a6ed9e  e83de2f4ff           call 0x9bcfe0
// 00a6eda3  898690000000         mov dword ptr [esi + 0x90], eax
// 00a6eda9  e8b2eaf4ff           call 0x9bd860
// 00a6edae  6a12                 push 0x12
// 00a6edb0  8bc8                 mov ecx, eax
// 00a6edb2  e829e2f4ff           call 0x9bcfe0
// 00a6edb7  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 00a6edbd  8986cc000000         mov dword ptr [esi + 0xcc], eax
// 00a6edc3  e818eefdff           call 0xa4dbe0
// 00a6edc8  85c0                 test eax, eax
// 00a6edca  7508                 jne 0xa6edd4
// 00a6edcc  8bce                 mov ecx, esi
// 00a6edce  5e                   pop esi
// 00a6edcf  e90cecffff           jmp 0xa6d9e0
// 00a6edd4  e887eaf4ff           call 0x9bd860
// 00a6edd9  8bc8                 mov ecx, eax
// 00a6eddb  e830e8f4ff           call 0x9bd610
// 00a6ede0  85c0                 test eax, eax
// 00a6ede2  7e32                 jle 0xa6ee16
// 00a6ede4  83f802               cmp eax, 2
// 00a6ede7  7e16                 jle 0xa6edff
// 00a6ede9  83f803               cmp eax, 3
// 00a6edec  7528                 jne 0xa6ee16
// 00a6edee  c7869c000000f5f5f800 mov dword ptr [esi + 0x9c], 0xf8f5f5
// 00a6edf8  68eeeeee00           push 0xeeeeee
// 00a6edfd  eb05                 jmp 0xa6ee04
// 00a6edff  68e4e2d500           push 0xd5e2e4
// 00a6ee04  8d4e04               lea ecx, [esi + 4]
// 00a6ee07  e8a4e9f4ff           call 0x9bd7b0
// 00a6ee0c  c7861802000001000000 mov dword ptr [esi + 0x218], 1
// 00a6ee16  e845eaf4ff           call 0x9bd860
// 00a6ee1b  6a39                 push 0x39
// 00a6ee1d  8bc8                 mov ecx, eax
// 00a6ee1f  e8bce1f4ff           call 0x9bcfe0
// 00a6ee24  898654010000         mov dword ptr [esi + 0x154], eax
// 00a6ee2a  e831eaf4ff           call 0x9bd860
// 00a6ee2f  6a39                 push 0x39
// 00a6ee31  8bc8                 mov ecx, eax
// 00a6ee33  e8a8e1f4ff           call 0x9bcfe0
// 00a6ee38  894648               mov dword ptr [esi + 0x48], eax
// 00a6ee3b  5e                   pop esi
// 00a6ee3c  c3                   ret 
// copied from an identical function in another client (function ?RefreshMetrics@CColorSetVisualStudio2005@CXTPTabPaintManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp