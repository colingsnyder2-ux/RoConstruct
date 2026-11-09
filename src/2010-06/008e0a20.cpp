// from server: 100% by auto
// roc 2010-06 008e0a20  unit: Ogre::RbxMaterialAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e0a20
//
// 008e0a20  56                   push esi
// 008e0a21  8b74240c             mov esi, dword ptr [esp + 0xc]
// 008e0a25  57                   push edi
// 008e0a26  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008e0a2a  8bc6                 mov eax, esi
// 008e0a2c  8bcf                 mov ecx, edi
// 008e0a2e  85f6                 test esi, esi
// 008e0a30  7612                 jbe 0x8e0a44
// 008e0a32  8b542414             mov edx, dword ptr [esp + 0x14]
// 008e0a36  53                   push ebx
// 008e0a37  8b1a                 mov ebx, dword ptr [edx]
// 008e0a39  8919                 mov dword ptr [ecx], ebx
// 008e0a3b  48                   dec eax
// 008e0a3c  83c104               add ecx, 4
// 008e0a3f  85c0                 test eax, eax
// 008e0a41  77f4                 ja 0x8e0a37
// 008e0a43  5b                   pop ebx
// 008e0a44  8d04b7               lea eax, [edi + esi*4]
// 008e0a47  5f                   pop edi
// 008e0a48  5e                   pop esi
// 008e0a49  c20c00               ret 0xc
// standard library vector<ptr> (function ?_Ufill@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAPAUT@@PAPAU3@IABQAU3@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
