// from server: 100% by auto
// roc 2009-06 005ddf30  unit: RBX::VInstance::?$NonFactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ddf30
//
// 005ddf30  6aff                 push -1
// 005ddf32  68485e8500           push 0x855e48
// 005ddf37  64a100000000         mov eax, dword ptr fs:[0]
// 005ddf3d  50                   push eax
// 005ddf3e  64892500000000       mov dword ptr fs:[0], esp
// 005ddf45  83ec0c               sub esp, 0xc
// 005ddf48  56                   push esi
// 005ddf49  8bf1                 mov esi, ecx
// 005ddf4b  89742404             mov dword ptr [esp + 4], esi
// 005ddf4f  8b4618               mov eax, dword ptr [esi + 0x18]
// 005ddf52  8b0e                 mov ecx, dword ptr [esi]
// 005ddf54  8b10                 mov edx, dword ptr [eax]
// 005ddf56  50                   push eax
// 005ddf57  51                   push ecx
// 005ddf58  52                   push edx
// 005ddf59  51                   push ecx
// 005ddf5a  8d442418             lea eax, [esp + 0x18]
// 005ddf5e  50                   push eax
// 005ddf5f  8bce                 mov ecx, esi
// 005ddf61  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005ddf69  e872f2ffff           call 0x5dd1e0
// 005ddf6e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005ddf71  51                   push ecx
// 005ddf72  e8bbaa1300           call 0x718a32
// 005ddf77  8b16                 mov edx, dword ptr [esi]
// 005ddf79  52                   push edx
// 005ddf7a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005ddf81  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005ddf88  e8a5aa1300           call 0x718a32
// 005ddf8d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005ddf91  83c408               add esp, 8
// 005ddf94  5e                   pop esi
// 005ddf95  64890d00000000       mov dword ptr fs:[0], ecx
// 005ddf9c  83c418               add esp, 0x18
// 005ddf9f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
