// from server: 100% by auto
// roc 2012-06 00629360  unit: G3D::ReferenceCountedObject  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00629360
//
// 00629360  6aff                 push -1
// 00629362  68e9f3a900           push 0xa9f3e9
// 00629367  64a100000000         mov eax, dword ptr fs:[0]
// 0062936d  50                   push eax
// 0062936e  64892500000000       mov dword ptr fs:[0], esp
// 00629375  51                   push ecx
// 00629376  56                   push esi
// 00629377  57                   push edi
// 00629378  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0062937c  8bf1                 mov esi, ecx
// 0062937e  57                   push edi
// 0062937f  8974240c             mov dword ptr [esp + 0xc], esi
// 00629383  ff154426b200         call dword ptr [0xb22644]
// 00629389  83c71c               add edi, 0x1c
// 0062938c  57                   push edi
// 0062938d  8d4e1c               lea ecx, [esi + 0x1c]
// 00629390  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00629398  ff154426b200         call dword ptr [0xb22644]
// 0062939e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006293a2  5f                   pop edi
// 006293a3  8bc6                 mov eax, esi
// 006293a5  5e                   pop esi
// 006293a6  64890d00000000       mov dword ptr fs:[0], ecx
// 006293ad  83c410               add esp, 0x10
// 006293b0  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
