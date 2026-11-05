// roc 2012-06 0059a600  unit: RBX::Network::Marker  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0059a600
//
// 0059a600  53                   push ebx
// 0059a601  55                   push ebp
// 0059a602  56                   push esi
// 0059a603  8b742414             mov esi, dword ptr [esp + 0x14]
// 0059a607  8be9                 mov ebp, ecx
// 0059a609  837d0800             cmp dword ptr [ebp + 8], 0
// 0059a60d  57                   push edi
// 0059a60e  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0059a612  7e65                 jle 0x59a679
// 0059a614  8b5d00               mov ebx, dword ptr [ebp]
// 0059a617  8b03                 mov eax, dword ptr [ebx]
// 0059a619  56                   push esi
// 0059a61a  57                   push edi
// 0059a61b  50                   push eax
// 0059a61c  ff159c04d900         call dword ptr [0xd9049c]
// 0059a622  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0059a625  56                   push esi
// 0059a626  57                   push edi
// 0059a627  51                   push ecx
// 0059a628  ff159c04d900         call dword ptr [0xd9049c]
// 0059a62e  8bc3                 mov eax, ebx
// 0059a630  8b5b0c               mov ebx, dword ptr [ebx + 0xc]
// 0059a633  83c418               add esp, 0x18
// 0059a636  3b5d00               cmp ebx, dword ptr [ebp]
// 0059a639  7432                 je 0x59a66d
// 0059a63b  eb03                 jmp 0x59a640
// 0059a63d  8d4900               lea ecx, [ecx]
// 0059a640  56                   push esi
// 0059a641  57                   push edi
// 0059a642  50                   push eax
// 0059a643  ff159c04d900         call dword ptr [0xd9049c]
// 0059a649  8b13                 mov edx, dword ptr [ebx]
// 0059a64b  56                   push esi
// 0059a64c  57                   push edi
// 0059a64d  52                   push edx
// 0059a64e  ff159c04d900         call dword ptr [0xd9049c]
// 0059a654  8b4308               mov eax, dword ptr [ebx + 8]
// 0059a657  56                   push esi
// 0059a658  57                   push edi
// 0059a659  50                   push eax
// 0059a65a  ff159c04d900         call dword ptr [0xd9049c]
// 0059a660  8bc3                 mov eax, ebx
// 0059a662  8b5b0c               mov ebx, dword ptr [ebx + 0xc]
// 0059a665  83c424               add esp, 0x24
// 0059a668  3b5d00               cmp ebx, dword ptr [ebp]
// 0059a66b  75d3                 jne 0x59a640
// 0059a66d  56                   push esi
// 0059a66e  57                   push edi
// 0059a66f  50                   push eax
// 0059a670  ff159c04d900         call dword ptr [0xd9049c]
// 0059a676  83c40c               add esp, 0xc
// 0059a679  33c0                 xor eax, eax
// 0059a67b  39450c               cmp dword ptr [ebp + 0xc], eax
// 0059a67e  7e62                 jle 0x59a6e2
// 0059a680  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0059a683  8b0b                 mov ecx, dword ptr [ebx]
// 0059a685  56                   push esi
// 0059a686  57                   push edi
// 0059a687  51                   push ecx
// 0059a688  ff159c04d900         call dword ptr [0xd9049c]
// 0059a68e  8b5308               mov edx, dword ptr [ebx + 8]
// 0059a691  56                   push esi
// 0059a692  57                   push edi
// 0059a693  52                   push edx
// 0059a694  ff159c04d900         call dword ptr [0xd9049c]
// 0059a69a  8bc3                 mov eax, ebx
// 0059a69c  8b5b0c               mov ebx, dword ptr [ebx + 0xc]
// 0059a69f  83c418               add esp, 0x18
// 0059a6a2  3b5d04               cmp ebx, dword ptr [ebp + 4]
// 0059a6a5  742d                 je 0x59a6d4
// 0059a6a7  56                   push esi
// 0059a6a8  57                   push edi
// 0059a6a9  50                   push eax
// 0059a6aa  ff159c04d900         call dword ptr [0xd9049c]
// 0059a6b0  8b03                 mov eax, dword ptr [ebx]
// 0059a6b2  56                   push esi
// 0059a6b3  57                   push edi
// 0059a6b4  50                   push eax
// 0059a6b5  ff159c04d900         call dword ptr [0xd9049c]
// 0059a6bb  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0059a6be  56                   push esi
// 0059a6bf  57                   push edi
// 0059a6c0  51                   push ecx
// 0059a6c1  ff159c04d900         call dword ptr [0xd9049c]
// 0059a6c7  8bc3                 mov eax, ebx
// 0059a6c9  8b5b0c               mov ebx, dword ptr [ebx + 0xc]
// 0059a6cc  83c424               add esp, 0x24
// 0059a6cf  3b5d04               cmp ebx, dword ptr [ebp + 4]
// 0059a6d2  75d3                 jne 0x59a6a7
// 0059a6d4  56                   push esi
// 0059a6d5  57                   push edi
// 0059a6d6  50                   push eax
// 0059a6d7  ff159c04d900         call dword ptr [0xd9049c]
// 0059a6dd  83c40c               add esp, 0xc
// 0059a6e0  33c0                 xor eax, eax
// 0059a6e2  5f                   pop edi
// 0059a6e3  5e                   pop esi
// 0059a6e4  89450c               mov dword ptr [ebp + 0xc], eax
// 0059a6e7  894508               mov dword ptr [ebp + 8], eax
// 0059a6ea  5d                   pop ebp
// 0059a6eb  5b                   pop ebx
// 0059a6ec  c20800               ret 8
// copied from an identical function in another client (function ?Clear@?$MemoryPool@URemoteSystemIndex@RakNet@@@DataStructures@@QAEXPBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp