// from server: 100% by auto
// roc 2010-06 007a0260  unit: RBX::TaskScheduler::VThread::?$sp_counted_impl_p  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007a0260
//
// 007a0260  83ec08               sub esp, 8
// 007a0263  53                   push ebx
// 007a0264  55                   push ebp
// 007a0265  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 007a026b  56                   push esi
// 007a026c  8bf1                 mov esi, ecx
// 007a026e  8b4618               mov eax, dword ptr [esi + 0x18]
// 007a0271  8b18                 mov ebx, dword ptr [eax]
// 007a0273  8b06                 mov eax, dword ptr [esi]
// 007a0275  57                   push edi
// 007a0276  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007a027a  85ff                 test edi, edi
// 007a027c  7404                 je 0x7a0282
// 007a027e  3bf8                 cmp edi, eax
// 007a0280  7406                 je 0x7a0288
// 007a0282  ffd5                 call ebp
// 007a0284  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007a0288  395c2424             cmp dword ptr [esp + 0x24], ebx
// 007a028c  7562                 jne 0x7a02f0
// 007a028e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007a0292  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 007a0295  8b06                 mov eax, dword ptr [esi]
// 007a0297  85c9                 test ecx, ecx
// 007a0299  7404                 je 0x7a029f
// 007a029b  3bc8                 cmp ecx, eax
// 007a029d  7406                 je 0x7a02a5
// 007a029f  ffd5                 call ebp
// 007a02a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007a02a5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 007a02a9  7545                 jne 0x7a02f0
// 007a02ab  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007a02ae  8b5104               mov edx, dword ptr [ecx + 4]
// 007a02b1  52                   push edx
// 007a02b2  8bce                 mov ecx, esi
// 007a02b4  e8d783ccff           call 0x468690
// 007a02b9  8b4618               mov eax, dword ptr [esi + 0x18]
// 007a02bc  894004               mov dword ptr [eax + 4], eax
// 007a02bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 007a02c2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007a02c9  8900                 mov dword ptr [eax], eax
// 007a02cb  8b4618               mov eax, dword ptr [esi + 0x18]
// 007a02ce  894008               mov dword ptr [eax + 8], eax
// 007a02d1  8b4618               mov eax, dword ptr [esi + 0x18]
// 007a02d4  8b16                 mov edx, dword ptr [esi]
// 007a02d6  8b08                 mov ecx, dword ptr [eax]
// 007a02d8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007a02dc  5f                   pop edi
// 007a02dd  5e                   pop esi
// 007a02de  5d                   pop ebp
// 007a02df  894804               mov dword ptr [eax + 4], ecx
// 007a02e2  8910                 mov dword ptr [eax], edx
// 007a02e4  5b                   pop ebx
// 007a02e5  83c408               add esp, 8
// 007a02e8  c21400               ret 0x14
// 007a02eb  eb03                 jmp 0x7a02f0
// 007a02ed  8d4900               lea ecx, [ecx]
// 007a02f0  85ff                 test edi, edi
// 007a02f2  7406                 je 0x7a02fa
// 007a02f4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 007a02f8  7406                 je 0x7a0300
// 007a02fa  ffd5                 call ebp
// 007a02fc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007a0300  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007a0304  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 007a0308  741d                 je 0x7a0327
// 007a030a  8d4c2420             lea ecx, [esp + 0x20]
// 007a030e  e8cd76f4ff           call 0x6e79e0
// 007a0313  53                   push ebx
// 007a0314  57                   push edi
// 007a0315  8d442418             lea eax, [esp + 0x18]
// 007a0319  50                   push eax
// 007a031a  8bce                 mov ecx, esi
// 007a031c  e87ffcffff           call 0x79ffa0
// 007a0321  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007a0325  ebc9                 jmp 0x7a02f0
// 007a0327  8b36                 mov esi, dword ptr [esi]
// 007a0329  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007a032d  5f                   pop edi
// 007a032e  8930                 mov dword ptr [eax], esi
// 007a0330  5e                   pop esi
// 007a0331  5d                   pop ebp
// 007a0332  895804               mov dword ptr [eax + 4], ebx
// 007a0335  5b                   pop ebx
// 007a0336  83c408               add esp, 8
// 007a0339  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
