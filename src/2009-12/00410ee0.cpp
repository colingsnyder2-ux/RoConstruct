// from server: 100% by auto
// roc 2009-12 00410ee0  unit: CChildFrame  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00410ee0
//
// 00410ee0  80790400             cmp byte ptr [ecx + 4], 0
// 00410ee4  7430                 je 0x410f16
// 00410ee6  8b09                 mov ecx, dword ptr [ecx]
// 00410ee8  b800000080           mov eax, 0x80000000
// 00410eed  8bd1                 mov edx, ecx
// 00410eef  f00fc102             lock xadd dword ptr [edx], eax
// 00410ef3  a900000040           test eax, 0x40000000
// 00410ef8  751c                 jne 0x410f16
// 00410efa  3d00000080           cmp eax, 0x80000000
// 00410eff  7e15                 jle 0x410f16
// 00410f01  8bc1                 mov eax, ecx
// 00410f03  f00fba281e           lock bts dword ptr [eax], 0x1e
// 00410f08  720c                 jb 0x410f16
// 00410f0a  e8d1faffff           call 0x4109e0
// 00410f0f  50                   push eax
// 00410f10  ff1528b29800         call dword ptr [0x98b228]
// 00410f16  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??1?$unique_lock@Vmutex@boost@@@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
