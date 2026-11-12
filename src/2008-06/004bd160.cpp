// from server: 100% by auto
// roc 2008-06 004bd160  unit: ProfiledRakPeer  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bd160
//
// 004bd160  53                   push ebx
// 004bd161  56                   push esi
// 004bd162  8bf1                 mov esi, ecx
// 004bd164  8d9e84020000         lea ebx, [esi + 0x284]
// 004bd16a  57                   push edi
// 004bd16b  8bcb                 mov ecx, ebx
// 004bd16d  33ff                 xor edi, edi
// 004bd16f  e81c6e0100           call 0x4d3f90
// 004bd174  39bea0020000         cmp dword ptr [esi + 0x2a0], edi
// 004bd17a  7630                 jbe 0x4bd1ac
// 004bd17c  8d642400             lea esp, [esp]
// 004bd180  8b869c020000         mov eax, dword ptr [esi + 0x29c]
// 004bd186  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 004bd189  8b11                 mov edx, dword ptr [ecx]
// 004bd18b  52                   push edx
// 004bd18c  e8e9341e00           call 0x6a067a
// 004bd191  8b869c020000         mov eax, dword ptr [esi + 0x29c]
// 004bd197  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 004bd19a  51                   push ecx
// 004bd19b  e8da341e00           call 0x6a067a
// 004bd1a0  47                   inc edi
// 004bd1a1  83c408               add esp, 8
// 004bd1a4  3bbea0020000         cmp edi, dword ptr [esi + 0x2a0]
// 004bd1aa  72d4                 jb 0x4bd180
// 004bd1ac  8b86a4020000         mov eax, dword ptr [esi + 0x2a4]
// 004bd1b2  85c0                 test eax, eax
// 004bd1b4  7434                 je 0x4bd1ea
// 004bd1b6  3d00020000           cmp eax, 0x200
// 004bd1bb  7623                 jbe 0x4bd1e0
// 004bd1bd  8b969c020000         mov edx, dword ptr [esi + 0x29c]
// 004bd1c3  52                   push edx
// 004bd1c4  e8b1341e00           call 0x6a067a
// 004bd1c9  83c404               add esp, 4
// 004bd1cc  c786a402000000000000 mov dword ptr [esi + 0x2a4], 0
// 004bd1d6  c7869c02000000000000 mov dword ptr [esi + 0x29c], 0
// 004bd1e0  c786a002000000000000 mov dword ptr [esi + 0x2a0], 0
// 004bd1ea  5f                   pop edi
// 004bd1eb  5e                   pop esi
// 004bd1ec  8bcb                 mov ecx, ebx
// 004bd1ee  5b                   pop ebx
// 004bd1ef  e9ac6d0100           jmp 0x4d3fa0
// library openrbx-raknet/RakPeer.cpp (function ?ClearBanList@RakPeer@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
