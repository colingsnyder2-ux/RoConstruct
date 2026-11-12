// from server: 100% by auto
// roc 2008-06 004bbcb0  unit: ProfiledRakPeer  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bbcb0
//
// 004bbcb0  64a100000000         mov eax, dword ptr fs:[0]
// 004bbcb6  6aff                 push -1
// 004bbcb8  6806937c00           push 0x7c9306
// 004bbcbd  50                   push eax
// 004bbcbe  64892500000000       mov dword ptr fs:[0], esp
// 004bbcc5  53                   push ebx
// 004bbcc6  56                   push esi
// 004bbcc7  8bf1                 mov esi, ecx
// 004bbcc9  8b06                 mov eax, dword ptr [esi]
// 004bbccb  8b502c               mov edx, dword ptr [eax + 0x2c]
// 004bbcce  ffd2                 call edx
// 004bbcd0  84c0                 test al, al
// 004bbcd2  7415                 je 0x4bbce9
// 004bbcd4  32c0                 xor al, al
// 004bbcd6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004bbcda  64890d00000000       mov dword ptr fs:[0], ecx
// 004bbce1  5e                   pop esi
// 004bbce2  5b                   pop ebx
// 004bbce3  83c40c               add esp, 0xc
// 004bbce6  c20800               ret 8
// 004bbce9  8b06                 mov eax, dword ptr [esi]
// 004bbceb  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004bbcef  8b90dc000000         mov edx, dword ptr [eax + 0xdc]
// 004bbcf5  53                   push ebx
// 004bbcf6  8bce                 mov ecx, esi
// 004bbcf8  ffd2                 call edx
// 004bbcfa  6804080000           push 0x804
// 004bbcff  e81c4c1e00           call 0x6a0920
// 004bbd04  83c404               add esp, 4
// 004bbd07  8944241c             mov dword ptr [esp + 0x1c], eax
// 004bbd0b  84db                 test bl, bl
// 004bbd0d  742f                 je 0x4bbd3e
// 004bbd0f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004bbd17  85c0                 test eax, eax
// 004bbd19  7414                 je 0x4bbd2f
// 004bbd1b  8bc8                 mov ecx, eax
// 004bbd1d  e8ee4a0300           call 0x4f0810
// 004bbd22  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004bbd26  8986cc060000         mov dword ptr [esi + 0x6cc], eax
// 004bbd2c  51                   push ecx
// 004bbd2d  eb31                 jmp 0x4bbd60
// 004bbd2f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004bbd33  33c0                 xor eax, eax
// 004bbd35  8986cc060000         mov dword ptr [esi + 0x6cc], eax
// 004bbd3b  51                   push ecx
// 004bbd3c  eb22                 jmp 0x4bbd60
// 004bbd3e  c744241001000000     mov dword ptr [esp + 0x10], 1
// 004bbd46  85c0                 test eax, eax
// 004bbd48  7409                 je 0x4bbd53
// 004bbd4a  8bc8                 mov ecx, eax
// 004bbd4c  e8bf4a0300           call 0x4f0810
// 004bbd51  eb02                 jmp 0x4bbd55
// 004bbd53  33c0                 xor eax, eax
// 004bbd55  8b542418             mov edx, dword ptr [esp + 0x18]
// 004bbd59  8986d0060000         mov dword ptr [esi + 0x6d0], eax
// 004bbd5f  52                   push edx
// 004bbd60  8bc8                 mov ecx, eax
// 004bbd62  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004bbd6a  e871250100           call 0x4ce2e0
// 004bbd6f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004bbd73  5e                   pop esi
// 004bbd74  b001                 mov al, 1
// 004bbd76  64890d00000000       mov dword ptr fs:[0], ecx
// 004bbd7d  5b                   pop ebx
// 004bbd7e  83c40c               add esp, 0xc
// 004bbd81  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?GenerateCompressionLayer@RakPeer@@UAE_NQAI_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
