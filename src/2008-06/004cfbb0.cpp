// from server: 100% by auto
// roc 2008-06 004cfbb0  unit: RBX::Network::PhysicsSender  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cfbb0
//
// 004cfbb0  8b542404             mov edx, dword ptr [esp + 4]
// 004cfbb4  56                   push esi
// 004cfbb5  8bb294010000         mov esi, dword ptr [edx + 0x194]
// 004cfbbb  8b4604               mov eax, dword ptr [esi + 4]
// 004cfbbe  85c0                 test eax, eax
// 004cfbc0  7566                 jne 0x4cfc28
// 004cfbc2  8b06                 mov eax, dword ptr [esi]
// 004cfbc4  8910                 mov dword ptr [eax], edx
// 004cfbc6  ff4604               inc dword ptr [esi + 4]
// 004cfbc9  ff490c               dec dword ptr [ecx + 0xc]
// 004cfbcc  8b560c               mov edx, dword ptr [esi + 0xc]
// 004cfbcf  8b4610               mov eax, dword ptr [esi + 0x10]
// 004cfbd2  894210               mov dword ptr [edx + 0x10], eax
// 004cfbd5  8b5610               mov edx, dword ptr [esi + 0x10]
// 004cfbd8  8b460c               mov eax, dword ptr [esi + 0xc]
// 004cfbdb  89420c               mov dword ptr [edx + 0xc], eax
// 004cfbde  83790c00             cmp dword ptr [ecx + 0xc], 0
// 004cfbe2  7e0d                 jle 0x4cfbf1
// 004cfbe4  8b4104               mov eax, dword ptr [ecx + 4]
// 004cfbe7  3bf0                 cmp esi, eax
// 004cfbe9  7506                 jne 0x4cfbf1
// 004cfbeb  8b500c               mov edx, dword ptr [eax + 0xc]
// 004cfbee  895104               mov dword ptr [ecx + 4], edx
// 004cfbf1  8b4108               mov eax, dword ptr [ecx + 8]
// 004cfbf4  8d5001               lea edx, [eax + 1]
// 004cfbf7  895108               mov dword ptr [ecx + 8], edx
// 004cfbfa  85c0                 test eax, eax
// 004cfbfc  750c                 jne 0x4cfc0a
// 004cfbfe  8931                 mov dword ptr [ecx], esi
// 004cfc00  89760c               mov dword ptr [esi + 0xc], esi
// 004cfc03  897610               mov dword ptr [esi + 0x10], esi
// 004cfc06  5e                   pop esi
// 004cfc07  c20400               ret 4
// 004cfc0a  8b01                 mov eax, dword ptr [ecx]
// 004cfc0c  89460c               mov dword ptr [esi + 0xc], eax
// 004cfc0f  8b11                 mov edx, dword ptr [ecx]
// 004cfc11  8b4210               mov eax, dword ptr [edx + 0x10]
// 004cfc14  894610               mov dword ptr [esi + 0x10], eax
// 004cfc17  8b11                 mov edx, dword ptr [ecx]
// 004cfc19  8b4210               mov eax, dword ptr [edx + 0x10]
// 004cfc1c  89700c               mov dword ptr [eax + 0xc], esi
// 004cfc1f  8b09                 mov ecx, dword ptr [ecx]
// 004cfc21  897110               mov dword ptr [ecx + 0x10], esi
// 004cfc24  5e                   pop esi
// 004cfc25  c20400               ret 4
// 004cfc28  57                   push edi
// 004cfc29  8b3e                 mov edi, dword ptr [esi]
// 004cfc2b  891487               mov dword ptr [edi + eax*4], edx
// 004cfc2e  ff4604               inc dword ptr [esi + 4]
// 004cfc31  8b7e04               mov edi, dword ptr [esi + 4]
// 004cfc34  b8a1a0a0a0           mov eax, 0xa0a0a0a1
// 004cfc39  f76110               mul dword ptr [ecx + 0x10]
// 004cfc3c  c1ea08               shr edx, 8
// 004cfc3f  3bfa                 cmp edi, edx
// 004cfc41  753b                 jne 0x4cfc7e
// 004cfc43  83790804             cmp dword ptr [ecx + 8], 4
// 004cfc47  7c35                 jl 0x4cfc7e
// 004cfc49  3b31                 cmp esi, dword ptr [ecx]
// 004cfc4b  7505                 jne 0x4cfc52
// 004cfc4d  8b560c               mov edx, dword ptr [esi + 0xc]
// 004cfc50  8911                 mov dword ptr [ecx], edx
// 004cfc52  8b4610               mov eax, dword ptr [esi + 0x10]
// 004cfc55  8b560c               mov edx, dword ptr [esi + 0xc]
// 004cfc58  8b3dc0288000         mov edi, dword ptr [0x8028c0]
// 004cfc5e  89500c               mov dword ptr [eax + 0xc], edx
// 004cfc61  8b460c               mov eax, dword ptr [esi + 0xc]
// 004cfc64  8b5610               mov edx, dword ptr [esi + 0x10]
// 004cfc67  895010               mov dword ptr [eax + 0x10], edx
// 004cfc6a  ff4908               dec dword ptr [ecx + 8]
// 004cfc6d  8b06                 mov eax, dword ptr [esi]
// 004cfc6f  50                   push eax
// 004cfc70  ffd7                 call edi
// 004cfc72  8b4e08               mov ecx, dword ptr [esi + 8]
// 004cfc75  51                   push ecx
// 004cfc76  ffd7                 call edi
// 004cfc78  56                   push esi
// 004cfc79  ffd7                 call edi
// 004cfc7b  83c40c               add esp, 0xc
// 004cfc7e  5f                   pop edi
// 004cfc7f  5e                   pop esi
// 004cfc80  c20400               ret 4
// library openrbx-raknet/ReliabilityLayer.cpp (function ?Release@?$MemoryPool@U?$Page@IPAUInternalPacket@@$0CA@@DataStructures@@@DataStructures@@QAEXPAU?$Page@IPAUInternalPacket@@$0CA@@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
