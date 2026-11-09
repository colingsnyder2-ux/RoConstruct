// from server: 100% by auto
// roc 2010-06 00528820  unit: ?1??ViewG3D_InitModule::ViewG3DFactory  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00528820
//
// 00528820  83ec08               sub esp, 8
// 00528823  53                   push ebx
// 00528824  55                   push ebp
// 00528825  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0052882b  56                   push esi
// 0052882c  8bf1                 mov esi, ecx
// 0052882e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00528831  8b18                 mov ebx, dword ptr [eax]
// 00528833  8b06                 mov eax, dword ptr [esi]
// 00528835  57                   push edi
// 00528836  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0052883a  85ff                 test edi, edi
// 0052883c  7404                 je 0x528842
// 0052883e  3bf8                 cmp edi, eax
// 00528840  7406                 je 0x528848
// 00528842  ffd5                 call ebp
// 00528844  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00528848  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0052884c  7562                 jne 0x5288b0
// 0052884e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00528852  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00528855  8b06                 mov eax, dword ptr [esi]
// 00528857  85c9                 test ecx, ecx
// 00528859  7404                 je 0x52885f
// 0052885b  3bc8                 cmp ecx, eax
// 0052885d  7406                 je 0x528865
// 0052885f  ffd5                 call ebp
// 00528861  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00528865  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00528869  7545                 jne 0x5288b0
// 0052886b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0052886e  8b5104               mov edx, dword ptr [ecx + 4]
// 00528871  52                   push edx
// 00528872  8bce                 mov ecx, esi
// 00528874  e8e7f8ffff           call 0x528160
// 00528879  8b4618               mov eax, dword ptr [esi + 0x18]
// 0052887c  894004               mov dword ptr [eax + 4], eax
// 0052887f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00528882  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00528889  8900                 mov dword ptr [eax], eax
// 0052888b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0052888e  894008               mov dword ptr [eax + 8], eax
// 00528891  8b4618               mov eax, dword ptr [esi + 0x18]
// 00528894  8b16                 mov edx, dword ptr [esi]
// 00528896  8b08                 mov ecx, dword ptr [eax]
// 00528898  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0052889c  5f                   pop edi
// 0052889d  5e                   pop esi
// 0052889e  5d                   pop ebp
// 0052889f  894804               mov dword ptr [eax + 4], ecx
// 005288a2  8910                 mov dword ptr [eax], edx
// 005288a4  5b                   pop ebx
// 005288a5  83c408               add esp, 8
// 005288a8  c21400               ret 0x14
// 005288ab  eb03                 jmp 0x5288b0
// 005288ad  8d4900               lea ecx, [ecx]
// 005288b0  85ff                 test edi, edi
// 005288b2  7406                 je 0x5288ba
// 005288b4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005288b8  7406                 je 0x5288c0
// 005288ba  ffd5                 call ebp
// 005288bc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005288c0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005288c4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005288c8  741d                 je 0x5288e7
// 005288ca  8d4c2420             lea ecx, [esp + 0x20]
// 005288ce  e83d062300           call 0x758f10
// 005288d3  53                   push ebx
// 005288d4  57                   push edi
// 005288d5  8d442418             lea eax, [esp + 0x18]
// 005288d9  50                   push eax
// 005288da  8bce                 mov ecx, esi
// 005288dc  e88ff5ffff           call 0x527e70
// 005288e1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005288e5  ebc9                 jmp 0x5288b0
// 005288e7  8b36                 mov esi, dword ptr [esi]
// 005288e9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005288ed  5f                   pop edi
// 005288ee  8930                 mov dword ptr [eax], esi
// 005288f0  5e                   pop esi
// 005288f1  5d                   pop ebp
// 005288f2  895804               mov dword ptr [eax + 4], ebx
// 005288f5  5b                   pop ebx
// 005288f6  83c408               add esp, 8
// 005288f9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
