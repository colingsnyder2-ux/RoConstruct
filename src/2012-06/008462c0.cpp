// from server: 100% by Xemicl
// roc 2012-06 008462c0  unit: RBX::Lua::VWaitScriptSlot::?$TGenericSlotWrapper  size: 147 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008462c0
//
// 008462c0  55                   push ebp
// 008462c1  8bec                 mov ebp, esp
// 008462c3  6aff                 push -1
// 008462c5  6881d4ac00           push 0xacd481
// 008462ca  64a100000000         mov eax, dword ptr fs:[0]
// 008462d0  50                   push eax
// 008462d1  64892500000000       mov dword ptr fs:[0], esp
// 008462d8  83ec0c               sub esp, 0xc
// 008462db  53                   push ebx
// 008462dc  56                   push esi
// 008462dd  57                   push edi
// 008462de  8965f0               mov dword ptr [ebp - 0x10], esp
// 008462e1  6a68                 push 0x68
// 008462e3  e832be1300           call 0x98211a
// 008462e8  8bf0                 mov esi, eax
// 008462ea  83c404               add esp, 4
// 008462ed  8975ec               mov dword ptr [ebp - 0x14], esi
// 008462f0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 008462f7  8975e8               mov dword ptr [ebp - 0x18], esi
// 008462fa  c645fc01             mov byte ptr [ebp - 4], 1
// 008462fe  85f6                 test esi, esi
// 00846300  7427                 je 0x846329
// 00846302  8b4508               mov eax, dword ptr [ebp + 8]
// 00846305  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00846308  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0084630b  8906                 mov dword ptr [esi], eax
// 0084630d  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00846310  894e04               mov dword ptr [esi + 4], ecx
// 00846313  50                   push eax
// 00846314  8d4e0c               lea ecx, [esi + 0xc]
// 00846317  895608               mov dword ptr [esi + 8], edx
// 0084631a  e861f5ffff           call 0x845880
// 0084631f  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 00846322  884e64               mov byte ptr [esi + 0x64], cl
// 00846325  c6466500             mov byte ptr [esi + 0x65], 0
// 00846329  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0084632c  5f                   pop edi
// 0084632d  8bc6                 mov eax, esi
// 0084632f  5e                   pop esi
// 00846330  64890d00000000       mov dword ptr fs:[0], ecx
// 00846337  5b                   pop ebx
// 00846338  8be5                 mov esp, ebp
// 0084633a  5d                   pop ebp
// 0084633b  c21400               ret 0x14
// 0084633e  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00846341  52                   push edx
// 00846342  e8cdbd1300           call 0x982114
// 00846347  83c404               add esp, 4
// 0084634a  6a00                 push 0
// 0084634c  6a00                 push 0
// 0084634e  e8f1cd1300           call 0x983144
// copied from an identical function in another client (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// from server: 100% by auto
// roc 2009-06 00413b10  unit: CutVerb  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00413b10
//
// 00413b10  8b542404             mov edx, dword ptr [esp + 4]
// 00413b14  8b4208               mov eax, dword ptr [edx + 8]
// 00413b17  56                   push esi
// 00413b18  8b30                 mov esi, dword ptr [eax]
// 00413b1a  897208               mov dword ptr [edx + 8], esi
// 00413b1d  8b30                 mov esi, dword ptr [eax]
// 00413b1f  807e4500             cmp byte ptr [esi + 0x45], 0
// 00413b23  7503                 jne 0x413b28
// 00413b25  895604               mov dword ptr [esi + 4], edx
// 00413b28  8b7204               mov esi, dword ptr [edx + 4]
// 00413b2b  897004               mov dword ptr [eax + 4], esi
// 00413b2e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00413b31  5e                   pop esi
// 00413b32  3b5104               cmp edx, dword ptr [ecx + 4]
// 00413b35  750b                 jne 0x413b42
// 00413b37  894104               mov dword ptr [ecx + 4], eax
// 00413b3a  8910                 mov dword ptr [eax], edx
// 00413b3c  894204               mov dword ptr [edx + 4], eax
// 00413b3f  c20400               ret 4
// 00413b42  8b4a04               mov ecx, dword ptr [edx + 4]
// 00413b45  3b11                 cmp edx, dword ptr [ecx]
// 00413b47  750a                 jne 0x413b53
// 00413b49  8901                 mov dword ptr [ecx], eax
// 00413b4b  8910                 mov dword ptr [eax], edx
// 00413b4d  894204               mov dword ptr [edx + 4], eax
// 00413b50  c20400               ret 4
// 00413b53  894108               mov dword ptr [ecx + 8], eax
// 00413b56  8910                 mov dword ptr [eax], edx
// 00413b58  894204               mov dword ptr [edx + 4], eax
// 00413b5b  c20400               ret 4
// standard library map_str<string> (function ?_Lrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<string>
#include <string>
struct E { std::string s; char pad[32]; };
#include <map>
#include <string>
template class std::map<std::string, E>;