// from server: 100% by auto
// roc 2008-06 004bbb30  unit: ProfiledRakPeer  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bbb30
//
// 004bbb30  56                   push esi
// 004bbb31  8b742408             mov esi, dword ptr [esp + 8]
// 004bbb35  83fe0a               cmp esi, 0xa
// 004bbb38  7205                 jb 0x4bbb3f
// 004bbb3a  be09000000           mov esi, 9
// 004bbb3f  68a0000000           push 0xa0
// 004bbb44  6a00                 push 0
// 004bbb46  6818189700           push 0x971818
// 004bbb4b  e8b45b1e00           call 0x6a1704
// 004bbb50  83c40c               add esp, 0xc
// 004bbb53  6818189700           push 0x971818
// 004bbb58  b9311d9700           mov ecx, 0x971d31
// 004bbb5d  e85e2d0100           call 0x4ce8c0
// 004bbb62  8bc6                 mov eax, esi
// 004bbb64  c1e004               shl eax, 4
// 004bbb67  0518189700           add eax, 0x971818
// 004bbb6c  5e                   pop esi
// 004bbb6d  c20400               ret 4
// library openrbx-raknet/RakPeer.cpp (function ?GetLocalIP@RakPeer@@UAEPBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
