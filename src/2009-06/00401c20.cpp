// from server: 100% by auto
// roc 2009-06 00401c20  unit: CAboutRobloxDialog  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401c20
//
// 00401c20  83ec08               sub esp, 8
// 00401c23  53                   push ebx
// 00401c24  55                   push ebp
// 00401c25  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00401c2b  56                   push esi
// 00401c2c  8bf1                 mov esi, ecx
// 00401c2e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00401c31  8b18                 mov ebx, dword ptr [eax]
// 00401c33  8b06                 mov eax, dword ptr [esi]
// 00401c35  57                   push edi
// 00401c36  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00401c3a  85ff                 test edi, edi
// 00401c3c  7404                 je 0x401c42
// 00401c3e  3bf8                 cmp edi, eax
// 00401c40  7406                 je 0x401c48
// 00401c42  ffd5                 call ebp
// 00401c44  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00401c48  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00401c4c  7562                 jne 0x401cb0
// 00401c4e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00401c52  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00401c55  8b06                 mov eax, dword ptr [esi]
// 00401c57  85c9                 test ecx, ecx
// 00401c59  7404                 je 0x401c5f
// 00401c5b  3bc8                 cmp ecx, eax
// 00401c5d  7406                 je 0x401c65
// 00401c5f  ffd5                 call ebp
// 00401c61  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00401c65  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00401c69  7545                 jne 0x401cb0
// 00401c6b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00401c6e  8b5104               mov edx, dword ptr [ecx + 4]
// 00401c71  52                   push edx
// 00401c72  8bce                 mov ecx, esi
// 00401c74  e847f13000           call 0x710dc0
// 00401c79  8b4618               mov eax, dword ptr [esi + 0x18]
// 00401c7c  894004               mov dword ptr [eax + 4], eax
// 00401c7f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00401c82  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00401c89  8900                 mov dword ptr [eax], eax
// 00401c8b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00401c8e  894008               mov dword ptr [eax + 8], eax
// 00401c91  8b4618               mov eax, dword ptr [esi + 0x18]
// 00401c94  8b16                 mov edx, dword ptr [esi]
// 00401c96  8b08                 mov ecx, dword ptr [eax]
// 00401c98  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00401c9c  5f                   pop edi
// 00401c9d  5e                   pop esi
// 00401c9e  5d                   pop ebp
// 00401c9f  894804               mov dword ptr [eax + 4], ecx
// 00401ca2  8910                 mov dword ptr [eax], edx
// 00401ca4  5b                   pop ebx
// 00401ca5  83c408               add esp, 8
// 00401ca8  c21400               ret 0x14
// 00401cab  eb03                 jmp 0x401cb0
// 00401cad  8d4900               lea ecx, [ecx]
// 00401cb0  85ff                 test edi, edi
// 00401cb2  7406                 je 0x401cba
// 00401cb4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00401cb8  7406                 je 0x401cc0
// 00401cba  ffd5                 call ebp
// 00401cbc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00401cc0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00401cc4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00401cc8  741d                 je 0x401ce7
// 00401cca  8d4c2420             lea ecx, [esp + 0x20]
// 00401cce  e89d741e00           call 0x5e9170
// 00401cd3  53                   push ebx
// 00401cd4  57                   push edi
// 00401cd5  8d442418             lea eax, [esp + 0x18]
// 00401cd9  50                   push eax
// 00401cda  8bce                 mov ecx, esi
// 00401cdc  e8cffbffff           call 0x4018b0
// 00401ce1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00401ce5  ebc9                 jmp 0x401cb0
// 00401ce7  8b36                 mov esi, dword ptr [esi]
// 00401ce9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00401ced  5f                   pop edi
// 00401cee  8930                 mov dword ptr [eax], esi
// 00401cf0  5e                   pop esi
// 00401cf1  5d                   pop ebp
// 00401cf2  895804               mov dword ptr [eax + 4], ebx
// 00401cf5  5b                   pop ebx
// 00401cf6  83c408               add esp, 8
// 00401cf9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
