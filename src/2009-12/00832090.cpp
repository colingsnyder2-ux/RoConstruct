// from server: 100% by auto
// roc 2009-12 00832090  unit: CRobloxTreeCtrl  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00832090
//
// 00832090  56                   push esi
// 00832091  8bf1                 mov esi, ecx
// 00832093  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00832096  e80b460f00           call 0x9266a6
// 0083209b  85c0                 test eax, eax
// 0083209d  7510                 jne 0x8320af
// 0083209f  e82cd9ffff           call 0x82f9d0
// 008320a4  6a0f                 push 0xf
// 008320a6  8bc8                 mov ecx, eax
// 008320a8  e853d0ffff           call 0x82f100
// 008320ad  5e                   pop esi
// 008320ae  c3                   ret 
// 008320af  e86c960000           call 0x83b720
// 008320b4  8bc8                 mov ecx, eax
// 008320b6  e835a60000           call 0x83c6f0
// 008320bb  3d47000400           cmp eax, 0x40047
// 008320c0  721b                 jb 0x8320dd
// 008320c2  8b4634               mov eax, dword ptr [esi + 0x34]
// 008320c5  8b4020               mov eax, dword ptr [eax + 0x20]
// 008320c8  6a00                 push 0
// 008320ca  6a00                 push 0
// 008320cc  681f110000           push 0x111f
// 008320d1  50                   push eax
// 008320d2  ff15c4cb9800         call dword ptr [0x98cbc4]
// 008320d8  83f8ff               cmp eax, -1
// 008320db  750e                 jne 0x8320eb
// 008320dd  e8eed8ffff           call 0x82f9d0
// 008320e2  6a05                 push 5
// 008320e4  8bc8                 mov ecx, eax
// 008320e6  e815d0ffff           call 0x82f100
// 008320eb  5e                   pop esi
// 008320ec  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetTreeBackColor@CXTPTreeBase@@MBEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
