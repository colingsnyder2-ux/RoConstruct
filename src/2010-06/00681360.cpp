// from server: 100% by auto
// roc 2010-06 00681360  unit: seg_00680000  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00681360
//
// 00681360  83ec08               sub esp, 8
// 00681363  53                   push ebx
// 00681364  55                   push ebp
// 00681365  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0068136b  56                   push esi
// 0068136c  8bf1                 mov esi, ecx
// 0068136e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00681371  8b18                 mov ebx, dword ptr [eax]
// 00681373  8b06                 mov eax, dword ptr [esi]
// 00681375  57                   push edi
// 00681376  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0068137a  85ff                 test edi, edi
// 0068137c  7404                 je 0x681382
// 0068137e  3bf8                 cmp edi, eax
// 00681380  7406                 je 0x681388
// 00681382  ffd5                 call ebp
// 00681384  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00681388  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0068138c  7562                 jne 0x6813f0
// 0068138e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00681392  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00681395  8b06                 mov eax, dword ptr [esi]
// 00681397  85c9                 test ecx, ecx
// 00681399  7404                 je 0x68139f
// 0068139b  3bc8                 cmp ecx, eax
// 0068139d  7406                 je 0x6813a5
// 0068139f  ffd5                 call ebp
// 006813a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006813a5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006813a9  7545                 jne 0x6813f0
// 006813ab  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006813ae  8b5104               mov edx, dword ptr [ecx + 4]
// 006813b1  52                   push edx
// 006813b2  8bce                 mov ecx, esi
// 006813b4  e807deffff           call 0x67f1c0
// 006813b9  8b4618               mov eax, dword ptr [esi + 0x18]
// 006813bc  894004               mov dword ptr [eax + 4], eax
// 006813bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 006813c2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006813c9  8900                 mov dword ptr [eax], eax
// 006813cb  8b4618               mov eax, dword ptr [esi + 0x18]
// 006813ce  894008               mov dword ptr [eax + 8], eax
// 006813d1  8b4618               mov eax, dword ptr [esi + 0x18]
// 006813d4  8b16                 mov edx, dword ptr [esi]
// 006813d6  8b08                 mov ecx, dword ptr [eax]
// 006813d8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006813dc  5f                   pop edi
// 006813dd  5e                   pop esi
// 006813de  5d                   pop ebp
// 006813df  894804               mov dword ptr [eax + 4], ecx
// 006813e2  8910                 mov dword ptr [eax], edx
// 006813e4  5b                   pop ebx
// 006813e5  83c408               add esp, 8
// 006813e8  c21400               ret 0x14
// 006813eb  eb03                 jmp 0x6813f0
// 006813ed  8d4900               lea ecx, [ecx]
// 006813f0  85ff                 test edi, edi
// 006813f2  7406                 je 0x6813fa
// 006813f4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006813f8  7406                 je 0x681400
// 006813fa  ffd5                 call ebp
// 006813fc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00681400  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00681404  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00681408  741d                 je 0x681427
// 0068140a  8d4c2420             lea ecx, [esp + 0x20]
// 0068140e  e88d97ffff           call 0x67aba0
// 00681413  53                   push ebx
// 00681414  57                   push edi
// 00681415  8d442418             lea eax, [esp + 0x18]
// 00681419  50                   push eax
// 0068141a  8bce                 mov ecx, esi
// 0068141c  e8dfe4ffff           call 0x67f900
// 00681421  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00681425  ebc9                 jmp 0x6813f0
// 00681427  8b36                 mov esi, dword ptr [esi]
// 00681429  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0068142d  5f                   pop edi
// 0068142e  8930                 mov dword ptr [eax], esi
// 00681430  5e                   pop esi
// 00681431  5d                   pop ebp
// 00681432  895804               mov dword ptr [eax + 4], ebx
// 00681435  5b                   pop ebx
// 00681436  83c408               add esp, 8
// 00681439  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
