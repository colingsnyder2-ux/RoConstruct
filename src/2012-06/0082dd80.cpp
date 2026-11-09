// from server: 100% by auto
// roc 2012-06 0082dd80  unit: RBX::BallBlockContact  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0082dd80
//
// 0082dd80  8b442404             mov eax, dword ptr [esp + 4]
// 0082dd84  6a00                 push 0
// 0082dd86  50                   push eax
// 0082dd87  e8f4f9ffff           call 0x82d780
// 0082dd8c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
