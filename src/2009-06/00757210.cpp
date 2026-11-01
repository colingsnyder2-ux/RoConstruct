// from server: 100% by auto
// roc 2009-06 00757210  unit: CRobloxTreeCtrl  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00757210
//
// 00757210  56                   push esi
// 00757211  8bf1                 mov esi, ecx
// 00757213  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00757216  e81f4f0f00           call 0x84c13a
// 0075721b  85c0                 test eax, eax
// 0075721d  7510                 jne 0x75722f
// 0075721f  e8fcd8ffff           call 0x754b20
// 00757224  6a0f                 push 0xf
// 00757226  8bc8                 mov ecx, eax
// 00757228  e873d0ffff           call 0x7542a0
// 0075722d  5e                   pop esi
// 0075722e  c3                   ret 
// 0075722f  e81c970000           call 0x760950
// 00757234  8bc8                 mov ecx, eax
// 00757236  e8e5a60000           call 0x761920
// 0075723b  3d47000400           cmp eax, 0x40047
// 00757240  721b                 jb 0x75725d
// 00757242  8b4634               mov eax, dword ptr [esi + 0x34]
// 00757245  8b4020               mov eax, dword ptr [eax + 0x20]
// 00757248  6a00                 push 0
// 0075724a  6a00                 push 0
// 0075724c  681f110000           push 0x111f
// 00757251  50                   push eax
// 00757252  ff1590ee8900         call dword ptr [0x89ee90]
// 00757258  83f8ff               cmp eax, -1
// 0075725b  750e                 jne 0x75726b
// 0075725d  e8bed8ffff           call 0x754b20
// 00757262  6a05                 push 5
// 00757264  8bc8                 mov ecx, eax
// 00757266  e835d0ffff           call 0x7542a0
// 0075726b  5e                   pop esi
// 0075726c  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetTreeBackColor@CXTPTreeBase@@MBEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
