// from server: 100% by auto
// roc 2012-06 0040c3d0  unit: RBX::Instance::ICombinedSignalData  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040c3d0
//
// 0040c3d0  80790400             cmp byte ptr [ecx + 4], 0
// 0040c3d4  7430                 je 0x40c406
// 0040c3d6  8b09                 mov ecx, dword ptr [ecx]
// 0040c3d8  b800000080           mov eax, 0x80000000
// 0040c3dd  8bd1                 mov edx, ecx
// 0040c3df  f00fc102             lock xadd dword ptr [edx], eax
// 0040c3e3  a900000040           test eax, 0x40000000
// 0040c3e8  751c                 jne 0x40c406
// 0040c3ea  3d00000080           cmp eax, 0x80000000
// 0040c3ef  7e15                 jle 0x40c406
// 0040c3f1  8bc1                 mov eax, ecx
// 0040c3f3  f00fba281e           lock bts dword ptr [eax], 0x1e
// 0040c3f8  720c                 jb 0x40c406
// 0040c3fa  e8c1f5ffff           call 0x40b9c0
// 0040c3ff  50                   push eax
// 0040c400  ff150c23b200         call dword ptr [0xb2230c]
// 0040c406  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??1?$unique_lock@Vmutex@boost@@@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
