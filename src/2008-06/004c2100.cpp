// from server: 100% by auto
// roc 2008-06 004c2100  unit: ProfiledRakPeer  size: 336 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c2100
//
// 004c2100  6aff                 push -1
// 004c2102  681b937c00           push 0x7c931b
// 004c2107  64a100000000         mov eax, dword ptr fs:[0]
// 004c210d  50                   push eax
// 004c210e  64892500000000       mov dword ptr fs:[0], esp
// 004c2115  81ec1c010000         sub esp, 0x11c
// 004c211b  53                   push ebx
// 004c211c  55                   push ebp
// 004c211d  56                   push esi
// 004c211e  57                   push edi
// 004c211f  8bf9                 mov edi, ecx
// 004c2121  6a0b                 push 0xb
// 004c2123  8d4c241c             lea ecx, [esp + 0x1c]
// 004c2127  e8942ffeff           call 0x4a50c0
// 004c212c  6a01                 push 1
// 004c212e  6a08                 push 8
// 004c2130  8d442418             lea eax, [esp + 0x18]
// 004c2134  50                   push eax
// 004c2135  8d4c2424             lea ecx, [esp + 0x24]
// 004c2139  c784244001000000000000 mov dword ptr [esp + 0x140], 0
// 004c2144  c644241c0d           mov byte ptr [esp + 0x1c], 0xd
// 004c2149  e8b234feff           call 0x4a5600
// 004c214e  8bb4243c010000       mov esi, dword ptr [esp + 0x13c]
// 004c2155  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c2158  6a01                 push 1
// 004c215a  6a20                 push 0x20
// 004c215c  8d54241c             lea edx, [esp + 0x1c]
// 004c2160  894c241c             mov dword ptr [esp + 0x1c], ecx
// 004c2164  52                   push edx
// 004c2165  8d4c2424             lea ecx, [esp + 0x24]
// 004c2169  e89234feff           call 0x4a5600
// 004c216e  0fb74608             movzx eax, word ptr [esi + 8]
// 004c2172  6a01                 push 1
// 004c2174  6a10                 push 0x10
// 004c2176  8d4c241c             lea ecx, [esp + 0x1c]
// 004c217a  51                   push ecx
// 004c217b  8d4c2424             lea ecx, [esp + 0x24]
// 004c217f  89442420             mov dword ptr [esp + 0x20], eax
// 004c2183  e87834feff           call 0x4a5600
// 004c2188  8b5608               mov edx, dword ptr [esi + 8]
// 004c218b  8b4604               mov eax, dword ptr [esi + 4]
// 004c218e  6a01                 push 1
// 004c2190  52                   push edx
// 004c2191  50                   push eax
// 004c2192  8bcf                 mov ecx, edi
// 004c2194  e897dbffff           call 0x4bfd30
// 004c2199  0fb7c8               movzx ecx, ax
// 004c219c  6a01                 push 1
// 004c219e  6a10                 push 0x10
// 004c21a0  8d54241c             lea edx, [esp + 0x1c]
// 004c21a4  894c241c             mov dword ptr [esp + 0x1c], ecx
// 004c21a8  52                   push edx
// 004c21a9  8d4c2424             lea ecx, [esp + 0x24]
// 004c21ad  e84e34feff           call 0x4a5600
// 004c21b2  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004c21b6  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 004c21ba  e8d1750000           call 0x4c9790
// 004c21bf  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c21c2  52                   push edx
// 004c21c3  50                   push eax
// 004c21c4  8b4608               mov eax, dword ptr [esi + 8]
// 004c21c7  6a00                 push 0
// 004c21c9  6a00                 push 0
// 004c21cb  50                   push eax
// 004c21cc  51                   push ecx
// 004c21cd  6a00                 push 0
// 004c21cf  6a02                 push 2
// 004c21d1  6a00                 push 0
// 004c21d3  53                   push ebx
// 004c21d4  55                   push ebp
// 004c21d5  8bcf                 mov ecx, edi
// 004c21d7  e844e2ffff           call 0x4c0420
// 004c21dc  8a842444010000       mov al, byte ptr [esp + 0x144]
// 004c21e3  888630080000         mov byte ptr [esi + 0x830], al
// 004c21e9  84c0                 test al, al
// 004c21eb  7434                 je 0x4c2221
// 004c21ed  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 004c21f4  8b10                 mov edx, dword ptr [eax]
// 004c21f6  899620080000         mov dword ptr [esi + 0x820], edx
// 004c21fc  8b4804               mov ecx, dword ptr [eax + 4]
// 004c21ff  898e24080000         mov dword ptr [esi + 0x824], ecx
// 004c2205  8b5008               mov edx, dword ptr [eax + 8]
// 004c2208  899628080000         mov dword ptr [esi + 0x828], edx
// 004c220e  8b400c               mov eax, dword ptr [eax + 0xc]
// 004c2211  89862c080000         mov dword ptr [esi + 0x82c], eax
// 004c2217  c7864808000007000000 mov dword ptr [esi + 0x848], 7
// 004c2221  8d4c2418             lea ecx, [esp + 0x18]
// 004c2225  c7842434010000ffffffff mov dword ptr [esp + 0x134], 0xffffffff
// 004c2230  e86b2ffeff           call 0x4a51a0
// 004c2235  8b8c242c010000       mov ecx, dword ptr [esp + 0x12c]
// 004c223c  5f                   pop edi
// 004c223d  5e                   pop esi
// 004c223e  5d                   pop ebp
// 004c223f  5b                   pop ebx
// 004c2240  64890d00000000       mov dword ptr fs:[0], ecx
// 004c2247  81c428010000         add esp, 0x128
// 004c224d  c20c00               ret 0xc
// library openrbx-raknet/RakPeer.cpp (function ?OnConnectionRequest@RakPeer@@IAEXPAURemoteSystemStruct@1@PAE_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
