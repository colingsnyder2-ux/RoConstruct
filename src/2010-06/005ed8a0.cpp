// from server: 100% by auto
// roc 2010-06 005ed8a0  unit: RBX::VChangeHistoryService::?$BoundFuncDesc  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005ed8a0
//
// 005ed8a0  83ec08               sub esp, 8
// 005ed8a3  53                   push ebx
// 005ed8a4  55                   push ebp
// 005ed8a5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 005ed8ab  56                   push esi
// 005ed8ac  8bf1                 mov esi, ecx
// 005ed8ae  8b4618               mov eax, dword ptr [esi + 0x18]
// 005ed8b1  8b18                 mov ebx, dword ptr [eax]
// 005ed8b3  8b06                 mov eax, dword ptr [esi]
// 005ed8b5  57                   push edi
// 005ed8b6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005ed8ba  85ff                 test edi, edi
// 005ed8bc  7404                 je 0x5ed8c2
// 005ed8be  3bf8                 cmp edi, eax
// 005ed8c0  7406                 je 0x5ed8c8
// 005ed8c2  ffd5                 call ebp
// 005ed8c4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005ed8c8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 005ed8cc  7562                 jne 0x5ed930
// 005ed8ce  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005ed8d2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 005ed8d5  8b06                 mov eax, dword ptr [esi]
// 005ed8d7  85c9                 test ecx, ecx
// 005ed8d9  7404                 je 0x5ed8df
// 005ed8db  3bc8                 cmp ecx, eax
// 005ed8dd  7406                 je 0x5ed8e5
// 005ed8df  ffd5                 call ebp
// 005ed8e1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005ed8e5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005ed8e9  7545                 jne 0x5ed930
// 005ed8eb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005ed8ee  8b5104               mov edx, dword ptr [ecx + 4]
// 005ed8f1  52                   push edx
// 005ed8f2  8bce                 mov ecx, esi
// 005ed8f4  e817eaffff           call 0x5ec310
// 005ed8f9  8b4618               mov eax, dword ptr [esi + 0x18]
// 005ed8fc  894004               mov dword ptr [eax + 4], eax
// 005ed8ff  8b4618               mov eax, dword ptr [esi + 0x18]
// 005ed902  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005ed909  8900                 mov dword ptr [eax], eax
// 005ed90b  8b4618               mov eax, dword ptr [esi + 0x18]
// 005ed90e  894008               mov dword ptr [eax + 8], eax
// 005ed911  8b4618               mov eax, dword ptr [esi + 0x18]
// 005ed914  8b16                 mov edx, dword ptr [esi]
// 005ed916  8b08                 mov ecx, dword ptr [eax]
// 005ed918  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005ed91c  5f                   pop edi
// 005ed91d  5e                   pop esi
// 005ed91e  5d                   pop ebp
// 005ed91f  894804               mov dword ptr [eax + 4], ecx
// 005ed922  8910                 mov dword ptr [eax], edx
// 005ed924  5b                   pop ebx
// 005ed925  83c408               add esp, 8
// 005ed928  c21400               ret 0x14
// 005ed92b  eb03                 jmp 0x5ed930
// 005ed92d  8d4900               lea ecx, [ecx]
// 005ed930  85ff                 test edi, edi
// 005ed932  7406                 je 0x5ed93a
// 005ed934  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005ed938  7406                 je 0x5ed940
// 005ed93a  ffd5                 call ebp
// 005ed93c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005ed940  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005ed944  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005ed948  741d                 je 0x5ed967
// 005ed94a  8d4c2420             lea ecx, [esp + 0x20]
// 005ed94e  e8eddc0100           call 0x60b640
// 005ed953  53                   push ebx
// 005ed954  57                   push edi
// 005ed955  8d442418             lea eax, [esp + 0x18]
// 005ed959  50                   push eax
// 005ed95a  8bce                 mov ecx, esi
// 005ed95c  e88ff2ffff           call 0x5ecbf0
// 005ed961  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005ed965  ebc9                 jmp 0x5ed930
// 005ed967  8b36                 mov esi, dword ptr [esi]
// 005ed969  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005ed96d  5f                   pop edi
// 005ed96e  8930                 mov dword ptr [eax], esi
// 005ed970  5e                   pop esi
// 005ed971  5d                   pop ebp
// 005ed972  895804               mov dword ptr [eax + 4], ebx
// 005ed975  5b                   pop ebx
// 005ed976  83c408               add esp, 8
// 005ed979  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
