// from server: 100% by auto
// roc 2010-06 00738970  unit: seg_00730000  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00738970
//
// 00738970  6aff                 push -1
// 00738972  6858a29900           push 0x99a258
// 00738977  64a100000000         mov eax, dword ptr fs:[0]
// 0073897d  50                   push eax
// 0073897e  64892500000000       mov dword ptr fs:[0], esp
// 00738985  51                   push ecx
// 00738986  56                   push esi
// 00738987  8bf1                 mov esi, ecx
// 00738989  6a04                 push 4
// 0073898b  89742408             mov dword ptr [esp + 8], esi
// 0073898f  e80cf00600           call 0x7a79a0
// 00738994  83c404               add esp, 4
// 00738997  85c0                 test eax, eax
// 00738999  7404                 je 0x73899f
// 0073899b  8930                 mov dword ptr [eax], esi
// 0073899d  eb02                 jmp 0x7389a1
// 0073899f  33c0                 xor eax, eax
// 007389a1  8906                 mov dword ptr [esi], eax
// 007389a3  8bce                 mov ecx, esi
// 007389a5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007389ad  e86efaffff           call 0x738420
// 007389b2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007389b6  894618               mov dword ptr [esi + 0x18], eax
// 007389b9  c6403901             mov byte ptr [eax + 0x39], 1
// 007389bd  8b4618               mov eax, dword ptr [esi + 0x18]
// 007389c0  894004               mov dword ptr [eax + 4], eax
// 007389c3  8b4618               mov eax, dword ptr [esi + 0x18]
// 007389c6  8900                 mov dword ptr [eax], eax
// 007389c8  8b4618               mov eax, dword ptr [esi + 0x18]
// 007389cb  894008               mov dword ptr [eax + 8], eax
// 007389ce  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007389d5  8bc6                 mov eax, esi
// 007389d7  5e                   pop esi
// 007389d8  64890d00000000       mov dword ptr fs:[0], ecx
// 007389df  83c410               add esp, 0x10
// 007389e2  c20800               ret 8
// standard library map_int<pod40> (function ??0?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE@ABU?$less@H@1@ABV?$allocator@U?$pair@$$CBHUE@@@std@@@1@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
