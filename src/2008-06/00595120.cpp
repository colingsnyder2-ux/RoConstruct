// from server: 100% by auto
// roc 2008-06 00595120  unit: RBX::Lua::ThreadRef::VNode::?$sp_counted_impl_p  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00595120
//
// 00595120  8b4104               mov eax, dword ptr [ecx + 4]
// 00595123  8b542404             mov edx, dword ptr [esp + 4]
// 00595127  33c9                 xor ecx, ecx
// 00595129  3b4204               cmp eax, dword ptr [edx + 4]
// 0059512c  0f94c1               sete cl
// 0059512f  8ac1                 mov al, cl
// 00595131  c20400               ret 4
// standard library list<ptr> (function ??8?$_Const_iterator@$0A@@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE_NABV012@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
