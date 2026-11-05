// from server: 100% by auto
// roc 2008-06 004d8680  unit: G3D::VVector3::?$Table  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d8680
//
// 004d8680  6aff                 push -1
// 004d8682  68e8727d00           push 0x7d72e8
// 004d8687  64a100000000         mov eax, dword ptr fs:[0]
// 004d868d  50                   push eax
// 004d868e  64892500000000       mov dword ptr fs:[0], esp
// 004d8695  51                   push ecx
// 004d8696  56                   push esi
// 004d8697  8bf1                 mov esi, ecx
// 004d8699  6a04                 push 4
// 004d869b  89742408             mov dword ptr [esp + 8], esi
// 004d869f  e87c821c00           call 0x6a0920
// 004d86a4  83c404               add esp, 4
// 004d86a7  85c0                 test eax, eax
// 004d86a9  7404                 je 0x4d86af
// 004d86ab  8930                 mov dword ptr [eax], esi
// 004d86ad  eb02                 jmp 0x4d86b1
// 004d86af  33c0                 xor eax, eax
// 004d86b1  8906                 mov dword ptr [esi], eax
// 004d86b3  8bce                 mov ecx, esi
// 004d86b5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004d86bd  e8aef0ffff           call 0x4d7770
// 004d86c2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004d86c6  894618               mov dword ptr [esi + 0x18], eax
// 004d86c9  c6402901             mov byte ptr [eax + 0x29], 1
// 004d86cd  8b4618               mov eax, dword ptr [esi + 0x18]
// 004d86d0  894004               mov dword ptr [eax + 4], eax
// 004d86d3  8b4618               mov eax, dword ptr [esi + 0x18]
// 004d86d6  8900                 mov dword ptr [eax], eax
// 004d86d8  8b4618               mov eax, dword ptr [esi + 0x18]
// 004d86db  894008               mov dword ptr [eax + 8], eax
// 004d86de  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004d86e5  8bc6                 mov eax, esi
// 004d86e7  5e                   pop esi
// 004d86e8  64890d00000000       mov dword ptr fs:[0], ecx
// 004d86ef  83c410               add esp, 0x10
// 004d86f2  c20800               ret 8
// standard library set<string> (function ??0?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@ABV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
