// from server: 100% by auto
// roc 2009-06 00619d80  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00619d80
//
// 00619d80  83ec08               sub esp, 8
// 00619d83  53                   push ebx
// 00619d84  55                   push ebp
// 00619d85  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00619d8b  56                   push esi
// 00619d8c  8bf1                 mov esi, ecx
// 00619d8e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00619d91  8b18                 mov ebx, dword ptr [eax]
// 00619d93  8b06                 mov eax, dword ptr [esi]
// 00619d95  57                   push edi
// 00619d96  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00619d9a  85ff                 test edi, edi
// 00619d9c  7404                 je 0x619da2
// 00619d9e  3bf8                 cmp edi, eax
// 00619da0  7406                 je 0x619da8
// 00619da2  ffd5                 call ebp
// 00619da4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00619da8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00619dac  7562                 jne 0x619e10
// 00619dae  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00619db2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00619db5  8b06                 mov eax, dword ptr [esi]
// 00619db7  85c9                 test ecx, ecx
// 00619db9  7404                 je 0x619dbf
// 00619dbb  3bc8                 cmp ecx, eax
// 00619dbd  7406                 je 0x619dc5
// 00619dbf  ffd5                 call ebp
// 00619dc1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00619dc5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00619dc9  7545                 jne 0x619e10
// 00619dcb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00619dce  8b5104               mov edx, dword ptr [ecx + 4]
// 00619dd1  52                   push edx
// 00619dd2  8bce                 mov ecx, esi
// 00619dd4  e847f0ffff           call 0x618e20
// 00619dd9  8b4618               mov eax, dword ptr [esi + 0x18]
// 00619ddc  894004               mov dword ptr [eax + 4], eax
// 00619ddf  8b4618               mov eax, dword ptr [esi + 0x18]
// 00619de2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00619de9  8900                 mov dword ptr [eax], eax
// 00619deb  8b4618               mov eax, dword ptr [esi + 0x18]
// 00619dee  894008               mov dword ptr [eax + 8], eax
// 00619df1  8b4618               mov eax, dword ptr [esi + 0x18]
// 00619df4  8b16                 mov edx, dword ptr [esi]
// 00619df6  8b08                 mov ecx, dword ptr [eax]
// 00619df8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00619dfc  5f                   pop edi
// 00619dfd  5e                   pop esi
// 00619dfe  5d                   pop ebp
// 00619dff  894804               mov dword ptr [eax + 4], ecx
// 00619e02  8910                 mov dword ptr [eax], edx
// 00619e04  5b                   pop ebx
// 00619e05  83c408               add esp, 8
// 00619e08  c21400               ret 0x14
// 00619e0b  eb03                 jmp 0x619e10
// 00619e0d  8d4900               lea ecx, [ecx]
// 00619e10  85ff                 test edi, edi
// 00619e12  7406                 je 0x619e1a
// 00619e14  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00619e18  7406                 je 0x619e20
// 00619e1a  ffd5                 call ebp
// 00619e1c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00619e20  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00619e24  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00619e28  741d                 je 0x619e47
// 00619e2a  8d4c2420             lea ecx, [esp + 0x20]
// 00619e2e  e88d840000           call 0x6222c0
// 00619e33  53                   push ebx
// 00619e34  57                   push edi
// 00619e35  8d442418             lea eax, [esp + 0x18]
// 00619e39  50                   push eax
// 00619e3a  8bce                 mov ecx, esi
// 00619e3c  e81ff1ffff           call 0x618f60
// 00619e41  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00619e45  ebc9                 jmp 0x619e10
// 00619e47  8b36                 mov esi, dword ptr [esi]
// 00619e49  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00619e4d  5f                   pop edi
// 00619e4e  8930                 mov dword ptr [eax], esi
// 00619e50  5e                   pop esi
// 00619e51  5d                   pop ebp
// 00619e52  895804               mov dword ptr [eax + 4], ebx
// 00619e55  5b                   pop ebx
// 00619e56  83c408               add esp, 8
// 00619e59  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
