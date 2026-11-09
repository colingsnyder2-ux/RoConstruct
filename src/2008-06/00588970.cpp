// from server: 100% by auto
// roc 2008-06 00588970  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00588970
//
// 00588970  83ec08               sub esp, 8
// 00588973  53                   push ebx
// 00588974  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0058897a  56                   push esi
// 0058897b  8bf1                 mov esi, ecx
// 0058897d  8b4614               mov eax, dword ptr [esi + 0x14]
// 00588980  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00588984  57                   push edi
// 00588985  8b38                 mov edi, dword ptr [eax]
// 00588987  8b06                 mov eax, dword ptr [esi]
// 00588989  85c9                 test ecx, ecx
// 0058898b  7404                 je 0x588991
// 0058898d  3bc8                 cmp ecx, eax
// 0058898f  7406                 je 0x588997
// 00588991  ffd3                 call ebx
// 00588993  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00588997  8b442420             mov eax, dword ptr [esp + 0x20]
// 0058899b  3bc7                 cmp eax, edi
// 0058899d  7541                 jne 0x5889e0
// 0058899f  8b7e14               mov edi, dword ptr [esi + 0x14]
// 005889a2  8b16                 mov edx, dword ptr [esi]
// 005889a4  55                   push ebp
// 005889a5  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 005889a9  85ed                 test ebp, ebp
// 005889ab  7404                 je 0x5889b1
// 005889ad  3bea                 cmp ebp, edx
// 005889af  740a                 je 0x5889bb
// 005889b1  ffd3                 call ebx
// 005889b3  8b442424             mov eax, dword ptr [esp + 0x24]
// 005889b7  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005889bb  5d                   pop ebp
// 005889bc  397c2428             cmp dword ptr [esp + 0x28], edi
// 005889c0  751e                 jne 0x5889e0
// 005889c2  8bce                 mov ecx, esi
// 005889c4  e8d7ebffff           call 0x5875a0
// 005889c9  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005889cc  8b16                 mov edx, dword ptr [esi]
// 005889ce  8b442418             mov eax, dword ptr [esp + 0x18]
// 005889d2  5f                   pop edi
// 005889d3  5e                   pop esi
// 005889d4  894804               mov dword ptr [eax + 4], ecx
// 005889d7  8910                 mov dword ptr [eax], edx
// 005889d9  5b                   pop ebx
// 005889da  83c408               add esp, 8
// 005889dd  c21400               ret 0x14
// 005889e0  85c9                 test ecx, ecx
// 005889e2  7406                 je 0x5889ea
// 005889e4  3b4c2424             cmp ecx, dword ptr [esp + 0x24]
// 005889e8  740a                 je 0x5889f4
// 005889ea  ffd3                 call ebx
// 005889ec  8b442420             mov eax, dword ptr [esp + 0x20]
// 005889f0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005889f4  8b542428             mov edx, dword ptr [esp + 0x28]
// 005889f8  3bc2                 cmp eax, edx
// 005889fa  741d                 je 0x588a19
// 005889fc  50                   push eax
// 005889fd  51                   push ecx
// 005889fe  8d442414             lea eax, [esp + 0x14]
// 00588a02  50                   push eax
// 00588a03  8bce                 mov ecx, esi
// 00588a05  e8e6feffff           call 0x5888f0
// 00588a0a  8b08                 mov ecx, dword ptr [eax]
// 00588a0c  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00588a10  8b4004               mov eax, dword ptr [eax + 4]
// 00588a13  89442420             mov dword ptr [esp + 0x20], eax
// 00588a17  ebc7                 jmp 0x5889e0
// 00588a19  8b0e                 mov ecx, dword ptr [esi]
// 00588a1b  8b442418             mov eax, dword ptr [esp + 0x18]
// 00588a1f  5f                   pop edi
// 00588a20  5e                   pop esi
// 00588a21  895004               mov dword ptr [eax + 4], edx
// 00588a24  8908                 mov dword ptr [eax], ecx
// 00588a26  5b                   pop ebx
// 00588a27  83c408               add esp, 8
// 00588a2a  c21400               ret 0x14
// standard library list<ptr> (function ?erase@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
