// from server: 100% by auto
// roc 2009-12 00980ad0  unit: seg_00980000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00980ad0
//
// 00980ad0  833d941ab80000       cmp dword ptr [0xb81a94], 0
// 00980ad7  760c                 jbe 0x980ae5
// 00980ad9  a18c1ab800           mov eax, dword ptr [0xb81a8c]
// 00980ade  50                   push eax
// 00980adf  e82230e7ff           call 0x7f3b06
// 00980ae4  59                   pop ecx
// 00980ae5  c3                   ret 
// library raknet-4.081/RakString.cpp (function ??__F?freeList@RakString@RakNet@@2V?$List@PAUSharedString@RakString@RakNet@@@DataStructures@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 RakString.cpp
