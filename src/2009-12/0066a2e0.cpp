// from server: 100% by auto
// roc 2009-12 0066a2e0  unit: RBX::VInstance::?$NonFactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0066a2e0
//
// 0066a2e0  83ec08               sub esp, 8
// 0066a2e3  53                   push ebx
// 0066a2e4  55                   push ebp
// 0066a2e5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0066a2eb  56                   push esi
// 0066a2ec  8bf1                 mov esi, ecx
// 0066a2ee  8b4618               mov eax, dword ptr [esi + 0x18]
// 0066a2f1  8b18                 mov ebx, dword ptr [eax]
// 0066a2f3  8b06                 mov eax, dword ptr [esi]
// 0066a2f5  57                   push edi
// 0066a2f6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0066a2fa  85ff                 test edi, edi
// 0066a2fc  7404                 je 0x66a302
// 0066a2fe  3bf8                 cmp edi, eax
// 0066a300  7406                 je 0x66a308
// 0066a302  ffd5                 call ebp
// 0066a304  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0066a308  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0066a30c  7562                 jne 0x66a370
// 0066a30e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0066a312  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0066a315  8b06                 mov eax, dword ptr [esi]
// 0066a317  85c9                 test ecx, ecx
// 0066a319  7404                 je 0x66a31f
// 0066a31b  3bc8                 cmp ecx, eax
// 0066a31d  7406                 je 0x66a325
// 0066a31f  ffd5                 call ebp
// 0066a321  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0066a325  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0066a329  7545                 jne 0x66a370
// 0066a32b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0066a32e  8b5104               mov edx, dword ptr [ecx + 4]
// 0066a331  52                   push edx
// 0066a332  8bce                 mov ecx, esi
// 0066a334  e817f3ffff           call 0x669650
// 0066a339  8b4618               mov eax, dword ptr [esi + 0x18]
// 0066a33c  894004               mov dword ptr [eax + 4], eax
// 0066a33f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0066a342  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0066a349  8900                 mov dword ptr [eax], eax
// 0066a34b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0066a34e  894008               mov dword ptr [eax + 8], eax
// 0066a351  8b4618               mov eax, dword ptr [esi + 0x18]
// 0066a354  8b16                 mov edx, dword ptr [esi]
// 0066a356  8b08                 mov ecx, dword ptr [eax]
// 0066a358  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0066a35c  5f                   pop edi
// 0066a35d  5e                   pop esi
// 0066a35e  5d                   pop ebp
// 0066a35f  894804               mov dword ptr [eax + 4], ecx
// 0066a362  8910                 mov dword ptr [eax], edx
// 0066a364  5b                   pop ebx
// 0066a365  83c408               add esp, 8
// 0066a368  c21400               ret 0x14
// 0066a36b  eb03                 jmp 0x66a370
// 0066a36d  8d4900               lea ecx, [ecx]
// 0066a370  85ff                 test edi, edi
// 0066a372  7406                 je 0x66a37a
// 0066a374  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0066a378  7406                 je 0x66a380
// 0066a37a  ffd5                 call ebp
// 0066a37c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0066a380  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0066a384  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0066a388  741d                 je 0x66a3a7
// 0066a38a  8d4c2420             lea ecx, [esp + 0x20]
// 0066a38e  e8ede1ecff           call 0x538580
// 0066a393  53                   push ebx
// 0066a394  57                   push edi
// 0066a395  8d442418             lea eax, [esp + 0x18]
// 0066a399  50                   push eax
// 0066a39a  8bce                 mov ecx, esi
// 0066a39c  e8afefffff           call 0x669350
// 0066a3a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0066a3a5  ebc9                 jmp 0x66a370
// 0066a3a7  8b36                 mov esi, dword ptr [esi]
// 0066a3a9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0066a3ad  5f                   pop edi
// 0066a3ae  8930                 mov dword ptr [eax], esi
// 0066a3b0  5e                   pop esi
// 0066a3b1  5d                   pop ebp
// 0066a3b2  895804               mov dword ptr [eax + 4], ebx
// 0066a3b5  5b                   pop ebx
// 0066a3b6  83c408               add esp, 8
// 0066a3b9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
