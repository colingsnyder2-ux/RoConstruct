// from server: 100% by auto
// roc 2009-12 00554e60  unit: RBX::Network::ClientReplicator  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00554e60
//
// 00554e60  8b4104               mov eax, dword ptr [ecx + 4]
// 00554e63  8b542404             mov edx, dword ptr [esp + 4]
// 00554e67  3bd0                 cmp edx, eax
// 00554e69  7324                 jae 0x554e8f
// 00554e6b  48                   dec eax
// 00554e6c  3bd0                 cmp edx, eax
// 00554e6e  731c                 jae 0x554e8c
// 00554e70  56                   push esi
// 00554e71  8b01                 mov eax, dword ptr [ecx]
// 00554e73  8b74d008             mov esi, dword ptr [eax + edx*8 + 8]
// 00554e77  8d04d0               lea eax, [eax + edx*8]
// 00554e7a  8930                 mov dword ptr [eax], esi
// 00554e7c  8b700c               mov esi, dword ptr [eax + 0xc]
// 00554e7f  897004               mov dword ptr [eax + 4], esi
// 00554e82  8b4104               mov eax, dword ptr [ecx + 4]
// 00554e85  42                   inc edx
// 00554e86  48                   dec eax
// 00554e87  3bd0                 cmp edx, eax
// 00554e89  72e6                 jb 0x554e71
// 00554e8b  5e                   pop esi
// 00554e8c  ff4904               dec dword ptr [ecx + 4]
// 00554e8f  c20400               ret 4
// library raknet-4.081/FileListTransfer.cpp (function ?RemoveAtIndex@?$List@UMapNode@?$Map@IUFLR_MemoryBlock@RakNet@@$1??$defaultMapKeyComparison@I@DataStructures@@YAHABI0@Z@DataStructures@@@DataStructures@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 FileListTransfer.cpp
