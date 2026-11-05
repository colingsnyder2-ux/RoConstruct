// from server: 100% by auto
// roc 2009-12 004ab170  unit: Ogre::RbxSceneUpdater  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ab170
//
// 004ab170  56                   push esi
// 004ab171  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004ab175  57                   push edi
// 004ab176  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004ab17a  8bc6                 mov eax, esi
// 004ab17c  8bcf                 mov ecx, edi
// 004ab17e  85f6                 test esi, esi
// 004ab180  7612                 jbe 0x4ab194
// 004ab182  8b542414             mov edx, dword ptr [esp + 0x14]
// 004ab186  53                   push ebx
// 004ab187  8b1a                 mov ebx, dword ptr [edx]
// 004ab189  8919                 mov dword ptr [ecx], ebx
// 004ab18b  48                   dec eax
// 004ab18c  83c104               add ecx, 4
// 004ab18f  85c0                 test eax, eax
// 004ab191  77f4                 ja 0x4ab187
// 004ab193  5b                   pop ebx
// 004ab194  8d04b7               lea eax, [edi + esi*4]
// 004ab197  5f                   pop edi
// 004ab198  5e                   pop esi
// 004ab199  c20c00               ret 0xc
// standard library vector<ptr> (function ?_Ufill@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAPAUT@@PAPAU3@IABQAU3@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
