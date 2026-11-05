// from server: 100% by auto
// roc 2010-06 00468fa0  unit: RBX::VInstance::?$NonFactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00468fa0
//
// 00468fa0  6aff                 push -1
// 00468fa2  68b8d19b00           push 0x9bd1b8
// 00468fa7  64a100000000         mov eax, dword ptr fs:[0]
// 00468fad  50                   push eax
// 00468fae  64892500000000       mov dword ptr fs:[0], esp
// 00468fb5  83ec0c               sub esp, 0xc
// 00468fb8  56                   push esi
// 00468fb9  8bf1                 mov esi, ecx
// 00468fbb  89742404             mov dword ptr [esp + 4], esi
// 00468fbf  8b4618               mov eax, dword ptr [esi + 0x18]
// 00468fc2  8b0e                 mov ecx, dword ptr [esi]
// 00468fc4  8b10                 mov edx, dword ptr [eax]
// 00468fc6  50                   push eax
// 00468fc7  51                   push ecx
// 00468fc8  52                   push edx
// 00468fc9  51                   push ecx
// 00468fca  8d442418             lea eax, [esp + 0x18]
// 00468fce  50                   push eax
// 00468fcf  8bce                 mov ecx, esi
// 00468fd1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00468fd9  e8223a1400           call 0x5aca00
// 00468fde  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00468fe1  51                   push ecx
// 00468fe2  e8b3e93300           call 0x7a799a
// 00468fe7  8b16                 mov edx, dword ptr [esi]
// 00468fe9  52                   push edx
// 00468fea  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00468ff1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00468ff8  e89de93300           call 0x7a799a
// 00468ffd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00469001  83c408               add esp, 8
// 00469004  5e                   pop esi
// 00469005  64890d00000000       mov dword ptr fs:[0], ecx
// 0046900c  83c418               add esp, 0x18
// 0046900f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
