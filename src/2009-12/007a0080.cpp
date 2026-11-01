// from server: 100% by auto
// roc 2009-12 007a0080  unit: seg_007a0000  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007a0080
//
// 007a0080  83ec08               sub esp, 8
// 007a0083  53                   push ebx
// 007a0084  55                   push ebp
// 007a0085  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 007a008b  56                   push esi
// 007a008c  8bf1                 mov esi, ecx
// 007a008e  8b4618               mov eax, dword ptr [esi + 0x18]
// 007a0091  8b18                 mov ebx, dword ptr [eax]
// 007a0093  8b06                 mov eax, dword ptr [esi]
// 007a0095  57                   push edi
// 007a0096  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007a009a  85ff                 test edi, edi
// 007a009c  7404                 je 0x7a00a2
// 007a009e  3bf8                 cmp edi, eax
// 007a00a0  7406                 je 0x7a00a8
// 007a00a2  ffd5                 call ebp
// 007a00a4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007a00a8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 007a00ac  7562                 jne 0x7a0110
// 007a00ae  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007a00b2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 007a00b5  8b06                 mov eax, dword ptr [esi]
// 007a00b7  85c9                 test ecx, ecx
// 007a00b9  7404                 je 0x7a00bf
// 007a00bb  3bc8                 cmp ecx, eax
// 007a00bd  7406                 je 0x7a00c5
// 007a00bf  ffd5                 call ebp
// 007a00c1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007a00c5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 007a00c9  7545                 jne 0x7a0110
// 007a00cb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007a00ce  8b5104               mov edx, dword ptr [ecx + 4]
// 007a00d1  52                   push edx
// 007a00d2  8bce                 mov ecx, esi
// 007a00d4  e807fcffff           call 0x79fce0
// 007a00d9  8b4618               mov eax, dword ptr [esi + 0x18]
// 007a00dc  894004               mov dword ptr [eax + 4], eax
// 007a00df  8b4618               mov eax, dword ptr [esi + 0x18]
// 007a00e2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007a00e9  8900                 mov dword ptr [eax], eax
// 007a00eb  8b4618               mov eax, dword ptr [esi + 0x18]
// 007a00ee  894008               mov dword ptr [eax + 8], eax
// 007a00f1  8b4618               mov eax, dword ptr [esi + 0x18]
// 007a00f4  8b16                 mov edx, dword ptr [esi]
// 007a00f6  8b08                 mov ecx, dword ptr [eax]
// 007a00f8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007a00fc  5f                   pop edi
// 007a00fd  5e                   pop esi
// 007a00fe  5d                   pop ebp
// 007a00ff  894804               mov dword ptr [eax + 4], ecx
// 007a0102  8910                 mov dword ptr [eax], edx
// 007a0104  5b                   pop ebx
// 007a0105  83c408               add esp, 8
// 007a0108  c21400               ret 0x14
// 007a010b  eb03                 jmp 0x7a0110
// 007a010d  8d4900               lea ecx, [ecx]
// 007a0110  85ff                 test edi, edi
// 007a0112  7406                 je 0x7a011a
// 007a0114  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 007a0118  7406                 je 0x7a0120
// 007a011a  ffd5                 call ebp
// 007a011c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007a0120  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007a0124  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 007a0128  741d                 je 0x7a0147
// 007a012a  8d4c2420             lea ecx, [esp + 0x20]
// 007a012e  e8dda7cdff           call 0x47a910
// 007a0133  53                   push ebx
// 007a0134  57                   push edi
// 007a0135  8d442418             lea eax, [esp + 0x18]
// 007a0139  50                   push eax
// 007a013a  8bce                 mov ecx, esi
// 007a013c  e8bff8ffff           call 0x79fa00
// 007a0141  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007a0145  ebc9                 jmp 0x7a0110
// 007a0147  8b36                 mov esi, dword ptr [esi]
// 007a0149  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007a014d  5f                   pop edi
// 007a014e  8930                 mov dword ptr [eax], esi
// 007a0150  5e                   pop esi
// 007a0151  5d                   pop ebp
// 007a0152  895804               mov dword ptr [eax + 4], ebx
// 007a0155  5b                   pop ebx
// 007a0156  83c408               add esp, 8
// 007a0159  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
