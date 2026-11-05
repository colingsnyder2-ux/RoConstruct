// from server: 100% by auto
// roc 2009-06 00414a70  unit: CopyVerb  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00414a70
//
// 00414a70  6aff                 push -1
// 00414a72  6878ef8600           push 0x86ef78
// 00414a77  64a100000000         mov eax, dword ptr fs:[0]
// 00414a7d  50                   push eax
// 00414a7e  64892500000000       mov dword ptr fs:[0], esp
// 00414a85  51                   push ecx
// 00414a86  56                   push esi
// 00414a87  8bf1                 mov esi, ecx
// 00414a89  6a04                 push 4
// 00414a8b  89742408             mov dword ptr [esp + 8], esi
// 00414a8f  e8a43f3000           call 0x718a38
// 00414a94  83c404               add esp, 4
// 00414a97  85c0                 test eax, eax
// 00414a99  7404                 je 0x414a9f
// 00414a9b  8930                 mov dword ptr [eax], esi
// 00414a9d  eb02                 jmp 0x414aa1
// 00414a9f  33c0                 xor eax, eax
// 00414aa1  8906                 mov dword ptr [esi], eax
// 00414aa3  8bce                 mov ecx, esi
// 00414aa5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00414aad  e80ef7ffff           call 0x4141c0
// 00414ab2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00414ab6  894618               mov dword ptr [esi + 0x18], eax
// 00414ab9  c6404501             mov byte ptr [eax + 0x45], 1
// 00414abd  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414ac0  894004               mov dword ptr [eax + 4], eax
// 00414ac3  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414ac6  8900                 mov dword ptr [eax], eax
// 00414ac8  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414acb  894008               mov dword ptr [eax + 8], eax
// 00414ace  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00414ad5  8bc6                 mov eax, esi
// 00414ad7  5e                   pop esi
// 00414ad8  64890d00000000       mov dword ptr fs:[0], ecx
// 00414adf  83c410               add esp, 0x10
// 00414ae2  c20800               ret 8
// standard library map_str<string> (function ??0?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@ABV?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@1@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
