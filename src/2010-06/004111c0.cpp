// from server: 100% by auto
// roc 2010-06 004111c0  unit: CChildFrame  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004111c0
//
// 004111c0  80790400             cmp byte ptr [ecx + 4], 0
// 004111c4  7430                 je 0x4111f6
// 004111c6  8b09                 mov ecx, dword ptr [ecx]
// 004111c8  b800000080           mov eax, 0x80000000
// 004111cd  8bd1                 mov edx, ecx
// 004111cf  f00fc102             lock xadd dword ptr [edx], eax
// 004111d3  a900000040           test eax, 0x40000000
// 004111d8  751c                 jne 0x4111f6
// 004111da  3d00000080           cmp eax, 0x80000000
// 004111df  7e15                 jle 0x4111f6
// 004111e1  8bc1                 mov eax, ecx
// 004111e3  f00fba281e           lock bts dword ptr [eax], 0x1e
// 004111e8  720c                 jb 0x4111f6
// 004111ea  e8c1faffff           call 0x410cb0
// 004111ef  50                   push eax
// 004111f0  ff1598a39e00         call dword ptr [0x9ea398]
// 004111f6  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??1?$unique_lock@Vmutex@boost@@@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
