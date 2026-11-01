// from server: 100% by auto
// roc 2007-03 00651c40  unit: seg_00650000  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00651c40
//
// 00651c40  56                   push esi
// 00651c41  8bf1                 mov esi, ecx
// 00651c43  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00651c46  e86f900e00           call 0x73acba
// 00651c4b  85c0                 test eax, eax
// 00651c4d  7510                 jne 0x651c5f
// 00651c4f  e84c330000           call 0x654fa0
// 00651c54  6a0f                 push 0xf
// 00651c56  8bc8                 mov ecx, eax
// 00651c58  e8532b0000           call 0x6547b0
// 00651c5d  5e                   pop esi
// 00651c5e  c3                   ret 
// 00651c5f  e8ac400300           call 0x685d10
// 00651c64  8bc8                 mov ecx, eax
// 00651c66  e805500300           call 0x686c70
// 00651c6b  3d47000400           cmp eax, 0x40047
// 00651c70  721b                 jb 0x651c8d
// 00651c72  8b4634               mov eax, dword ptr [esi + 0x34]
// 00651c75  8b4020               mov eax, dword ptr [eax + 0x20]
// 00651c78  6a00                 push 0
// 00651c7a  6a00                 push 0
// 00651c7c  681f110000           push 0x111f
// 00651c81  50                   push eax
// 00651c82  ff1550ee7700         call dword ptr [0x77ee50]
// 00651c88  83f8ff               cmp eax, -1
// 00651c8b  750e                 jne 0x651c9b
// 00651c8d  e80e330000           call 0x654fa0
// 00651c92  6a05                 push 5
// 00651c94  8bc8                 mov ecx, eax
// 00651c96  e8152b0000           call 0x6547b0
// 00651c9b  5e                   pop esi
// 00651c9c  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetTreeBackColor@CXTPTreeBase@@MBEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
