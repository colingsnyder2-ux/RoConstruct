// from server: 100% by auto
// roc 2008-06 004bb620  unit: RakPeerInterface  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bb620
//
// 004bb620  6aff                 push -1
// 004bb622  68db927c00           push 0x7c92db
// 004bb627  64a100000000         mov eax, dword ptr fs:[0]
// 004bb62d  50                   push eax
// 004bb62e  64892500000000       mov dword ptr fs:[0], esp
// 004bb635  51                   push ecx
// 004bb636  56                   push esi
// 004bb637  8bf1                 mov esi, ecx
// 004bb639  89742404             mov dword ptr [esp + 4], esi
// 004bb63d  8d8e38080000         lea ecx, [esi + 0x838]
// 004bb643  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004bb64b  e8d0880100           call 0x4d3f20
// 004bb650  8d4e18               lea ecx, [esi + 0x18]
// 004bb653  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004bb65b  e8e0840100           call 0x4d3b40
// 004bb660  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004bb664  5e                   pop esi
// 004bb665  64890d00000000       mov dword ptr fs:[0], ecx
// 004bb66c  83c410               add esp, 0x10
// 004bb66f  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??1RemoteSystemStruct@RakPeer@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
