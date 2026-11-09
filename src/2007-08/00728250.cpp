// from server: 100% by auto
// roc 2007-08 00728250  unit: boost::signals::detail::Vsignal_base_impl::?$sp_counted_impl_p  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00728250
//
// 00728250  8b4104               mov eax, dword ptr [ecx + 4]
// 00728253  8b542404             mov edx, dword ptr [esp + 4]
// 00728257  33c9                 xor ecx, ecx
// 00728259  3b4204               cmp eax, dword ptr [edx + 4]
// 0072825c  0f94c1               sete cl
// 0072825f  8ac1                 mov al, cl
// 00728261  c20400               ret 4
// standard library list<ptr> (function ??8?$_Const_iterator@$0A@@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE_NABV012@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
