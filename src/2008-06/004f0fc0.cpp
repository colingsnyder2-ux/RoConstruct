// from server: 100% by auto
// roc 2008-06 004f0fc0  unit: RBX::RenderBase::VMaterialBase::?$WeakReferenceCountedPointer  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004f0fc0
//
// 004f0fc0  6aff                 push -1
// 004f0fc2  68e8727d00           push 0x7d72e8
// 004f0fc7  64a100000000         mov eax, dword ptr fs:[0]
// 004f0fcd  50                   push eax
// 004f0fce  64892500000000       mov dword ptr fs:[0], esp
// 004f0fd5  51                   push ecx
// 004f0fd6  56                   push esi
// 004f0fd7  8bf1                 mov esi, ecx
// 004f0fd9  6a04                 push 4
// 004f0fdb  89742408             mov dword ptr [esp + 8], esi
// 004f0fdf  e83cf91a00           call 0x6a0920
// 004f0fe4  83c404               add esp, 4
// 004f0fe7  85c0                 test eax, eax
// 004f0fe9  7404                 je 0x4f0fef
// 004f0feb  8930                 mov dword ptr [eax], esi
// 004f0fed  eb02                 jmp 0x4f0ff1
// 004f0fef  33c0                 xor eax, eax
// 004f0ff1  8906                 mov dword ptr [esi], eax
// 004f0ff3  8bce                 mov ecx, esi
// 004f0ff5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004f0ffd  e81e200c00           call 0x5b3020
// 004f1002  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004f1006  894618               mov dword ptr [esi + 0x18], eax
// 004f1009  c6402101             mov byte ptr [eax + 0x21], 1
// 004f100d  8b4618               mov eax, dword ptr [esi + 0x18]
// 004f1010  894004               mov dword ptr [eax + 4], eax
// 004f1013  8b4618               mov eax, dword ptr [esi + 0x18]
// 004f1016  8900                 mov dword ptr [eax], eax
// 004f1018  8b4618               mov eax, dword ptr [esi + 0x18]
// 004f101b  894008               mov dword ptr [eax + 8], eax
// 004f101e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004f1025  8bc6                 mov eax, esi
// 004f1027  5e                   pop esi
// 004f1028  64890d00000000       mov dword ptr fs:[0], ecx
// 004f102f  83c410               add esp, 0x10
// 004f1032  c20800               ret 8
// standard library set<pod20> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
