// from server: 100% by auto
// roc 2009-12 0088de30  unit: CXTPCommandBarAnimation::PAUCAnimateInfo::?$CArray  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088de30
//
// 0088de30  56                   push esi
// 0088de31  8bf1                 mov esi, ecx
// 0088de33  8d4e04               lea ecx, [esi + 4]
// 0088de36  e8e35ff6ff           call 0x7f3e1e
// 0088de3b  8bce                 mov ecx, esi
// 0088de3d  5e                   pop esi
// 0088de3e  e96dffffff           jmp 0x88ddb0
// library raknet-4.081/FileList.cpp (function ??1FileListNode@RakNet@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: raknet-4.081 FileList.cpp
