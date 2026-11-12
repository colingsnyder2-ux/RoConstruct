// from server: 100% by auto
// roc 2011-06 0052ef60  unit: RBX::Network::ProfiledRakPeer  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0052ef60
//
// 0052ef60  57                   push edi
// 0052ef61  8bf9                 mov edi, ecx
// 0052ef63  837f0400             cmp dword ptr [edi + 4], 0
// 0052ef67  750d                 jne 0x52ef76
// 0052ef69  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0052ef6d  c60000               mov byte ptr [eax], 0
// 0052ef70  33c0                 xor eax, eax
// 0052ef72  5f                   pop edi
// 0052ef73  c20c00               ret 0xc
// 0052ef76  8b4704               mov eax, dword ptr [edi + 4]
// 0052ef79  8b0f                 mov ecx, dword ptr [edi]
// 0052ef7b  53                   push ebx
// 0052ef7c  55                   push ebp
// 0052ef7d  8d68ff               lea ebp, [eax - 1]
// 0052ef80  99                   cdq 
// 0052ef81  2bc2                 sub eax, edx
// 0052ef83  8b542410             mov edx, dword ptr [esp + 0x10]
// 0052ef87  56                   push esi
// 0052ef88  8bf0                 mov esi, eax
// 0052ef8a  d1fe                 sar esi, 1
// 0052ef8c  8d04b1               lea eax, [ecx + esi*4]
// 0052ef8f  50                   push eax
// 0052ef90  52                   push edx
// 0052ef91  33db                 xor ebx, ebx
// 0052ef93  ff542424             call dword ptr [esp + 0x24]
// 0052ef97  83c408               add esp, 8
// 0052ef9a  85c0                 test eax, eax
// 0052ef9c  7431                 je 0x52efcf
// 0052ef9e  7d05                 jge 0x52efa5
// 0052efa0  8d6eff               lea ebp, [esi - 1]
// 0052efa3  eb03                 jmp 0x52efa8
// 0052efa5  8d5e01               lea ebx, [esi + 1]
// 0052efa8  8bc5                 mov eax, ebp
// 0052efaa  2bc3                 sub eax, ebx
// 0052efac  99                   cdq 
// 0052efad  2bc2                 sub eax, edx
// 0052efaf  8bf0                 mov esi, eax
// 0052efb1  d1fe                 sar esi, 1
// 0052efb3  03f3                 add esi, ebx
// 0052efb5  3bdd                 cmp ebx, ebp
// 0052efb7  7f26                 jg 0x52efdf
// 0052efb9  8b07                 mov eax, dword ptr [edi]
// 0052efbb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0052efbf  8d04b0               lea eax, [eax + esi*4]
// 0052efc2  50                   push eax
// 0052efc3  51                   push ecx
// 0052efc4  ff542424             call dword ptr [esp + 0x24]
// 0052efc8  83c408               add esp, 8
// 0052efcb  85c0                 test eax, eax
// 0052efcd  75cf                 jne 0x52ef9e
// 0052efcf  8b542418             mov edx, dword ptr [esp + 0x18]
// 0052efd3  8bc6                 mov eax, esi
// 0052efd5  5e                   pop esi
// 0052efd6  5d                   pop ebp
// 0052efd7  5b                   pop ebx
// 0052efd8  c60201               mov byte ptr [edx], 1
// 0052efdb  5f                   pop edi
// 0052efdc  c20c00               ret 0xc
// 0052efdf  8b442418             mov eax, dword ptr [esp + 0x18]
// 0052efe3  5e                   pop esi
// 0052efe4  5d                   pop ebp
// 0052efe5  c60000               mov byte ptr [eax], 0
// 0052efe8  8bc3                 mov eax, ebx
// 0052efea  5b                   pop ebx
// 0052efeb  5f                   pop edi
// 0052efec  c20c00               ret 0xc
// library openrbx-raknet/ReliabilityLayer.cpp (function ?GetIndexFromKey@?$OrderedList@IPAUInternalPacket@@$1?SplitPacketIndexComp@@YAHABIABQAU1@@Z@DataStructures@@QBEIABIPA_NP6AH0ABQAUInternalPacket@@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
