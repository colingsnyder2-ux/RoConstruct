// from server: 100% by auto
// roc 2009-12 007b09c0  unit: RBX::Block  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b09c0
//
// 007b09c0  6aff                 push -1
// 007b09c2  68d8c59300           push 0x93c5d8
// 007b09c7  64a100000000         mov eax, dword ptr fs:[0]
// 007b09cd  50                   push eax
// 007b09ce  64892500000000       mov dword ptr fs:[0], esp
// 007b09d5  51                   push ecx
// 007b09d6  56                   push esi
// 007b09d7  8bf1                 mov esi, ecx
// 007b09d9  6a04                 push 4
// 007b09db  89742408             mov dword ptr [esp + 8], esi
// 007b09df  e87c2e0400           call 0x7f3860
// 007b09e4  83c404               add esp, 4
// 007b09e7  85c0                 test eax, eax
// 007b09e9  7404                 je 0x7b09ef
// 007b09eb  8930                 mov dword ptr [eax], esi
// 007b09ed  eb02                 jmp 0x7b09f1
// 007b09ef  33c0                 xor eax, eax
// 007b09f1  8906                 mov dword ptr [esi], eax
// 007b09f3  8bce                 mov ecx, esi
// 007b09f5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007b09fd  e80ef3ffff           call 0x7afd10
// 007b0a02  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007b0a06  894618               mov dword ptr [esi + 0x18], eax
// 007b0a09  c6401d01             mov byte ptr [eax + 0x1d], 1
// 007b0a0d  8b4618               mov eax, dword ptr [esi + 0x18]
// 007b0a10  894004               mov dword ptr [eax + 4], eax
// 007b0a13  8b4618               mov eax, dword ptr [esi + 0x18]
// 007b0a16  8900                 mov dword ptr [eax], eax
// 007b0a18  8b4618               mov eax, dword ptr [esi + 0x18]
// 007b0a1b  894008               mov dword ptr [eax + 8], eax
// 007b0a1e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007b0a25  8bc6                 mov eax, esi
// 007b0a27  5e                   pop esi
// 007b0a28  64890d00000000       mov dword ptr fs:[0], ecx
// 007b0a2f  83c410               add esp, 0x10
// 007b0a32  c20800               ret 8
// standard library set<pod16> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
