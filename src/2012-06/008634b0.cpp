// from server: 100% by auto
// roc 2012-06 008634b0  unit: VWiniInetRequest_source::?$stream_buffer  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008634b0
//
// 008634b0  8b09                 mov ecx, dword ptr [ecx]
// 008634b2  b800000080           mov eax, 0x80000000
// 008634b7  8bd1                 mov edx, ecx
// 008634b9  f00fc102             lock xadd dword ptr [edx], eax
// 008634bd  a900000040           test eax, 0x40000000
// 008634c2  751c                 jne 0x8634e0
// 008634c4  3d00000080           cmp eax, 0x80000000
// 008634c9  7e15                 jle 0x8634e0
// 008634cb  8bc1                 mov eax, ecx
// 008634cd  f00fba281e           lock bts dword ptr [eax], 0x1e
// 008634d2  720c                 jb 0x8634e0
// 008634d4  e8e784baff           call 0x40b9c0
// 008634d9  50                   push eax
// 008634da  ff150c23b200         call dword ptr [0xb2230c]
// 008634e0  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??1?$lock_guard@Vmutex@boost@@@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
