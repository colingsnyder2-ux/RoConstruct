// from server: 100% by auto
// roc 2009-12 00706a50  unit: RBX::VInstance::?$NonFactoryProduct  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00706a50
//
// 00706a50  6aff                 push -1
// 00706a52  68d8c59300           push 0x93c5d8
// 00706a57  64a100000000         mov eax, dword ptr fs:[0]
// 00706a5d  50                   push eax
// 00706a5e  64892500000000       mov dword ptr fs:[0], esp
// 00706a65  51                   push ecx
// 00706a66  56                   push esi
// 00706a67  8bf1                 mov esi, ecx
// 00706a69  6a04                 push 4
// 00706a6b  89742408             mov dword ptr [esp + 8], esi
// 00706a6f  e8eccd0e00           call 0x7f3860
// 00706a74  83c404               add esp, 4
// 00706a77  85c0                 test eax, eax
// 00706a79  7404                 je 0x706a7f
// 00706a7b  8930                 mov dword ptr [eax], esi
// 00706a7d  eb02                 jmp 0x706a81
// 00706a7f  33c0                 xor eax, eax
// 00706a81  8906                 mov dword ptr [esi], eax
// 00706a83  8bce                 mov ecx, esi
// 00706a85  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00706a8d  e8dec9ffff           call 0x703470
// 00706a92  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00706a96  894618               mov dword ptr [esi + 0x18], eax
// 00706a99  c6405101             mov byte ptr [eax + 0x51], 1
// 00706a9d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00706aa0  894004               mov dword ptr [eax + 4], eax
// 00706aa3  8b4618               mov eax, dword ptr [esi + 0x18]
// 00706aa6  8900                 mov dword ptr [eax], eax
// 00706aa8  8b4618               mov eax, dword ptr [esi + 0x18]
// 00706aab  894008               mov dword ptr [eax + 8], eax
// 00706aae  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00706ab5  8bc6                 mov eax, esi
// 00706ab7  5e                   pop esi
// 00706ab8  64890d00000000       mov dword ptr fs:[0], ecx
// 00706abf  83c410               add esp, 0x10
// 00706ac2  c20800               ret 8
// standard library map_int<pod64> (function ??0?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE@ABU?$less@H@1@ABV?$allocator@U?$pair@$$CBHUE@@@std@@@1@@Z)

// stl: map_int<pod64>
struct E { int v[16]; };
#include <map>
template class std::map<int, E>;
