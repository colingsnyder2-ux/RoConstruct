// from server: 100% by auto
// roc 2010-06 00773ec0  unit: RBX::ScoreHud  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00773ec0
//
// 00773ec0  6aff                 push -1
// 00773ec2  68b8d19b00           push 0x9bd1b8
// 00773ec7  64a100000000         mov eax, dword ptr fs:[0]
// 00773ecd  50                   push eax
// 00773ece  64892500000000       mov dword ptr fs:[0], esp
// 00773ed5  83ec0c               sub esp, 0xc
// 00773ed8  56                   push esi
// 00773ed9  8bf1                 mov esi, ecx
// 00773edb  89742404             mov dword ptr [esp + 4], esi
// 00773edf  8b4618               mov eax, dword ptr [esi + 0x18]
// 00773ee2  8b0e                 mov ecx, dword ptr [esi]
// 00773ee4  8b10                 mov edx, dword ptr [eax]
// 00773ee6  50                   push eax
// 00773ee7  51                   push ecx
// 00773ee8  52                   push edx
// 00773ee9  51                   push ecx
// 00773eea  8d442418             lea eax, [esp + 0x18]
// 00773eee  50                   push eax
// 00773eef  8bce                 mov ecx, esi
// 00773ef1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00773ef9  e832ebffff           call 0x772a30
// 00773efe  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00773f01  51                   push ecx
// 00773f02  e8933a0300           call 0x7a799a
// 00773f07  8b16                 mov edx, dword ptr [esi]
// 00773f09  52                   push edx
// 00773f0a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00773f11  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00773f18  e87d3a0300           call 0x7a799a
// 00773f1d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00773f21  83c408               add esp, 8
// 00773f24  5e                   pop esi
// 00773f25  64890d00000000       mov dword ptr fs:[0], ecx
// 00773f2c  83c418               add esp, 0x18
// 00773f2f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
