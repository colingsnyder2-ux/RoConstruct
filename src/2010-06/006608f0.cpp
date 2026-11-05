// from server: 100% by auto
// roc 2010-06 006608f0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006608f0
//
// 006608f0  6aff                 push -1
// 006608f2  6858a29900           push 0x99a258
// 006608f7  64a100000000         mov eax, dword ptr fs:[0]
// 006608fd  50                   push eax
// 006608fe  64892500000000       mov dword ptr fs:[0], esp
// 00660905  51                   push ecx
// 00660906  56                   push esi
// 00660907  8bf1                 mov esi, ecx
// 00660909  6a04                 push 4
// 0066090b  89742408             mov dword ptr [esp + 8], esi
// 0066090f  e88c701400           call 0x7a79a0
// 00660914  83c404               add esp, 4
// 00660917  85c0                 test eax, eax
// 00660919  7404                 je 0x66091f
// 0066091b  8930                 mov dword ptr [eax], esi
// 0066091d  eb02                 jmp 0x660921
// 0066091f  33c0                 xor eax, eax
// 00660921  8906                 mov dword ptr [esi], eax
// 00660923  8bce                 mov ecx, esi
// 00660925  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0066092d  e87e5fe7ff           call 0x4d68b0
// 00660932  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00660936  894618               mov dword ptr [esi + 0x18], eax
// 00660939  c6401501             mov byte ptr [eax + 0x15], 1
// 0066093d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00660940  894004               mov dword ptr [eax + 4], eax
// 00660943  8b4618               mov eax, dword ptr [esi + 0x18]
// 00660946  8900                 mov dword ptr [eax], eax
// 00660948  8b4618               mov eax, dword ptr [esi + 0x18]
// 0066094b  894008               mov dword ptr [eax + 8], eax
// 0066094e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00660955  8bc6                 mov eax, esi
// 00660957  5e                   pop esi
// 00660958  64890d00000000       mov dword ptr fs:[0], ecx
// 0066095f  83c410               add esp, 0x10
// 00660962  c20800               ret 8
// standard library set<pod8> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
