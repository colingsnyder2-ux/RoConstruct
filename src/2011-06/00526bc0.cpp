// from server: 100% by tester
// roc 2007-03 004b39c0  unit: seg_004b0000  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004b39c0
//
// 004b39c0  8a4104               mov al, byte ptr [ecx + 4]
// 004b39c3  33c9                 xor ecx, ecx
// 004b39c5  84c0                 test al, al
// 004b39c7  0f94c1               sete cl
// 004b39ca  8ac1                 mov al, cl
// 004b39cc  c3                   ret 
// library rbx2016-raknet/RakPeer.cpp (function ?IsActive@RakPeer@RakNet@@UBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp
