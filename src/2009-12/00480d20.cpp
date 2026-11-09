// from server: 100% by auto
// roc 2009-12 00480d20  unit: RBX::AdornRbxGfx  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00480d20
//
// 00480d20  6aff                 push -1
// 00480d22  68d8c59300           push 0x93c5d8
// 00480d27  64a100000000         mov eax, dword ptr fs:[0]
// 00480d2d  50                   push eax
// 00480d2e  64892500000000       mov dword ptr fs:[0], esp
// 00480d35  51                   push ecx
// 00480d36  56                   push esi
// 00480d37  8bf1                 mov esi, ecx
// 00480d39  6a04                 push 4
// 00480d3b  89742408             mov dword ptr [esp + 8], esi
// 00480d3f  e81c2b3700           call 0x7f3860
// 00480d44  83c404               add esp, 4
// 00480d47  85c0                 test eax, eax
// 00480d49  7404                 je 0x480d4f
// 00480d4b  8930                 mov dword ptr [eax], esi
// 00480d4d  eb02                 jmp 0x480d51
// 00480d4f  33c0                 xor eax, eax
// 00480d51  8906                 mov dword ptr [esi], eax
// 00480d53  8bce                 mov ecx, esi
// 00480d55  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00480d5d  e80ee7ffff           call 0x47f470
// 00480d62  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00480d66  894618               mov dword ptr [esi + 0x18], eax
// 00480d69  c6403901             mov byte ptr [eax + 0x39], 1
// 00480d6d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00480d70  894004               mov dword ptr [eax + 4], eax
// 00480d73  8b4618               mov eax, dword ptr [esi + 0x18]
// 00480d76  8900                 mov dword ptr [eax], eax
// 00480d78  8b4618               mov eax, dword ptr [esi + 0x18]
// 00480d7b  894008               mov dword ptr [eax + 8], eax
// 00480d7e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00480d85  8bc6                 mov eax, esi
// 00480d87  5e                   pop esi
// 00480d88  64890d00000000       mov dword ptr fs:[0], ecx
// 00480d8f  83c410               add esp, 0x10
// 00480d92  c20800               ret 8
// standard library map_int<pod40> (function ??0?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE@ABU?$less@H@1@ABV?$allocator@U?$pair@$$CBHUE@@@std@@@1@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
