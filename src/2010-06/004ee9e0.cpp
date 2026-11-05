// from server: 100% by auto
// roc 2010-06 004ee9e0  unit: RBX::Network::Replicator::NewInstanceItem  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ee9e0
//
// 004ee9e0  6aff                 push -1
// 004ee9e2  68b8d19b00           push 0x9bd1b8
// 004ee9e7  64a100000000         mov eax, dword ptr fs:[0]
// 004ee9ed  50                   push eax
// 004ee9ee  64892500000000       mov dword ptr fs:[0], esp
// 004ee9f5  83ec0c               sub esp, 0xc
// 004ee9f8  56                   push esi
// 004ee9f9  8bf1                 mov esi, ecx
// 004ee9fb  89742404             mov dword ptr [esp + 4], esi
// 004ee9ff  8b4618               mov eax, dword ptr [esi + 0x18]
// 004eea02  8b0e                 mov ecx, dword ptr [esi]
// 004eea04  8b10                 mov edx, dword ptr [eax]
// 004eea06  50                   push eax
// 004eea07  51                   push ecx
// 004eea08  52                   push edx
// 004eea09  51                   push ecx
// 004eea0a  8d442418             lea eax, [esp + 0x18]
// 004eea0e  50                   push eax
// 004eea0f  8bce                 mov ecx, esi
// 004eea11  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004eea19  e852ebffff           call 0x4ed570
// 004eea1e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004eea21  51                   push ecx
// 004eea22  e8738f2b00           call 0x7a799a
// 004eea27  8b16                 mov edx, dword ptr [esi]
// 004eea29  52                   push edx
// 004eea2a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004eea31  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004eea38  e85d8f2b00           call 0x7a799a
// 004eea3d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004eea41  83c408               add esp, 8
// 004eea44  5e                   pop esi
// 004eea45  64890d00000000       mov dword ptr fs:[0], ecx
// 004eea4c  83c418               add esp, 0x18
// 004eea4f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
