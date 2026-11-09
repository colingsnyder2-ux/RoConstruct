// from server: 100% by auto
// roc 2009-06 0043c750  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043c750
//
// 0043c750  83ec08               sub esp, 8
// 0043c753  53                   push ebx
// 0043c754  55                   push ebp
// 0043c755  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 0043c75b  56                   push esi
// 0043c75c  8bf1                 mov esi, ecx
// 0043c75e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0043c761  8b18                 mov ebx, dword ptr [eax]
// 0043c763  8b06                 mov eax, dword ptr [esi]
// 0043c765  57                   push edi
// 0043c766  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043c76a  85ff                 test edi, edi
// 0043c76c  7404                 je 0x43c772
// 0043c76e  3bf8                 cmp edi, eax
// 0043c770  7406                 je 0x43c778
// 0043c772  ffd5                 call ebp
// 0043c774  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043c778  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0043c77c  7562                 jne 0x43c7e0
// 0043c77e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0043c782  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0043c785  8b06                 mov eax, dword ptr [esi]
// 0043c787  85c9                 test ecx, ecx
// 0043c789  7404                 je 0x43c78f
// 0043c78b  3bc8                 cmp ecx, eax
// 0043c78d  7406                 je 0x43c795
// 0043c78f  ffd5                 call ebp
// 0043c791  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043c795  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0043c799  7545                 jne 0x43c7e0
// 0043c79b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0043c79e  8b5104               mov edx, dword ptr [ecx + 4]
// 0043c7a1  52                   push edx
// 0043c7a2  8bce                 mov ecx, esi
// 0043c7a4  e837feffff           call 0x43c5e0
// 0043c7a9  8b4618               mov eax, dword ptr [esi + 0x18]
// 0043c7ac  894004               mov dword ptr [eax + 4], eax
// 0043c7af  8b4618               mov eax, dword ptr [esi + 0x18]
// 0043c7b2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0043c7b9  8900                 mov dword ptr [eax], eax
// 0043c7bb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0043c7be  894008               mov dword ptr [eax + 8], eax
// 0043c7c1  8b4618               mov eax, dword ptr [esi + 0x18]
// 0043c7c4  8b16                 mov edx, dword ptr [esi]
// 0043c7c6  8b08                 mov ecx, dword ptr [eax]
// 0043c7c8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0043c7cc  5f                   pop edi
// 0043c7cd  5e                   pop esi
// 0043c7ce  5d                   pop ebp
// 0043c7cf  894804               mov dword ptr [eax + 4], ecx
// 0043c7d2  8910                 mov dword ptr [eax], edx
// 0043c7d4  5b                   pop ebx
// 0043c7d5  83c408               add esp, 8
// 0043c7d8  c21400               ret 0x14
// 0043c7db  eb03                 jmp 0x43c7e0
// 0043c7dd  8d4900               lea ecx, [ecx]
// 0043c7e0  85ff                 test edi, edi
// 0043c7e2  7406                 je 0x43c7ea
// 0043c7e4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0043c7e8  7406                 je 0x43c7f0
// 0043c7ea  ffd5                 call ebp
// 0043c7ec  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043c7f0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0043c7f4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0043c7f8  741d                 je 0x43c817
// 0043c7fa  8d4c2420             lea ecx, [esp + 0x20]
// 0043c7fe  e86db00d00           call 0x517870
// 0043c803  53                   push ebx
// 0043c804  57                   push edi
// 0043c805  8d442418             lea eax, [esp + 0x18]
// 0043c809  50                   push eax
// 0043c80a  8bce                 mov ecx, esi
// 0043c80c  e80ff9ffff           call 0x43c120
// 0043c811  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043c815  ebc9                 jmp 0x43c7e0
// 0043c817  8b36                 mov esi, dword ptr [esi]
// 0043c819  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0043c81d  5f                   pop edi
// 0043c81e  8930                 mov dword ptr [eax], esi
// 0043c820  5e                   pop esi
// 0043c821  5d                   pop ebp
// 0043c822  895804               mov dword ptr [eax + 4], ebx
// 0043c825  5b                   pop ebx
// 0043c826  83c408               add esp, 8
// 0043c829  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
