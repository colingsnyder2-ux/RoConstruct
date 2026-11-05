// roc 2012-06 00ae9e80  unit: seg_00ae0000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00ae9e80
//
// 00ae9e80  6a00                 push 0
// 00ae9e82  b9d489e100           mov ecx, 0xe189d4
// 00ae9e87  ff154c26b200         call dword ptr [0xb2264c]
// 00ae9e8d  c3                   ret 
// copied from an identical function in another client (function ??__Eid@@YAXXZ)

// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /Ob0 /GS- /MD
#include <locale>
std::locale::id id;