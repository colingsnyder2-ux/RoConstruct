// from server: 100% by auto
// roc 2008-06 0040f1e0  unit: VCBrowserViewExternal::?$CProxy_IBrowserViewExternalEvents  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040f1e0
//
// 0040f1e0  55                   push ebp
// 0040f1e1  8bec                 mov ebp, esp
// 0040f1e3  6aff                 push -1
// 0040f1e5  68a1d47b00           push 0x7bd4a1
// 0040f1ea  64a100000000         mov eax, dword ptr fs:[0]
// 0040f1f0  50                   push eax
// 0040f1f1  64892500000000       mov dword ptr fs:[0], esp
// 0040f1f8  83ec08               sub esp, 8
// 0040f1fb  53                   push ebx
// 0040f1fc  56                   push esi
// 0040f1fd  57                   push edi
// 0040f1fe  8965f0               mov dword ptr [ebp - 0x10], esp
// 0040f201  6a24                 push 0x24
// 0040f203  e818172900           call 0x6a0920
// 0040f208  8bf0                 mov esi, eax
// 0040f20a  83c404               add esp, 4
// 0040f20d  8975ec               mov dword ptr [ebp - 0x14], esi
// 0040f210  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0040f217  85f6                 test esi, esi
// 0040f219  7405                 je 0x40f220
// 0040f21b  8b4508               mov eax, dword ptr [ebp + 8]
// 0040f21e  8906                 mov dword ptr [esi], eax
// 0040f220  8d4604               lea eax, [esi + 4]
// 0040f223  85c0                 test eax, eax
// 0040f225  7405                 je 0x40f22c
// 0040f227  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0040f22a  8908                 mov dword ptr [eax], ecx
// 0040f22c  8d4e08               lea ecx, [esi + 8]
// 0040f22f  894d08               mov dword ptr [ebp + 8], ecx
// 0040f232  894d0c               mov dword ptr [ebp + 0xc], ecx
// 0040f235  c645fc01             mov byte ptr [ebp - 4], 1
// 0040f239  85c9                 test ecx, ecx
// 0040f23b  740a                 je 0x40f247
// 0040f23d  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0040f240  52                   push edx
// 0040f241  ff155c248000         call dword ptr [0x80245c]
// 0040f247  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0040f24a  5f                   pop edi
// 0040f24b  8bc6                 mov eax, esi
// 0040f24d  5e                   pop esi
// 0040f24e  64890d00000000       mov dword ptr fs:[0], ecx
// 0040f255  5b                   pop ebx
// 0040f256  8be5                 mov esp, ebp
// 0040f258  5d                   pop ebp
// 0040f259  c20c00               ret 0xc
// standard library list<string> (function ?_Buynode@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@PAU342@0ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
