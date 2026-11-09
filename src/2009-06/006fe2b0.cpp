// from server: 100% by auto
// roc 2009-06 006fe2b0  unit: RBX::AdornRbxGfx  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fe2b0
//
// 006fe2b0  83ec08               sub esp, 8
// 006fe2b3  53                   push ebx
// 006fe2b4  55                   push ebp
// 006fe2b5  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 006fe2bb  56                   push esi
// 006fe2bc  8bf1                 mov esi, ecx
// 006fe2be  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fe2c1  8b18                 mov ebx, dword ptr [eax]
// 006fe2c3  8b06                 mov eax, dword ptr [esi]
// 006fe2c5  57                   push edi
// 006fe2c6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006fe2ca  85ff                 test edi, edi
// 006fe2cc  7404                 je 0x6fe2d2
// 006fe2ce  3bf8                 cmp edi, eax
// 006fe2d0  7406                 je 0x6fe2d8
// 006fe2d2  ffd5                 call ebp
// 006fe2d4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006fe2d8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006fe2dc  7562                 jne 0x6fe340
// 006fe2de  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006fe2e2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006fe2e5  8b06                 mov eax, dword ptr [esi]
// 006fe2e7  85c9                 test ecx, ecx
// 006fe2e9  7404                 je 0x6fe2ef
// 006fe2eb  3bc8                 cmp ecx, eax
// 006fe2ed  7406                 je 0x6fe2f5
// 006fe2ef  ffd5                 call ebp
// 006fe2f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006fe2f5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006fe2f9  7545                 jne 0x6fe340
// 006fe2fb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006fe2fe  8b5104               mov edx, dword ptr [ecx + 4]
// 006fe301  52                   push edx
// 006fe302  8bce                 mov ecx, esi
// 006fe304  e857fbffff           call 0x6fde60
// 006fe309  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fe30c  894004               mov dword ptr [eax + 4], eax
// 006fe30f  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fe312  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006fe319  8900                 mov dword ptr [eax], eax
// 006fe31b  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fe31e  894008               mov dword ptr [eax + 8], eax
// 006fe321  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fe324  8b16                 mov edx, dword ptr [esi]
// 006fe326  8b08                 mov ecx, dword ptr [eax]
// 006fe328  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006fe32c  5f                   pop edi
// 006fe32d  5e                   pop esi
// 006fe32e  5d                   pop ebp
// 006fe32f  894804               mov dword ptr [eax + 4], ecx
// 006fe332  8910                 mov dword ptr [eax], edx
// 006fe334  5b                   pop ebx
// 006fe335  83c408               add esp, 8
// 006fe338  c21400               ret 0x14
// 006fe33b  eb03                 jmp 0x6fe340
// 006fe33d  8d4900               lea ecx, [ecx]
// 006fe340  85ff                 test edi, edi
// 006fe342  7406                 je 0x6fe34a
// 006fe344  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006fe348  7406                 je 0x6fe350
// 006fe34a  ffd5                 call ebp
// 006fe34c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006fe350  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006fe354  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006fe358  741d                 je 0x6fe377
// 006fe35a  8d4c2420             lea ecx, [esp + 0x20]
// 006fe35e  e8bde8ffff           call 0x6fcc20
// 006fe363  53                   push ebx
// 006fe364  57                   push edi
// 006fe365  8d442418             lea eax, [esp + 0x18]
// 006fe369  50                   push eax
// 006fe36a  8bce                 mov ecx, esi
// 006fe36c  e8dff3ffff           call 0x6fd750
// 006fe371  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006fe375  ebc9                 jmp 0x6fe340
// 006fe377  8b36                 mov esi, dword ptr [esi]
// 006fe379  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006fe37d  5f                   pop edi
// 006fe37e  8930                 mov dword ptr [eax], esi
// 006fe380  5e                   pop esi
// 006fe381  5d                   pop ebp
// 006fe382  895804               mov dword ptr [eax + 4], ebx
// 006fe385  5b                   pop ebx
// 006fe386  83c408               add esp, 8
// 006fe389  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
