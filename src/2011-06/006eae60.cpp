// from server: 100% by auto
// roc 2011-06 006eae60  unit: VWiniInetRequest_source::?$stream_buffer  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006eae60
//
// 006eae60  8b09                 mov ecx, dword ptr [ecx]
// 006eae62  b800000080           mov eax, 0x80000000
// 006eae67  8bd1                 mov edx, ecx
// 006eae69  f00fc102             lock xadd dword ptr [edx], eax
// 006eae6d  a900000040           test eax, 0x40000000
// 006eae72  751c                 jne 0x6eae90
// 006eae74  3d00000080           cmp eax, 0x80000000
// 006eae79  7e15                 jle 0x6eae90
// 006eae7b  8bc1                 mov eax, ecx
// 006eae7d  f00fba281e           lock bts dword ptr [eax], 0x1e
// 006eae82  720c                 jb 0x6eae90
// 006eae84  e827f4d1ff           call 0x40a2b0
// 006eae89  50                   push eax
// 006eae8a  ff157403a400         call dword ptr [0xa40374]
// 006eae90  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??1?$lock_guard@Vmutex@boost@@@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
