// from server: 100% by auto
// roc 2007-08 00558680  unit: RBX::DataModel  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00558680
//
// 00558680  6aff                 push -1
// 00558682  6858197500           push 0x751958
// 00558687  64a100000000         mov eax, dword ptr fs:[0]
// 0055868d  50                   push eax
// 0055868e  64892500000000       mov dword ptr fs:[0], esp
// 00558695  51                   push ecx
// 00558696  56                   push esi
// 00558697  57                   push edi
// 00558698  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0055869c  8bf1                 mov esi, ecx
// 0055869e  57                   push edi
// 0055869f  8974240c             mov dword ptr [esp + 0xc], esi
// 005586a3  ff159ce67700         call dword ptr [0x77e69c]
// 005586a9  83c71c               add edi, 0x1c
// 005586ac  57                   push edi
// 005586ad  8d4e1c               lea ecx, [esi + 0x1c]
// 005586b0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 005586b8  ff159ce67700         call dword ptr [0x77e69c]
// 005586be  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005586c2  5f                   pop edi
// 005586c3  8bc6                 mov eax, esi
// 005586c5  5e                   pop esi
// 005586c6  64890d00000000       mov dword ptr fs:[0], ecx
// 005586cd  83c410               add esp, 0x10
// 005586d0  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
