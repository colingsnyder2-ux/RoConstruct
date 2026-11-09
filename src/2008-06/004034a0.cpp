// from server: 100% by auto
// roc 2008-06 004034a0  unit: VCWorkspace::?$CComAggObject  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004034a0
//
// 004034a0  8b442404             mov eax, dword ptr [esp + 4]
// 004034a4  6a00                 push 0
// 004034a6  50                   push eax
// 004034a7  e8a4d60100           call 0x420b50
// 004034ac  83c408               add esp, 8
// 004034af  c20400               ret 4
// standard library vector<ptr> (function ?allocate@?$allocator@PAUT@@@std@@QAEPAPAUT@@I@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
