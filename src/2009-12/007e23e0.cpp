// from server: 100% by auto
// roc 2009-12 007e23e0  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e23e0
//
// 007e23e0  8b09                 mov ecx, dword ptr [ecx]
// 007e23e2  b800000080           mov eax, 0x80000000
// 007e23e7  8bd1                 mov edx, ecx
// 007e23e9  f00fc102             lock xadd dword ptr [edx], eax
// 007e23ed  a900000040           test eax, 0x40000000
// 007e23f2  751c                 jne 0x7e2410
// 007e23f4  3d00000080           cmp eax, 0x80000000
// 007e23f9  7e15                 jle 0x7e2410
// 007e23fb  8bc1                 mov eax, ecx
// 007e23fd  f00fba281e           lock bts dword ptr [eax], 0x1e
// 007e2402  720c                 jb 0x7e2410
// 007e2404  e8d7e5c2ff           call 0x4109e0
// 007e2409  50                   push eax
// 007e240a  ff1528b29800         call dword ptr [0x98b228]
// 007e2410  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??1?$lock_guard@Vmutex@boost@@@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
