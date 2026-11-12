// from server: 100% by auto
// roc 2008-06 004c2250  unit: ProfiledRakPeer  size: 277 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c2250
//
// 004c2250  6aff                 push -1
// 004c2252  681b937c00           push 0x7c931b
// 004c2257  64a100000000         mov eax, dword ptr fs:[0]
// 004c225d  50                   push eax
// 004c225e  64892500000000       mov dword ptr fs:[0], esp
// 004c2265  81ec18010000         sub esp, 0x118
// 004c226b  56                   push esi
// 004c226c  8bf1                 mov esi, ecx
// 004c226e  6a01                 push 1
// 004c2270  8d4c240c             lea ecx, [esp + 0xc]
// 004c2274  e8472efeff           call 0x4a50c0
// 004c2279  6a01                 push 1
// 004c227b  6a08                 push 8
// 004c227d  8d44240c             lea eax, [esp + 0xc]
// 004c2281  50                   push eax
// 004c2282  8d4c2414             lea ecx, [esp + 0x14]
// 004c2286  c784243001000000000000 mov dword ptr [esp + 0x130], 0
// 004c2291  c644241012           mov byte ptr [esp + 0x10], 0x12
// 004c2296  e86533feff           call 0x4a5600
// 004c229b  80bc243401000000     cmp byte ptr [esp + 0x134], 0
// 004c22a3  7463                 je 0x4c2308
// 004c22a5  53                   push ebx
// 004c22a6  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004c22aa  57                   push edi
// 004c22ab  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004c22af  e8dc740000           call 0x4c9790
// 004c22b4  8b8c2438010000       mov ecx, dword ptr [esp + 0x138]
// 004c22bb  52                   push edx
// 004c22bc  8b942438010000       mov edx, dword ptr [esp + 0x138]
// 004c22c3  50                   push eax
// 004c22c4  8b842448010000       mov eax, dword ptr [esp + 0x148]
// 004c22cb  6a00                 push 0
// 004c22cd  6a00                 push 0
// 004c22cf  51                   push ecx
// 004c22d0  52                   push edx
// 004c22d1  50                   push eax
// 004c22d2  6a03                 push 3
// 004c22d4  6a03                 push 3
// 004c22d6  57                   push edi
// 004c22d7  53                   push ebx
// 004c22d8  8bce                 mov ecx, esi
// 004c22da  e841e1ffff           call 0x4c0420
// 004c22df  8b8c2438010000       mov ecx, dword ptr [esp + 0x138]
// 004c22e6  8b942434010000       mov edx, dword ptr [esp + 0x134]
// 004c22ed  6a01                 push 1
// 004c22ef  6a01                 push 1
// 004c22f1  51                   push ecx
// 004c22f2  52                   push edx
// 004c22f3  8bce                 mov ecx, esi
// 004c22f5  e8e6daffff           call 0x4bfde0
// 004c22fa  5f                   pop edi
// 004c22fb  c7804808000001000000 mov dword ptr [eax + 0x848], 1
// 004c2305  5b                   pop ebx
// 004c2306  eb31                 jmp 0x4c2339
// 004c2308  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 004c230f  8b8c242c010000       mov ecx, dword ptr [esp + 0x12c]
// 004c2316  8b942438010000       mov edx, dword ptr [esp + 0x138]
// 004c231d  6a01                 push 1
// 004c231f  6a00                 push 0
// 004c2321  50                   push eax
// 004c2322  8b442414             mov eax, dword ptr [esp + 0x14]
// 004c2326  51                   push ecx
// 004c2327  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004c232b  52                   push edx
// 004c232c  6a03                 push 3
// 004c232e  6a03                 push 3
// 004c2330  50                   push eax
// 004c2331  51                   push ecx
// 004c2332  8bce                 mov ecx, esi
// 004c2334  e8f7b2ffff           call 0x4bd630
// 004c2339  8d4c2408             lea ecx, [esp + 8]
// 004c233d  c7842424010000ffffffff mov dword ptr [esp + 0x124], 0xffffffff
// 004c2348  e8532efeff           call 0x4a51a0
// 004c234d  8b8c241c010000       mov ecx, dword ptr [esp + 0x11c]
// 004c2354  5e                   pop esi
// 004c2355  64890d00000000       mov dword ptr fs:[0], ecx
// 004c235c  81c424010000         add esp, 0x124
// 004c2362  c21000               ret 0x10
// library openrbx-raknet/RakPeer.cpp (function ?NotifyAndFlagForShutdown@RakPeer@@IAEXUSystemAddress@@_NE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
