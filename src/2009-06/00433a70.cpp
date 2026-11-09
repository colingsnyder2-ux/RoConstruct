// from server: 100% by auto
// roc 2009-06 00433a70  unit: IIHAAH::?$CMap  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00433a70
//
// 00433a70  83ec08               sub esp, 8
// 00433a73  53                   push ebx
// 00433a74  55                   push ebp
// 00433a75  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00433a7b  56                   push esi
// 00433a7c  8bf1                 mov esi, ecx
// 00433a7e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00433a81  8b18                 mov ebx, dword ptr [eax]
// 00433a83  8b06                 mov eax, dword ptr [esi]
// 00433a85  57                   push edi
// 00433a86  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00433a8a  85ff                 test edi, edi
// 00433a8c  7404                 je 0x433a92
// 00433a8e  3bf8                 cmp edi, eax
// 00433a90  7406                 je 0x433a98
// 00433a92  ffd5                 call ebp
// 00433a94  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00433a98  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00433a9c  7562                 jne 0x433b00
// 00433a9e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00433aa2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00433aa5  8b06                 mov eax, dword ptr [esi]
// 00433aa7  85c9                 test ecx, ecx
// 00433aa9  7404                 je 0x433aaf
// 00433aab  3bc8                 cmp ecx, eax
// 00433aad  7406                 je 0x433ab5
// 00433aaf  ffd5                 call ebp
// 00433ab1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00433ab5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00433ab9  7545                 jne 0x433b00
// 00433abb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00433abe  8b5104               mov edx, dword ptr [ecx + 4]
// 00433ac1  52                   push edx
// 00433ac2  8bce                 mov ecx, esi
// 00433ac4  e857f4ffff           call 0x432f20
// 00433ac9  8b4618               mov eax, dword ptr [esi + 0x18]
// 00433acc  894004               mov dword ptr [eax + 4], eax
// 00433acf  8b4618               mov eax, dword ptr [esi + 0x18]
// 00433ad2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00433ad9  8900                 mov dword ptr [eax], eax
// 00433adb  8b4618               mov eax, dword ptr [esi + 0x18]
// 00433ade  894008               mov dword ptr [eax + 8], eax
// 00433ae1  8b4618               mov eax, dword ptr [esi + 0x18]
// 00433ae4  8b16                 mov edx, dword ptr [esi]
// 00433ae6  8b08                 mov ecx, dword ptr [eax]
// 00433ae8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00433aec  5f                   pop edi
// 00433aed  5e                   pop esi
// 00433aee  5d                   pop ebp
// 00433aef  894804               mov dword ptr [eax + 4], ecx
// 00433af2  8910                 mov dword ptr [eax], edx
// 00433af4  5b                   pop ebx
// 00433af5  83c408               add esp, 8
// 00433af8  c21400               ret 0x14
// 00433afb  eb03                 jmp 0x433b00
// 00433afd  8d4900               lea ecx, [ecx]
// 00433b00  85ff                 test edi, edi
// 00433b02  7406                 je 0x433b0a
// 00433b04  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00433b08  7406                 je 0x433b10
// 00433b0a  ffd5                 call ebp
// 00433b0c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00433b10  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00433b14  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00433b18  741d                 je 0x433b37
// 00433b1a  8d4c2420             lea ecx, [esp + 0x20]
// 00433b1e  e89de71e00           call 0x6222c0
// 00433b23  53                   push ebx
// 00433b24  57                   push edi
// 00433b25  8d442418             lea eax, [esp + 0x18]
// 00433b29  50                   push eax
// 00433b2a  8bce                 mov ecx, esi
// 00433b2c  e85ffaffff           call 0x433590
// 00433b31  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00433b35  ebc9                 jmp 0x433b00
// 00433b37  8b36                 mov esi, dword ptr [esi]
// 00433b39  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00433b3d  5f                   pop edi
// 00433b3e  8930                 mov dword ptr [eax], esi
// 00433b40  5e                   pop esi
// 00433b41  5d                   pop ebp
// 00433b42  895804               mov dword ptr [eax + 4], ebx
// 00433b45  5b                   pop ebx
// 00433b46  83c408               add esp, 8
// 00433b49  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
