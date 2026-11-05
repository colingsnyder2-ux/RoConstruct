// from server: 100% by auto
// roc 2008-06 00414490  unit: CopyVerb  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00414490
//
// 00414490  6aff                 push -1
// 00414492  68e8727d00           push 0x7d72e8
// 00414497  64a100000000         mov eax, dword ptr fs:[0]
// 0041449d  50                   push eax
// 0041449e  64892500000000       mov dword ptr fs:[0], esp
// 004144a5  51                   push ecx
// 004144a6  56                   push esi
// 004144a7  8bf1                 mov esi, ecx
// 004144a9  6a04                 push 4
// 004144ab  89742408             mov dword ptr [esp + 8], esi
// 004144af  e86cc42800           call 0x6a0920
// 004144b4  83c404               add esp, 4
// 004144b7  85c0                 test eax, eax
// 004144b9  7404                 je 0x4144bf
// 004144bb  8930                 mov dword ptr [eax], esi
// 004144bd  eb02                 jmp 0x4144c1
// 004144bf  33c0                 xor eax, eax
// 004144c1  8906                 mov dword ptr [esi], eax
// 004144c3  8bce                 mov ecx, esi
// 004144c5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004144cd  e80ef7ffff           call 0x413be0
// 004144d2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004144d6  894618               mov dword ptr [esi + 0x18], eax
// 004144d9  c6404501             mov byte ptr [eax + 0x45], 1
// 004144dd  8b4618               mov eax, dword ptr [esi + 0x18]
// 004144e0  894004               mov dword ptr [eax + 4], eax
// 004144e3  8b4618               mov eax, dword ptr [esi + 0x18]
// 004144e6  8900                 mov dword ptr [eax], eax
// 004144e8  8b4618               mov eax, dword ptr [esi + 0x18]
// 004144eb  894008               mov dword ptr [eax + 8], eax
// 004144ee  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004144f5  8bc6                 mov eax, esi
// 004144f7  5e                   pop esi
// 004144f8  64890d00000000       mov dword ptr fs:[0], ecx
// 004144ff  83c410               add esp, 0x10
// 00414502  c20800               ret 8
// standard library map_str<string> (function ??0?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@ABV?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@1@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
