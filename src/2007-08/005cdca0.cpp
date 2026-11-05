// from server: 100% by auto
// roc 2007-08 005cdca0  unit: RBX::BlockBlockContact  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005cdca0
//
// 005cdca0  55                   push ebp
// 005cdca1  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005cdca5  85ed                 test ebp, ebp
// 005cdca7  56                   push esi
// 005cdca8  57                   push edi
// 005cdca9  8bf9                 mov edi, ecx
// 005cdcab  7406                 je 0x5cdcb3
// 005cdcad  3b6c241c             cmp ebp, dword ptr [esp + 0x1c]
// 005cdcb1  7406                 je 0x5cdcb9
// 005cdcb3  ff15d8e67700         call dword ptr [0x77e6d8]
// 005cdcb9  8b742418             mov esi, dword ptr [esp + 0x18]
// 005cdcbd  8b542420             mov edx, dword ptr [esp + 0x20]
// 005cdcc1  3bf2                 cmp esi, edx
// 005cdcc3  7428                 je 0x5cdced
// 005cdcc5  8b4708               mov eax, dword ptr [edi + 8]
// 005cdcc8  2bc2                 sub eax, edx
// 005cdcca  c1f802               sar eax, 2
// 005cdccd  85c0                 test eax, eax
// 005cdccf  8d0c8500000000       lea ecx, [eax*4]
// 005cdcd6  53                   push ebx
// 005cdcd7  8d1c31               lea ebx, [ecx + esi]
// 005cdcda  7e0d                 jle 0x5cdce9
// 005cdcdc  51                   push ecx
// 005cdcdd  52                   push edx
// 005cdcde  51                   push ecx
// 005cdcdf  56                   push esi
// 005cdce0  ff1548e77700         call dword ptr [0x77e748]
// 005cdce6  83c410               add esp, 0x10
// 005cdce9  895f08               mov dword ptr [edi + 8], ebx
// 005cdcec  5b                   pop ebx
// 005cdced  8b442410             mov eax, dword ptr [esp + 0x10]
// 005cdcf1  5f                   pop edi
// 005cdcf2  897004               mov dword ptr [eax + 4], esi
// 005cdcf5  5e                   pop esi
// 005cdcf6  8928                 mov dword ptr [eax], ebp
// 005cdcf8  5d                   pop ebp
// 005cdcf9  c21400               ret 0x14
// standard library vector<ptr> (function ?erase@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V32@0@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
