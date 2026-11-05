// from server: 100% by auto
// roc 2012-06 00846140  unit: RBX::Lua::VWaitScriptSlot::?$TGenericSlotWrapper  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00846140
//
// 00846140  55                   push ebp
// 00846141  8bec                 mov ebp, esp
// 00846143  6aff                 push -1
// 00846145  6861d4ac00           push 0xacd461
// 0084614a  64a100000000         mov eax, dword ptr fs:[0]
// 00846150  50                   push eax
// 00846151  64892500000000       mov dword ptr fs:[0], esp
// 00846158  83ec08               sub esp, 8
// 0084615b  53                   push ebx
// 0084615c  56                   push esi
// 0084615d  57                   push edi
// 0084615e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00846161  6a24                 push 0x24
// 00846163  e8b2bf1300           call 0x98211a
// 00846168  8bf0                 mov esi, eax
// 0084616a  83c404               add esp, 4
// 0084616d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00846170  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00846177  85f6                 test esi, esi
// 00846179  7405                 je 0x846180
// 0084617b  8b4508               mov eax, dword ptr [ebp + 8]
// 0084617e  8906                 mov dword ptr [esi], eax
// 00846180  8d4604               lea eax, [esi + 4]
// 00846183  85c0                 test eax, eax
// 00846185  7405                 je 0x84618c
// 00846187  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0084618a  8908                 mov dword ptr [eax], ecx
// 0084618c  8d4e08               lea ecx, [esi + 8]
// 0084618f  894d08               mov dword ptr [ebp + 8], ecx
// 00846192  894d0c               mov dword ptr [ebp + 0xc], ecx
// 00846195  c645fc01             mov byte ptr [ebp - 4], 1
// 00846199  85c9                 test ecx, ecx
// 0084619b  740a                 je 0x8461a7
// 0084619d  8b5510               mov edx, dword ptr [ebp + 0x10]
// 008461a0  52                   push edx
// 008461a1  ff154426b200         call dword ptr [0xb22644]
// 008461a7  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 008461aa  5f                   pop edi
// 008461ab  8bc6                 mov eax, esi
// 008461ad  5e                   pop esi
// 008461ae  64890d00000000       mov dword ptr fs:[0], ecx
// 008461b5  5b                   pop ebx
// 008461b6  8be5                 mov esp, ebp
// 008461b8  5d                   pop ebp
// 008461b9  c20c00               ret 0xc
// standard library list<string> (function ?_Buynode@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@PAU342@0ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
