// from server: 100% by auto
// roc 2008-06 004cfb10  unit: RBX::Network::PhysicsSender  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cfb10
//
// 004cfb10  56                   push esi
// 004cfb11  8bf1                 mov esi, ecx
// 004cfb13  837e0800             cmp dword ptr [esi + 8], 0
// 004cfb17  7e67                 jle 0x4cfb80
// 004cfb19  8b0e                 mov ecx, dword ptr [esi]
// 004cfb1b  83caff               or edx, 0xffffffff
// 004cfb1e  015104               add dword ptr [ecx + 4], edx
// 004cfb21  8b4104               mov eax, dword ptr [ecx + 4]
// 004cfb24  57                   push edi
// 004cfb25  8b39                 mov edi, dword ptr [ecx]
// 004cfb27  8b0487               mov eax, dword ptr [edi + eax*4]
// 004cfb2a  7551                 jne 0x4cfb7d
// 004cfb2c  015608               add dword ptr [esi + 8], edx
// 004cfb2f  8b510c               mov edx, dword ptr [ecx + 0xc]
// 004cfb32  8916                 mov dword ptr [esi], edx
// 004cfb34  8b510c               mov edx, dword ptr [ecx + 0xc]
// 004cfb37  8b7910               mov edi, dword ptr [ecx + 0x10]
// 004cfb3a  897a10               mov dword ptr [edx + 0x10], edi
// 004cfb3d  8b5110               mov edx, dword ptr [ecx + 0x10]
// 004cfb40  8b790c               mov edi, dword ptr [ecx + 0xc]
// 004cfb43  897a0c               mov dword ptr [edx + 0xc], edi
// 004cfb46  8b560c               mov edx, dword ptr [esi + 0xc]
// 004cfb49  8d7a01               lea edi, [edx + 1]
// 004cfb4c  897e0c               mov dword ptr [esi + 0xc], edi
// 004cfb4f  85d2                 test edx, edx
// 004cfb51  750c                 jne 0x4cfb5f
// 004cfb53  894e04               mov dword ptr [esi + 4], ecx
// 004cfb56  5f                   pop edi
// 004cfb57  89490c               mov dword ptr [ecx + 0xc], ecx
// 004cfb5a  894910               mov dword ptr [ecx + 0x10], ecx
// 004cfb5d  5e                   pop esi
// 004cfb5e  c3                   ret 
// 004cfb5f  8b5604               mov edx, dword ptr [esi + 4]
// 004cfb62  89510c               mov dword ptr [ecx + 0xc], edx
// 004cfb65  8b5604               mov edx, dword ptr [esi + 4]
// 004cfb68  8b5210               mov edx, dword ptr [edx + 0x10]
// 004cfb6b  895110               mov dword ptr [ecx + 0x10], edx
// 004cfb6e  8b5604               mov edx, dword ptr [esi + 4]
// 004cfb71  8b5210               mov edx, dword ptr [edx + 0x10]
// 004cfb74  894a0c               mov dword ptr [edx + 0xc], ecx
// 004cfb77  8b5604               mov edx, dword ptr [esi + 4]
// 004cfb7a  894a10               mov dword ptr [edx + 0x10], ecx
// 004cfb7d  5f                   pop edi
// 004cfb7e  5e                   pop esi
// 004cfb7f  c3                   ret 
// 004cfb80  6a14                 push 0x14
// 004cfb82  ff15b0288000         call dword ptr [0x8028b0]
// 004cfb88  83c404               add esp, 4
// 004cfb8b  50                   push eax
// 004cfb8c  50                   push eax
// 004cfb8d  8bce                 mov ecx, esi
// 004cfb8f  8906                 mov dword ptr [esi], eax
// 004cfb91  c7460801000000       mov dword ptr [esi + 8], 1
// 004cfb98  e8c3faffff           call 0x4cf660
// 004cfb9d  8b06                 mov eax, dword ptr [esi]
// 004cfb9f  ff4804               dec dword ptr [eax + 4]
// 004cfba2  8b36                 mov esi, dword ptr [esi]
// 004cfba4  8b4604               mov eax, dword ptr [esi + 4]
// 004cfba7  8b0e                 mov ecx, dword ptr [esi]
// 004cfba9  8b0481               mov eax, dword ptr [ecx + eax*4]
// 004cfbac  5e                   pop esi
// 004cfbad  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ?Allocate@?$MemoryPool@UInternalPacket@@@DataStructures@@QAEPAUInternalPacket@@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
