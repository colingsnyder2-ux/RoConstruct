// from server: 100% by auto
// roc 2010-06 00541ab0  unit: RBX::AggregatingSceneManager  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00541ab0
//
// 00541ab0  83ec08               sub esp, 8
// 00541ab3  53                   push ebx
// 00541ab4  55                   push ebp
// 00541ab5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00541abb  56                   push esi
// 00541abc  8bf1                 mov esi, ecx
// 00541abe  8b4618               mov eax, dword ptr [esi + 0x18]
// 00541ac1  8b18                 mov ebx, dword ptr [eax]
// 00541ac3  8b06                 mov eax, dword ptr [esi]
// 00541ac5  57                   push edi
// 00541ac6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00541aca  85ff                 test edi, edi
// 00541acc  7404                 je 0x541ad2
// 00541ace  3bf8                 cmp edi, eax
// 00541ad0  7406                 je 0x541ad8
// 00541ad2  ffd5                 call ebp
// 00541ad4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00541ad8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00541adc  7562                 jne 0x541b40
// 00541ade  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00541ae2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00541ae5  8b06                 mov eax, dword ptr [esi]
// 00541ae7  85c9                 test ecx, ecx
// 00541ae9  7404                 je 0x541aef
// 00541aeb  3bc8                 cmp ecx, eax
// 00541aed  7406                 je 0x541af5
// 00541aef  ffd5                 call ebp
// 00541af1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00541af5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00541af9  7545                 jne 0x541b40
// 00541afb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00541afe  8b5104               mov edx, dword ptr [ecx + 4]
// 00541b01  52                   push edx
// 00541b02  8bce                 mov ecx, esi
// 00541b04  e8a7f3ffff           call 0x540eb0
// 00541b09  8b4618               mov eax, dword ptr [esi + 0x18]
// 00541b0c  894004               mov dword ptr [eax + 4], eax
// 00541b0f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00541b12  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00541b19  8900                 mov dword ptr [eax], eax
// 00541b1b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00541b1e  894008               mov dword ptr [eax + 8], eax
// 00541b21  8b4618               mov eax, dword ptr [esi + 0x18]
// 00541b24  8b16                 mov edx, dword ptr [esi]
// 00541b26  8b08                 mov ecx, dword ptr [eax]
// 00541b28  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00541b2c  5f                   pop edi
// 00541b2d  5e                   pop esi
// 00541b2e  5d                   pop ebp
// 00541b2f  894804               mov dword ptr [eax + 4], ecx
// 00541b32  8910                 mov dword ptr [eax], edx
// 00541b34  5b                   pop ebx
// 00541b35  83c408               add esp, 8
// 00541b38  c21400               ret 0x14
// 00541b3b  eb03                 jmp 0x541b40
// 00541b3d  8d4900               lea ecx, [ecx]
// 00541b40  85ff                 test edi, edi
// 00541b42  7406                 je 0x541b4a
// 00541b44  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00541b48  7406                 je 0x541b50
// 00541b4a  ffd5                 call ebp
// 00541b4c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00541b50  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00541b54  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00541b58  741d                 je 0x541b77
// 00541b5a  8d4c2420             lea ecx, [esp + 0x20]
// 00541b5e  e87d5e1a00           call 0x6e79e0
// 00541b63  53                   push ebx
// 00541b64  57                   push edi
// 00541b65  8d442418             lea eax, [esp + 0x18]
// 00541b69  50                   push eax
// 00541b6a  8bce                 mov ecx, esi
// 00541b6c  e82ff5ffff           call 0x5410a0
// 00541b71  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00541b75  ebc9                 jmp 0x541b40
// 00541b77  8b36                 mov esi, dword ptr [esi]
// 00541b79  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00541b7d  5f                   pop edi
// 00541b7e  8930                 mov dword ptr [eax], esi
// 00541b80  5e                   pop esi
// 00541b81  5d                   pop ebp
// 00541b82  895804               mov dword ptr [eax + 4], ebx
// 00541b85  5b                   pop ebx
// 00541b86  83c408               add esp, 8
// 00541b89  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
