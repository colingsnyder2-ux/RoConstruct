// from server: 100% by auto
// roc 2010-06 00641b60  unit: RBX::VInstance::?$NonFactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00641b60
//
// 00641b60  6aff                 push -1
// 00641b62  68b8d19b00           push 0x9bd1b8
// 00641b67  64a100000000         mov eax, dword ptr fs:[0]
// 00641b6d  50                   push eax
// 00641b6e  64892500000000       mov dword ptr fs:[0], esp
// 00641b75  83ec0c               sub esp, 0xc
// 00641b78  56                   push esi
// 00641b79  8bf1                 mov esi, ecx
// 00641b7b  89742404             mov dword ptr [esp + 4], esi
// 00641b7f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00641b82  8b0e                 mov ecx, dword ptr [esi]
// 00641b84  8b10                 mov edx, dword ptr [eax]
// 00641b86  50                   push eax
// 00641b87  51                   push ecx
// 00641b88  52                   push edx
// 00641b89  51                   push ecx
// 00641b8a  8d442418             lea eax, [esp + 0x18]
// 00641b8e  50                   push eax
// 00641b8f  8bce                 mov ecx, esi
// 00641b91  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00641b99  e892f8ffff           call 0x641430
// 00641b9e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00641ba1  51                   push ecx
// 00641ba2  e8f35d1600           call 0x7a799a
// 00641ba7  8b16                 mov edx, dword ptr [esi]
// 00641ba9  52                   push edx
// 00641baa  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00641bb1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00641bb8  e8dd5d1600           call 0x7a799a
// 00641bbd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00641bc1  83c408               add esp, 8
// 00641bc4  5e                   pop esi
// 00641bc5  64890d00000000       mov dword ptr fs:[0], ecx
// 00641bcc  83c418               add esp, 0x18
// 00641bcf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
