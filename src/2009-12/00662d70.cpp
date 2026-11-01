// from server: 100% by auto
// roc 2009-12 00662d70  unit: RBX::Reflection::EnumDescriptor  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00662d70
//
// 00662d70  8b442408             mov eax, dword ptr [esp + 8]
// 00662d74  8b542404             mov edx, dword ptr [esp + 4]
// 00662d78  2bc2                 sub eax, edx
// 00662d7a  c1f802               sar eax, 2
// 00662d7d  56                   push esi
// 00662d7e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00662d82  8d0c8500000000       lea ecx, [eax*4]
// 00662d89  2bf1                 sub esi, ecx
// 00662d8b  85c0                 test eax, eax
// 00662d8d  7e0d                 jle 0x662d9c
// 00662d8f  51                   push ecx
// 00662d90  52                   push edx
// 00662d91  51                   push ecx
// 00662d92  56                   push esi
// 00662d93  ff15c0b79800         call dword ptr [0x98b7c0]
// 00662d99  83c410               add esp, 0x10
// 00662d9c  8bc6                 mov eax, esi
// 00662d9e  5e                   pop esi
// 00662d9f  c3                   ret 
// standard library vector<ptr> (function ??$_Copy_backward_opt@PAPAUT@@PAPAU1@Urandom_access_iterator_tag@std@@@std@@YAPAPAUT@@PAPAU1@00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
