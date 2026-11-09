// from server: 100% by auto
// roc 2010-06 00641fa0  unit: RBX::VInstance::?$NonFactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00641fa0
//
// 00641fa0  6aff                 push -1
// 00641fa2  68b8d19b00           push 0x9bd1b8
// 00641fa7  64a100000000         mov eax, dword ptr fs:[0]
// 00641fad  50                   push eax
// 00641fae  64892500000000       mov dword ptr fs:[0], esp
// 00641fb5  83ec0c               sub esp, 0xc
// 00641fb8  56                   push esi
// 00641fb9  8bf1                 mov esi, ecx
// 00641fbb  89742404             mov dword ptr [esp + 4], esi
// 00641fbf  8b4618               mov eax, dword ptr [esi + 0x18]
// 00641fc2  8b0e                 mov ecx, dword ptr [esi]
// 00641fc4  8b10                 mov edx, dword ptr [eax]
// 00641fc6  50                   push eax
// 00641fc7  51                   push ecx
// 00641fc8  52                   push edx
// 00641fc9  51                   push ecx
// 00641fca  8d442418             lea eax, [esp + 0x18]
// 00641fce  50                   push eax
// 00641fcf  8bce                 mov ecx, esi
// 00641fd1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00641fd9  e8f2fbffff           call 0x641bd0
// 00641fde  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00641fe1  51                   push ecx
// 00641fe2  e8b3591600           call 0x7a799a
// 00641fe7  8b16                 mov edx, dword ptr [esi]
// 00641fe9  52                   push edx
// 00641fea  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00641ff1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00641ff8  e89d591600           call 0x7a799a
// 00641ffd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00642001  83c408               add esp, 8
// 00642004  5e                   pop esi
// 00642005  64890d00000000       mov dword ptr fs:[0], ecx
// 0064200c  83c418               add esp, 0x18
// 0064200f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
