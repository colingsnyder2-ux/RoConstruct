// from server: 100% by auto
// roc 2009-06 0051ed50  unit: RBX::VBlockMesh::?$FactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0051ed50
//
// 0051ed50  6aff                 push -1
// 0051ed52  68485e8500           push 0x855e48
// 0051ed57  64a100000000         mov eax, dword ptr fs:[0]
// 0051ed5d  50                   push eax
// 0051ed5e  64892500000000       mov dword ptr fs:[0], esp
// 0051ed65  83ec0c               sub esp, 0xc
// 0051ed68  56                   push esi
// 0051ed69  8bf1                 mov esi, ecx
// 0051ed6b  89742404             mov dword ptr [esp + 4], esi
// 0051ed6f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051ed72  8b0e                 mov ecx, dword ptr [esi]
// 0051ed74  8b10                 mov edx, dword ptr [eax]
// 0051ed76  50                   push eax
// 0051ed77  51                   push ecx
// 0051ed78  52                   push edx
// 0051ed79  51                   push ecx
// 0051ed7a  8d442418             lea eax, [esp + 0x18]
// 0051ed7e  50                   push eax
// 0051ed7f  8bce                 mov ecx, esi
// 0051ed81  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0051ed89  e8a2e1ffff           call 0x51cf30
// 0051ed8e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0051ed91  51                   push ecx
// 0051ed92  e89b9c1f00           call 0x718a32
// 0051ed97  8b16                 mov edx, dword ptr [esi]
// 0051ed99  52                   push edx
// 0051ed9a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0051eda1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0051eda8  e8859c1f00           call 0x718a32
// 0051edad  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0051edb1  83c408               add esp, 8
// 0051edb4  5e                   pop esi
// 0051edb5  64890d00000000       mov dword ptr fs:[0], ecx
// 0051edbc  83c418               add esp, 0x18
// 0051edbf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
