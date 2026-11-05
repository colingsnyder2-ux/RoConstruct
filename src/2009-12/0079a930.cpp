// from server: 100% by auto
// roc 2009-12 0079a930  unit: lua_exception  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a930
//
// 0079a930  80790600             cmp byte ptr [ecx + 6], 0
// 0079a934  742a                 je 0x79a960
// 0079a936  83c9ff               or ecx, 0xffffffff
// 0079a939  c7401074ab9e00       mov dword ptr [eax + 0x10], 0x9eab74
// 0079a940  89481c               mov dword ptr [eax + 0x1c], ecx
// 0079a943  894820               mov dword ptr [eax + 0x20], ecx
// 0079a946  8b4810               mov ecx, dword ptr [eax + 0x10]
// 0079a949  6a3c                 push 0x3c
// 0079a94b  c7400c70ab9e00       mov dword ptr [eax + 0xc], 0x9eab70
// 0079a952  51                   push ecx
// 0079a953  83c024               add eax, 0x24
// 0079a956  50                   push eax
// 0079a957  e844fcffff           call 0x79a5a0
// 0079a95c  83c40c               add esp, 0xc
// 0079a95f  c3                   ret 
// 0079a960  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0079a963  8b5220               mov edx, dword ptr [edx + 0x20]
// 0079a966  83c210               add edx, 0x10
// 0079a969  895010               mov dword ptr [eax + 0x10], edx
// 0079a96c  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0079a96f  8b523c               mov edx, dword ptr [edx + 0x3c]
// 0079a972  89501c               mov dword ptr [eax + 0x1c], edx
// 0079a975  83781c00             cmp dword ptr [eax + 0x1c], 0
// 0079a979  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 0079a97c  8b5140               mov edx, dword ptr [ecx + 0x40]
// 0079a97f  895020               mov dword ptr [eax + 0x20], edx
// 0079a982  b968ab9e00           mov ecx, 0x9eab68
// 0079a987  7405                 je 0x79a98e
// 0079a989  b944309d00           mov ecx, 0x9d3044
// 0079a98e  89480c               mov dword ptr [eax + 0xc], ecx
// 0079a991  8b4810               mov ecx, dword ptr [eax + 0x10]
// 0079a994  6a3c                 push 0x3c
// 0079a996  51                   push ecx
// 0079a997  83c024               add eax, 0x24
// 0079a99a  50                   push eax
// 0079a99b  e800fcffff           call 0x79a5a0
// 0079a9a0  83c40c               add esp, 0xc
// 0079a9a3  c3                   ret 
// library lua-5.1/ldebug.c (function _funcinfo)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
