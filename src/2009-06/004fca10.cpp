// from server: 100% by auto
// roc 2009-06 004fca10  unit: RBX::Network::ServerReplicator  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fca10
//
// 004fca10  6aff                 push -1
// 004fca12  6878ef8600           push 0x86ef78
// 004fca17  64a100000000         mov eax, dword ptr fs:[0]
// 004fca1d  50                   push eax
// 004fca1e  64892500000000       mov dword ptr fs:[0], esp
// 004fca25  51                   push ecx
// 004fca26  56                   push esi
// 004fca27  8bf1                 mov esi, ecx
// 004fca29  6a04                 push 4
// 004fca2b  89742408             mov dword ptr [esp + 8], esi
// 004fca2f  e804c02100           call 0x718a38
// 004fca34  83c404               add esp, 4
// 004fca37  85c0                 test eax, eax
// 004fca39  7404                 je 0x4fca3f
// 004fca3b  8930                 mov dword ptr [eax], esi
// 004fca3d  eb02                 jmp 0x4fca41
// 004fca3f  33c0                 xor eax, eax
// 004fca41  8906                 mov dword ptr [esi], eax
// 004fca43  8bce                 mov ecx, esi
// 004fca45  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004fca4d  e8def1ffff           call 0x4fbc30
// 004fca52  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004fca56  894618               mov dword ptr [esi + 0x18], eax
// 004fca59  c6403901             mov byte ptr [eax + 0x39], 1
// 004fca5d  8b4618               mov eax, dword ptr [esi + 0x18]
// 004fca60  894004               mov dword ptr [eax + 4], eax
// 004fca63  8b4618               mov eax, dword ptr [esi + 0x18]
// 004fca66  8900                 mov dword ptr [eax], eax
// 004fca68  8b4618               mov eax, dword ptr [esi + 0x18]
// 004fca6b  894008               mov dword ptr [eax + 8], eax
// 004fca6e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004fca75  8bc6                 mov eax, esi
// 004fca77  5e                   pop esi
// 004fca78  64890d00000000       mov dword ptr fs:[0], ecx
// 004fca7f  83c410               add esp, 0x10
// 004fca82  c20800               ret 8
// standard library map_int<pod40> (function ??0?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE@ABU?$less@H@1@ABV?$allocator@U?$pair@$$CBHUE@@@std@@@1@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
