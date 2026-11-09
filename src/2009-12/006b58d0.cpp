// from server: 100% by auto
// roc 2009-12 006b58d0  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b58d0
//
// 006b58d0  6aff                 push -1
// 006b58d2  68d8c59300           push 0x93c5d8
// 006b58d7  64a100000000         mov eax, dword ptr fs:[0]
// 006b58dd  50                   push eax
// 006b58de  64892500000000       mov dword ptr fs:[0], esp
// 006b58e5  51                   push ecx
// 006b58e6  56                   push esi
// 006b58e7  8bf1                 mov esi, ecx
// 006b58e9  6a04                 push 4
// 006b58eb  89742408             mov dword ptr [esp + 8], esi
// 006b58ef  e86cdf1300           call 0x7f3860
// 006b58f4  83c404               add esp, 4
// 006b58f7  85c0                 test eax, eax
// 006b58f9  7404                 je 0x6b58ff
// 006b58fb  8930                 mov dword ptr [eax], esi
// 006b58fd  eb02                 jmp 0x6b5901
// 006b58ff  33c0                 xor eax, eax
// 006b5901  8906                 mov dword ptr [esi], eax
// 006b5903  8bce                 mov ecx, esi
// 006b5905  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006b590d  e84eecffff           call 0x6b4560
// 006b5912  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006b5916  894618               mov dword ptr [esi + 0x18], eax
// 006b5919  c6403501             mov byte ptr [eax + 0x35], 1
// 006b591d  8b4618               mov eax, dword ptr [esi + 0x18]
// 006b5920  894004               mov dword ptr [eax + 4], eax
// 006b5923  8b4618               mov eax, dword ptr [esi + 0x18]
// 006b5926  8900                 mov dword ptr [eax], eax
// 006b5928  8b4618               mov eax, dword ptr [esi + 0x18]
// 006b592b  894008               mov dword ptr [eax + 8], eax
// 006b592e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006b5935  8bc6                 mov eax, esi
// 006b5937  5e                   pop esi
// 006b5938  64890d00000000       mov dword ptr fs:[0], ecx
// 006b593f  83c410               add esp, 0x10
// 006b5942  c20800               ret 8
// standard library set<pod40> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
