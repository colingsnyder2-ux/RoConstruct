// from server: 100% by auto
// roc 2009-12 007ec0d0  unit: RBX::TaskScheduler::VThread::?$sp_counted_impl_p  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007ec0d0
//
// 007ec0d0  83ec08               sub esp, 8
// 007ec0d3  53                   push ebx
// 007ec0d4  55                   push ebp
// 007ec0d5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 007ec0db  56                   push esi
// 007ec0dc  8bf1                 mov esi, ecx
// 007ec0de  8b4618               mov eax, dword ptr [esi + 0x18]
// 007ec0e1  8b18                 mov ebx, dword ptr [eax]
// 007ec0e3  8b06                 mov eax, dword ptr [esi]
// 007ec0e5  57                   push edi
// 007ec0e6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007ec0ea  85ff                 test edi, edi
// 007ec0ec  7404                 je 0x7ec0f2
// 007ec0ee  3bf8                 cmp edi, eax
// 007ec0f0  7406                 je 0x7ec0f8
// 007ec0f2  ffd5                 call ebp
// 007ec0f4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007ec0f8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 007ec0fc  7562                 jne 0x7ec160
// 007ec0fe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007ec102  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 007ec105  8b06                 mov eax, dword ptr [esi]
// 007ec107  85c9                 test ecx, ecx
// 007ec109  7404                 je 0x7ec10f
// 007ec10b  3bc8                 cmp ecx, eax
// 007ec10d  7406                 je 0x7ec115
// 007ec10f  ffd5                 call ebp
// 007ec111  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007ec115  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 007ec119  7545                 jne 0x7ec160
// 007ec11b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007ec11e  8b5104               mov edx, dword ptr [ecx + 4]
// 007ec121  52                   push edx
// 007ec122  8bce                 mov ecx, esi
// 007ec124  e8e779c4ff           call 0x433b10
// 007ec129  8b4618               mov eax, dword ptr [esi + 0x18]
// 007ec12c  894004               mov dword ptr [eax + 4], eax
// 007ec12f  8b4618               mov eax, dword ptr [esi + 0x18]
// 007ec132  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007ec139  8900                 mov dword ptr [eax], eax
// 007ec13b  8b4618               mov eax, dword ptr [esi + 0x18]
// 007ec13e  894008               mov dword ptr [eax + 8], eax
// 007ec141  8b4618               mov eax, dword ptr [esi + 0x18]
// 007ec144  8b16                 mov edx, dword ptr [esi]
// 007ec146  8b08                 mov ecx, dword ptr [eax]
// 007ec148  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007ec14c  5f                   pop edi
// 007ec14d  5e                   pop esi
// 007ec14e  5d                   pop ebp
// 007ec14f  894804               mov dword ptr [eax + 4], ecx
// 007ec152  8910                 mov dword ptr [eax], edx
// 007ec154  5b                   pop ebx
// 007ec155  83c408               add esp, 8
// 007ec158  c21400               ret 0x14
// 007ec15b  eb03                 jmp 0x7ec160
// 007ec15d  8d4900               lea ecx, [ecx]
// 007ec160  85ff                 test edi, edi
// 007ec162  7406                 je 0x7ec16a
// 007ec164  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 007ec168  7406                 je 0x7ec170
// 007ec16a  ffd5                 call ebp
// 007ec16c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007ec170  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007ec174  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 007ec178  741d                 je 0x7ec197
// 007ec17a  8d4c2420             lea ecx, [esp + 0x20]
// 007ec17e  e86d0fecff           call 0x6ad0f0
// 007ec183  53                   push ebx
// 007ec184  57                   push edi
// 007ec185  8d442418             lea eax, [esp + 0x18]
// 007ec189  50                   push eax
// 007ec18a  8bce                 mov ecx, esi
// 007ec18c  e87ffcffff           call 0x7ebe10
// 007ec191  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007ec195  ebc9                 jmp 0x7ec160
// 007ec197  8b36                 mov esi, dword ptr [esi]
// 007ec199  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007ec19d  5f                   pop edi
// 007ec19e  8930                 mov dword ptr [eax], esi
// 007ec1a0  5e                   pop esi
// 007ec1a1  5d                   pop ebp
// 007ec1a2  895804               mov dword ptr [eax + 4], ebx
// 007ec1a5  5b                   pop ebx
// 007ec1a6  83c408               add esp, 8
// 007ec1a9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
