// from server: 100% by auto
// roc 2008-06 004cdd20  unit: RBX::Network::PhysicsSender  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cdd20
//
// 004cdd20  64a100000000         mov eax, dword ptr fs:[0]
// 004cdd26  6aff                 push -1
// 004cdd28  681b937c00           push 0x7c931b
// 004cdd2d  50                   push eax
// 004cdd2e  64892500000000       mov dword ptr fs:[0], esp
// 004cdd35  81ec14010000         sub esp, 0x114
// 004cdd3b  53                   push ebx
// 004cdd3c  57                   push edi
// 004cdd3d  8bbc2430010000       mov edi, dword ptr [esp + 0x130]
// 004cdd44  8bd9                 mov ebx, ecx
// 004cdd46  85ff                 test edi, edi
// 004cdd48  0f867e000000         jbe 0x4cddcc
// 004cdd4e  8b8c242c010000       mov ecx, dword ptr [esp + 0x12c]
// 004cdd55  56                   push esi
// 004cdd56  6a00                 push 0
// 004cdd58  8d4707               lea eax, [edi + 7]
// 004cdd5b  c1e803               shr eax, 3
// 004cdd5e  50                   push eax
// 004cdd5f  51                   push ecx
// 004cdd60  8d4c2418             lea ecx, [esp + 0x18]
// 004cdd64  e8b773fdff           call 0x4a5120
// 004cdd69  8b33                 mov esi, dword ptr [ebx]
// 004cdd6b  c784242801000000000000 mov dword ptr [esp + 0x128], 0
// 004cdd76  85ff                 test edi, edi
// 004cdd78  763d                 jbe 0x4cddb7
// 004cdd7a  55                   push ebp
// 004cdd7b  8bac243c010000       mov ebp, dword ptr [esp + 0x13c]
// 004cdd82  8d4c2410             lea ecx, [esp + 0x10]
// 004cdd86  e85574fdff           call 0x4a51e0
// 004cdd8b  84c0                 test al, al
// 004cdd8d  7505                 jne 0x4cdd94
// 004cdd8f  8b7608               mov esi, dword ptr [esi + 8]
// 004cdd92  eb03                 jmp 0x4cdd97
// 004cdd94  8b760c               mov esi, dword ptr [esi + 0xc]
// 004cdd97  837e0800             cmp dword ptr [esi + 8], 0
// 004cdd9b  7514                 jne 0x4cddb1
// 004cdd9d  837e0c00             cmp dword ptr [esi + 0xc], 0
// 004cdda1  750e                 jne 0x4cddb1
// 004cdda3  6a01                 push 1
// 004cdda5  6a08                 push 8
// 004cdda7  56                   push esi
// 004cdda8  8bcd                 mov ecx, ebp
// 004cddaa  e85178fdff           call 0x4a5600
// 004cddaf  8b33                 mov esi, dword ptr [ebx]
// 004cddb1  83ef01               sub edi, 1
// 004cddb4  75cc                 jne 0x4cdd82
// 004cddb6  5d                   pop ebp
// 004cddb7  8d4c240c             lea ecx, [esp + 0xc]
// 004cddbb  c7842428010000ffffffff mov dword ptr [esp + 0x128], 0xffffffff
// 004cddc6  e8d573fdff           call 0x4a51a0
// 004cddcb  5e                   pop esi
// 004cddcc  8b8c241c010000       mov ecx, dword ptr [esp + 0x11c]
// 004cddd3  5f                   pop edi
// 004cddd4  5b                   pop ebx
// 004cddd5  64890d00000000       mov dword ptr fs:[0], ecx
// 004cdddc  81c420010000         add esp, 0x120
// 004cdde2  c20c00               ret 0xc
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?DecodeArray@HuffmanEncodingTree@@QAEXPAEIPAVBitStream@RakNet@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
