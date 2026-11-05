// from server: 100% by auto
// roc 2010-06 00795aa0  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00795aa0
//
// 00795aa0  8b09                 mov ecx, dword ptr [ecx]
// 00795aa2  b800000080           mov eax, 0x80000000
// 00795aa7  8bd1                 mov edx, ecx
// 00795aa9  f00fc102             lock xadd dword ptr [edx], eax
// 00795aad  a900000040           test eax, 0x40000000
// 00795ab2  751c                 jne 0x795ad0
// 00795ab4  3d00000080           cmp eax, 0x80000000
// 00795ab9  7e15                 jle 0x795ad0
// 00795abb  8bc1                 mov eax, ecx
// 00795abd  f00fba281e           lock bts dword ptr [eax], 0x1e
// 00795ac2  720c                 jb 0x795ad0
// 00795ac4  e8e7b1c7ff           call 0x410cb0
// 00795ac9  50                   push eax
// 00795aca  ff1598a39e00         call dword ptr [0x9ea398]
// 00795ad0  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??1?$lock_guard@Vmutex@boost@@@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
