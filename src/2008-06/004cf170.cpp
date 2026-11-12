// from server: 100% by auto
// roc 2008-06 004cf170  unit: RBX::Network::PhysicsSender  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cf170
//
// 004cf170  57                   push edi
// 004cf171  8bf9                 mov edi, ecx
// 004cf173  837f0400             cmp dword ptr [edi + 4], 0
// 004cf177  750d                 jne 0x4cf186
// 004cf179  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004cf17d  c60000               mov byte ptr [eax], 0
// 004cf180  33c0                 xor eax, eax
// 004cf182  5f                   pop edi
// 004cf183  c20c00               ret 0xc
// 004cf186  8b4704               mov eax, dword ptr [edi + 4]
// 004cf189  8b0f                 mov ecx, dword ptr [edi]
// 004cf18b  53                   push ebx
// 004cf18c  55                   push ebp
// 004cf18d  8d68ff               lea ebp, [eax - 1]
// 004cf190  99                   cdq 
// 004cf191  2bc2                 sub eax, edx
// 004cf193  8b542410             mov edx, dword ptr [esp + 0x10]
// 004cf197  56                   push esi
// 004cf198  8bf0                 mov esi, eax
// 004cf19a  d1fe                 sar esi, 1
// 004cf19c  8d04b1               lea eax, [ecx + esi*4]
// 004cf19f  50                   push eax
// 004cf1a0  52                   push edx
// 004cf1a1  33db                 xor ebx, ebx
// 004cf1a3  ff542424             call dword ptr [esp + 0x24]
// 004cf1a7  83c408               add esp, 8
// 004cf1aa  85c0                 test eax, eax
// 004cf1ac  7431                 je 0x4cf1df
// 004cf1ae  7d05                 jge 0x4cf1b5
// 004cf1b0  8d6eff               lea ebp, [esi - 1]
// 004cf1b3  eb03                 jmp 0x4cf1b8
// 004cf1b5  8d5e01               lea ebx, [esi + 1]
// 004cf1b8  8bc5                 mov eax, ebp
// 004cf1ba  2bc3                 sub eax, ebx
// 004cf1bc  99                   cdq 
// 004cf1bd  2bc2                 sub eax, edx
// 004cf1bf  8bf0                 mov esi, eax
// 004cf1c1  d1fe                 sar esi, 1
// 004cf1c3  03f3                 add esi, ebx
// 004cf1c5  3bdd                 cmp ebx, ebp
// 004cf1c7  7f26                 jg 0x4cf1ef
// 004cf1c9  8b07                 mov eax, dword ptr [edi]
// 004cf1cb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004cf1cf  8d04b0               lea eax, [eax + esi*4]
// 004cf1d2  50                   push eax
// 004cf1d3  51                   push ecx
// 004cf1d4  ff542424             call dword ptr [esp + 0x24]
// 004cf1d8  83c408               add esp, 8
// 004cf1db  85c0                 test eax, eax
// 004cf1dd  75cf                 jne 0x4cf1ae
// 004cf1df  8b542418             mov edx, dword ptr [esp + 0x18]
// 004cf1e3  8bc6                 mov eax, esi
// 004cf1e5  5e                   pop esi
// 004cf1e6  5d                   pop ebp
// 004cf1e7  5b                   pop ebx
// 004cf1e8  c60201               mov byte ptr [edx], 1
// 004cf1eb  5f                   pop edi
// 004cf1ec  c20c00               ret 0xc
// 004cf1ef  8b442418             mov eax, dword ptr [esp + 0x18]
// 004cf1f3  5e                   pop esi
// 004cf1f4  5d                   pop ebp
// 004cf1f5  c60000               mov byte ptr [eax], 0
// 004cf1f8  8bc3                 mov eax, ebx
// 004cf1fa  5b                   pop ebx
// 004cf1fb  5f                   pop edi
// 004cf1fc  c20c00               ret 0xc
// library openrbx-raknet/ReliabilityLayer.cpp (function ?GetIndexFromKey@?$OrderedList@IPAUInternalPacket@@$1?SplitPacketIndexComp@@YAHABIABQAU1@@Z@DataStructures@@QBEIABIPA_NP6AH0ABQAUInternalPacket@@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
