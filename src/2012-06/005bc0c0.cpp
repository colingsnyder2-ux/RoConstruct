// roc 2012-06 005bc0c0  unit: RakNet::RakPeer  size: 604 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bc0c0
//
// 005bc0c0  55                   push ebp
// 005bc0c1  8bec                 mov ebp, esp
// 005bc0c3  83ec0c               sub esp, 0xc
// 005bc0c6  53                   push ebx
// 005bc0c7  56                   push esi
// 005bc0c8  57                   push edi
// 005bc0c9  8bf9                 mov edi, ecx
// 005bc0cb  684c69e200           push 0xe2694c
// 005bc0d0  8d4d2c               lea ecx, [ebp + 0x2c]
// 005bc0d3  c645ff00             mov byte ptr [ebp - 1], 0
// 005bc0d7  c745f800000000       mov dword ptr [ebp - 8], 0
// 005bc0de  e8ed57faff           call 0x5618d0
// 005bc0e3  84c0                 test al, al
// 005bc0e5  7432                 je 0x5bc119
// 005bc0e7  8b4d2c               mov ecx, dword ptr [ebp + 0x2c]
// 005bc0ea  8b5530               mov edx, dword ptr [ebp + 0x30]
// 005bc0ed  6a01                 push 1
// 005bc0ef  83ec14               sub esp, 0x14
// 005bc0f2  8bc4                 mov eax, esp
// 005bc0f4  8908                 mov dword ptr [eax], ecx
// 005bc0f6  8b4d34               mov ecx, dword ptr [ebp + 0x34]
// 005bc0f9  895004               mov dword ptr [eax + 4], edx
// 005bc0fc  8b5538               mov edx, dword ptr [ebp + 0x38]
// 005bc0ff  894808               mov dword ptr [eax + 8], ecx
// 005bc102  8b4d3c               mov ecx, dword ptr [ebp + 0x3c]
// 005bc105  89500c               mov dword ptr [eax + 0xc], edx
// 005bc108  894810               mov dword ptr [eax + 0x10], ecx
// 005bc10b  8bcf                 mov ecx, edi
// 005bc10d  e8cefcffff           call 0x5bbde0
// 005bc112  8bf0                 mov esi, eax
// 005bc114  8975f4               mov dword ptr [ebp - 0xc], esi
// 005bc117  eb45                 jmp 0x5bc15e
// 005bc119  68f815d900           push 0xd915f8
// 005bc11e  8d4d1c               lea ecx, [ebp + 0x1c]
// 005bc121  e80a5cfaff           call 0x561d30
// 005bc126  84c0                 test al, al
// 005bc128  742a                 je 0x5bc154
// 005bc12a  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005bc12d  8b4d20               mov ecx, dword ptr [ebp + 0x20]
// 005bc130  83ec10               sub esp, 0x10
// 005bc133  8bc4                 mov eax, esp
// 005bc135  8910                 mov dword ptr [eax], edx
// 005bc137  8b5524               mov edx, dword ptr [ebp + 0x24]
// 005bc13a  894804               mov dword ptr [eax + 4], ecx
// 005bc13d  8b4d28               mov ecx, dword ptr [ebp + 0x28]
// 005bc140  895008               mov dword ptr [eax + 8], edx
// 005bc143  89480c               mov dword ptr [eax + 0xc], ecx
// 005bc146  8bcf                 mov ecx, edi
// 005bc148  e833ebffff           call 0x5bac80
// 005bc14d  8945f4               mov dword ptr [ebp - 0xc], eax
// 005bc150  8bf0                 mov esi, eax
// 005bc152  eb0a                 jmp 0x5bc15e
// 005bc154  c745f4ffffffff       mov dword ptr [ebp - 0xc], 0xffffffff
// 005bc15b  8b75f4               mov esi, dword ptr [ebp - 0xc]
// 005bc15e  807d4400             cmp byte ptr [ebp + 0x44], 0
// 005bc162  7557                 jne 0x5bc1bb
// 005bc164  83feff               cmp esi, -1
// 005bc167  750e                 jne 0x5bc177
// 005bc169  32c0                 xor al, al
// 005bc16b  8d65e8               lea esp, [ebp - 0x18]
// 005bc16e  5f                   pop edi
// 005bc16f  5e                   pop esi
// 005bc170  5b                   pop ebx
// 005bc171  8be5                 mov esp, ebp
// 005bc173  5d                   pop ebp
// 005bc174  c25000               ret 0x50
// 005bc177  b804000000           mov eax, 4
// 005bc17c  e85f713c00           call 0x9832e0
// 005bc181  8b872c020000         mov eax, dword ptr [edi + 0x22c]
// 005bc187  8bd6                 mov edx, esi
// 005bc189  69d208120000         imul edx, edx, 0x1208
// 005bc18f  03c2                 add eax, edx
// 005bc191  803800               cmp byte ptr [eax], 0
// 005bc194  8bcc                 mov ecx, esp
// 005bc196  894d44               mov dword ptr [ebp + 0x44], ecx
// 005bc199  74ce                 je 0x5bc169
// 005bc19b  8b8000120000         mov eax, dword ptr [eax + 0x1200]
// 005bc1a1  83f801               cmp eax, 1
// 005bc1a4  74c3                 je 0x5bc169
// 005bc1a6  83f802               cmp eax, 2
// 005bc1a9  74be                 je 0x5bc169
// 005bc1ab  83f803               cmp eax, 3
// 005bc1ae  74b9                 je 0x5bc169
// 005bc1b0  8931                 mov dword ptr [ecx], esi
// 005bc1b2  c745f801000000       mov dword ptr [ebp - 8], 1
// 005bc1b9  eb6d                 jmp 0x5bc228
// 005bc1bb  0fb75f0e             movzx ebx, word ptr [edi + 0xe]
// 005bc1bf  8d049d00000000       lea eax, [ebx*4]
// 005bc1c6  e845713c00           call 0x983310
// 005bc1cb  33f6                 xor esi, esi
// 005bc1cd  896544               mov dword ptr [ebp + 0x44], esp
// 005bc1d0  85db                 test ebx, ebx
// 005bc1d2  7695                 jbe 0x5bc169
// 005bc1d4  33db                 xor ebx, ebx
// 005bc1d6  8b45f4               mov eax, dword ptr [ebp - 0xc]
// 005bc1d9  83f8ff               cmp eax, -1
// 005bc1dc  7404                 je 0x5bc1e2
// 005bc1de  3bf0                 cmp esi, eax
// 005bc1e0  742d                 je 0x5bc20f
// 005bc1e2  8b8f2c020000         mov ecx, dword ptr [edi + 0x22c]
// 005bc1e8  803c1900             cmp byte ptr [ecx + ebx], 0
// 005bc1ec  8d0419               lea eax, [ecx + ebx]
// 005bc1ef  741e                 je 0x5bc20f
// 005bc1f1  684c69e200           push 0xe2694c
// 005bc1f6  8d4804               lea ecx, [eax + 4]
// 005bc1f9  e8d256faff           call 0x5618d0
// 005bc1fe  84c0                 test al, al
// 005bc200  740d                 je 0x5bc20f
// 005bc202  8b45f8               mov eax, dword ptr [ebp - 8]
// 005bc205  8b5544               mov edx, dword ptr [ebp + 0x44]
// 005bc208  893482               mov dword ptr [edx + eax*4], esi
// 005bc20b  40                   inc eax
// 005bc20c  8945f8               mov dword ptr [ebp - 8], eax
// 005bc20f  0fb7470e             movzx eax, word ptr [edi + 0xe]
// 005bc213  46                   inc esi
// 005bc214  81c308120000         add ebx, 0x1208
// 005bc21a  3bf0                 cmp esi, eax
// 005bc21c  72b8                 jb 0x5bc1d6
// 005bc21e  837df800             cmp dword ptr [ebp - 8], 0
// 005bc222  0f8441ffffff         je 0x5bc169
// 005bc228  33c0                 xor eax, eax
// 005bc22a  8945f4               mov dword ptr [ebp - 0xc], eax
// 005bc22d  3945f8               cmp dword ptr [ebp - 8], eax
// 005bc230  0f86d7000000         jbe 0x5bc30d
// 005bc236  eb0b                 jmp 0x5bc243
// 005bc238  eb06                 jmp 0x5bc240
// 005bc23a  8d9b00000000         lea ebx, [ebx]
// 005bc240  8b45f4               mov eax, dword ptr [ebp - 0xc]
// 005bc243  807d4800             cmp byte ptr [ebp + 0x48], 0
// 005bc247  7412                 je 0x5bc25b
// 005bc249  807dff00             cmp byte ptr [ebp - 1], 0
// 005bc24d  750c                 jne 0x5bc25b
// 005bc24f  8d4801               lea ecx, [eax + 1]
// 005bc252  3b4df8               cmp ecx, dword ptr [ebp - 8]
// 005bc255  7504                 jne 0x5bc25b
// 005bc257  b301                 mov bl, 1
// 005bc259  eb02                 jmp 0x5bc25d
// 005bc25b  32db                 xor bl, bl
// 005bc25d  8b5544               mov edx, dword ptr [ebp + 0x44]
// 005bc260  8b3482               mov esi, dword ptr [edx + eax*4]
// 005bc263  8b4d54               mov ecx, dword ptr [ebp + 0x54]
// 005bc266  69f608120000         imul esi, esi, 0x1208
// 005bc26c  8b872c020000         mov eax, dword ptr [edi + 0x22c]
// 005bc272  8b5550               mov edx, dword ptr [ebp + 0x50]
// 005bc275  51                   push ecx
// 005bc276  8b4d4c               mov ecx, dword ptr [ebp + 0x4c]
// 005bc279  52                   push edx
// 005bc27a  8b9430f0110000       mov edx, dword ptr [eax + esi + 0x11f0]
// 005bc281  51                   push ecx
// 005bc282  52                   push edx
// 005bc283  03c6                 add eax, esi
// 005bc285  84db                 test bl, bl
// 005bc287  0f94c1               sete cl
// 005bc28a  0fb6d1               movzx edx, cl
// 005bc28d  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 005bc290  52                   push edx
// 005bc291  8b5514               mov edx, dword ptr [ebp + 0x14]
// 005bc294  51                   push ecx
// 005bc295  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 005bc298  52                   push edx
// 005bc299  8b550c               mov edx, dword ptr [ebp + 0xc]
// 005bc29c  51                   push ecx
// 005bc29d  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005bc2a0  52                   push edx
// 005bc2a1  51                   push ecx
// 005bc2a2  8d88f8000000         lea ecx, [eax + 0xf8]
// 005bc2a8  e8e319feff           call 0x59dc90
// 005bc2ad  84db                 test bl, bl
// 005bc2af  7404                 je 0x5bc2b5
// 005bc2b1  c645ff01             mov byte ptr [ebp - 1], 1
// 005bc2b5  8b4514               mov eax, dword ptr [ebp + 0x14]
// 005bc2b8  83f802               cmp eax, 2
// 005bc2bb  7414                 je 0x5bc2d1
// 005bc2bd  83f803               cmp eax, 3
// 005bc2c0  740f                 je 0x5bc2d1
// 005bc2c2  83f804               cmp eax, 4
// 005bc2c5  740a                 je 0x5bc2d1
// 005bc2c7  83f806               cmp eax, 6
// 005bc2ca  7405                 je 0x5bc2d1
// 005bc2cc  83f807               cmp eax, 7
// 005bc2cf  752c                 jne 0x5bc2fd
// 005bc2d1  8b5550               mov edx, dword ptr [ebp + 0x50]
// 005bc2d4  8b454c               mov eax, dword ptr [ebp + 0x4c]
// 005bc2d7  6a00                 push 0
// 005bc2d9  68e8030000           push 0x3e8
// 005bc2de  52                   push edx
// 005bc2df  50                   push eax
// 005bc2e0  e8fb703c00           call 0x9833e0
// 005bc2e5  8b8f2c020000         mov ecx, dword ptr [edi + 0x22c]
// 005bc2eb  89840ed0110000       mov dword ptr [esi + ecx + 0x11d0], eax
// 005bc2f2  c7840ed411000000000000 mov dword ptr [esi + ecx + 0x11d4], 0
// 005bc2fd  8b45f4               mov eax, dword ptr [ebp - 0xc]
// 005bc300  40                   inc eax
// 005bc301  8945f4               mov dword ptr [ebp - 0xc], eax
// 005bc304  3b45f8               cmp eax, dword ptr [ebp - 8]
// 005bc307  0f8233ffffff         jb 0x5bc240
// 005bc30d  8a45ff               mov al, byte ptr [ebp - 1]
// 005bc310  8d65e8               lea esp, [ebp - 0x18]
// 005bc313  5f                   pop edi
// 005bc314  5e                   pop esi
// 005bc315  5b                   pop ebx
// 005bc316  8be5                 mov esp, ebp
// 005bc318  5d                   pop ebp
// 005bc319  c25000               ret 0x50
// copied from an identical function in another client (function ?SendImmediate@RakPeer@RakNet@@IAE_NPADIW4PacketPriority@@W4PacketReliability@@DUAddressOrGUID@2@_N4_KI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp