// from server: 100% by auto
// roc 2009-12 0056b0f0  unit: RakPeer  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0056b0f0
//
// 0056b0f0  8a4104               mov al, byte ptr [ecx + 4]
// 0056b0f3  33c9                 xor ecx, ecx
// 0056b0f5  84c0                 test al, al
// 0056b0f7  0f94c1               sete cl
// 0056b0fa  8ac1                 mov al, cl
// 0056b0fc  c3                   ret 
// library rbx2016-raknet/RakPeer.cpp (function ?IsActive@RakPeer@RakNet@@UBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp
