// from server: 100% by auto
// roc 2010-06 005eafa0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005eafa0
//
// 005eafa0  83ec08               sub esp, 8
// 005eafa3  53                   push ebx
// 005eafa4  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 005eafaa  56                   push esi
// 005eafab  8bf1                 mov esi, ecx
// 005eafad  8b4614               mov eax, dword ptr [esi + 0x14]
// 005eafb0  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005eafb4  57                   push edi
// 005eafb5  8b38                 mov edi, dword ptr [eax]
// 005eafb7  8b06                 mov eax, dword ptr [esi]
// 005eafb9  85c9                 test ecx, ecx
// 005eafbb  7404                 je 0x5eafc1
// 005eafbd  3bc8                 cmp ecx, eax
// 005eafbf  7406                 je 0x5eafc7
// 005eafc1  ffd3                 call ebx
// 005eafc3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005eafc7  8b442420             mov eax, dword ptr [esp + 0x20]
// 005eafcb  3bc7                 cmp eax, edi
// 005eafcd  7541                 jne 0x5eb010
// 005eafcf  8b7e14               mov edi, dword ptr [esi + 0x14]
// 005eafd2  8b16                 mov edx, dword ptr [esi]
// 005eafd4  55                   push ebp
// 005eafd5  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 005eafd9  85ed                 test ebp, ebp
// 005eafdb  7404                 je 0x5eafe1
// 005eafdd  3bea                 cmp ebp, edx
// 005eafdf  740a                 je 0x5eafeb
// 005eafe1  ffd3                 call ebx
// 005eafe3  8b442424             mov eax, dword ptr [esp + 0x24]
// 005eafe7  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005eafeb  5d                   pop ebp
// 005eafec  397c2428             cmp dword ptr [esp + 0x28], edi
// 005eaff0  751e                 jne 0x5eb010
// 005eaff2  8bce                 mov ecx, esi
// 005eaff4  e857ca0f00           call 0x6e7a50
// 005eaff9  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005eaffc  8b16                 mov edx, dword ptr [esi]
// 005eaffe  8b442418             mov eax, dword ptr [esp + 0x18]
// 005eb002  5f                   pop edi
// 005eb003  5e                   pop esi
// 005eb004  894804               mov dword ptr [eax + 4], ecx
// 005eb007  8910                 mov dword ptr [eax], edx
// 005eb009  5b                   pop ebx
// 005eb00a  83c408               add esp, 8
// 005eb00d  c21400               ret 0x14
// 005eb010  85c9                 test ecx, ecx
// 005eb012  7406                 je 0x5eb01a
// 005eb014  3b4c2424             cmp ecx, dword ptr [esp + 0x24]
// 005eb018  740a                 je 0x5eb024
// 005eb01a  ffd3                 call ebx
// 005eb01c  8b442420             mov eax, dword ptr [esp + 0x20]
// 005eb020  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005eb024  8b542428             mov edx, dword ptr [esp + 0x28]
// 005eb028  3bc2                 cmp eax, edx
// 005eb02a  741d                 je 0x5eb049
// 005eb02c  50                   push eax
// 005eb02d  51                   push ecx
// 005eb02e  8d442414             lea eax, [esp + 0x14]
// 005eb032  50                   push eax
// 005eb033  8bce                 mov ecx, esi
// 005eb035  e806383100           call 0x8fe840
// 005eb03a  8b08                 mov ecx, dword ptr [eax]
// 005eb03c  894c241c             mov dword ptr [esp + 0x1c], ecx
// 005eb040  8b4004               mov eax, dword ptr [eax + 4]
// 005eb043  89442420             mov dword ptr [esp + 0x20], eax
// 005eb047  ebc7                 jmp 0x5eb010
// 005eb049  8b0e                 mov ecx, dword ptr [esi]
// 005eb04b  8b442418             mov eax, dword ptr [esp + 0x18]
// 005eb04f  5f                   pop edi
// 005eb050  5e                   pop esi
// 005eb051  895004               mov dword ptr [eax + 4], edx
// 005eb054  8908                 mov dword ptr [eax], ecx
// 005eb056  5b                   pop ebx
// 005eb057  83c408               add esp, 8
// 005eb05a  c21400               ret 0x14
// standard library list<ptr> (function ?erase@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
