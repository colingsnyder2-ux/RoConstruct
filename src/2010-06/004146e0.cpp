// from server: 100% by auto
// roc 2010-06 004146e0  unit: CopyVerb  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004146e0
//
// 004146e0  6aff                 push -1
// 004146e2  6858a29900           push 0x99a258
// 004146e7  64a100000000         mov eax, dword ptr fs:[0]
// 004146ed  50                   push eax
// 004146ee  64892500000000       mov dword ptr fs:[0], esp
// 004146f5  51                   push ecx
// 004146f6  56                   push esi
// 004146f7  8bf1                 mov esi, ecx
// 004146f9  6a04                 push 4
// 004146fb  89742408             mov dword ptr [esp + 8], esi
// 004146ff  e89c323900           call 0x7a79a0
// 00414704  83c404               add esp, 4
// 00414707  85c0                 test eax, eax
// 00414709  7404                 je 0x41470f
// 0041470b  8930                 mov dword ptr [eax], esi
// 0041470d  eb02                 jmp 0x414711
// 0041470f  33c0                 xor eax, eax
// 00414711  8906                 mov dword ptr [esi], eax
// 00414713  8bce                 mov ecx, esi
// 00414715  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041471d  e80ef7ffff           call 0x413e30
// 00414722  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00414726  894618               mov dword ptr [esi + 0x18], eax
// 00414729  c6404501             mov byte ptr [eax + 0x45], 1
// 0041472d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414730  894004               mov dword ptr [eax + 4], eax
// 00414733  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414736  8900                 mov dword ptr [eax], eax
// 00414738  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041473b  894008               mov dword ptr [eax + 8], eax
// 0041473e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00414745  8bc6                 mov eax, esi
// 00414747  5e                   pop esi
// 00414748  64890d00000000       mov dword ptr fs:[0], ecx
// 0041474f  83c410               add esp, 0x10
// 00414752  c20800               ret 8
// standard library map_str<string> (function ??0?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@ABV?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@1@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
