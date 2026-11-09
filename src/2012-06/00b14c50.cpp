// from server: 100% by auto
// roc 2012-06 00b14c50  unit: seg_00b10000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14c50
//
// 00b14c50  a14487e200           mov eax, dword ptr [0xe28744]
// 00b14c55  50                   push eax
// 00b14c56  c7053c87e200643bb800 mov dword ptr [0xe2873c], 0xb83b64
// 00b14c60  e855d7e6ff           call 0x9823ba
// 00b14c65  83c404               add esp, 4
// 00b14c68  c7054487e20000000000 mov dword ptr [0xe28744], 0
// 00b14c72  c3                   ret 
// library rbx2016-g3d/Random.cpp (function ??__Fr@?1??common@Random@G3D@@SAAAV12@XZ@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d Random.cpp
