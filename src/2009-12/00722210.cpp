// from server: 100% by auto
// roc 2009-12 00722210  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00722210
//
// 00722210  6a0c                 push 0xc
// 00722212  e849160d00           call 0x7f3860
// 00722217  83c404               add esp, 4
// 0072221a  85c0                 test eax, eax
// 0072221c  7402                 je 0x722220
// 0072221e  8900                 mov dword ptr [eax], eax
// 00722220  8d4804               lea ecx, [eax + 4]
// 00722223  85c9                 test ecx, ecx
// 00722225  7402                 je 0x722229
// 00722227  8901                 mov dword ptr [ecx], eax
// 00722229  c3                   ret 
// standard library list<ptr> (function ?_Buynode@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAU_Node@?$_List_nod@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
