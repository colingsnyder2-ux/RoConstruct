// from server: 100% by auto
// roc 2010-06 005d0f30  unit: RBX::VInstance::?$NonFactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005d0f30
//
// 005d0f30  6aff                 push -1
// 005d0f32  68f8689900           push 0x9968f8
// 005d0f37  64a100000000         mov eax, dword ptr fs:[0]
// 005d0f3d  50                   push eax
// 005d0f3e  64892500000000       mov dword ptr fs:[0], esp
// 005d0f45  83ec0c               sub esp, 0xc
// 005d0f48  56                   push esi
// 005d0f49  8bf1                 mov esi, ecx
// 005d0f4b  89742404             mov dword ptr [esp + 4], esi
// 005d0f4f  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d0f52  8b0e                 mov ecx, dword ptr [esi]
// 005d0f54  8b10                 mov edx, dword ptr [eax]
// 005d0f56  50                   push eax
// 005d0f57  51                   push ecx
// 005d0f58  52                   push edx
// 005d0f59  51                   push ecx
// 005d0f5a  8d442418             lea eax, [esp + 0x18]
// 005d0f5e  50                   push eax
// 005d0f5f  8bce                 mov ecx, esi
// 005d0f61  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005d0f69  e842e7ecff           call 0x49f6b0
// 005d0f6e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005d0f71  51                   push ecx
// 005d0f72  e8236a1d00           call 0x7a799a
// 005d0f77  8b16                 mov edx, dword ptr [esi]
// 005d0f79  52                   push edx
// 005d0f7a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005d0f81  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005d0f88  e80d6a1d00           call 0x7a799a
// 005d0f8d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005d0f91  83c408               add esp, 8
// 005d0f94  5e                   pop esi
// 005d0f95  64890d00000000       mov dword ptr fs:[0], ecx
// 005d0f9c  83c418               add esp, 0x18
// 005d0f9f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
