// from server: 100% by auto
// roc 2009-12 007c2680  unit: RBX::VChatLine::?$sp_counted_impl_p  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c2680
//
// 007c2680  6aff                 push -1
// 007c2682  68d8c59300           push 0x93c5d8
// 007c2687  64a100000000         mov eax, dword ptr fs:[0]
// 007c268d  50                   push eax
// 007c268e  64892500000000       mov dword ptr fs:[0], esp
// 007c2695  51                   push ecx
// 007c2696  56                   push esi
// 007c2697  8bf1                 mov esi, ecx
// 007c2699  6a04                 push 4
// 007c269b  89742408             mov dword ptr [esp + 8], esi
// 007c269f  e8bc110300           call 0x7f3860
// 007c26a4  83c404               add esp, 4
// 007c26a7  85c0                 test eax, eax
// 007c26a9  7404                 je 0x7c26af
// 007c26ab  8930                 mov dword ptr [eax], esi
// 007c26ad  eb02                 jmp 0x7c26b1
// 007c26af  33c0                 xor eax, eax
// 007c26b1  8906                 mov dword ptr [esi], eax
// 007c26b3  8bce                 mov ecx, esi
// 007c26b5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007c26bd  e82efbffff           call 0x7c21f0
// 007c26c2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007c26c6  894618               mov dword ptr [esi + 0x18], eax
// 007c26c9  c6404d01             mov byte ptr [eax + 0x4d], 1
// 007c26cd  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c26d0  894004               mov dword ptr [eax + 4], eax
// 007c26d3  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c26d6  8900                 mov dword ptr [eax], eax
// 007c26d8  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c26db  894008               mov dword ptr [eax + 8], eax
// 007c26de  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007c26e5  8bc6                 mov eax, esi
// 007c26e7  5e                   pop esi
// 007c26e8  64890d00000000       mov dword ptr fs:[0], ecx
// 007c26ef  83c410               add esp, 0x10
// 007c26f2  c20800               ret 8
// standard library set<pod64> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod64>
struct E { int v[16]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
