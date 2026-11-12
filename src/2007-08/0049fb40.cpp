// from server: 100% by auto
// roc 2007-08 0049fb40  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0049fb40
//
// 0049fb40  8b442404             mov eax, dword ptr [esp + 4]
// 0049fb44  85c0                 test eax, eax
// 0049fb46  56                   push esi
// 0049fb47  8bf1                 mov esi, ecx
// 0049fb49  7e6f                 jle 0x49fbba
// 0049fb4b  8b0e                 mov ecx, dword ptr [esi]
// 0049fb4d  57                   push edi
// 0049fb4e  8d3c01               lea edi, [ecx + eax]
// 0049fb51  85ff                 test edi, edi
// 0049fb53  7e5c                 jle 0x49fbb1
// 0049fb55  8b5604               mov edx, dword ptr [esi + 4]
// 0049fb58  83ea01               sub edx, 1
// 0049fb5b  8d47ff               lea eax, [edi - 1]
// 0049fb5e  83e2f8               and edx, 0xfffffff8
// 0049fb61  83e0f8               and eax, 0xfffffff8
// 0049fb64  3bd0                 cmp edx, eax
// 0049fb66  7d49                 jge 0x49fbb1
// 0049fb68  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0049fb6b  03ff                 add edi, edi
// 0049fb6d  53                   push ebx
// 0049fb6e  8d4707               lea eax, [edi + 7]
// 0049fb71  8d5e11               lea ebx, [esi + 0x11]
// 0049fb74  c1f803               sar eax, 3
// 0049fb77  3bcb                 cmp ecx, ebx
// 0049fb79  7527                 jne 0x49fba2
// 0049fb7b  3d00010000           cmp eax, 0x100
// 0049fb80  7e2e                 jle 0x49fbb0
// 0049fb82  50                   push eax
// 0049fb83  ff15d0e67700         call dword ptr [0x77e6d0]
// 0049fb89  8b4e04               mov ecx, dword ptr [esi + 4]
// 0049fb8c  83c107               add ecx, 7
// 0049fb8f  c1f903               sar ecx, 3
// 0049fb92  51                   push ecx
// 0049fb93  53                   push ebx
// 0049fb94  50                   push eax
// 0049fb95  89460c               mov dword ptr [esi + 0xc], eax
// 0049fb98  e8af111900           call 0x630d4c
// 0049fb9d  83c410               add esp, 0x10
// 0049fba0  eb0e                 jmp 0x49fbb0
// 0049fba2  50                   push eax
// 0049fba3  51                   push ecx
// 0049fba4  ff1520e77700         call dword ptr [0x77e720]
// 0049fbaa  83c408               add esp, 8
// 0049fbad  89460c               mov dword ptr [esi + 0xc], eax
// 0049fbb0  5b                   pop ebx
// 0049fbb1  3b7e04               cmp edi, dword ptr [esi + 4]
// 0049fbb4  7e03                 jle 0x49fbb9
// 0049fbb6  897e04               mov dword ptr [esi + 4], edi
// 0049fbb9  5f                   pop edi
// 0049fbba  5e                   pop esi
// 0049fbbb  c20400               ret 4
// library openrbx-raknet/BitStream.cpp (function ?AddBitsAndReallocate@BitStream@RakNet@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet BitStream.cpp
