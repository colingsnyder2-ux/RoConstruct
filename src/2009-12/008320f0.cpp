// from server: 100% by auto
// roc 2009-12 008320f0  unit: CRobloxTreeCtrl  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008320f0
//
// 008320f0  56                   push esi
// 008320f1  8bf1                 mov esi, ecx
// 008320f3  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 008320f6  e8ab450f00           call 0x9266a6
// 008320fb  85c0                 test eax, eax
// 008320fd  7510                 jne 0x83210f
// 008320ff  e8ccd8ffff           call 0x82f9d0
// 00832104  6a11                 push 0x11
// 00832106  8bc8                 mov ecx, eax
// 00832108  e8f3cfffff           call 0x82f100
// 0083210d  5e                   pop esi
// 0083210e  c3                   ret 
// 0083210f  e80c960000           call 0x83b720
// 00832114  8bc8                 mov ecx, eax
// 00832116  e8d5a50000           call 0x83c6f0
// 0083211b  3d47000400           cmp eax, 0x40047
// 00832120  721b                 jb 0x83213d
// 00832122  8b4634               mov eax, dword ptr [esi + 0x34]
// 00832125  8b4020               mov eax, dword ptr [eax + 0x20]
// 00832128  6a00                 push 0
// 0083212a  6a00                 push 0
// 0083212c  6820110000           push 0x1120
// 00832131  50                   push eax
// 00832132  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00832138  83f8ff               cmp eax, -1
// 0083213b  750e                 jne 0x83214b
// 0083213d  e88ed8ffff           call 0x82f9d0
// 00832142  6a08                 push 8
// 00832144  8bc8                 mov ecx, eax
// 00832146  e8b5cfffff           call 0x82f100
// 0083214b  5e                   pop esi
// 0083214c  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetTreeTextColor@CXTPTreeBase@@MBEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
