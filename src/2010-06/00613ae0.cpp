// from server: 100% by auto
// roc 2010-06 00613ae0  unit: RBX::VScriptContext::?$FactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00613ae0
//
// 00613ae0  83ec08               sub esp, 8
// 00613ae3  53                   push ebx
// 00613ae4  55                   push ebp
// 00613ae5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00613aeb  56                   push esi
// 00613aec  8bf1                 mov esi, ecx
// 00613aee  8b4618               mov eax, dword ptr [esi + 0x18]
// 00613af1  8b18                 mov ebx, dword ptr [eax]
// 00613af3  8b06                 mov eax, dword ptr [esi]
// 00613af5  57                   push edi
// 00613af6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00613afa  85ff                 test edi, edi
// 00613afc  7404                 je 0x613b02
// 00613afe  3bf8                 cmp edi, eax
// 00613b00  7406                 je 0x613b08
// 00613b02  ffd5                 call ebp
// 00613b04  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00613b08  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00613b0c  7562                 jne 0x613b70
// 00613b0e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00613b12  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00613b15  8b06                 mov eax, dword ptr [esi]
// 00613b17  85c9                 test ecx, ecx
// 00613b19  7404                 je 0x613b1f
// 00613b1b  3bc8                 cmp ecx, eax
// 00613b1d  7406                 je 0x613b25
// 00613b1f  ffd5                 call ebp
// 00613b21  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00613b25  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00613b29  7545                 jne 0x613b70
// 00613b2b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00613b2e  8b5104               mov edx, dword ptr [ecx + 4]
// 00613b31  52                   push edx
// 00613b32  8bce                 mov ecx, esi
// 00613b34  e897e6ffff           call 0x6121d0
// 00613b39  8b4618               mov eax, dword ptr [esi + 0x18]
// 00613b3c  894004               mov dword ptr [eax + 4], eax
// 00613b3f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00613b42  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00613b49  8900                 mov dword ptr [eax], eax
// 00613b4b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00613b4e  894008               mov dword ptr [eax + 8], eax
// 00613b51  8b4618               mov eax, dword ptr [esi + 0x18]
// 00613b54  8b16                 mov edx, dword ptr [esi]
// 00613b56  8b08                 mov ecx, dword ptr [eax]
// 00613b58  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00613b5c  5f                   pop edi
// 00613b5d  5e                   pop esi
// 00613b5e  5d                   pop ebp
// 00613b5f  894804               mov dword ptr [eax + 4], ecx
// 00613b62  8910                 mov dword ptr [eax], edx
// 00613b64  5b                   pop ebx
// 00613b65  83c408               add esp, 8
// 00613b68  c21400               ret 0x14
// 00613b6b  eb03                 jmp 0x613b70
// 00613b6d  8d4900               lea ecx, [ecx]
// 00613b70  85ff                 test edi, edi
// 00613b72  7406                 je 0x613b7a
// 00613b74  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00613b78  7406                 je 0x613b80
// 00613b7a  ffd5                 call ebp
// 00613b7c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00613b80  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00613b84  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00613b88  741d                 je 0x613ba7
// 00613b8a  8d4c2420             lea ecx, [esp + 0x20]
// 00613b8e  e85d322b00           call 0x8c6df0
// 00613b93  53                   push ebx
// 00613b94  57                   push edi
// 00613b95  8d442418             lea eax, [esp + 0x18]
// 00613b99  50                   push eax
// 00613b9a  8bce                 mov ecx, esi
// 00613b9c  e82fe3ffff           call 0x611ed0
// 00613ba1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00613ba5  ebc9                 jmp 0x613b70
// 00613ba7  8b36                 mov esi, dword ptr [esi]
// 00613ba9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00613bad  5f                   pop edi
// 00613bae  8930                 mov dword ptr [eax], esi
// 00613bb0  5e                   pop esi
// 00613bb1  5d                   pop ebp
// 00613bb2  895804               mov dword ptr [eax + 4], ebx
// 00613bb5  5b                   pop ebx
// 00613bb6  83c408               add esp, 8
// 00613bb9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
