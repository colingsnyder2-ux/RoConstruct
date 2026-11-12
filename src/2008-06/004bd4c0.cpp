// from server: 100% by auto
// roc 2008-06 004bd4c0  unit: ProfiledRakPeer  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bd4c0
//
// 004bd4c0  56                   push esi
// 004bd4c1  8bf1                 mov esi, ecx
// 004bd4c3  8b06                 mov eax, dword ptr [esi]
// 004bd4c5  8b502c               mov edx, dword ptr [eax + 0x2c]
// 004bd4c8  ffd2                 call edx
// 004bd4ca  84c0                 test al, al
// 004bd4cc  7406                 je 0x4bd4d4
// 004bd4ce  32c0                 xor al, al
// 004bd4d0  5e                   pop esi
// 004bd4d1  c20400               ret 4
// 004bd4d4  807c240800           cmp byte ptr [esp + 8], 0
// 004bd4d9  57                   push edi
// 004bd4da  742b                 je 0x4bd507
// 004bd4dc  8bbecc060000         mov edi, dword ptr [esi + 0x6cc]
// 004bd4e2  85ff                 test edi, edi
// 004bd4e4  7445                 je 0x4bd52b
// 004bd4e6  8bcf                 mov ecx, edi
// 004bd4e8  e8e30d0100           call 0x4ce2d0
// 004bd4ed  57                   push edi
// 004bd4ee  e887311e00           call 0x6a067a
// 004bd4f3  83c404               add esp, 4
// 004bd4f6  5f                   pop edi
// 004bd4f7  c786cc06000000000000 mov dword ptr [esi + 0x6cc], 0
// 004bd501  b001                 mov al, 1
// 004bd503  5e                   pop esi
// 004bd504  c20400               ret 4
// 004bd507  8bbed0060000         mov edi, dword ptr [esi + 0x6d0]
// 004bd50d  85ff                 test edi, edi
// 004bd50f  741a                 je 0x4bd52b
// 004bd511  8bcf                 mov ecx, edi
// 004bd513  e8b80d0100           call 0x4ce2d0
// 004bd518  57                   push edi
// 004bd519  e85c311e00           call 0x6a067a
// 004bd51e  c786d006000000000000 mov dword ptr [esi + 0x6d0], 0
// 004bd528  83c404               add esp, 4
// 004bd52b  5f                   pop edi
// 004bd52c  b001                 mov al, 1
// 004bd52e  5e                   pop esi
// 004bd52f  c20400               ret 4
// library openrbx-raknet/RakPeer.cpp (function ?DeleteCompressionLayer@RakPeer@@UAE_N_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
