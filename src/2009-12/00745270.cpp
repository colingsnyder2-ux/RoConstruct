// from server: 100% by auto
// roc 2009-12 00745270  unit: RBX::P8ModelInstance::?$GetSetImpl  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00745270
//
// 00745270  6a0c                 push 0xc
// 00745272  e8e9e50a00           call 0x7f3860
// 00745277  83c404               add esp, 4
// 0074527a  85c0                 test eax, eax
// 0074527c  7406                 je 0x745284
// 0074527e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00745282  8908                 mov dword ptr [eax], ecx
// 00745284  8d4804               lea ecx, [eax + 4]
// 00745287  85c9                 test ecx, ecx
// 00745289  7406                 je 0x745291
// 0074528b  8b542408             mov edx, dword ptr [esp + 8]
// 0074528f  8911                 mov dword ptr [ecx], edx
// 00745291  8d4808               lea ecx, [eax + 8]
// 00745294  85c9                 test ecx, ecx
// 00745296  7408                 je 0x7452a0
// 00745298  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0074529c  8b12                 mov edx, dword ptr [edx]
// 0074529e  8911                 mov dword ptr [ecx], edx
// 007452a0  c20c00               ret 0xc
// standard library list<ptr> (function ?_Buynode@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAU_Node@?$_List_nod@PAUT@@V?$allocator@PAUT@@@std@@@2@PAU342@0ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
