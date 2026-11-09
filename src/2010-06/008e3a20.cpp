// from server: 100% by auto
// roc 2010-06 008e3a20  unit: RBX::RbxTextureProxy  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e3a20
//
// 008e3a20  83ec08               sub esp, 8
// 008e3a23  53                   push ebx
// 008e3a24  55                   push ebp
// 008e3a25  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 008e3a2b  56                   push esi
// 008e3a2c  8bf1                 mov esi, ecx
// 008e3a2e  8b4618               mov eax, dword ptr [esi + 0x18]
// 008e3a31  8b18                 mov ebx, dword ptr [eax]
// 008e3a33  8b06                 mov eax, dword ptr [esi]
// 008e3a35  57                   push edi
// 008e3a36  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008e3a3a  85ff                 test edi, edi
// 008e3a3c  7404                 je 0x8e3a42
// 008e3a3e  3bf8                 cmp edi, eax
// 008e3a40  7406                 je 0x8e3a48
// 008e3a42  ffd5                 call ebp
// 008e3a44  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008e3a48  395c2424             cmp dword ptr [esp + 0x24], ebx
// 008e3a4c  7562                 jne 0x8e3ab0
// 008e3a4e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008e3a52  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 008e3a55  8b06                 mov eax, dword ptr [esi]
// 008e3a57  85c9                 test ecx, ecx
// 008e3a59  7404                 je 0x8e3a5f
// 008e3a5b  3bc8                 cmp ecx, eax
// 008e3a5d  7406                 je 0x8e3a65
// 008e3a5f  ffd5                 call ebp
// 008e3a61  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008e3a65  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 008e3a69  7545                 jne 0x8e3ab0
// 008e3a6b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 008e3a6e  8b5104               mov edx, dword ptr [ecx + 4]
// 008e3a71  52                   push edx
// 008e3a72  8bce                 mov ecx, esi
// 008e3a74  e85777d3ff           call 0x61b1d0
// 008e3a79  8b4618               mov eax, dword ptr [esi + 0x18]
// 008e3a7c  894004               mov dword ptr [eax + 4], eax
// 008e3a7f  8b4618               mov eax, dword ptr [esi + 0x18]
// 008e3a82  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 008e3a89  8900                 mov dword ptr [eax], eax
// 008e3a8b  8b4618               mov eax, dword ptr [esi + 0x18]
// 008e3a8e  894008               mov dword ptr [eax + 8], eax
// 008e3a91  8b4618               mov eax, dword ptr [esi + 0x18]
// 008e3a94  8b16                 mov edx, dword ptr [esi]
// 008e3a96  8b08                 mov ecx, dword ptr [eax]
// 008e3a98  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e3a9c  5f                   pop edi
// 008e3a9d  5e                   pop esi
// 008e3a9e  5d                   pop ebp
// 008e3a9f  894804               mov dword ptr [eax + 4], ecx
// 008e3aa2  8910                 mov dword ptr [eax], edx
// 008e3aa4  5b                   pop ebx
// 008e3aa5  83c408               add esp, 8
// 008e3aa8  c21400               ret 0x14
// 008e3aab  eb03                 jmp 0x8e3ab0
// 008e3aad  8d4900               lea ecx, [ecx]
// 008e3ab0  85ff                 test edi, edi
// 008e3ab2  7406                 je 0x8e3aba
// 008e3ab4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 008e3ab8  7406                 je 0x8e3ac0
// 008e3aba  ffd5                 call ebp
// 008e3abc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008e3ac0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 008e3ac4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 008e3ac8  741d                 je 0x8e3ae7
// 008e3aca  8d4c2420             lea ecx, [esp + 0x20]
// 008e3ace  e82d76d3ff           call 0x61b100
// 008e3ad3  53                   push ebx
// 008e3ad4  57                   push edi
// 008e3ad5  8d442418             lea eax, [esp + 0x18]
// 008e3ad9  50                   push eax
// 008e3ada  8bce                 mov ecx, esi
// 008e3adc  e8dffbffff           call 0x8e36c0
// 008e3ae1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008e3ae5  ebc9                 jmp 0x8e3ab0
// 008e3ae7  8b36                 mov esi, dword ptr [esi]
// 008e3ae9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e3aed  5f                   pop edi
// 008e3aee  8930                 mov dword ptr [eax], esi
// 008e3af0  5e                   pop esi
// 008e3af1  5d                   pop ebp
// 008e3af2  895804               mov dword ptr [eax + 4], ebx
// 008e3af5  5b                   pop ebx
// 008e3af6  83c408               add esp, 8
// 008e3af9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
