// from server: 100% by auto
// roc 2008-06 004cf900  unit: RBX::Network::PhysicsSender  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cf900
//
// 004cf900  56                   push esi
// 004cf901  8bf1                 mov esi, ecx
// 004cf903  837e0800             cmp dword ptr [esi + 8], 0
// 004cf907  7e67                 jle 0x4cf970
// 004cf909  8b0e                 mov ecx, dword ptr [esi]
// 004cf90b  83caff               or edx, 0xffffffff
// 004cf90e  015104               add dword ptr [ecx + 4], edx
// 004cf911  8b4104               mov eax, dword ptr [ecx + 4]
// 004cf914  57                   push edi
// 004cf915  8b39                 mov edi, dword ptr [ecx]
// 004cf917  8b0487               mov eax, dword ptr [edi + eax*4]
// 004cf91a  7551                 jne 0x4cf96d
// 004cf91c  015608               add dword ptr [esi + 8], edx
// 004cf91f  8b510c               mov edx, dword ptr [ecx + 0xc]
// 004cf922  8916                 mov dword ptr [esi], edx
// 004cf924  8b510c               mov edx, dword ptr [ecx + 0xc]
// 004cf927  8b7910               mov edi, dword ptr [ecx + 0x10]
// 004cf92a  897a10               mov dword ptr [edx + 0x10], edi
// 004cf92d  8b5110               mov edx, dword ptr [ecx + 0x10]
// 004cf930  8b790c               mov edi, dword ptr [ecx + 0xc]
// 004cf933  897a0c               mov dword ptr [edx + 0xc], edi
// 004cf936  8b560c               mov edx, dword ptr [esi + 0xc]
// 004cf939  8d7a01               lea edi, [edx + 1]
// 004cf93c  897e0c               mov dword ptr [esi + 0xc], edi
// 004cf93f  85d2                 test edx, edx
// 004cf941  750c                 jne 0x4cf94f
// 004cf943  894e04               mov dword ptr [esi + 4], ecx
// 004cf946  5f                   pop edi
// 004cf947  89490c               mov dword ptr [ecx + 0xc], ecx
// 004cf94a  894910               mov dword ptr [ecx + 0x10], ecx
// 004cf94d  5e                   pop esi
// 004cf94e  c3                   ret 
// 004cf94f  8b5604               mov edx, dword ptr [esi + 4]
// 004cf952  89510c               mov dword ptr [ecx + 0xc], edx
// 004cf955  8b5604               mov edx, dword ptr [esi + 4]
// 004cf958  8b5210               mov edx, dword ptr [edx + 0x10]
// 004cf95b  895110               mov dword ptr [ecx + 0x10], edx
// 004cf95e  8b5604               mov edx, dword ptr [esi + 4]
// 004cf961  8b5210               mov edx, dword ptr [edx + 0x10]
// 004cf964  894a0c               mov dword ptr [edx + 0xc], ecx
// 004cf967  8b5604               mov edx, dword ptr [esi + 4]
// 004cf96a  894a10               mov dword ptr [edx + 0x10], ecx
// 004cf96d  5f                   pop edi
// 004cf96e  5e                   pop esi
// 004cf96f  c3                   ret 
// 004cf970  6a14                 push 0x14
// 004cf972  ff15b0288000         call dword ptr [0x8028b0]
// 004cf978  83c404               add esp, 4
// 004cf97b  50                   push eax
// 004cf97c  50                   push eax
// 004cf97d  8bce                 mov ecx, esi
// 004cf97f  8906                 mov dword ptr [esi], eax
// 004cf981  c7460801000000       mov dword ptr [esi + 8], 1
// 004cf988  e893faffff           call 0x4cf420
// 004cf98d  8b06                 mov eax, dword ptr [esi]
// 004cf98f  ff4804               dec dword ptr [eax + 4]
// 004cf992  8b36                 mov esi, dword ptr [esi]
// 004cf994  8b4604               mov eax, dword ptr [esi + 4]
// 004cf997  8b0e                 mov ecx, dword ptr [esi]
// 004cf999  8b0481               mov eax, dword ptr [ecx + eax*4]
// 004cf99c  5e                   pop esi
// 004cf99d  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ?Allocate@?$MemoryPool@UInternalPacket@@@DataStructures@@QAEPAUInternalPacket@@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
