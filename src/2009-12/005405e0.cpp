// from server: 100% by auto
// roc 2009-12 005405e0  unit: RBX::Network::Replicator::NewInstanceItem  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005405e0
//
// 005405e0  6aff                 push -1
// 005405e2  68888f9400           push 0x948f88
// 005405e7  64a100000000         mov eax, dword ptr fs:[0]
// 005405ed  50                   push eax
// 005405ee  64892500000000       mov dword ptr fs:[0], esp
// 005405f5  83ec0c               sub esp, 0xc
// 005405f8  56                   push esi
// 005405f9  8bf1                 mov esi, ecx
// 005405fb  89742404             mov dword ptr [esp + 4], esi
// 005405ff  8b4618               mov eax, dword ptr [esi + 0x18]
// 00540602  8b0e                 mov ecx, dword ptr [esi]
// 00540604  8b10                 mov edx, dword ptr [eax]
// 00540606  50                   push eax
// 00540607  51                   push ecx
// 00540608  52                   push edx
// 00540609  51                   push ecx
// 0054060a  8d442418             lea eax, [esp + 0x18]
// 0054060e  50                   push eax
// 0054060f  8bce                 mov ecx, esi
// 00540611  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00540619  e8c2ebffff           call 0x53f1e0
// 0054061e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00540621  51                   push ecx
// 00540622  e833322b00           call 0x7f385a
// 00540627  8b16                 mov edx, dword ptr [esi]
// 00540629  52                   push edx
// 0054062a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00540631  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00540638  e81d322b00           call 0x7f385a
// 0054063d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00540641  83c408               add esp, 8
// 00540644  5e                   pop esi
// 00540645  64890d00000000       mov dword ptr fs:[0], ecx
// 0054064c  83c418               add esp, 0x18
// 0054064f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
