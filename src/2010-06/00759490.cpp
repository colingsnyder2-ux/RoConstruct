// from server: 100% by auto
// roc 2010-06 00759490  unit: RBX::PyramidPoly  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00759490
//
// 00759490  6aff                 push -1
// 00759492  6858a29900           push 0x99a258
// 00759497  64a100000000         mov eax, dword ptr fs:[0]
// 0075949d  50                   push eax
// 0075949e  64892500000000       mov dword ptr fs:[0], esp
// 007594a5  51                   push ecx
// 007594a6  56                   push esi
// 007594a7  8bf1                 mov esi, ecx
// 007594a9  6a04                 push 4
// 007594ab  89742408             mov dword ptr [esp + 8], esi
// 007594af  e8ece40400           call 0x7a79a0
// 007594b4  83c404               add esp, 4
// 007594b7  85c0                 test eax, eax
// 007594b9  7404                 je 0x7594bf
// 007594bb  8930                 mov dword ptr [eax], esi
// 007594bd  eb02                 jmp 0x7594c1
// 007594bf  33c0                 xor eax, eax
// 007594c1  8906                 mov dword ptr [esi], eax
// 007594c3  8bce                 mov ecx, esi
// 007594c5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007594cd  e8aefaffff           call 0x758f80
// 007594d2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007594d6  894618               mov dword ptr [esi + 0x18], eax
// 007594d9  c6402501             mov byte ptr [eax + 0x25], 1
// 007594dd  8b4618               mov eax, dword ptr [esi + 0x18]
// 007594e0  894004               mov dword ptr [eax + 4], eax
// 007594e3  8b4618               mov eax, dword ptr [esi + 0x18]
// 007594e6  8900                 mov dword ptr [eax], eax
// 007594e8  8b4618               mov eax, dword ptr [esi + 0x18]
// 007594eb  894008               mov dword ptr [eax + 8], eax
// 007594ee  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007594f5  8bc6                 mov eax, esi
// 007594f7  5e                   pop esi
// 007594f8  64890d00000000       mov dword ptr fs:[0], ecx
// 007594ff  83c410               add esp, 0x10
// 00759502  c20800               ret 8
// standard library set<pod24> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
