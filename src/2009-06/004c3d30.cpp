// from server: 100% by auto
// roc 2009-06 004c3d30  unit: RBX::Network::VPlayer::?$EventDesc  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c3d30
//
// 004c3d30  6aff                 push -1
// 004c3d32  686b9a8500           push 0x859a6b
// 004c3d37  64a100000000         mov eax, dword ptr fs:[0]
// 004c3d3d  50                   push eax
// 004c3d3e  64892500000000       mov dword ptr fs:[0], esp
// 004c3d45  83ec14               sub esp, 0x14
// 004c3d48  56                   push esi
// 004c3d49  8bf1                 mov esi, ecx
// 004c3d4b  57                   push edi
// 004c3d4c  33ff                 xor edi, edi
// 004c3d4e  c706244f8c00         mov dword ptr [esi], 0x8c4f24
// 004c3d54  897e04               mov dword ptr [esi + 4], edi
// 004c3d57  89742408             mov dword ptr [esp + 8], esi
// 004c3d5b  c74608ffffffff       mov dword ptr [esi + 8], 0xffffffff
// 004c3d62  57                   push edi
// 004c3d63  57                   push edi
// 004c3d64  6a01                 push 1
// 004c3d66  57                   push edi
// 004c3d67  897c2434             mov dword ptr [esp + 0x34], edi
// 004c3d6b  ff1504e28900         call dword ptr [0x89e204]
// 004c3d71  3bc7                 cmp eax, edi
// 004c3d73  7518                 jne 0x4c3d8d
// 004c3d75  8d4c240c             lea ecx, [esp + 0xc]
// 004c3d79  e872182400           call 0x7055f0
// 004c3d7e  68e8af9700           push 0x97afe8
// 004c3d83  8d442410             lea eax, [esp + 0x10]
// 004c3d87  50                   push eax
// 004c3d88  e8bd5c2500           call 0x719a4a
// 004c3d8d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004c3d91  89460c               mov dword ptr [esi + 0xc], eax
// 004c3d94  897e10               mov dword ptr [esi + 0x10], edi
// 004c3d97  897e14               mov dword ptr [esi + 0x14], edi
// 004c3d9a  897e1c               mov dword ptr [esi + 0x1c], edi
// 004c3d9d  c6461801             mov byte ptr [esi + 0x18], 1
// 004c3da1  5f                   pop edi
// 004c3da2  8bc6                 mov eax, esi
// 004c3da4  5e                   pop esi
// 004c3da5  64890d00000000       mov dword ptr fs:[0], ecx
// 004c3dac  83c420               add esp, 0x20
// 004c3daf  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0thread_data_base@detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
