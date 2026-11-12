// from server: 100% by auto
// roc 2007-08 004c5b90  unit: RakPeer  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004c5b90
//
// 004c5b90  56                   push esi
// 004c5b91  8bf1                 mov esi, ecx
// 004c5b93  837e0800             cmp dword ptr [esi + 8], 0
// 004c5b97  7e67                 jle 0x4c5c00
// 004c5b99  8b0e                 mov ecx, dword ptr [esi]
// 004c5b9b  83caff               or edx, 0xffffffff
// 004c5b9e  015104               add dword ptr [ecx + 4], edx
// 004c5ba1  8b4104               mov eax, dword ptr [ecx + 4]
// 004c5ba4  57                   push edi
// 004c5ba5  8b39                 mov edi, dword ptr [ecx]
// 004c5ba7  8b0487               mov eax, dword ptr [edi + eax*4]
// 004c5baa  7551                 jne 0x4c5bfd
// 004c5bac  015608               add dword ptr [esi + 8], edx
// 004c5baf  8b510c               mov edx, dword ptr [ecx + 0xc]
// 004c5bb2  8916                 mov dword ptr [esi], edx
// 004c5bb4  8b510c               mov edx, dword ptr [ecx + 0xc]
// 004c5bb7  8b7910               mov edi, dword ptr [ecx + 0x10]
// 004c5bba  897a10               mov dword ptr [edx + 0x10], edi
// 004c5bbd  8b5110               mov edx, dword ptr [ecx + 0x10]
// 004c5bc0  8b790c               mov edi, dword ptr [ecx + 0xc]
// 004c5bc3  897a0c               mov dword ptr [edx + 0xc], edi
// 004c5bc6  8b560c               mov edx, dword ptr [esi + 0xc]
// 004c5bc9  85d2                 test edx, edx
// 004c5bcb  8d7a01               lea edi, [edx + 1]
// 004c5bce  897e0c               mov dword ptr [esi + 0xc], edi
// 004c5bd1  750c                 jne 0x4c5bdf
// 004c5bd3  894e04               mov dword ptr [esi + 4], ecx
// 004c5bd6  5f                   pop edi
// 004c5bd7  89490c               mov dword ptr [ecx + 0xc], ecx
// 004c5bda  894910               mov dword ptr [ecx + 0x10], ecx
// 004c5bdd  5e                   pop esi
// 004c5bde  c3                   ret 
// 004c5bdf  8b5604               mov edx, dword ptr [esi + 4]
// 004c5be2  89510c               mov dword ptr [ecx + 0xc], edx
// 004c5be5  8b5604               mov edx, dword ptr [esi + 4]
// 004c5be8  8b5210               mov edx, dword ptr [edx + 0x10]
// 004c5beb  895110               mov dword ptr [ecx + 0x10], edx
// 004c5bee  8b5604               mov edx, dword ptr [esi + 4]
// 004c5bf1  8b5210               mov edx, dword ptr [edx + 0x10]
// 004c5bf4  894a0c               mov dword ptr [edx + 0xc], ecx
// 004c5bf7  8b5604               mov edx, dword ptr [esi + 4]
// 004c5bfa  894a10               mov dword ptr [edx + 0x10], ecx
// 004c5bfd  5f                   pop edi
// 004c5bfe  5e                   pop esi
// 004c5bff  c3                   ret 
// 004c5c00  6a14                 push 0x14
// 004c5c02  ff15d0e67700         call dword ptr [0x77e6d0]
// 004c5c08  83c404               add esp, 4
// 004c5c0b  50                   push eax
// 004c5c0c  50                   push eax
// 004c5c0d  8bce                 mov ecx, esi
// 004c5c0f  8906                 mov dword ptr [esi], eax
// 004c5c11  c7460801000000       mov dword ptr [esi + 8], 1
// 004c5c18  e8f3f9ffff           call 0x4c5610
// 004c5c1d  8b06                 mov eax, dword ptr [esi]
// 004c5c1f  834004ff             add dword ptr [eax + 4], -1
// 004c5c23  8b36                 mov esi, dword ptr [esi]
// 004c5c25  8b4604               mov eax, dword ptr [esi + 4]
// 004c5c28  8b0e                 mov ecx, dword ptr [esi]
// 004c5c2a  8b0481               mov eax, dword ptr [ecx + eax*4]
// 004c5c2d  5e                   pop esi
// 004c5c2e  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ?Allocate@?$MemoryPool@UInternalPacket@@@DataStructures@@QAEPAUInternalPacket@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
