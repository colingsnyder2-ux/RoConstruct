// from server: 100% by auto
// roc 2008-06 004c2720  unit: ProfiledRakPeer  size: 281 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c2720
//
// 004c2720  64a100000000         mov eax, dword ptr fs:[0]
// 004c2726  6aff                 push -1
// 004c2728  681b937c00           push 0x7c931b
// 004c272d  50                   push eax
// 004c272e  64892500000000       mov dword ptr fs:[0], esp
// 004c2735  81ec1c010000         sub esp, 0x11c
// 004c273b  56                   push esi
// 004c273c  8bf1                 mov esi, ecx
// 004c273e  8b06                 mov eax, dword ptr [esi]
// 004c2740  8b502c               mov edx, dword ptr [eax + 0x2c]
// 004c2743  ffd2                 call edx
// 004c2745  84c0                 test al, al
// 004c2747  0f84d4000000         je 0x4c2821
// 004c274d  55                   push ebp
// 004c274e  57                   push edi
// 004c274f  6a05                 push 5
// 004c2751  8d4c2418             lea ecx, [esp + 0x18]
// 004c2755  e86629feff           call 0x4a50c0
// 004c275a  6a01                 push 1
// 004c275c  6a08                 push 8
// 004c275e  8d442414             lea eax, [esp + 0x14]
// 004c2762  50                   push eax
// 004c2763  8d4c2420             lea ecx, [esp + 0x20]
// 004c2767  c784243c01000000000000 mov dword ptr [esp + 0x13c], 0
// 004c2772  c644241800           mov byte ptr [esp + 0x18], 0
// 004c2777  e8842efeff           call 0x4a5600
// 004c277c  e80f700000           call 0x4c9790
// 004c2781  8bf8                 mov edi, eax
// 004c2783  8bea                 mov ebp, edx
// 004c2785  e886710000           call 0x4c9910
// 004c278a  6a01                 push 1
// 004c278c  6a20                 push 0x20
// 004c278e  8d4c2418             lea ecx, [esp + 0x18]
// 004c2792  51                   push ecx
// 004c2793  8d4c2420             lea ecx, [esp + 0x20]
// 004c2797  8944241c             mov dword ptr [esp + 0x1c], eax
// 004c279b  e8602efeff           call 0x4a5600
// 004c27a0  80bc244001000000     cmp byte ptr [esp + 0x140], 0
// 004c27a8  7435                 je 0x4c27df
// 004c27aa  8b94243c010000       mov edx, dword ptr [esp + 0x13c]
// 004c27b1  8b842438010000       mov eax, dword ptr [esp + 0x138]
// 004c27b8  8b8c2444010000       mov ecx, dword ptr [esp + 0x144]
// 004c27bf  55                   push ebp
// 004c27c0  57                   push edi
// 004c27c1  6a00                 push 0
// 004c27c3  6a00                 push 0
// 004c27c5  52                   push edx
// 004c27c6  8b542428             mov edx, dword ptr [esp + 0x28]
// 004c27ca  50                   push eax
// 004c27cb  8b442438             mov eax, dword ptr [esp + 0x38]
// 004c27cf  6a00                 push 0
// 004c27d1  51                   push ecx
// 004c27d2  6a00                 push 0
// 004c27d4  52                   push edx
// 004c27d5  50                   push eax
// 004c27d6  8bce                 mov ecx, esi
// 004c27d8  e843dcffff           call 0x4c0420
// 004c27dd  eb2c                 jmp 0x4c280b
// 004c27df  8b84243c010000       mov eax, dword ptr [esp + 0x13c]
// 004c27e6  8b8c2438010000       mov ecx, dword ptr [esp + 0x138]
// 004c27ed  8b16                 mov edx, dword ptr [esi]
// 004c27ef  8b5234               mov edx, dword ptr [edx + 0x34]
// 004c27f2  6a00                 push 0
// 004c27f4  50                   push eax
// 004c27f5  8b84244c010000       mov eax, dword ptr [esp + 0x14c]
// 004c27fc  51                   push ecx
// 004c27fd  6a00                 push 0
// 004c27ff  50                   push eax
// 004c2800  6a00                 push 0
// 004c2802  8d4c242c             lea ecx, [esp + 0x2c]
// 004c2806  51                   push ecx
// 004c2807  8bce                 mov ecx, esi
// 004c2809  ffd2                 call edx
// 004c280b  8d4c2414             lea ecx, [esp + 0x14]
// 004c280f  c7842430010000ffffffff mov dword ptr [esp + 0x130], 0xffffffff
// 004c281a  e88129feff           call 0x4a51a0
// 004c281f  5f                   pop edi
// 004c2820  5d                   pop ebp
// 004c2821  8b8c2420010000       mov ecx, dword ptr [esp + 0x120]
// 004c2828  5e                   pop esi
// 004c2829  64890d00000000       mov dword ptr fs:[0], ecx
// 004c2830  81c428010000         add esp, 0x128
// 004c2836  c21000               ret 0x10
// library openrbx-raknet/RakPeer.cpp (function ?PingInternal@RakPeer@@IAEXUSystemAddress@@_NW4PacketReliability@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
