// from server: 100% by auto
// roc 2008-06 004c0870  unit: ProfiledRakPeer  size: 437 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c0870
//
// 004c0870  81ec00010000         sub esp, 0x100
// 004c0876  33c0                 xor eax, eax
// 004c0878  53                   push ebx
// 004c0879  55                   push ebp
// 004c087a  56                   push esi
// 004c087b  8bb42410010000       mov esi, dword ptr [esp + 0x110]
// 004c0882  57                   push edi
// 004c0883  b908000000           mov ecx, 8
// 004c0888  8d7c2410             lea edi, [esp + 0x10]
// 004c088c  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c088e  8bb42418010000       mov esi, dword ptr [esp + 0x118]
// 004c0895  b908000000           mov ecx, 8
// 004c089a  8dbc2490000000       lea edi, [esp + 0x90]
// 004c08a1  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c08a3  8bb4241c010000       mov esi, dword ptr [esp + 0x11c]
// 004c08aa  b908000000           mov ecx, 8
// 004c08af  8d7c2450             lea edi, [esp + 0x50]
// 004c08b3  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c08b5  6a3c                 push 0x3c
// 004c08b7  50                   push eax
// 004c08b8  89442438             mov dword ptr [esp + 0x38], eax
// 004c08bc  8944243c             mov dword ptr [esp + 0x3c], eax
// 004c08c0  89442440             mov dword ptr [esp + 0x40], eax
// 004c08c4  89442444             mov dword ptr [esp + 0x44], eax
// 004c08c8  89442448             mov dword ptr [esp + 0x48], eax
// 004c08cc  8944244c             mov dword ptr [esp + 0x4c], eax
// 004c08d0  89442450             mov dword ptr [esp + 0x50], eax
// 004c08d4  89442454             mov dword ptr [esp + 0x54], eax
// 004c08d8  898424b8000000       mov dword ptr [esp + 0xb8], eax
// 004c08df  898424bc000000       mov dword ptr [esp + 0xbc], eax
// 004c08e6  898424c0000000       mov dword ptr [esp + 0xc0], eax
// 004c08ed  898424c4000000       mov dword ptr [esp + 0xc4], eax
// 004c08f4  898424c8000000       mov dword ptr [esp + 0xc8], eax
// 004c08fb  898424cc000000       mov dword ptr [esp + 0xcc], eax
// 004c0902  898424d0000000       mov dword ptr [esp + 0xd0], eax
// 004c0909  898424d4000000       mov dword ptr [esp + 0xd4], eax
// 004c0910  89442478             mov dword ptr [esp + 0x78], eax
// 004c0914  8944247c             mov dword ptr [esp + 0x7c], eax
// 004c0918  89842480000000       mov dword ptr [esp + 0x80], eax
// 004c091f  89842484000000       mov dword ptr [esp + 0x84], eax
// 004c0926  89842488000000       mov dword ptr [esp + 0x88], eax
// 004c092d  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 004c0934  89842490000000       mov dword ptr [esp + 0x90], eax
// 004c093b  89842494000000       mov dword ptr [esp + 0x94], eax
// 004c0942  8d8424dc000000       lea eax, [esp + 0xdc]
// 004c0949  50                   push eax
// 004c094a  c78424dc00000001000000 mov dword ptr [esp + 0xdc], 1
// 004c0955  e8aa0d1e00           call 0x6a1704
// 004c095a  8d4c241c             lea ecx, [esp + 0x1c]
// 004c095e  51                   push ecx
// 004c095f  8d542460             lea edx, [esp + 0x60]
// 004c0963  52                   push edx
// 004c0964  8bc1                 mov eax, ecx
// 004c0966  50                   push eax
// 004c0967  e814d6ffff           call 0x4bdf80
// 004c096c  83c418               add esp, 0x18
// 004c096f  33f6                 xor esi, esi
// 004c0971  33ed                 xor ebp, ebp
// 004c0973  eb0b                 jmp 0x4c0980
// 004c0975  8da42400000000       lea esp, [esp]
// 004c097c  8d642400             lea esp, [esp]
// 004c0980  8b9cac90000000       mov ebx, dword ptr [esp + ebp*4 + 0x90]
// 004c0987  bf20000000           mov edi, 0x20
// 004c098c  85db                 test ebx, ebx
// 004c098e  7469                 je 0x4c09f9
// 004c0990  f6c301               test bl, 1
// 004c0993  745c                 je 0x4c09f1
// 004c0995  85f6                 test esi, esi
// 004c0997  742b                 je 0x4c09c4
// 004c0999  8da42400000000       lea esp, [esp]
// 004c09a0  8d4c2410             lea ecx, [esp + 0x10]
// 004c09a4  51                   push ecx
// 004c09a5  e836dcffff           call 0x4be5e0
// 004c09aa  8d542414             lea edx, [esp + 0x14]
// 004c09ae  52                   push edx
// 004c09af  8d442458             lea eax, [esp + 0x58]
// 004c09b3  50                   push eax
// 004c09b4  8bca                 mov ecx, edx
// 004c09b6  51                   push ecx
// 004c09b7  e8c4d5ffff           call 0x4bdf80
// 004c09bc  83c410               add esp, 0x10
// 004c09bf  83ee01               sub esi, 1
// 004c09c2  75dc                 jne 0x4c09a0
// 004c09c4  8d9424d0000000       lea edx, [esp + 0xd0]
// 004c09cb  52                   push edx
// 004c09cc  8d442414             lea eax, [esp + 0x14]
// 004c09d0  50                   push eax
// 004c09d1  8bca                 mov ecx, edx
// 004c09d3  51                   push ecx
// 004c09d4  e817ddffff           call 0x4be6f0
// 004c09d9  8d9424dc000000       lea edx, [esp + 0xdc]
// 004c09e0  52                   push edx
// 004c09e1  8d442460             lea eax, [esp + 0x60]
// 004c09e5  50                   push eax
// 004c09e6  8bca                 mov ecx, edx
// 004c09e8  51                   push ecx
// 004c09e9  e892d5ffff           call 0x4bdf80
// 004c09ee  83c418               add esp, 0x18
// 004c09f1  d1eb                 shr ebx, 1
// 004c09f3  46                   inc esi
// 004c09f4  4f                   dec edi
// 004c09f5  85db                 test ebx, ebx
// 004c09f7  7597                 jne 0x4c0990
// 004c09f9  45                   inc ebp
// 004c09fa  03f7                 add esi, edi
// 004c09fc  83fd08               cmp ebp, 8
// 004c09ff  0f827bffffff         jb 0x4c0980
// 004c0a05  8bbc2420010000       mov edi, dword ptr [esp + 0x120]
// 004c0a0c  b908000000           mov ecx, 8
// 004c0a11  8db424d0000000       lea esi, [esp + 0xd0]
// 004c0a18  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c0a1a  5f                   pop edi
// 004c0a1b  5e                   pop esi
// 004c0a1c  5d                   pop ebp
// 004c0a1d  5b                   pop ebx
// 004c0a1e  81c400010000         add esp, 0x100
// 004c0a24  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$simpleModExp@$$BY07I@big@@YAXAAY07I000@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
