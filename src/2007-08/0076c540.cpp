// from server: 100% by colin
// roc 2007-08 0076c540  unit: seg_00760000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076c540
//
// 0076c540  6a00                 push 0
// 0076c542  b924ae8b00           mov ecx, 0x8bae24
// 0076c547  ff15a0e67700         call dword ptr [0x77e6a0]
// 0076c54d  c3                   ret 
// copied from an identical function in another client (function ??__Eid@@YAXXZ)

// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /Ob0 /GS- /MD
#include <locale>
std::locale::id id;