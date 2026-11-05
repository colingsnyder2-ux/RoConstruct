// from server: 100% by auto
// roc 2009-06 00619ae0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00619ae0
//
// 00619ae0  83ec08               sub esp, 8
// 00619ae3  53                   push ebx
// 00619ae4  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00619aea  56                   push esi
// 00619aeb  8bf1                 mov esi, ecx
// 00619aed  8b4614               mov eax, dword ptr [esi + 0x14]
// 00619af0  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00619af4  57                   push edi
// 00619af5  8b38                 mov edi, dword ptr [eax]
// 00619af7  8b06                 mov eax, dword ptr [esi]
// 00619af9  85c9                 test ecx, ecx
// 00619afb  7404                 je 0x619b01
// 00619afd  3bc8                 cmp ecx, eax
// 00619aff  7406                 je 0x619b07
// 00619b01  ffd3                 call ebx
// 00619b03  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00619b07  8b442420             mov eax, dword ptr [esp + 0x20]
// 00619b0b  3bc7                 cmp eax, edi
// 00619b0d  7541                 jne 0x619b50
// 00619b0f  8b7e14               mov edi, dword ptr [esi + 0x14]
// 00619b12  8b16                 mov edx, dword ptr [esi]
// 00619b14  55                   push ebp
// 00619b15  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 00619b19  85ed                 test ebp, ebp
// 00619b1b  7404                 je 0x619b21
// 00619b1d  3bea                 cmp ebp, edx
// 00619b1f  740a                 je 0x619b2b
// 00619b21  ffd3                 call ebx
// 00619b23  8b442424             mov eax, dword ptr [esp + 0x24]
// 00619b27  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00619b2b  5d                   pop ebp
// 00619b2c  397c2428             cmp dword ptr [esp + 0x28], edi
// 00619b30  751e                 jne 0x619b50
// 00619b32  8bce                 mov ecx, esi
// 00619b34  e807cbe5ff           call 0x476640
// 00619b39  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00619b3c  8b16                 mov edx, dword ptr [esi]
// 00619b3e  8b442418             mov eax, dword ptr [esp + 0x18]
// 00619b42  5f                   pop edi
// 00619b43  5e                   pop esi
// 00619b44  894804               mov dword ptr [eax + 4], ecx
// 00619b47  8910                 mov dword ptr [eax], edx
// 00619b49  5b                   pop ebx
// 00619b4a  83c408               add esp, 8
// 00619b4d  c21400               ret 0x14
// 00619b50  85c9                 test ecx, ecx
// 00619b52  7406                 je 0x619b5a
// 00619b54  3b4c2424             cmp ecx, dword ptr [esp + 0x24]
// 00619b58  740a                 je 0x619b64
// 00619b5a  ffd3                 call ebx
// 00619b5c  8b442420             mov eax, dword ptr [esp + 0x20]
// 00619b60  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00619b64  8b542428             mov edx, dword ptr [esp + 0x28]
// 00619b68  3bc2                 cmp eax, edx
// 00619b6a  741d                 je 0x619b89
// 00619b6c  50                   push eax
// 00619b6d  51                   push ecx
// 00619b6e  8d442414             lea eax, [esp + 0x14]
// 00619b72  50                   push eax
// 00619b73  8bce                 mov ecx, esi
// 00619b75  e8b6cfe5ff           call 0x476b30
// 00619b7a  8b08                 mov ecx, dword ptr [eax]
// 00619b7c  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00619b80  8b4004               mov eax, dword ptr [eax + 4]
// 00619b83  89442420             mov dword ptr [esp + 0x20], eax
// 00619b87  ebc7                 jmp 0x619b50
// 00619b89  8b0e                 mov ecx, dword ptr [esi]
// 00619b8b  8b442418             mov eax, dword ptr [esp + 0x18]
// 00619b8f  5f                   pop edi
// 00619b90  5e                   pop esi
// 00619b91  895004               mov dword ptr [eax + 4], edx
// 00619b94  8908                 mov dword ptr [eax], ecx
// 00619b96  5b                   pop ebx
// 00619b97  83c408               add esp, 8
// 00619b9a  c21400               ret 0x14
// standard library list<ptr> (function ?erase@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
