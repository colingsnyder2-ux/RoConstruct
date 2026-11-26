// from server: 100% by Xemicl
// roc 2012-06 00b11272  unit: seg_00b10000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11272
//
// 00b11272  ff15ac22b200         call dword ptr [0xb222ac]
// 00b11278  686e18b200           push 0xb2186e
// 00b1127d  c705f0a4e50040bbc200 mov dword ptr [0xe5a4f0], 0xc2bb40
// 00b11287  a3f4a4e500           mov dword ptr [0xe5a4f4], eax
// 00b1128c  c605f8a4e50000       mov byte ptr [0xe5a4f8], 0
// 00b11293  e85d1fe7ff           call 0x9831f5
// 00b11298  59                   pop ecx
// 00b11299  c3                   ret 
// copied from an identical function in another client (function ??__Eg_strheap@ATL@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlstr.obj