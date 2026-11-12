// from server: 100% by auto
// roc 2007-08 004c5c30  unit: RakPeer  size: 215 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004c5c30
//
// 004c5c30  8b542404             mov edx, dword ptr [esp + 4]
// 004c5c34  56                   push esi
// 004c5c35  8bb294010000         mov esi, dword ptr [edx + 0x194]
// 004c5c3b  8b4604               mov eax, dword ptr [esi + 4]
// 004c5c3e  85c0                 test eax, eax
// 004c5c40  7568                 jne 0x4c5caa
// 004c5c42  8b06                 mov eax, dword ptr [esi]
// 004c5c44  8910                 mov dword ptr [eax], edx
// 004c5c46  83460401             add dword ptr [esi + 4], 1
// 004c5c4a  83410cff             add dword ptr [ecx + 0xc], -1
// 004c5c4e  8b560c               mov edx, dword ptr [esi + 0xc]
// 004c5c51  8b4610               mov eax, dword ptr [esi + 0x10]
// 004c5c54  894210               mov dword ptr [edx + 0x10], eax
// 004c5c57  8b5610               mov edx, dword ptr [esi + 0x10]
// 004c5c5a  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c5c5d  89420c               mov dword ptr [edx + 0xc], eax
// 004c5c60  83790c00             cmp dword ptr [ecx + 0xc], 0
// 004c5c64  7e0d                 jle 0x4c5c73
// 004c5c66  8b4104               mov eax, dword ptr [ecx + 4]
// 004c5c69  3bf0                 cmp esi, eax
// 004c5c6b  7506                 jne 0x4c5c73
// 004c5c6d  8b500c               mov edx, dword ptr [eax + 0xc]
// 004c5c70  895104               mov dword ptr [ecx + 4], edx
// 004c5c73  8b4108               mov eax, dword ptr [ecx + 8]
// 004c5c76  85c0                 test eax, eax
// 004c5c78  8d5001               lea edx, [eax + 1]
// 004c5c7b  895108               mov dword ptr [ecx + 8], edx
// 004c5c7e  750c                 jne 0x4c5c8c
// 004c5c80  8931                 mov dword ptr [ecx], esi
// 004c5c82  89760c               mov dword ptr [esi + 0xc], esi
// 004c5c85  897610               mov dword ptr [esi + 0x10], esi
// 004c5c88  5e                   pop esi
// 004c5c89  c20400               ret 4
// 004c5c8c  8b01                 mov eax, dword ptr [ecx]
// 004c5c8e  89460c               mov dword ptr [esi + 0xc], eax
// 004c5c91  8b11                 mov edx, dword ptr [ecx]
// 004c5c93  8b4210               mov eax, dword ptr [edx + 0x10]
// 004c5c96  894610               mov dword ptr [esi + 0x10], eax
// 004c5c99  8b11                 mov edx, dword ptr [ecx]
// 004c5c9b  8b4210               mov eax, dword ptr [edx + 0x10]
// 004c5c9e  89700c               mov dword ptr [eax + 0xc], esi
// 004c5ca1  8b09                 mov ecx, dword ptr [ecx]
// 004c5ca3  897110               mov dword ptr [ecx + 0x10], esi
// 004c5ca6  5e                   pop esi
// 004c5ca7  c20400               ret 4
// 004c5caa  57                   push edi
// 004c5cab  8b3e                 mov edi, dword ptr [esi]
// 004c5cad  891487               mov dword ptr [edi + eax*4], edx
// 004c5cb0  83460401             add dword ptr [esi + 4], 1
// 004c5cb4  8b7e04               mov edi, dword ptr [esi + 4]
// 004c5cb7  b8a1a0a0a0           mov eax, 0xa0a0a0a1
// 004c5cbc  f76110               mul dword ptr [ecx + 0x10]
// 004c5cbf  c1ea08               shr edx, 8
// 004c5cc2  3bfa                 cmp edi, edx
// 004c5cc4  753c                 jne 0x4c5d02
// 004c5cc6  83790804             cmp dword ptr [ecx + 8], 4
// 004c5cca  7c36                 jl 0x4c5d02
// 004c5ccc  3b31                 cmp esi, dword ptr [ecx]
// 004c5cce  7505                 jne 0x4c5cd5
// 004c5cd0  8b560c               mov edx, dword ptr [esi + 0xc]
// 004c5cd3  8911                 mov dword ptr [ecx], edx
// 004c5cd5  8b4610               mov eax, dword ptr [esi + 0x10]
// 004c5cd8  8b560c               mov edx, dword ptr [esi + 0xc]
// 004c5cdb  8b3dc4e67700         mov edi, dword ptr [0x77e6c4]
// 004c5ce1  89500c               mov dword ptr [eax + 0xc], edx
// 004c5ce4  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c5ce7  8b5610               mov edx, dword ptr [esi + 0x10]
// 004c5cea  895010               mov dword ptr [eax + 0x10], edx
// 004c5ced  834108ff             add dword ptr [ecx + 8], -1
// 004c5cf1  8b06                 mov eax, dword ptr [esi]
// 004c5cf3  50                   push eax
// 004c5cf4  ffd7                 call edi
// 004c5cf6  8b4e08               mov ecx, dword ptr [esi + 8]
// 004c5cf9  51                   push ecx
// 004c5cfa  ffd7                 call edi
// 004c5cfc  56                   push esi
// 004c5cfd  ffd7                 call edi
// 004c5cff  83c40c               add esp, 0xc
// 004c5d02  5f                   pop edi
// 004c5d03  5e                   pop esi
// 004c5d04  c20400               ret 4
// library openrbx-raknet/ReliabilityLayer.cpp (function ?Release@?$MemoryPool@U?$Page@IPAUInternalPacket@@$0CA@@DataStructures@@@DataStructures@@QAEXPAU?$Page@IPAUInternalPacket@@$0CA@@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
