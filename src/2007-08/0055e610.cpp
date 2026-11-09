// from server: 100% by auto
// roc 2007-08 0055e610  unit: RBX::FixedCameraCommand  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055e610
//
// 0055e610  8b5104               mov edx, dword ptr [ecx + 4]
// 0055e613  85d2                 test edx, edx
// 0055e615  7503                 jne 0x55e61a
// 0055e617  33c0                 xor eax, eax
// 0055e619  c3                   ret 
// 0055e61a  8b4108               mov eax, dword ptr [ecx + 8]
// 0055e61d  2bc2                 sub eax, edx
// 0055e61f  c1f802               sar eax, 2
// 0055e622  c3                   ret 
// standard library vector<ptr> (function ?size@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEIXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
