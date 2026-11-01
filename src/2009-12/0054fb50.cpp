// from server: 100% by auto
// roc 2009-12 0054fb50  unit: RBX::Network::IdSerializer  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0054fb50
//
// 0054fb50  53                   push ebx
// 0054fb51  56                   push esi
// 0054fb52  8bf1                 mov esi, ecx
// 0054fb54  33db                 xor ebx, ebx
// 0054fb56  885e14               mov byte ptr [esi + 0x14], bl
// 0054fb59  395e08               cmp dword ptr [esi + 8], ebx
// 0054fb5c  7439                 je 0x54fb97
// 0054fb5e  8b06                 mov eax, dword ptr [esi]
// 0054fb60  50                   push eax
// 0054fb61  e8a03f2a00           call 0x7f3b06
// 0054fb66  83c404               add esp, 4
// 0054fb69  895e08               mov dword ptr [esi + 8], ebx
// 0054fb6c  891e                 mov dword ptr [esi], ebx
// 0054fb6e  895e04               mov dword ptr [esi + 4], ebx
// 0054fb71  3bdb                 cmp ebx, ebx
// 0054fb73  7422                 je 0x54fb97
// 0054fb75  8bcb                 mov ecx, ebx
// 0054fb77  51                   push ecx
// 0054fb78  e8893f2a00           call 0x7f3b06
// 0054fb7d  83c404               add esp, 4
// 0054fb80  895e08               mov dword ptr [esi + 8], ebx
// 0054fb83  891e                 mov dword ptr [esi], ebx
// 0054fb85  895e04               mov dword ptr [esi + 4], ebx
// 0054fb88  3bdb                 cmp ebx, ebx
// 0054fb8a  760b                 jbe 0x54fb97
// 0054fb8c  8bd3                 mov edx, ebx
// 0054fb8e  52                   push edx
// 0054fb8f  e8723f2a00           call 0x7f3b06
// 0054fb94  83c404               add esp, 4
// 0054fb97  5e                   pop esi
// 0054fb98  5b                   pop ebx
// 0054fb99  c3                   ret 
// library raknet-4.081/FileListTransfer.cpp (function ??1?$Map@IUFLR_MemoryBlock@RakNet@@$1??$defaultMapKeyComparison@I@DataStructures@@YAHABI0@Z@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 FileListTransfer.cpp
