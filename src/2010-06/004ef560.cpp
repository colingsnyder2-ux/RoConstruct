// from server: 100% by auto
// roc 2010-06 004ef560  unit: RBX::Network::Replicator::EventInvocationItem  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ef560
//
// 004ef560  6aff                 push -1
// 004ef562  68b8d19b00           push 0x9bd1b8
// 004ef567  64a100000000         mov eax, dword ptr fs:[0]
// 004ef56d  50                   push eax
// 004ef56e  64892500000000       mov dword ptr fs:[0], esp
// 004ef575  83ec0c               sub esp, 0xc
// 004ef578  56                   push esi
// 004ef579  8bf1                 mov esi, ecx
// 004ef57b  89742404             mov dword ptr [esp + 4], esi
// 004ef57f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004ef582  8b0e                 mov ecx, dword ptr [esi]
// 004ef584  8b10                 mov edx, dword ptr [eax]
// 004ef586  50                   push eax
// 004ef587  51                   push ecx
// 004ef588  52                   push edx
// 004ef589  51                   push ecx
// 004ef58a  8d442418             lea eax, [esp + 0x18]
// 004ef58e  50                   push eax
// 004ef58f  8bce                 mov ecx, esi
// 004ef591  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004ef599  e882edffff           call 0x4ee320
// 004ef59e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004ef5a1  51                   push ecx
// 004ef5a2  e8f3832b00           call 0x7a799a
// 004ef5a7  8b16                 mov edx, dword ptr [esi]
// 004ef5a9  52                   push edx
// 004ef5aa  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004ef5b1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004ef5b8  e8dd832b00           call 0x7a799a
// 004ef5bd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004ef5c1  83c408               add esp, 8
// 004ef5c4  5e                   pop esi
// 004ef5c5  64890d00000000       mov dword ptr fs:[0], ecx
// 004ef5cc  83c418               add esp, 0x18
// 004ef5cf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
