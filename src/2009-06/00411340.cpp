// from server: 100% by auto
// roc 2009-06 00411340  unit: CChildFrame  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00411340
//
// 00411340  80790400             cmp byte ptr [ecx + 4], 0
// 00411344  7430                 je 0x411376
// 00411346  8b09                 mov ecx, dword ptr [ecx]
// 00411348  b800000080           mov eax, 0x80000000
// 0041134d  8bd1                 mov edx, ecx
// 0041134f  f00fc102             lock xadd dword ptr [edx], eax
// 00411353  a900000040           test eax, 0x40000000
// 00411358  751c                 jne 0x411376
// 0041135a  3d00000080           cmp eax, 0x80000000
// 0041135f  7e15                 jle 0x411376
// 00411361  8bc1                 mov eax, ecx
// 00411363  f00fba281e           lock bts dword ptr [eax], 0x1e
// 00411368  720c                 jb 0x411376
// 0041136a  e8f1f9ffff           call 0x410d60
// 0041136f  50                   push eax
// 00411370  ff15f0e18900         call dword ptr [0x89e1f0]
// 00411376  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??1?$unique_lock@Vmutex@boost@@@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
