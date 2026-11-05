// from server: 100% by auto
// roc 2009-12 00410f20  unit: CChildFrame  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00410f20
//
// 00410f20  8b442408             mov eax, dword ptr [esp + 8]
// 00410f24  83f804               cmp eax, 4
// 00410f27  774f                 ja 0x410f78
// 00410f29  ff24858c0f4100       jmp dword ptr [eax*4 + 0x410f8c]
// 00410f30  8b442404             mov eax, dword ptr [esp + 4]
// 00410f34  c70000000000         mov dword ptr [eax], 0
// 00410f3a  c7400400000080       mov dword ptr [eax + 4], 0x80000000
// 00410f41  c3                   ret 
// 00410f42  8b442404             mov eax, dword ptr [esp + 4]
// 00410f46  c700ffffffff         mov dword ptr [eax], 0xffffffff
// 00410f4c  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 00410f53  c3                   ret 
// 00410f54  8b442404             mov eax, dword ptr [esp + 4]
// 00410f58  c700fdffffff         mov dword ptr [eax], 0xfffffffd
// 00410f5e  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 00410f65  c3                   ret 
// 00410f66  8b442404             mov eax, dword ptr [esp + 4]
// 00410f6a  c70001000000         mov dword ptr [eax], 1
// 00410f70  c7400400000080       mov dword ptr [eax + 4], 0x80000000
// 00410f77  c3                   ret 
// 00410f78  8b442404             mov eax, dword ptr [esp + 4]
// 00410f7c  c700feffffff         mov dword ptr [eax], 0xfffffffe
// 00410f82  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 00410f89  c3                   ret 
// 00410f8a  8bff                 mov edi, edi
// 00410f8c  780f                 js 0x410f9d
// 00410f8e  41                   inc ecx
// 00410f8f  0030                 add byte ptr [eax], dh
// 00410f91  0f4100               cmovno eax, dword ptr [eax]
// 00410f94  42                   inc edx
// 00410f95  0f4100               cmovno eax, dword ptr [eax]
// 00410f98  660f4100             cmovno ax, word ptr [eax]
// 00410f9c  54                   push esp
// 00410f9d  0f4100               cmovno eax, dword ptr [eax]
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?from_special@?$int_adapter@_J@date_time@boost@@SA?AV123@W4special_values@23@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
