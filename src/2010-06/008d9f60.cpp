// from server: 100% by auto
// roc 2010-06 008d9f60  unit: Ogre::TextureCompositor  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d9f60
//
// 008d9f60  6aff                 push -1
// 008d9f62  68b8d19b00           push 0x9bd1b8
// 008d9f67  64a100000000         mov eax, dword ptr fs:[0]
// 008d9f6d  50                   push eax
// 008d9f6e  64892500000000       mov dword ptr fs:[0], esp
// 008d9f75  83ec0c               sub esp, 0xc
// 008d9f78  56                   push esi
// 008d9f79  8bf1                 mov esi, ecx
// 008d9f7b  89742404             mov dword ptr [esp + 4], esi
// 008d9f7f  8b4618               mov eax, dword ptr [esi + 0x18]
// 008d9f82  8b0e                 mov ecx, dword ptr [esi]
// 008d9f84  8b10                 mov edx, dword ptr [eax]
// 008d9f86  50                   push eax
// 008d9f87  51                   push ecx
// 008d9f88  52                   push edx
// 008d9f89  51                   push ecx
// 008d9f8a  8d442418             lea eax, [esp + 0x18]
// 008d9f8e  50                   push eax
// 008d9f8f  8bce                 mov ecx, esi
// 008d9f91  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 008d9f99  e822fcffff           call 0x8d9bc0
// 008d9f9e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 008d9fa1  51                   push ecx
// 008d9fa2  e8f3d9ecff           call 0x7a799a
// 008d9fa7  8b16                 mov edx, dword ptr [esi]
// 008d9fa9  52                   push edx
// 008d9faa  c7461800000000       mov dword ptr [esi + 0x18], 0
// 008d9fb1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 008d9fb8  e8ddd9ecff           call 0x7a799a
// 008d9fbd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008d9fc1  83c408               add esp, 8
// 008d9fc4  5e                   pop esi
// 008d9fc5  64890d00000000       mov dword ptr fs:[0], ecx
// 008d9fcc  83c418               add esp, 0x18
// 008d9fcf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
