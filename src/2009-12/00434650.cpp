// from server: 100% by auto
// roc 2009-12 00434650  unit: CPropGrid::UpdateItemsJob  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00434650
//
// 00434650  83ec08               sub esp, 8
// 00434653  53                   push ebx
// 00434654  55                   push ebp
// 00434655  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0043465b  56                   push esi
// 0043465c  8bf1                 mov esi, ecx
// 0043465e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00434661  8b18                 mov ebx, dword ptr [eax]
// 00434663  8b06                 mov eax, dword ptr [esi]
// 00434665  57                   push edi
// 00434666  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043466a  85ff                 test edi, edi
// 0043466c  7404                 je 0x434672
// 0043466e  3bf8                 cmp edi, eax
// 00434670  7406                 je 0x434678
// 00434672  ffd5                 call ebp
// 00434674  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00434678  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0043467c  7562                 jne 0x4346e0
// 0043467e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00434682  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00434685  8b06                 mov eax, dword ptr [esi]
// 00434687  85c9                 test ecx, ecx
// 00434689  7404                 je 0x43468f
// 0043468b  3bc8                 cmp ecx, eax
// 0043468d  7406                 je 0x434695
// 0043468f  ffd5                 call ebp
// 00434691  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00434695  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00434699  7545                 jne 0x4346e0
// 0043469b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0043469e  8b5104               mov edx, dword ptr [ecx + 4]
// 004346a1  52                   push edx
// 004346a2  8bce                 mov ecx, esi
// 004346a4  e8a7dafcff           call 0x402150
// 004346a9  8b4618               mov eax, dword ptr [esi + 0x18]
// 004346ac  894004               mov dword ptr [eax + 4], eax
// 004346af  8b4618               mov eax, dword ptr [esi + 0x18]
// 004346b2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004346b9  8900                 mov dword ptr [eax], eax
// 004346bb  8b4618               mov eax, dword ptr [esi + 0x18]
// 004346be  894008               mov dword ptr [eax + 8], eax
// 004346c1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004346c4  8b16                 mov edx, dword ptr [esi]
// 004346c6  8b08                 mov ecx, dword ptr [eax]
// 004346c8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004346cc  5f                   pop edi
// 004346cd  5e                   pop esi
// 004346ce  5d                   pop ebp
// 004346cf  894804               mov dword ptr [eax + 4], ecx
// 004346d2  8910                 mov dword ptr [eax], edx
// 004346d4  5b                   pop ebx
// 004346d5  83c408               add esp, 8
// 004346d8  c21400               ret 0x14
// 004346db  eb03                 jmp 0x4346e0
// 004346dd  8d4900               lea ecx, [ecx]
// 004346e0  85ff                 test edi, edi
// 004346e2  7406                 je 0x4346ea
// 004346e4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004346e8  7406                 je 0x4346f0
// 004346ea  ffd5                 call ebp
// 004346ec  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004346f0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004346f4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004346f8  741d                 je 0x434717
// 004346fa  8d4c2420             lea ecx, [esp + 0x20]
// 004346fe  e87d582e00           call 0x719f80
// 00434703  53                   push ebx
// 00434704  57                   push edi
// 00434705  8d442418             lea eax, [esp + 0x18]
// 00434709  50                   push eax
// 0043470a  8bce                 mov ecx, esi
// 0043470c  e89ff9ffff           call 0x4340b0
// 00434711  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00434715  ebc9                 jmp 0x4346e0
// 00434717  8b36                 mov esi, dword ptr [esi]
// 00434719  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0043471d  5f                   pop edi
// 0043471e  8930                 mov dword ptr [eax], esi
// 00434720  5e                   pop esi
// 00434721  5d                   pop ebp
// 00434722  895804               mov dword ptr [eax + 4], ebx
// 00434725  5b                   pop ebx
// 00434726  83c408               add esp, 8
// 00434729  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
