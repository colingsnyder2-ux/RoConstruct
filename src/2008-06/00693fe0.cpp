// from server: 100% by auto
// roc 2008-06 00693fe0  unit: Ogre::RbxSceneManager  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00693fe0
//
// 00693fe0  8b442410             mov eax, dword ptr [esp + 0x10]
// 00693fe4  8b542408             mov edx, dword ptr [esp + 8]
// 00693fe8  2bc2                 sub eax, edx
// 00693fea  56                   push esi
// 00693feb  c1f802               sar eax, 2
// 00693fee  57                   push edi
// 00693fef  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00693ff3  8d0c8500000000       lea ecx, [eax*4]
// 00693ffa  8d3439               lea esi, [ecx + edi]
// 00693ffd  85c0                 test eax, eax
// 00693fff  760d                 jbe 0x69400e
// 00694001  51                   push ecx
// 00694002  52                   push edx
// 00694003  51                   push ecx
// 00694004  57                   push edi
// 00694005  ff1550288000         call dword ptr [0x802850]
// 0069400b  83c410               add esp, 0x10
// 0069400e  5f                   pop edi
// 0069400f  8bc6                 mov eax, esi
// 00694011  5e                   pop esi
// 00694012  c21400               ret 0x14
// standard library vector<ptr> (function ??$_Ucopy@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAPAUT@@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@1@0PAPAU2@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
