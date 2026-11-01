// from server: 100% by auto
// roc 2009-12 0063df50  unit: RBX::MD5HasherImpl  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0063df50
//
// 0063df50  6aff                 push -1
// 0063df52  68eba59400           push 0x94a5eb
// 0063df57  64a100000000         mov eax, dword ptr fs:[0]
// 0063df5d  50                   push eax
// 0063df5e  64892500000000       mov dword ptr fs:[0], esp
// 0063df65  51                   push ecx
// 0063df66  6a28                 push 0x28
// 0063df68  e8f3581b00           call 0x7f3860
// 0063df6d  83c404               add esp, 4
// 0063df70  890424               mov dword ptr [esp], eax
// 0063df73  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0063df7b  85c0                 test eax, eax
// 0063df7d  7416                 je 0x63df95
// 0063df7f  8bc8                 mov ecx, eax
// 0063df81  e8fafaffff           call 0x63da80
// 0063df86  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0063df8a  64890d00000000       mov dword ptr fs:[0], ecx
// 0063df91  83c410               add esp, 0x10
// 0063df94  c3                   ret 
// 0063df95  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0063df99  33c0                 xor eax, eax
// 0063df9b  64890d00000000       mov dword ptr fs:[0], ecx
// 0063dfa2  83c410               add esp, 0x10
// 0063dfa5  c3                   ret 
// library raknet-4.081/UDPProxyCoordinator.cpp (function ??$OP_NEW@VUDPProxyCoordinator@RakNet@@@RakNet@@YAPAVUDPProxyCoordinator@0@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 UDPProxyCoordinator.cpp
