// from server: 100% by auto
// roc 2009-06 00515b30  unit: seg_00510000  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00515b30
//
// 00515b30  6aff                 push -1
// 00515b32  6878ef8600           push 0x86ef78
// 00515b37  64a100000000         mov eax, dword ptr fs:[0]
// 00515b3d  50                   push eax
// 00515b3e  64892500000000       mov dword ptr fs:[0], esp
// 00515b45  51                   push ecx
// 00515b46  56                   push esi
// 00515b47  8bf1                 mov esi, ecx
// 00515b49  6a04                 push 4
// 00515b4b  89742408             mov dword ptr [esp + 8], esi
// 00515b4f  e8e42e2000           call 0x718a38
// 00515b54  83c404               add esp, 4
// 00515b57  85c0                 test eax, eax
// 00515b59  7404                 je 0x515b5f
// 00515b5b  8930                 mov dword ptr [eax], esi
// 00515b5d  eb02                 jmp 0x515b61
// 00515b5f  33c0                 xor eax, eax
// 00515b61  8906                 mov dword ptr [esi], eax
// 00515b63  8bce                 mov ecx, esi
// 00515b65  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00515b6d  e8cefbffff           call 0x515740
// 00515b72  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00515b76  894618               mov dword ptr [esi + 0x18], eax
// 00515b79  c6402501             mov byte ptr [eax + 0x25], 1
// 00515b7d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00515b80  894004               mov dword ptr [eax + 4], eax
// 00515b83  8b4618               mov eax, dword ptr [esi + 0x18]
// 00515b86  8900                 mov dword ptr [eax], eax
// 00515b88  8b4618               mov eax, dword ptr [esi + 0x18]
// 00515b8b  894008               mov dword ptr [eax + 8], eax
// 00515b8e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00515b95  8bc6                 mov eax, esi
// 00515b97  5e                   pop esi
// 00515b98  64890d00000000       mov dword ptr fs:[0], ecx
// 00515b9f  83c410               add esp, 0x10
// 00515ba2  c20800               ret 8
// standard library set<pod24> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
