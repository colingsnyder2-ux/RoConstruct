// from server: 100% by auto
// roc 2009-12 004508f0  unit: RBX::VExplosion::?$FactoryProduct::Creator  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004508f0
//
// 004508f0  6aff                 push -1
// 004508f2  68888f9400           push 0x948f88
// 004508f7  64a100000000         mov eax, dword ptr fs:[0]
// 004508fd  50                   push eax
// 004508fe  64892500000000       mov dword ptr fs:[0], esp
// 00450905  83ec0c               sub esp, 0xc
// 00450908  56                   push esi
// 00450909  8bf1                 mov esi, ecx
// 0045090b  89742404             mov dword ptr [esp + 4], esi
// 0045090f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00450912  8b0e                 mov ecx, dword ptr [esi]
// 00450914  8b10                 mov edx, dword ptr [eax]
// 00450916  50                   push eax
// 00450917  51                   push ecx
// 00450918  52                   push edx
// 00450919  51                   push ecx
// 0045091a  8d442418             lea eax, [esp + 0x18]
// 0045091e  50                   push eax
// 0045091f  8bce                 mov ecx, esi
// 00450921  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00450929  e882faffff           call 0x4503b0
// 0045092e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00450931  51                   push ecx
// 00450932  e8232f3a00           call 0x7f385a
// 00450937  8b16                 mov edx, dword ptr [esi]
// 00450939  52                   push edx
// 0045093a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00450941  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00450948  e80d2f3a00           call 0x7f385a
// 0045094d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00450951  83c408               add esp, 8
// 00450954  5e                   pop esi
// 00450955  64890d00000000       mov dword ptr fs:[0], ecx
// 0045095c  83c418               add esp, 0x18
// 0045095f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
