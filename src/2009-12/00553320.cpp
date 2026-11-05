// from server: 100% by auto
// roc 2009-12 00553320  unit: RBX::Network::ClientReplicator  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00553320
//
// 00553320  8b442404             mov eax, dword ptr [esp + 4]
// 00553324  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00553328  8b00                 mov eax, dword ptr [eax]
// 0055332a  8b09                 mov ecx, dword ptr [ecx]
// 0055332c  3bc1                 cmp eax, ecx
// 0055332e  7304                 jae 0x553334
// 00553330  83c8ff               or eax, 0xffffffff
// 00553333  c3                   ret 
// 00553334  33d2                 xor edx, edx
// 00553336  3bc1                 cmp eax, ecx
// 00553338  0f95c2               setne dl
// 0055333b  8bc2                 mov eax, edx
// 0055333d  c3                   ret 
// library raknet-4.081/FileListTransfer.cpp (function ??$defaultMapKeyComparison@I@DataStructures@@YAHABI0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 FileListTransfer.cpp
