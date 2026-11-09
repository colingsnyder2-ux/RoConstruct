// from server: 100% by auto
// roc 2012-06 0056b430  unit: RBX::Network::ConcurrentRakPeer::StatsUpdateJob  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0056b430
//
// 0056b430  51                   push ecx
// 0056b431  56                   push esi
// 0056b432  8bf1                 mov esi, ecx
// 0056b434  d906                 fld dword ptr [esi]
// 0056b436  51                   push ecx
// 0056b437  d9542408             fst dword ptr [esp + 8]
// 0056b43b  d91c24               fstp dword ptr [esp]
// 0056b43e  e8cd0c0c00           call 0x62c110
// 0056b443  83c404               add esp, 4
// 0056b446  84c0                 test al, al
// 0056b448  7576                 jne 0x56b4c0
// 0056b44a  e8510c0c00           call 0x62c0a0
// 0056b44f  d9442404             fld dword ptr [esp + 4]
// 0056b453  d9c9                 fxch st(1)
// 0056b455  dff1                 fcompi st(1)
// 0056b457  ddd8                 fstp st(0)
// 0056b459  7665                 jbe 0x56b4c0
// 0056b45b  e8400c0c00           call 0x62c0a0
// 0056b460  d9e0                 fchs 
// 0056b462  d9442404             fld dword ptr [esp + 4]
// 0056b466  dff1                 fcompi st(1)
// 0056b468  ddd8                 fstp st(0)
// 0056b46a  7654                 jbe 0x56b4c0
// 0056b46c  d94604               fld dword ptr [esi + 4]
// 0056b46f  51                   push ecx
// 0056b470  d9542408             fst dword ptr [esp + 8]
// 0056b474  d91c24               fstp dword ptr [esp]
// 0056b477  e8940c0c00           call 0x62c110
// 0056b47c  83c404               add esp, 4
// 0056b47f  84c0                 test al, al
// 0056b481  753d                 jne 0x56b4c0
// 0056b483  e8180c0c00           call 0x62c0a0
// 0056b488  d9442404             fld dword ptr [esp + 4]
// 0056b48c  d9c9                 fxch st(1)
// 0056b48e  dff1                 fcompi st(1)
// 0056b490  ddd8                 fstp st(0)
// 0056b492  762c                 jbe 0x56b4c0
// 0056b494  e8070c0c00           call 0x62c0a0
// 0056b499  d9e0                 fchs 
// 0056b49b  d9442404             fld dword ptr [esp + 4]
// 0056b49f  dff1                 fcompi st(1)
// 0056b4a1  ddd8                 fstp st(0)
// 0056b4a3  761b                 jbe 0x56b4c0
// 0056b4a5  d94608               fld dword ptr [esi + 8]
// 0056b4a8  51                   push ecx
// 0056b4a9  d91c24               fstp dword ptr [esp]
// 0056b4ac  e83fffffff           call 0x56b3f0
// 0056b4b1  83c404               add esp, 4
// 0056b4b4  84c0                 test al, al
// 0056b4b6  7408                 je 0x56b4c0
// 0056b4b8  b801000000           mov eax, 1
// 0056b4bd  5e                   pop esi
// 0056b4be  59                   pop ecx
// 0056b4bf  c3                   ret 
// 0056b4c0  33c0                 xor eax, eax
// 0056b4c2  5e                   pop esi
// 0056b4c3  59                   pop ecx
// 0056b4c4  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?isFinite@Vector3@G3D@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
