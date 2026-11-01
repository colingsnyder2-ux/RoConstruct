// from server: 100% by auto
// roc 2009-12 0054fd30  unit: RBX::Network::IdSerializer  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0054fd30
//
// 0054fd30  6aff                 push -1
// 0054fd32  68eba59400           push 0x94a5eb
// 0054fd37  64a100000000         mov eax, dword ptr fs:[0]
// 0054fd3d  50                   push eax
// 0054fd3e  64892500000000       mov dword ptr fs:[0], esp
// 0054fd45  51                   push ecx
// 0054fd46  6a18                 push 0x18
// 0054fd48  e8133b2a00           call 0x7f3860
// 0054fd4d  83c404               add esp, 4
// 0054fd50  890424               mov dword ptr [esp], eax
// 0054fd53  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0054fd5b  85c0                 test eax, eax
// 0054fd5d  7416                 je 0x54fd75
// 0054fd5f  8bc8                 mov ecx, eax
// 0054fd61  e8aafeffff           call 0x54fc10
// 0054fd66  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0054fd6a  64890d00000000       mov dword ptr fs:[0], ecx
// 0054fd71  83c410               add esp, 0x10
// 0054fd74  c3                   ret 
// 0054fd75  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0054fd79  33c0                 xor eax, eax
// 0054fd7b  64890d00000000       mov dword ptr fs:[0], ecx
// 0054fd82  83c410               add esp, 0x10
// 0054fd85  c3                   ret 
// library raknet-4.081/DirectoryDeltaTransfer.cpp (function ??$OP_NEW@VFileList@RakNet@@@RakNet@@YAPAVFileList@0@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 DirectoryDeltaTransfer.cpp
