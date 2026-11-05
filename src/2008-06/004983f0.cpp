// from server: 100% by auto
// roc 2008-06 004983f0  unit: RBX::VInstance::?$NonFactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004983f0
//
// 004983f0  83ec08               sub esp, 8
// 004983f3  53                   push ebx
// 004983f4  55                   push ebp
// 004983f5  8b2d90288000         mov ebp, dword ptr [0x802890]
// 004983fb  56                   push esi
// 004983fc  8bf1                 mov esi, ecx
// 004983fe  8b4618               mov eax, dword ptr [esi + 0x18]
// 00498401  8b18                 mov ebx, dword ptr [eax]
// 00498403  8b06                 mov eax, dword ptr [esi]
// 00498405  57                   push edi
// 00498406  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0049840a  85ff                 test edi, edi
// 0049840c  7404                 je 0x498412
// 0049840e  3bf8                 cmp edi, eax
// 00498410  7406                 je 0x498418
// 00498412  ffd5                 call ebp
// 00498414  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00498418  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0049841c  7562                 jne 0x498480
// 0049841e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00498422  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00498425  8b06                 mov eax, dword ptr [esi]
// 00498427  85c9                 test ecx, ecx
// 00498429  7404                 je 0x49842f
// 0049842b  3bc8                 cmp ecx, eax
// 0049842d  7406                 je 0x498435
// 0049842f  ffd5                 call ebp
// 00498431  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00498435  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00498439  7545                 jne 0x498480
// 0049843b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0049843e  8b5104               mov edx, dword ptr [ecx + 4]
// 00498441  52                   push edx
// 00498442  8bce                 mov ecx, esi
// 00498444  e897ecffff           call 0x4970e0
// 00498449  8b4618               mov eax, dword ptr [esi + 0x18]
// 0049844c  894004               mov dword ptr [eax + 4], eax
// 0049844f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00498452  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00498459  8900                 mov dword ptr [eax], eax
// 0049845b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0049845e  894008               mov dword ptr [eax + 8], eax
// 00498461  8b4618               mov eax, dword ptr [esi + 0x18]
// 00498464  8b16                 mov edx, dword ptr [esi]
// 00498466  8b08                 mov ecx, dword ptr [eax]
// 00498468  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0049846c  5f                   pop edi
// 0049846d  5e                   pop esi
// 0049846e  5d                   pop ebp
// 0049846f  894804               mov dword ptr [eax + 4], ecx
// 00498472  8910                 mov dword ptr [eax], edx
// 00498474  5b                   pop ebx
// 00498475  83c408               add esp, 8
// 00498478  c21400               ret 0x14
// 0049847b  eb03                 jmp 0x498480
// 0049847d  8d4900               lea ecx, [ecx]
// 00498480  85ff                 test edi, edi
// 00498482  7406                 je 0x49848a
// 00498484  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00498488  7406                 je 0x498490
// 0049848a  ffd5                 call ebp
// 0049848c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00498490  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00498494  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00498498  741d                 je 0x4984b7
// 0049849a  8d4c2420             lea ecx, [esp + 0x20]
// 0049849e  e8aded1100           call 0x5b7250
// 004984a3  53                   push ebx
// 004984a4  57                   push edi
// 004984a5  8d442418             lea eax, [esp + 0x18]
// 004984a9  50                   push eax
// 004984aa  8bce                 mov ecx, esi
// 004984ac  e84ff6ffff           call 0x497b00
// 004984b1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004984b5  ebc9                 jmp 0x498480
// 004984b7  8b36                 mov esi, dword ptr [esi]
// 004984b9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004984bd  5f                   pop edi
// 004984be  8930                 mov dword ptr [eax], esi
// 004984c0  5e                   pop esi
// 004984c1  5d                   pop ebp
// 004984c2  895804               mov dword ptr [eax + 4], ebx
// 004984c5  5b                   pop ebx
// 004984c6  83c408               add esp, 8
// 004984c9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
