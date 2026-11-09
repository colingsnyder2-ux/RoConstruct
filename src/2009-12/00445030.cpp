// from server: 100% by auto
// roc 2009-12 00445030  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00445030
//
// 00445030  8b442408             mov eax, dword ptr [esp + 8]
// 00445034  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00445038  85c0                 test eax, eax
// 0044503a  7612                 jbe 0x44504e
// 0044503c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00445040  56                   push esi
// 00445041  8b32                 mov esi, dword ptr [edx]
// 00445043  8931                 mov dword ptr [ecx], esi
// 00445045  48                   dec eax
// 00445046  83c104               add ecx, 4
// 00445049  85c0                 test eax, eax
// 0044504b  77f4                 ja 0x445041
// 0044504d  5e                   pop esi
// 0044504e  c3                   ret 
// standard library vector<ptr> (function ??$_Fill_n@PAPAUT@@IPAU1@@std@@YAXPAPAUT@@IABQAU1@Urandom_access_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
