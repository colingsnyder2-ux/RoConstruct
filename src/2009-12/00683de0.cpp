// from server: 100% by auto
// roc 2009-12 00683de0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00683de0
//
// 00683de0  83ec08               sub esp, 8
// 00683de3  53                   push ebx
// 00683de4  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00683dea  56                   push esi
// 00683deb  8bf1                 mov esi, ecx
// 00683ded  8b4614               mov eax, dword ptr [esi + 0x14]
// 00683df0  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00683df4  57                   push edi
// 00683df5  8b38                 mov edi, dword ptr [eax]
// 00683df7  8b06                 mov eax, dword ptr [esi]
// 00683df9  85c9                 test ecx, ecx
// 00683dfb  7404                 je 0x683e01
// 00683dfd  3bc8                 cmp ecx, eax
// 00683dff  7406                 je 0x683e07
// 00683e01  ffd3                 call ebx
// 00683e03  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00683e07  8b442420             mov eax, dword ptr [esp + 0x20]
// 00683e0b  3bc7                 cmp eax, edi
// 00683e0d  7541                 jne 0x683e50
// 00683e0f  8b7e14               mov edi, dword ptr [esi + 0x14]
// 00683e12  8b16                 mov edx, dword ptr [esi]
// 00683e14  55                   push ebp
// 00683e15  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 00683e19  85ed                 test ebp, ebp
// 00683e1b  7404                 je 0x683e21
// 00683e1d  3bea                 cmp ebp, edx
// 00683e1f  740a                 je 0x683e2b
// 00683e21  ffd3                 call ebx
// 00683e23  8b442424             mov eax, dword ptr [esp + 0x24]
// 00683e27  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00683e2b  5d                   pop ebp
// 00683e2c  397c2428             cmp dword ptr [esp + 0x28], edi
// 00683e30  751e                 jne 0x683e50
// 00683e32  8bce                 mov ecx, esi
// 00683e34  e8677eefff           call 0x57bca0
// 00683e39  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00683e3c  8b16                 mov edx, dword ptr [esi]
// 00683e3e  8b442418             mov eax, dword ptr [esp + 0x18]
// 00683e42  5f                   pop edi
// 00683e43  5e                   pop esi
// 00683e44  894804               mov dword ptr [eax + 4], ecx
// 00683e47  8910                 mov dword ptr [eax], edx
// 00683e49  5b                   pop ebx
// 00683e4a  83c408               add esp, 8
// 00683e4d  c21400               ret 0x14
// 00683e50  85c9                 test ecx, ecx
// 00683e52  7406                 je 0x683e5a
// 00683e54  3b4c2424             cmp ecx, dword ptr [esp + 0x24]
// 00683e58  740a                 je 0x683e64
// 00683e5a  ffd3                 call ebx
// 00683e5c  8b442420             mov eax, dword ptr [esp + 0x20]
// 00683e60  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00683e64  8b542428             mov edx, dword ptr [esp + 0x28]
// 00683e68  3bc2                 cmp eax, edx
// 00683e6a  741d                 je 0x683e89
// 00683e6c  50                   push eax
// 00683e6d  51                   push ecx
// 00683e6e  8d442414             lea eax, [esp + 0x14]
// 00683e72  50                   push eax
// 00683e73  8bce                 mov ecx, esi
// 00683e75  e82671e2ff           call 0x4aafa0
// 00683e7a  8b08                 mov ecx, dword ptr [eax]
// 00683e7c  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00683e80  8b4004               mov eax, dword ptr [eax + 4]
// 00683e83  89442420             mov dword ptr [esp + 0x20], eax
// 00683e87  ebc7                 jmp 0x683e50
// 00683e89  8b0e                 mov ecx, dword ptr [esi]
// 00683e8b  8b442418             mov eax, dword ptr [esp + 0x18]
// 00683e8f  5f                   pop edi
// 00683e90  5e                   pop esi
// 00683e91  895004               mov dword ptr [eax + 4], edx
// 00683e94  8908                 mov dword ptr [eax], ecx
// 00683e96  5b                   pop ebx
// 00683e97  83c408               add esp, 8
// 00683e9a  c21400               ret 0x14
// standard library list<ptr> (function ?erase@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
