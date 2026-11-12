// from server: 100% by auto
// roc 2009-06 004f5480  unit: RBX::Network::ClientReplicator  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004f5480
//
// 004f5480  57                   push edi
// 004f5481  8bf9                 mov edi, ecx
// 004f5483  837f0400             cmp dword ptr [edi + 4], 0
// 004f5487  750d                 jne 0x4f5496
// 004f5489  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004f548d  c60000               mov byte ptr [eax], 0
// 004f5490  33c0                 xor eax, eax
// 004f5492  5f                   pop edi
// 004f5493  c20c00               ret 0xc
// 004f5496  8b4704               mov eax, dword ptr [edi + 4]
// 004f5499  8b0f                 mov ecx, dword ptr [edi]
// 004f549b  53                   push ebx
// 004f549c  55                   push ebp
// 004f549d  8d68ff               lea ebp, [eax - 1]
// 004f54a0  99                   cdq 
// 004f54a1  2bc2                 sub eax, edx
// 004f54a3  8b542410             mov edx, dword ptr [esp + 0x10]
// 004f54a7  56                   push esi
// 004f54a8  8bf0                 mov esi, eax
// 004f54aa  d1fe                 sar esi, 1
// 004f54ac  8d04b1               lea eax, [ecx + esi*4]
// 004f54af  50                   push eax
// 004f54b0  52                   push edx
// 004f54b1  33db                 xor ebx, ebx
// 004f54b3  ff542424             call dword ptr [esp + 0x24]
// 004f54b7  83c408               add esp, 8
// 004f54ba  85c0                 test eax, eax
// 004f54bc  7431                 je 0x4f54ef
// 004f54be  7d05                 jge 0x4f54c5
// 004f54c0  8d6eff               lea ebp, [esi - 1]
// 004f54c3  eb03                 jmp 0x4f54c8
// 004f54c5  8d5e01               lea ebx, [esi + 1]
// 004f54c8  8bc5                 mov eax, ebp
// 004f54ca  2bc3                 sub eax, ebx
// 004f54cc  99                   cdq 
// 004f54cd  2bc2                 sub eax, edx
// 004f54cf  8bf0                 mov esi, eax
// 004f54d1  d1fe                 sar esi, 1
// 004f54d3  03f3                 add esi, ebx
// 004f54d5  3bdd                 cmp ebx, ebp
// 004f54d7  7f26                 jg 0x4f54ff
// 004f54d9  8b07                 mov eax, dword ptr [edi]
// 004f54db  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004f54df  8d04b0               lea eax, [eax + esi*4]
// 004f54e2  50                   push eax
// 004f54e3  51                   push ecx
// 004f54e4  ff542424             call dword ptr [esp + 0x24]
// 004f54e8  83c408               add esp, 8
// 004f54eb  85c0                 test eax, eax
// 004f54ed  75cf                 jne 0x4f54be
// 004f54ef  8b542418             mov edx, dword ptr [esp + 0x18]
// 004f54f3  8bc6                 mov eax, esi
// 004f54f5  5e                   pop esi
// 004f54f6  5d                   pop ebp
// 004f54f7  5b                   pop ebx
// 004f54f8  c60201               mov byte ptr [edx], 1
// 004f54fb  5f                   pop edi
// 004f54fc  c20c00               ret 0xc
// 004f54ff  8b442418             mov eax, dword ptr [esp + 0x18]
// 004f5503  5e                   pop esi
// 004f5504  5d                   pop ebp
// 004f5505  c60000               mov byte ptr [eax], 0
// 004f5508  8bc3                 mov eax, ebx
// 004f550a  5b                   pop ebx
// 004f550b  5f                   pop edi
// 004f550c  c20c00               ret 0xc
// library openrbx-raknet/ReliabilityLayer.cpp (function ?GetIndexFromKey@?$OrderedList@IPAUInternalPacket@@$1?SplitPacketIndexComp@@YAHABIABQAU1@@Z@DataStructures@@QBEIABIPA_NP6AH0ABQAUInternalPacket@@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
