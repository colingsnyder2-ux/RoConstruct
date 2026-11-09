// from server: 100% by auto
// roc 2010-06 008c8910  unit: RBX::AdornRbxGfx  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c8910
//
// 008c8910  6aff                 push -1
// 008c8912  6858a29900           push 0x99a258
// 008c8917  64a100000000         mov eax, dword ptr fs:[0]
// 008c891d  50                   push eax
// 008c891e  64892500000000       mov dword ptr fs:[0], esp
// 008c8925  51                   push ecx
// 008c8926  56                   push esi
// 008c8927  8bf1                 mov esi, ecx
// 008c8929  6a04                 push 4
// 008c892b  89742408             mov dword ptr [esp + 8], esi
// 008c892f  e86cf0edff           call 0x7a79a0
// 008c8934  83c404               add esp, 4
// 008c8937  85c0                 test eax, eax
// 008c8939  7404                 je 0x8c893f
// 008c893b  8930                 mov dword ptr [eax], esi
// 008c893d  eb02                 jmp 0x8c8941
// 008c893f  33c0                 xor eax, eax
// 008c8941  8906                 mov dword ptr [esi], eax
// 008c8943  8bce                 mov ecx, esi
// 008c8945  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008c894d  e8bee7ffff           call 0x8c7110
// 008c8952  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008c8956  894618               mov dword ptr [esi + 0x18], eax
// 008c8959  c6402d01             mov byte ptr [eax + 0x2d], 1
// 008c895d  8b4618               mov eax, dword ptr [esi + 0x18]
// 008c8960  894004               mov dword ptr [eax + 4], eax
// 008c8963  8b4618               mov eax, dword ptr [esi + 0x18]
// 008c8966  8900                 mov dword ptr [eax], eax
// 008c8968  8b4618               mov eax, dword ptr [esi + 0x18]
// 008c896b  894008               mov dword ptr [eax + 8], eax
// 008c896e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 008c8975  8bc6                 mov eax, esi
// 008c8977  5e                   pop esi
// 008c8978  64890d00000000       mov dword ptr fs:[0], ecx
// 008c897f  83c410               add esp, 0x10
// 008c8982  c20800               ret 8
// standard library set<pod32> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
