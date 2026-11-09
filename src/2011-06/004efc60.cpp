// from server: 100% by auto
// roc 2011-06 004efc60  unit: RBX::Network::ConcurrentRakPeer::StatsUpdateJob  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004efc60
//
// 004efc60  d9442404             fld dword ptr [esp + 4]
// 004efc64  51                   push ecx
// 004efc65  d91c24               fstp dword ptr [esp]
// 004efc68  e833320500           call 0x542ea0
// 004efc6d  83c404               add esp, 4
// 004efc70  84c0                 test al, al
// 004efc72  7528                 jne 0x4efc9c
// 004efc74  e8b7310500           call 0x542e30
// 004efc79  d9442404             fld dword ptr [esp + 4]
// 004efc7d  d9c9                 fxch st(1)
// 004efc7f  dff1                 fcompi st(1)
// 004efc81  ddd8                 fstp st(0)
// 004efc83  7617                 jbe 0x4efc9c
// 004efc85  e8a6310500           call 0x542e30
// 004efc8a  d9e0                 fchs 
// 004efc8c  d9442404             fld dword ptr [esp + 4]
// 004efc90  dff1                 fcompi st(1)
// 004efc92  ddd8                 fstp st(0)
// 004efc94  7606                 jbe 0x4efc9c
// 004efc96  b801000000           mov eax, 1
// 004efc9b  c3                   ret 
// 004efc9c  33c0                 xor eax, eax
// 004efc9e  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?isFinite@G3D@@YA_NM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
