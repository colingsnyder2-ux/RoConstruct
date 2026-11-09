// from server: 100% by auto
// roc 2009-06 0051be20  unit: G3D::VVector3::?$Table  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0051be20
//
// 0051be20  6aff                 push -1
// 0051be22  6878ef8600           push 0x86ef78
// 0051be27  64a100000000         mov eax, dword ptr fs:[0]
// 0051be2d  50                   push eax
// 0051be2e  64892500000000       mov dword ptr fs:[0], esp
// 0051be35  51                   push ecx
// 0051be36  56                   push esi
// 0051be37  8bf1                 mov esi, ecx
// 0051be39  6a04                 push 4
// 0051be3b  89742408             mov dword ptr [esp + 8], esi
// 0051be3f  e8f4cb1f00           call 0x718a38
// 0051be44  83c404               add esp, 4
// 0051be47  85c0                 test eax, eax
// 0051be49  7404                 je 0x51be4f
// 0051be4b  8930                 mov dword ptr [eax], esi
// 0051be4d  eb02                 jmp 0x51be51
// 0051be4f  33c0                 xor eax, eax
// 0051be51  8906                 mov dword ptr [esi], eax
// 0051be53  8bce                 mov ecx, esi
// 0051be55  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0051be5d  e8beccffff           call 0x518b20
// 0051be62  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0051be66  894618               mov dword ptr [esi + 0x18], eax
// 0051be69  c6402101             mov byte ptr [eax + 0x21], 1
// 0051be6d  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051be70  894004               mov dword ptr [eax + 4], eax
// 0051be73  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051be76  8900                 mov dword ptr [eax], eax
// 0051be78  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051be7b  894008               mov dword ptr [eax + 8], eax
// 0051be7e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0051be85  8bc6                 mov eax, esi
// 0051be87  5e                   pop esi
// 0051be88  64890d00000000       mov dword ptr fs:[0], ecx
// 0051be8f  83c410               add esp, 0x10
// 0051be92  c20800               ret 8
// standard library set<pod20> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
