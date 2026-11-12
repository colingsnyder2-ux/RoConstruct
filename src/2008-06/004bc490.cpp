// from server: 100% by auto
// roc 2008-06 004bc490  unit: ProfiledRakPeer  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc490
//
// 004bc490  56                   push esi
// 004bc491  8bf1                 mov esi, ecx
// 004bc493  8b4608               mov eax, dword ptr [esi + 8]
// 004bc496  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 004bc499  8b5608               mov edx, dword ptr [esi + 8]
// 004bc49c  894e0c               mov dword ptr [esi + 0xc], ecx
// 004bc49f  8b423c               mov eax, dword ptr [edx + 0x3c]
// 004bc4a2  b901000000           mov ecx, 1
// 004bc4a7  3b4608               cmp eax, dword ptr [esi + 8]
// 004bc4aa  7433                 je 0x4bc4df
// 004bc4ac  8d642400             lea esp, [esp]
// 004bc4b0  8b403c               mov eax, dword ptr [eax + 0x3c]
// 004bc4b3  41                   inc ecx
// 004bc4b4  3b4608               cmp eax, dword ptr [esi + 8]
// 004bc4b7  75f7                 jne 0x4bc4b0
// 004bc4b9  83f908               cmp ecx, 8
// 004bc4bc  7e21                 jle 0x4bc4df
// 004bc4be  53                   push ebx
// 004bc4bf  57                   push edi
// 004bc4c0  8d59f8               lea ebx, [ecx - 8]
// 004bc4c3  8b460c               mov eax, dword ptr [esi + 0xc]
// 004bc4c6  8b783c               mov edi, dword ptr [eax + 0x3c]
// 004bc4c9  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004bc4cc  51                   push ecx
// 004bc4cd  e8a8411e00           call 0x6a067a
// 004bc4d2  83c404               add esp, 4
// 004bc4d5  83eb01               sub ebx, 1
// 004bc4d8  897e0c               mov dword ptr [esi + 0xc], edi
// 004bc4db  75e6                 jne 0x4bc4c3
// 004bc4dd  5f                   pop edi
// 004bc4de  5b                   pop ebx
// 004bc4df  8b460c               mov eax, dword ptr [esi + 0xc]
// 004bc4e2  8b5608               mov edx, dword ptr [esi + 8]
// 004bc4e5  89423c               mov dword ptr [edx + 0x3c], eax
// 004bc4e8  8b4608               mov eax, dword ptr [esi + 8]
// 004bc4eb  89460c               mov dword ptr [esi + 0xc], eax
// 004bc4ee  8906                 mov dword ptr [esi], eax
// 004bc4f0  894604               mov dword ptr [esi + 4], eax
// 004bc4f3  33c0                 xor eax, eax
// 004bc4f5  894614               mov dword ptr [esi + 0x14], eax
// 004bc4f8  894610               mov dword ptr [esi + 0x10], eax
// 004bc4fb  5e                   pop esi
// 004bc4fc  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?Clear@?$SingleProducerConsumer@UBufferedCommandStruct@RakPeer@@@DataStructures@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
