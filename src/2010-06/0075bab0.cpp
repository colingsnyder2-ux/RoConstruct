// from server: 100% by auto
// roc 2010-06 0075bab0  unit: RBX::ParallelRampPoly  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075bab0
//
// 0075bab0  6aff                 push -1
// 0075bab2  6858a29900           push 0x99a258
// 0075bab7  64a100000000         mov eax, dword ptr fs:[0]
// 0075babd  50                   push eax
// 0075babe  64892500000000       mov dword ptr fs:[0], esp
// 0075bac5  51                   push ecx
// 0075bac6  56                   push esi
// 0075bac7  8bf1                 mov esi, ecx
// 0075bac9  6a04                 push 4
// 0075bacb  89742408             mov dword ptr [esp + 8], esi
// 0075bacf  e8ccbe0400           call 0x7a79a0
// 0075bad4  83c404               add esp, 4
// 0075bad7  85c0                 test eax, eax
// 0075bad9  7404                 je 0x75badf
// 0075badb  8930                 mov dword ptr [eax], esi
// 0075badd  eb02                 jmp 0x75bae1
// 0075badf  33c0                 xor eax, eax
// 0075bae1  8906                 mov dword ptr [esi], eax
// 0075bae3  8bce                 mov ecx, esi
// 0075bae5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0075baed  e8ce2be3ff           call 0x58e6c0
// 0075baf2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0075baf6  894618               mov dword ptr [esi + 0x18], eax
// 0075baf9  c6401d01             mov byte ptr [eax + 0x1d], 1
// 0075bafd  8b4618               mov eax, dword ptr [esi + 0x18]
// 0075bb00  894004               mov dword ptr [eax + 4], eax
// 0075bb03  8b4618               mov eax, dword ptr [esi + 0x18]
// 0075bb06  8900                 mov dword ptr [eax], eax
// 0075bb08  8b4618               mov eax, dword ptr [esi + 0x18]
// 0075bb0b  894008               mov dword ptr [eax + 8], eax
// 0075bb0e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0075bb15  8bc6                 mov eax, esi
// 0075bb17  5e                   pop esi
// 0075bb18  64890d00000000       mov dword ptr fs:[0], ecx
// 0075bb1f  83c410               add esp, 0x10
// 0075bb22  c20800               ret 8
// standard library set<pod16> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
