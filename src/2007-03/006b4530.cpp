// from server: 100% by auto
// roc 2007-03 006b4530  unit: seg_006b0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b4530
//
// 006b4530  56                   push esi
// 006b4531  8bf1                 mov esi, ecx
// 006b4533  8d4e04               lea ecx, [esi + 4]
// 006b4536  e87fa1f6ff           call 0x61e6ba
// 006b453b  8bce                 mov ecx, esi
// 006b453d  5e                   pop esi
// 006b453e  e95dfeffff           jmp 0x6b43a0
// library raknet-4.081/FileList.cpp (function ??1FileListNode@RakNet@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: raknet-4.081 FileList.cpp
