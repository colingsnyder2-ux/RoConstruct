// from server: 100% by auto
// roc 2009-12 005d1c80  unit: G3D::VVector3::?$Table  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005d1c80
//
// 005d1c80  6aff                 push -1
// 005d1c82  68d8c59300           push 0x93c5d8
// 005d1c87  64a100000000         mov eax, dword ptr fs:[0]
// 005d1c8d  50                   push eax
// 005d1c8e  64892500000000       mov dword ptr fs:[0], esp
// 005d1c95  51                   push ecx
// 005d1c96  56                   push esi
// 005d1c97  8bf1                 mov esi, ecx
// 005d1c99  6a04                 push 4
// 005d1c9b  89742408             mov dword ptr [esp + 8], esi
// 005d1c9f  e8bc1b2200           call 0x7f3860
// 005d1ca4  83c404               add esp, 4
// 005d1ca7  85c0                 test eax, eax
// 005d1ca9  7404                 je 0x5d1caf
// 005d1cab  8930                 mov dword ptr [eax], esi
// 005d1cad  eb02                 jmp 0x5d1cb1
// 005d1caf  33c0                 xor eax, eax
// 005d1cb1  8906                 mov dword ptr [esi], eax
// 005d1cb3  8bce                 mov ecx, esi
// 005d1cb5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005d1cbd  e8eec8ffff           call 0x5ce5b0
// 005d1cc2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005d1cc6  894618               mov dword ptr [esi + 0x18], eax
// 005d1cc9  c6402901             mov byte ptr [eax + 0x29], 1
// 005d1ccd  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d1cd0  894004               mov dword ptr [eax + 4], eax
// 005d1cd3  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d1cd6  8900                 mov dword ptr [eax], eax
// 005d1cd8  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d1cdb  894008               mov dword ptr [eax + 8], eax
// 005d1cde  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005d1ce5  8bc6                 mov eax, esi
// 005d1ce7  5e                   pop esi
// 005d1ce8  64890d00000000       mov dword ptr fs:[0], ecx
// 005d1cef  83c410               add esp, 0x10
// 005d1cf2  c20800               ret 8
// standard library set<string> (function ??0?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@ABV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
