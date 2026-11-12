// from server: 100% by auto
// roc 2008-06 004cf9a0  unit: RBX::Network::PhysicsSender  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cf9a0
//
// 004cf9a0  8b542404             mov edx, dword ptr [esp + 4]
// 004cf9a4  56                   push esi
// 004cf9a5  8b7240               mov esi, dword ptr [edx + 0x40]
// 004cf9a8  8b4604               mov eax, dword ptr [esi + 4]
// 004cf9ab  85c0                 test eax, eax
// 004cf9ad  7566                 jne 0x4cfa15
// 004cf9af  8b06                 mov eax, dword ptr [esi]
// 004cf9b1  8910                 mov dword ptr [eax], edx
// 004cf9b3  ff4604               inc dword ptr [esi + 4]
// 004cf9b6  ff490c               dec dword ptr [ecx + 0xc]
// 004cf9b9  8b560c               mov edx, dword ptr [esi + 0xc]
// 004cf9bc  8b4610               mov eax, dword ptr [esi + 0x10]
// 004cf9bf  894210               mov dword ptr [edx + 0x10], eax
// 004cf9c2  8b5610               mov edx, dword ptr [esi + 0x10]
// 004cf9c5  8b460c               mov eax, dword ptr [esi + 0xc]
// 004cf9c8  89420c               mov dword ptr [edx + 0xc], eax
// 004cf9cb  83790c00             cmp dword ptr [ecx + 0xc], 0
// 004cf9cf  7e0d                 jle 0x4cf9de
// 004cf9d1  8b4104               mov eax, dword ptr [ecx + 4]
// 004cf9d4  3bf0                 cmp esi, eax
// 004cf9d6  7506                 jne 0x4cf9de
// 004cf9d8  8b500c               mov edx, dword ptr [eax + 0xc]
// 004cf9db  895104               mov dword ptr [ecx + 4], edx
// 004cf9de  8b4108               mov eax, dword ptr [ecx + 8]
// 004cf9e1  8d5001               lea edx, [eax + 1]
// 004cf9e4  895108               mov dword ptr [ecx + 8], edx
// 004cf9e7  85c0                 test eax, eax
// 004cf9e9  750c                 jne 0x4cf9f7
// 004cf9eb  8931                 mov dword ptr [ecx], esi
// 004cf9ed  89760c               mov dword ptr [esi + 0xc], esi
// 004cf9f0  897610               mov dword ptr [esi + 0x10], esi
// 004cf9f3  5e                   pop esi
// 004cf9f4  c20400               ret 4
// 004cf9f7  8b01                 mov eax, dword ptr [ecx]
// 004cf9f9  89460c               mov dword ptr [esi + 0xc], eax
// 004cf9fc  8b11                 mov edx, dword ptr [ecx]
// 004cf9fe  8b4210               mov eax, dword ptr [edx + 0x10]
// 004cfa01  894610               mov dword ptr [esi + 0x10], eax
// 004cfa04  8b11                 mov edx, dword ptr [ecx]
// 004cfa06  8b4210               mov eax, dword ptr [edx + 0x10]
// 004cfa09  89700c               mov dword ptr [eax + 0xc], esi
// 004cfa0c  8b09                 mov ecx, dword ptr [ecx]
// 004cfa0e  897110               mov dword ptr [ecx + 0x10], esi
// 004cfa11  5e                   pop esi
// 004cfa12  c20400               ret 4
// 004cfa15  57                   push edi
// 004cfa16  8b3e                 mov edi, dword ptr [esi]
// 004cfa18  891487               mov dword ptr [edi + eax*4], edx
// 004cfa1b  ff4604               inc dword ptr [esi + 4]
// 004cfa1e  8b7e04               mov edi, dword ptr [esi + 4]
// 004cfa21  b8398ee338           mov eax, 0x38e38e39
// 004cfa26  f76110               mul dword ptr [ecx + 0x10]
// 004cfa29  c1ea04               shr edx, 4
// 004cfa2c  3bfa                 cmp edi, edx
// 004cfa2e  753b                 jne 0x4cfa6b
// 004cfa30  83790804             cmp dword ptr [ecx + 8], 4
// 004cfa34  7c35                 jl 0x4cfa6b
// 004cfa36  3b31                 cmp esi, dword ptr [ecx]
// 004cfa38  7505                 jne 0x4cfa3f
// 004cfa3a  8b560c               mov edx, dword ptr [esi + 0xc]
// 004cfa3d  8911                 mov dword ptr [ecx], edx
// 004cfa3f  8b4610               mov eax, dword ptr [esi + 0x10]
// 004cfa42  8b560c               mov edx, dword ptr [esi + 0xc]
// 004cfa45  8b3dc0288000         mov edi, dword ptr [0x8028c0]
// 004cfa4b  89500c               mov dword ptr [eax + 0xc], edx
// 004cfa4e  8b460c               mov eax, dword ptr [esi + 0xc]
// 004cfa51  8b5610               mov edx, dword ptr [esi + 0x10]
// 004cfa54  895010               mov dword ptr [eax + 0x10], edx
// 004cfa57  ff4908               dec dword ptr [ecx + 8]
// 004cfa5a  8b06                 mov eax, dword ptr [esi]
// 004cfa5c  50                   push eax
// 004cfa5d  ffd7                 call edi
// 004cfa5f  8b4e08               mov ecx, dword ptr [esi + 8]
// 004cfa62  51                   push ecx
// 004cfa63  ffd7                 call edi
// 004cfa65  56                   push esi
// 004cfa66  ffd7                 call edi
// 004cfa68  83c40c               add esp, 0xc
// 004cfa6b  5f                   pop edi
// 004cfa6c  5e                   pop esi
// 004cfa6d  c20400               ret 4
// library openrbx-raknet/ReliabilityLayer.cpp (function ?Release@?$MemoryPool@UInternalPacket@@@DataStructures@@QAEXPAUInternalPacket@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
