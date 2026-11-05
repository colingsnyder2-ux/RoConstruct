// from server: 100% by auto
// roc 2009-12 007b0450  unit: RBX::Block  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b0450
//
// 007b0450  83ec08               sub esp, 8
// 007b0453  53                   push ebx
// 007b0454  55                   push ebp
// 007b0455  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 007b045b  56                   push esi
// 007b045c  8bf1                 mov esi, ecx
// 007b045e  8b4618               mov eax, dword ptr [esi + 0x18]
// 007b0461  8b18                 mov ebx, dword ptr [eax]
// 007b0463  8b06                 mov eax, dword ptr [esi]
// 007b0465  57                   push edi
// 007b0466  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007b046a  85ff                 test edi, edi
// 007b046c  7404                 je 0x7b0472
// 007b046e  3bf8                 cmp edi, eax
// 007b0470  7406                 je 0x7b0478
// 007b0472  ffd5                 call ebp
// 007b0474  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007b0478  395c2424             cmp dword ptr [esp + 0x24], ebx
// 007b047c  7562                 jne 0x7b04e0
// 007b047e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007b0482  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 007b0485  8b06                 mov eax, dword ptr [esi]
// 007b0487  85c9                 test ecx, ecx
// 007b0489  7404                 je 0x7b048f
// 007b048b  3bc8                 cmp ecx, eax
// 007b048d  7406                 je 0x7b0495
// 007b048f  ffd5                 call ebp
// 007b0491  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007b0495  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 007b0499  7545                 jne 0x7b04e0
// 007b049b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007b049e  8b5104               mov edx, dword ptr [ecx + 4]
// 007b04a1  52                   push edx
// 007b04a2  8bce                 mov ecx, esi
// 007b04a4  e8f7f8ffff           call 0x7afda0
// 007b04a9  8b4618               mov eax, dword ptr [esi + 0x18]
// 007b04ac  894004               mov dword ptr [eax + 4], eax
// 007b04af  8b4618               mov eax, dword ptr [esi + 0x18]
// 007b04b2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007b04b9  8900                 mov dword ptr [eax], eax
// 007b04bb  8b4618               mov eax, dword ptr [esi + 0x18]
// 007b04be  894008               mov dword ptr [eax + 8], eax
// 007b04c1  8b4618               mov eax, dword ptr [esi + 0x18]
// 007b04c4  8b16                 mov edx, dword ptr [esi]
// 007b04c6  8b08                 mov ecx, dword ptr [eax]
// 007b04c8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007b04cc  5f                   pop edi
// 007b04cd  5e                   pop esi
// 007b04ce  5d                   pop ebp
// 007b04cf  894804               mov dword ptr [eax + 4], ecx
// 007b04d2  8910                 mov dword ptr [eax], edx
// 007b04d4  5b                   pop ebx
// 007b04d5  83c408               add esp, 8
// 007b04d8  c21400               ret 0x14
// 007b04db  eb03                 jmp 0x7b04e0
// 007b04dd  8d4900               lea ecx, [ecx]
// 007b04e0  85ff                 test edi, edi
// 007b04e2  7406                 je 0x7b04ea
// 007b04e4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 007b04e8  7406                 je 0x7b04f0
// 007b04ea  ffd5                 call ebp
// 007b04ec  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007b04f0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007b04f4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 007b04f8  741d                 je 0x7b0517
// 007b04fa  8d4c2420             lea ecx, [esp + 0x20]
// 007b04fe  e86df4ffff           call 0x7af970
// 007b0503  53                   push ebx
// 007b0504  57                   push edi
// 007b0505  8d442418             lea eax, [esp + 0x18]
// 007b0509  50                   push eax
// 007b050a  8bce                 mov ecx, esi
// 007b050c  e8cffaffff           call 0x7affe0
// 007b0511  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007b0515  ebc9                 jmp 0x7b04e0
// 007b0517  8b36                 mov esi, dword ptr [esi]
// 007b0519  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007b051d  5f                   pop edi
// 007b051e  8930                 mov dword ptr [eax], esi
// 007b0520  5e                   pop esi
// 007b0521  5d                   pop ebp
// 007b0522  895804               mov dword ptr [eax + 4], ebx
// 007b0525  5b                   pop ebx
// 007b0526  83c408               add esp, 8
// 007b0529  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
