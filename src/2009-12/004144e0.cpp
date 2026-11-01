// from server: 100% by auto
// roc 2009-12 004144e0  unit: CopyVerb  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004144e0
//
// 004144e0  6aff                 push -1
// 004144e2  68d8c59300           push 0x93c5d8
// 004144e7  64a100000000         mov eax, dword ptr fs:[0]
// 004144ed  50                   push eax
// 004144ee  64892500000000       mov dword ptr fs:[0], esp
// 004144f5  51                   push ecx
// 004144f6  56                   push esi
// 004144f7  8bf1                 mov esi, ecx
// 004144f9  6a04                 push 4
// 004144fb  89742408             mov dword ptr [esp + 8], esi
// 004144ff  e85cf33d00           call 0x7f3860
// 00414504  83c404               add esp, 4
// 00414507  85c0                 test eax, eax
// 00414509  7404                 je 0x41450f
// 0041450b  8930                 mov dword ptr [eax], esi
// 0041450d  eb02                 jmp 0x414511
// 0041450f  33c0                 xor eax, eax
// 00414511  8906                 mov dword ptr [esi], eax
// 00414513  8bce                 mov ecx, esi
// 00414515  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041451d  e88ef6ffff           call 0x413bb0
// 00414522  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00414526  894618               mov dword ptr [esi + 0x18], eax
// 00414529  c6404501             mov byte ptr [eax + 0x45], 1
// 0041452d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414530  894004               mov dword ptr [eax + 4], eax
// 00414533  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414536  8900                 mov dword ptr [eax], eax
// 00414538  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041453b  894008               mov dword ptr [eax + 8], eax
// 0041453e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00414545  8bc6                 mov eax, esi
// 00414547  5e                   pop esi
// 00414548  64890d00000000       mov dword ptr fs:[0], ecx
// 0041454f  83c410               add esp, 0x10
// 00414552  c20800               ret 8
// standard library map_str<string> (function ??0?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@ABV?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@1@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
