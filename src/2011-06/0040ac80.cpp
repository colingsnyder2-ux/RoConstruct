// from server: 100% by auto
// roc 2011-06 0040ac80  unit: RBX::Instance::ICombinedSignalData  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040ac80
//
// 0040ac80  80790400             cmp byte ptr [ecx + 4], 0
// 0040ac84  7430                 je 0x40acb6
// 0040ac86  8b09                 mov ecx, dword ptr [ecx]
// 0040ac88  b800000080           mov eax, 0x80000000
// 0040ac8d  8bd1                 mov edx, ecx
// 0040ac8f  f00fc102             lock xadd dword ptr [edx], eax
// 0040ac93  a900000040           test eax, 0x40000000
// 0040ac98  751c                 jne 0x40acb6
// 0040ac9a  3d00000080           cmp eax, 0x80000000
// 0040ac9f  7e15                 jle 0x40acb6
// 0040aca1  8bc1                 mov eax, ecx
// 0040aca3  f00fba281e           lock bts dword ptr [eax], 0x1e
// 0040aca8  720c                 jb 0x40acb6
// 0040acaa  e801f6ffff           call 0x40a2b0
// 0040acaf  50                   push eax
// 0040acb0  ff157403a400         call dword ptr [0xa40374]
// 0040acb6  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??1?$unique_lock@Vmutex@boost@@@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
