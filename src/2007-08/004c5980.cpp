// from server: 100% by auto
// roc 2007-08 004c5980  unit: RakPeer  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004c5980
//
// 004c5980  56                   push esi
// 004c5981  8bf1                 mov esi, ecx
// 004c5983  837e0800             cmp dword ptr [esi + 8], 0
// 004c5987  7e67                 jle 0x4c59f0
// 004c5989  8b0e                 mov ecx, dword ptr [esi]
// 004c598b  83caff               or edx, 0xffffffff
// 004c598e  015104               add dword ptr [ecx + 4], edx
// 004c5991  8b4104               mov eax, dword ptr [ecx + 4]
// 004c5994  57                   push edi
// 004c5995  8b39                 mov edi, dword ptr [ecx]
// 004c5997  8b0487               mov eax, dword ptr [edi + eax*4]
// 004c599a  7551                 jne 0x4c59ed
// 004c599c  015608               add dword ptr [esi + 8], edx
// 004c599f  8b510c               mov edx, dword ptr [ecx + 0xc]
// 004c59a2  8916                 mov dword ptr [esi], edx
// 004c59a4  8b510c               mov edx, dword ptr [ecx + 0xc]
// 004c59a7  8b7910               mov edi, dword ptr [ecx + 0x10]
// 004c59aa  897a10               mov dword ptr [edx + 0x10], edi
// 004c59ad  8b5110               mov edx, dword ptr [ecx + 0x10]
// 004c59b0  8b790c               mov edi, dword ptr [ecx + 0xc]
// 004c59b3  897a0c               mov dword ptr [edx + 0xc], edi
// 004c59b6  8b560c               mov edx, dword ptr [esi + 0xc]
// 004c59b9  85d2                 test edx, edx
// 004c59bb  8d7a01               lea edi, [edx + 1]
// 004c59be  897e0c               mov dword ptr [esi + 0xc], edi
// 004c59c1  750c                 jne 0x4c59cf
// 004c59c3  894e04               mov dword ptr [esi + 4], ecx
// 004c59c6  5f                   pop edi
// 004c59c7  89490c               mov dword ptr [ecx + 0xc], ecx
// 004c59ca  894910               mov dword ptr [ecx + 0x10], ecx
// 004c59cd  5e                   pop esi
// 004c59ce  c3                   ret 
// 004c59cf  8b5604               mov edx, dword ptr [esi + 4]
// 004c59d2  89510c               mov dword ptr [ecx + 0xc], edx
// 004c59d5  8b5604               mov edx, dword ptr [esi + 4]
// 004c59d8  8b5210               mov edx, dword ptr [edx + 0x10]
// 004c59db  895110               mov dword ptr [ecx + 0x10], edx
// 004c59de  8b5604               mov edx, dword ptr [esi + 4]
// 004c59e1  8b5210               mov edx, dword ptr [edx + 0x10]
// 004c59e4  894a0c               mov dword ptr [edx + 0xc], ecx
// 004c59e7  8b5604               mov edx, dword ptr [esi + 4]
// 004c59ea  894a10               mov dword ptr [edx + 0x10], ecx
// 004c59ed  5f                   pop edi
// 004c59ee  5e                   pop esi
// 004c59ef  c3                   ret 
// 004c59f0  6a14                 push 0x14
// 004c59f2  ff15d0e67700         call dword ptr [0x77e6d0]
// 004c59f8  83c404               add esp, 4
// 004c59fb  50                   push eax
// 004c59fc  50                   push eax
// 004c59fd  8bce                 mov ecx, esi
// 004c59ff  8906                 mov dword ptr [esi], eax
// 004c5a01  c7460801000000       mov dword ptr [esi + 8], 1
// 004c5a08  e863f9ffff           call 0x4c5370
// 004c5a0d  8b06                 mov eax, dword ptr [esi]
// 004c5a0f  834004ff             add dword ptr [eax + 4], -1
// 004c5a13  8b36                 mov esi, dword ptr [esi]
// 004c5a15  8b4604               mov eax, dword ptr [esi + 4]
// 004c5a18  8b0e                 mov ecx, dword ptr [esi]
// 004c5a1a  8b0481               mov eax, dword ptr [ecx + eax*4]
// 004c5a1d  5e                   pop esi
// 004c5a1e  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ?Allocate@?$MemoryPool@UInternalPacket@@@DataStructures@@QAEPAUInternalPacket@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
