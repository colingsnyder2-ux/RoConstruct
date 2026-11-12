// from server: 100% by auto
// roc 2008-06 004bb5d0  unit: RakPeerInterface  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bb5d0
//
// 004bb5d0  6aff                 push -1
// 004bb5d2  68db927c00           push 0x7c92db
// 004bb5d7  64a100000000         mov eax, dword ptr fs:[0]
// 004bb5dd  50                   push eax
// 004bb5de  64892500000000       mov dword ptr fs:[0], esp
// 004bb5e5  51                   push ecx
// 004bb5e6  56                   push esi
// 004bb5e7  8bf1                 mov esi, ecx
// 004bb5e9  8d4e18               lea ecx, [esi + 0x18]
// 004bb5ec  89742404             mov dword ptr [esp + 4], esi
// 004bb5f0  e8db6f0100           call 0x4d25d0
// 004bb5f5  8d8e38080000         lea ecx, [esi + 0x838]
// 004bb5fb  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004bb603  e888860100           call 0x4d3c90
// 004bb608  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004bb60c  8bc6                 mov eax, esi
// 004bb60e  5e                   pop esi
// 004bb60f  64890d00000000       mov dword ptr fs:[0], ecx
// 004bb616  83c410               add esp, 0x10
// 004bb619  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??0RemoteSystemStruct@RakPeer@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
