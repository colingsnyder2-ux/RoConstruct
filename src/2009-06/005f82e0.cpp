// from server: 100% by auto
// roc 2009-06 005f82e0  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005f82e0
//
// 005f82e0  6aff                 push -1
// 005f82e2  6878ef8600           push 0x86ef78
// 005f82e7  64a100000000         mov eax, dword ptr fs:[0]
// 005f82ed  50                   push eax
// 005f82ee  64892500000000       mov dword ptr fs:[0], esp
// 005f82f5  51                   push ecx
// 005f82f6  56                   push esi
// 005f82f7  8bf1                 mov esi, ecx
// 005f82f9  6a04                 push 4
// 005f82fb  89742408             mov dword ptr [esp + 8], esi
// 005f82ff  e834071200           call 0x718a38
// 005f8304  83c404               add esp, 4
// 005f8307  85c0                 test eax, eax
// 005f8309  7404                 je 0x5f830f
// 005f830b  8930                 mov dword ptr [eax], esi
// 005f830d  eb02                 jmp 0x5f8311
// 005f830f  33c0                 xor eax, eax
// 005f8311  8906                 mov dword ptr [esi], eax
// 005f8313  8bce                 mov ecx, esi
// 005f8315  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005f831d  e87e7ce4ff           call 0x43ffa0
// 005f8322  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005f8326  894618               mov dword ptr [esi + 0x18], eax
// 005f8329  c6401501             mov byte ptr [eax + 0x15], 1
// 005f832d  8b4618               mov eax, dword ptr [esi + 0x18]
// 005f8330  894004               mov dword ptr [eax + 4], eax
// 005f8333  8b4618               mov eax, dword ptr [esi + 0x18]
// 005f8336  8900                 mov dword ptr [eax], eax
// 005f8338  8b4618               mov eax, dword ptr [esi + 0x18]
// 005f833b  894008               mov dword ptr [eax + 8], eax
// 005f833e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005f8345  8bc6                 mov eax, esi
// 005f8347  5e                   pop esi
// 005f8348  64890d00000000       mov dword ptr fs:[0], ecx
// 005f834f  83c410               add esp, 0x10
// 005f8352  c20800               ret 8
// standard library set<pod8> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
