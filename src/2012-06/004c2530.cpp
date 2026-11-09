// from server: 100% by auto
// roc 2012-06 004c2530  unit: RBX::AdornRbxGfx  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004c2530
//
// 004c2530  6aff                 push -1
// 004c2532  68e9f3a900           push 0xa9f3e9
// 004c2537  64a100000000         mov eax, dword ptr fs:[0]
// 004c253d  50                   push eax
// 004c253e  64892500000000       mov dword ptr fs:[0], esp
// 004c2545  51                   push ecx
// 004c2546  56                   push esi
// 004c2547  57                   push edi
// 004c2548  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004c254c  8bf1                 mov esi, ecx
// 004c254e  57                   push edi
// 004c254f  8974240c             mov dword ptr [esp + 0xc], esi
// 004c2553  ff154426b200         call dword ptr [0xb22644]
// 004c2559  83c71c               add edi, 0x1c
// 004c255c  57                   push edi
// 004c255d  8d4e1c               lea ecx, [esi + 0x1c]
// 004c2560  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004c2568  ff153030b200         call dword ptr [0xb23030]
// 004c256e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004c2572  5f                   pop edi
// 004c2573  8bc6                 mov eax, esi
// 004c2575  5e                   pop esi
// 004c2576  64890d00000000       mov dword ptr fs:[0], ecx
// 004c257d  83c410               add esp, 0x10
// 004c2580  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
