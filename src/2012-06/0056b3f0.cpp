// from server: 100% by auto
// roc 2012-06 0056b3f0  unit: RBX::Network::ConcurrentRakPeer::StatsUpdateJob  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0056b3f0
//
// 0056b3f0  d9442404             fld dword ptr [esp + 4]
// 0056b3f4  51                   push ecx
// 0056b3f5  d91c24               fstp dword ptr [esp]
// 0056b3f8  e8130d0c00           call 0x62c110
// 0056b3fd  83c404               add esp, 4
// 0056b400  84c0                 test al, al
// 0056b402  7528                 jne 0x56b42c
// 0056b404  e8970c0c00           call 0x62c0a0
// 0056b409  d9442404             fld dword ptr [esp + 4]
// 0056b40d  d9c9                 fxch st(1)
// 0056b40f  dff1                 fcompi st(1)
// 0056b411  ddd8                 fstp st(0)
// 0056b413  7617                 jbe 0x56b42c
// 0056b415  e8860c0c00           call 0x62c0a0
// 0056b41a  d9e0                 fchs 
// 0056b41c  d9442404             fld dword ptr [esp + 4]
// 0056b420  dff1                 fcompi st(1)
// 0056b422  ddd8                 fstp st(0)
// 0056b424  7606                 jbe 0x56b42c
// 0056b426  b801000000           mov eax, 1
// 0056b42b  c3                   ret 
// 0056b42c  33c0                 xor eax, eax
// 0056b42e  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?isFinite@G3D@@YA_NM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
