// roc 2012-06 00ae9590  unit: seg_00ae0000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00ae9590
//
// 00ae9590  6a00                 push 0
// 00ae9592  b98463e100           mov ecx, 0xe16384
// 00ae9597  ff154c26b200         call dword ptr [0xb2264c]
// 00ae959d  c3                   ret 
// copied from an identical function in another client (function ??__Eid@@YAXXZ)

// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /Ob0 /GS- /MD
#include <locale>
std::locale::id id;