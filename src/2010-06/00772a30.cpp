// from server: 100% by auto
// roc 2010-06 00772a30  unit: RBX::ScoreHud  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00772a30
//
// 00772a30  83ec08               sub esp, 8
// 00772a33  53                   push ebx
// 00772a34  55                   push ebp
// 00772a35  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00772a3b  56                   push esi
// 00772a3c  8bf1                 mov esi, ecx
// 00772a3e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00772a41  8b18                 mov ebx, dword ptr [eax]
// 00772a43  8b06                 mov eax, dword ptr [esi]
// 00772a45  57                   push edi
// 00772a46  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00772a4a  85ff                 test edi, edi
// 00772a4c  7404                 je 0x772a52
// 00772a4e  3bf8                 cmp edi, eax
// 00772a50  7406                 je 0x772a58
// 00772a52  ffd5                 call ebp
// 00772a54  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00772a58  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00772a5c  7562                 jne 0x772ac0
// 00772a5e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00772a62  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00772a65  8b06                 mov eax, dword ptr [esi]
// 00772a67  85c9                 test ecx, ecx
// 00772a69  7404                 je 0x772a6f
// 00772a6b  3bc8                 cmp ecx, eax
// 00772a6d  7406                 je 0x772a75
// 00772a6f  ffd5                 call ebp
// 00772a71  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00772a75  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00772a79  7545                 jne 0x772ac0
// 00772a7b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00772a7e  8b5104               mov edx, dword ptr [ecx + 4]
// 00772a81  52                   push edx
// 00772a82  8bce                 mov ecx, esi
// 00772a84  e847f5ffff           call 0x771fd0
// 00772a89  8b4618               mov eax, dword ptr [esi + 0x18]
// 00772a8c  894004               mov dword ptr [eax + 4], eax
// 00772a8f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00772a92  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00772a99  8900                 mov dword ptr [eax], eax
// 00772a9b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00772a9e  894008               mov dword ptr [eax + 8], eax
// 00772aa1  8b4618               mov eax, dword ptr [esi + 0x18]
// 00772aa4  8b16                 mov edx, dword ptr [esi]
// 00772aa6  8b08                 mov ecx, dword ptr [eax]
// 00772aa8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00772aac  5f                   pop edi
// 00772aad  5e                   pop esi
// 00772aae  5d                   pop ebp
// 00772aaf  894804               mov dword ptr [eax + 4], ecx
// 00772ab2  8910                 mov dword ptr [eax], edx
// 00772ab4  5b                   pop ebx
// 00772ab5  83c408               add esp, 8
// 00772ab8  c21400               ret 0x14
// 00772abb  eb03                 jmp 0x772ac0
// 00772abd  8d4900               lea ecx, [ecx]
// 00772ac0  85ff                 test edi, edi
// 00772ac2  7406                 je 0x772aca
// 00772ac4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00772ac8  7406                 je 0x772ad0
// 00772aca  ffd5                 call ebp
// 00772acc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00772ad0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00772ad4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00772ad8  741d                 je 0x772af7
// 00772ada  8d4c2420             lea ecx, [esp + 0x20]
// 00772ade  e85d8be9ff           call 0x60b640
// 00772ae3  53                   push ebx
// 00772ae4  57                   push edi
// 00772ae5  8d442418             lea eax, [esp + 0x18]
// 00772ae9  50                   push eax
// 00772aea  8bce                 mov ecx, esi
// 00772aec  e8ffeeffff           call 0x7719f0
// 00772af1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00772af5  ebc9                 jmp 0x772ac0
// 00772af7  8b36                 mov esi, dword ptr [esi]
// 00772af9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00772afd  5f                   pop edi
// 00772afe  8930                 mov dword ptr [eax], esi
// 00772b00  5e                   pop esi
// 00772b01  5d                   pop ebp
// 00772b02  895804               mov dword ptr [eax + 4], ebx
// 00772b05  5b                   pop ebx
// 00772b06  83c408               add esp, 8
// 00772b09  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
