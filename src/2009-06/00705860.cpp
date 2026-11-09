// from server: 100% by auto
// roc 2009-06 00705860  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00705860
//
// 00705860  8b09                 mov ecx, dword ptr [ecx]
// 00705862  b800000080           mov eax, 0x80000000
// 00705867  8bd1                 mov edx, ecx
// 00705869  f00fc102             lock xadd dword ptr [edx], eax
// 0070586d  a900000040           test eax, 0x40000000
// 00705872  751c                 jne 0x705890
// 00705874  3d00000080           cmp eax, 0x80000000
// 00705879  7e15                 jle 0x705890
// 0070587b  8bc1                 mov eax, ecx
// 0070587d  f00fba281e           lock bts dword ptr [eax], 0x1e
// 00705882  720c                 jb 0x705890
// 00705884  e8d7b4d0ff           call 0x410d60
// 00705889  50                   push eax
// 0070588a  ff15f0e18900         call dword ptr [0x89e1f0]
// 00705890  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??1?$lock_guard@Vmutex@boost@@@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
