// from server: 100% by auto
// roc 2011-06 00773d00  unit: RBX::Lua::VWaitScriptSlot::?$TGenericSlotWrapper  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00773d00
//
// 00773d00  55                   push ebp
// 00773d01  8bec                 mov ebp, esp
// 00773d03  6aff                 push -1
// 00773d05  6841b09f00           push 0x9fb041
// 00773d0a  64a100000000         mov eax, dword ptr fs:[0]
// 00773d10  50                   push eax
// 00773d11  64892500000000       mov dword ptr fs:[0], esp
// 00773d18  83ec08               sub esp, 8
// 00773d1b  53                   push ebx
// 00773d1c  56                   push esi
// 00773d1d  57                   push edi
// 00773d1e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00773d21  6a24                 push 0x24
// 00773d23  e836630900           call 0x80a05e
// 00773d28  8bf0                 mov esi, eax
// 00773d2a  83c404               add esp, 4
// 00773d2d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00773d30  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00773d37  85f6                 test esi, esi
// 00773d39  7405                 je 0x773d40
// 00773d3b  8b4508               mov eax, dword ptr [ebp + 8]
// 00773d3e  8906                 mov dword ptr [esi], eax
// 00773d40  8d4604               lea eax, [esi + 4]
// 00773d43  85c0                 test eax, eax
// 00773d45  7405                 je 0x773d4c
// 00773d47  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00773d4a  8908                 mov dword ptr [eax], ecx
// 00773d4c  8d4e08               lea ecx, [esi + 8]
// 00773d4f  894d08               mov dword ptr [ebp + 8], ecx
// 00773d52  894d0c               mov dword ptr [ebp + 0xc], ecx
// 00773d55  c645fc01             mov byte ptr [ebp - 4], 1
// 00773d59  85c9                 test ecx, ecx
// 00773d5b  740a                 je 0x773d67
// 00773d5d  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00773d60  52                   push edx
// 00773d61  ff15c804a400         call dword ptr [0xa404c8]
// 00773d67  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00773d6a  5f                   pop edi
// 00773d6b  8bc6                 mov eax, esi
// 00773d6d  5e                   pop esi
// 00773d6e  64890d00000000       mov dword ptr fs:[0], ecx
// 00773d75  5b                   pop ebx
// 00773d76  8be5                 mov esp, ebp
// 00773d78  5d                   pop ebp
// 00773d79  c20c00               ret 0xc
// standard library list<string> (function ?_Buynode@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@PAU342@0ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
