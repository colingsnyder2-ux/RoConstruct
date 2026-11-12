// from server: 100% by auto
// roc 2010-06 00501ca0  unit: RBX::Network::ClientReplicator  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00501ca0
//
// 00501ca0  57                   push edi
// 00501ca1  8bf9                 mov edi, ecx
// 00501ca3  837f0400             cmp dword ptr [edi + 4], 0
// 00501ca7  750d                 jne 0x501cb6
// 00501ca9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00501cad  c60000               mov byte ptr [eax], 0
// 00501cb0  33c0                 xor eax, eax
// 00501cb2  5f                   pop edi
// 00501cb3  c20c00               ret 0xc
// 00501cb6  8b4704               mov eax, dword ptr [edi + 4]
// 00501cb9  8b0f                 mov ecx, dword ptr [edi]
// 00501cbb  53                   push ebx
// 00501cbc  55                   push ebp
// 00501cbd  8d68ff               lea ebp, [eax - 1]
// 00501cc0  99                   cdq 
// 00501cc1  2bc2                 sub eax, edx
// 00501cc3  8b542410             mov edx, dword ptr [esp + 0x10]
// 00501cc7  56                   push esi
// 00501cc8  8bf0                 mov esi, eax
// 00501cca  d1fe                 sar esi, 1
// 00501ccc  8d04b1               lea eax, [ecx + esi*4]
// 00501ccf  50                   push eax
// 00501cd0  52                   push edx
// 00501cd1  33db                 xor ebx, ebx
// 00501cd3  ff542424             call dword ptr [esp + 0x24]
// 00501cd7  83c408               add esp, 8
// 00501cda  85c0                 test eax, eax
// 00501cdc  7431                 je 0x501d0f
// 00501cde  7d05                 jge 0x501ce5
// 00501ce0  8d6eff               lea ebp, [esi - 1]
// 00501ce3  eb03                 jmp 0x501ce8
// 00501ce5  8d5e01               lea ebx, [esi + 1]
// 00501ce8  8bc5                 mov eax, ebp
// 00501cea  2bc3                 sub eax, ebx
// 00501cec  99                   cdq 
// 00501ced  2bc2                 sub eax, edx
// 00501cef  8bf0                 mov esi, eax
// 00501cf1  d1fe                 sar esi, 1
// 00501cf3  03f3                 add esi, ebx
// 00501cf5  3bdd                 cmp ebx, ebp
// 00501cf7  7f26                 jg 0x501d1f
// 00501cf9  8b07                 mov eax, dword ptr [edi]
// 00501cfb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00501cff  8d04b0               lea eax, [eax + esi*4]
// 00501d02  50                   push eax
// 00501d03  51                   push ecx
// 00501d04  ff542424             call dword ptr [esp + 0x24]
// 00501d08  83c408               add esp, 8
// 00501d0b  85c0                 test eax, eax
// 00501d0d  75cf                 jne 0x501cde
// 00501d0f  8b542418             mov edx, dword ptr [esp + 0x18]
// 00501d13  8bc6                 mov eax, esi
// 00501d15  5e                   pop esi
// 00501d16  5d                   pop ebp
// 00501d17  5b                   pop ebx
// 00501d18  c60201               mov byte ptr [edx], 1
// 00501d1b  5f                   pop edi
// 00501d1c  c20c00               ret 0xc
// 00501d1f  8b442418             mov eax, dword ptr [esp + 0x18]
// 00501d23  5e                   pop esi
// 00501d24  5d                   pop ebp
// 00501d25  c60000               mov byte ptr [eax], 0
// 00501d28  8bc3                 mov eax, ebx
// 00501d2a  5b                   pop ebx
// 00501d2b  5f                   pop edi
// 00501d2c  c20c00               ret 0xc
// library openrbx-raknet/ReliabilityLayer.cpp (function ?GetIndexFromKey@?$OrderedList@IPAUInternalPacket@@$1?SplitPacketIndexComp@@YAHABIABQAU1@@Z@DataStructures@@QBEIABIPA_NP6AH0ABQAUInternalPacket@@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
