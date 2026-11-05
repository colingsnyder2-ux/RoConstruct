// from server: 100% by auto
// roc 2008-06 00621fe0  unit: lua_exception  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00621fe0
//
// 00621fe0  8b4628               mov eax, dword ptr [esi + 0x28]
// 00621fe3  894614               mov dword ptr [esi + 0x14], eax
// 00621fe6  8b00                 mov eax, dword ptr [eax]
// 00621fe8  50                   push eax
// 00621fe9  56                   push esi
// 00621fea  89460c               mov dword ptr [esi + 0xc], eax
// 00621fed  e80ed60300           call 0x65f600
// 00621ff2  8b460c               mov eax, dword ptr [esi + 0xc]
// 00621ff5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00621ff9  50                   push eax
// 00621ffa  51                   push ecx
// 00621ffb  56                   push esi
// 00621ffc  e8eff7ffff           call 0x6217f0
// 00622001  33d2                 xor edx, edx
// 00622003  83c414               add esp, 0x14
// 00622006  817e30204e0000       cmp dword ptr [esi + 0x30], 0x4e20
// 0062200d  66895634             mov word ptr [esi + 0x34], dx
// 00622011  c6463701             mov byte ptr [esi + 0x37], 1
// 00622015  7e2f                 jle 0x622046
// 00622017  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0062201a  2b4e28               sub ecx, dword ptr [esi + 0x28]
// 0062201d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00622022  f7e9                 imul ecx
// 00622024  c1fa02               sar edx, 2
// 00622027  8bc2                 mov eax, edx
// 00622029  c1e81f               shr eax, 0x1f
// 0062202c  8d4c0201             lea ecx, [edx + eax + 1]
// 00622030  81f9204e0000         cmp ecx, 0x4e20
// 00622036  7d0e                 jge 0x622046
// 00622038  68204e0000           push 0x4e20
// 0062203d  56                   push esi
// 0062203e  e88dfaffff           call 0x621ad0
// 00622043  83c408               add esp, 8
// 00622046  33c0                 xor eax, eax
// 00622048  894674               mov dword ptr [esi + 0x74], eax
// 0062204b  894670               mov dword ptr [esi + 0x70], eax
// 0062204e  c3                   ret 
// library lua-5.1.2/ldo.c (function _resetstack)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldo.c
