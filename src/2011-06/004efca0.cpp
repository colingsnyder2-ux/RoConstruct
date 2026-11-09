// from server: 100% by auto
// roc 2011-06 004efca0  unit: RBX::Network::ConcurrentRakPeer::StatsUpdateJob  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004efca0
//
// 004efca0  51                   push ecx
// 004efca1  56                   push esi
// 004efca2  8bf1                 mov esi, ecx
// 004efca4  d906                 fld dword ptr [esi]
// 004efca6  51                   push ecx
// 004efca7  d9542408             fst dword ptr [esp + 8]
// 004efcab  d91c24               fstp dword ptr [esp]
// 004efcae  e8ed310500           call 0x542ea0
// 004efcb3  83c404               add esp, 4
// 004efcb6  84c0                 test al, al
// 004efcb8  7576                 jne 0x4efd30
// 004efcba  e871310500           call 0x542e30
// 004efcbf  d9442404             fld dword ptr [esp + 4]
// 004efcc3  d9c9                 fxch st(1)
// 004efcc5  dff1                 fcompi st(1)
// 004efcc7  ddd8                 fstp st(0)
// 004efcc9  7665                 jbe 0x4efd30
// 004efccb  e860310500           call 0x542e30
// 004efcd0  d9e0                 fchs 
// 004efcd2  d9442404             fld dword ptr [esp + 4]
// 004efcd6  dff1                 fcompi st(1)
// 004efcd8  ddd8                 fstp st(0)
// 004efcda  7654                 jbe 0x4efd30
// 004efcdc  d94604               fld dword ptr [esi + 4]
// 004efcdf  51                   push ecx
// 004efce0  d9542408             fst dword ptr [esp + 8]
// 004efce4  d91c24               fstp dword ptr [esp]
// 004efce7  e8b4310500           call 0x542ea0
// 004efcec  83c404               add esp, 4
// 004efcef  84c0                 test al, al
// 004efcf1  753d                 jne 0x4efd30
// 004efcf3  e838310500           call 0x542e30
// 004efcf8  d9442404             fld dword ptr [esp + 4]
// 004efcfc  d9c9                 fxch st(1)
// 004efcfe  dff1                 fcompi st(1)
// 004efd00  ddd8                 fstp st(0)
// 004efd02  762c                 jbe 0x4efd30
// 004efd04  e827310500           call 0x542e30
// 004efd09  d9e0                 fchs 
// 004efd0b  d9442404             fld dword ptr [esp + 4]
// 004efd0f  dff1                 fcompi st(1)
// 004efd11  ddd8                 fstp st(0)
// 004efd13  761b                 jbe 0x4efd30
// 004efd15  d94608               fld dword ptr [esi + 8]
// 004efd18  51                   push ecx
// 004efd19  d91c24               fstp dword ptr [esp]
// 004efd1c  e83fffffff           call 0x4efc60
// 004efd21  83c404               add esp, 4
// 004efd24  84c0                 test al, al
// 004efd26  7408                 je 0x4efd30
// 004efd28  b801000000           mov eax, 1
// 004efd2d  5e                   pop esi
// 004efd2e  59                   pop ecx
// 004efd2f  c3                   ret 
// 004efd30  33c0                 xor eax, eax
// 004efd32  5e                   pop esi
// 004efd33  59                   pop ecx
// 004efd34  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?isFinite@Vector3@G3D@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
