// from server: 100% by auto
// roc 2008-06 004c25e0  unit: ProfiledRakPeer  size: 317 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c25e0
//
// 004c25e0  6aff                 push -1
// 004c25e2  688b947c00           push 0x7c948b
// 004c25e7  64a100000000         mov eax, dword ptr fs:[0]
// 004c25ed  50                   push eax
// 004c25ee  64892500000000       mov dword ptr fs:[0], esp
// 004c25f5  81ecf0000000         sub esp, 0xf0
// 004c25fb  53                   push ebx
// 004c25fc  56                   push esi
// 004c25fd  8bd9                 mov ebx, ecx
// 004c25ff  57                   push edi
// 004c2600  8d4c2448             lea ecx, [esp + 0x48]
// 004c2604  e8a7320100           call 0x4d58b0
// 004c2609  c784240401000000000000 mov dword ptr [esp + 0x104], 0
// 004c2614  c644240c05           mov byte ptr [esp + 0xc], 5
// 004c2619  e8f2720000           call 0x4c9910
// 004c261e  3983a0080000         cmp dword ptr [ebx + 0x8a0], eax
// 004c2624  7307                 jae 0x4c262d
// 004c2626  8bcb                 mov ecx, ebx
// 004c2628  e86399ffff           call 0x4bbf90
// 004c262d  8d4c2448             lea ecx, [esp + 0x48]
// 004c2631  e8aa1c0100           call 0x4d42e0
// 004c2636  6a04                 push 4
// 004c2638  8d842410010000       lea eax, [esp + 0x110]
// 004c263f  50                   push eax
// 004c2640  8d4c2450             lea ecx, [esp + 0x50]
// 004c2644  e897300100           call 0x4d56e0
// 004c2649  6a02                 push 2
// 004c264b  8d8c2414010000       lea ecx, [esp + 0x114]
// 004c2652  51                   push ecx
// 004c2653  8d4c2450             lea ecx, [esp + 0x50]
// 004c2657  e884300100           call 0x4d56e0
// 004c265c  6a14                 push 0x14
// 004c265e  8d93a4080000         lea edx, [ebx + 0x8a4]
// 004c2664  52                   push edx
// 004c2665  8d4c2450             lea ecx, [esp + 0x50]
// 004c2669  e872300100           call 0x4d56e0
// 004c266e  8d4c2448             lea ecx, [esp + 0x48]
// 004c2672  e829310100           call 0x4d57a0
// 004c2677  8d4c2448             lea ecx, [esp + 0x48]
// 004c267b  e820320100           call 0x4d58a0
// 004c2680  8b08                 mov ecx, dword ptr [eax]
// 004c2682  894c240d             mov dword ptr [esp + 0xd], ecx
// 004c2686  8b5004               mov edx, dword ptr [eax + 4]
// 004c2689  89542411             mov dword ptr [esp + 0x11], edx
// 004c268d  8b4808               mov ecx, dword ptr [eax + 8]
// 004c2690  894c2415             mov dword ptr [esp + 0x15], ecx
// 004c2694  8b500c               mov edx, dword ptr [eax + 0xc]
// 004c2697  89542419             mov dword ptr [esp + 0x19], edx
// 004c269b  8b4010               mov eax, dword ptr [eax + 0x10]
// 004c269e  8944241d             mov dword ptr [esp + 0x1d], eax
// 004c26a2  8b8344070000         mov eax, dword ptr [ebx + 0x744]
// 004c26a8  89442421             mov dword ptr [esp + 0x21], eax
// 004c26ac  8db364070000         lea esi, [ebx + 0x764]
// 004c26b2  b908000000           mov ecx, 8
// 004c26b7  8d7c2425             lea edi, [esp + 0x25]
// 004c26bb  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c26bd  e8ce700000           call 0x4c9790
// 004c26c2  8b8c2410010000       mov ecx, dword ptr [esp + 0x110]
// 004c26c9  52                   push edx
// 004c26ca  8b942410010000       mov edx, dword ptr [esp + 0x110]
// 004c26d1  50                   push eax
// 004c26d2  6a00                 push 0
// 004c26d4  6a00                 push 0
// 004c26d6  51                   push ecx
// 004c26d7  52                   push edx
// 004c26d8  6a00                 push 0
// 004c26da  6a00                 push 0
// 004c26dc  6a00                 push 0
// 004c26de  68c8010000           push 0x1c8
// 004c26e3  8d442434             lea eax, [esp + 0x34]
// 004c26e7  50                   push eax
// 004c26e8  8bcb                 mov ecx, ebx
// 004c26ea  e831ddffff           call 0x4c0420
// 004c26ef  8d4c2448             lea ecx, [esp + 0x48]
// 004c26f3  c7842404010000ffffffff mov dword ptr [esp + 0x104], 0xffffffff
// 004c26fe  e8ed310100           call 0x4d58f0
// 004c2703  8b8c24fc000000       mov ecx, dword ptr [esp + 0xfc]
// 004c270a  5f                   pop edi
// 004c270b  5e                   pop esi
// 004c270c  5b                   pop ebx
// 004c270d  64890d00000000       mov dword ptr fs:[0], ecx
// 004c2714  81c4fc000000         add esp, 0xfc
// 004c271a  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?SecuredConnectionResponse@RakPeer@@IAEXUSystemAddress@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
