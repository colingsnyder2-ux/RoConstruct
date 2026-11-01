// from server: 100% by auto
// roc 2009-06 00757270  unit: CRobloxTreeCtrl  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00757270
//
// 00757270  56                   push esi
// 00757271  8bf1                 mov esi, ecx
// 00757273  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00757276  e8bf4e0f00           call 0x84c13a
// 0075727b  85c0                 test eax, eax
// 0075727d  7510                 jne 0x75728f
// 0075727f  e89cd8ffff           call 0x754b20
// 00757284  6a11                 push 0x11
// 00757286  8bc8                 mov ecx, eax
// 00757288  e813d0ffff           call 0x7542a0
// 0075728d  5e                   pop esi
// 0075728e  c3                   ret 
// 0075728f  e8bc960000           call 0x760950
// 00757294  8bc8                 mov ecx, eax
// 00757296  e885a60000           call 0x761920
// 0075729b  3d47000400           cmp eax, 0x40047
// 007572a0  721b                 jb 0x7572bd
// 007572a2  8b4634               mov eax, dword ptr [esi + 0x34]
// 007572a5  8b4020               mov eax, dword ptr [eax + 0x20]
// 007572a8  6a00                 push 0
// 007572aa  6a00                 push 0
// 007572ac  6820110000           push 0x1120
// 007572b1  50                   push eax
// 007572b2  ff1590ee8900         call dword ptr [0x89ee90]
// 007572b8  83f8ff               cmp eax, -1
// 007572bb  750e                 jne 0x7572cb
// 007572bd  e85ed8ffff           call 0x754b20
// 007572c2  6a08                 push 8
// 007572c4  8bc8                 mov ecx, eax
// 007572c6  e8d5cfffff           call 0x7542a0
// 007572cb  5e                   pop esi
// 007572cc  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetTreeTextColor@CXTPTreeBase@@MBEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
