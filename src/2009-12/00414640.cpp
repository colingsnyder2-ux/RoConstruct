// from server: 100% by auto
// roc 2009-12 00414640  unit: CopyVerb  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00414640
//
// 00414640  83ec08               sub esp, 8
// 00414643  53                   push ebx
// 00414644  55                   push ebp
// 00414645  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0041464b  56                   push esi
// 0041464c  8bf1                 mov esi, ecx
// 0041464e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414651  8b18                 mov ebx, dword ptr [eax]
// 00414653  8b06                 mov eax, dword ptr [esi]
// 00414655  57                   push edi
// 00414656  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041465a  85ff                 test edi, edi
// 0041465c  7404                 je 0x414662
// 0041465e  3bf8                 cmp edi, eax
// 00414660  7406                 je 0x414668
// 00414662  ffd5                 call ebp
// 00414664  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414668  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0041466c  7562                 jne 0x4146d0
// 0041466e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00414672  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00414675  8b06                 mov eax, dword ptr [esi]
// 00414677  85c9                 test ecx, ecx
// 00414679  7404                 je 0x41467f
// 0041467b  3bc8                 cmp ecx, eax
// 0041467d  7406                 je 0x414685
// 0041467f  ffd5                 call ebp
// 00414681  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414685  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00414689  7545                 jne 0x4146d0
// 0041468b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0041468e  8b5104               mov edx, dword ptr [ecx + 4]
// 00414691  52                   push edx
// 00414692  8bce                 mov ecx, esi
// 00414694  e847fdffff           call 0x4143e0
// 00414699  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041469c  894004               mov dword ptr [eax + 4], eax
// 0041469f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004146a2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004146a9  8900                 mov dword ptr [eax], eax
// 004146ab  8b4618               mov eax, dword ptr [esi + 0x18]
// 004146ae  894008               mov dword ptr [eax + 8], eax
// 004146b1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004146b4  8b16                 mov edx, dword ptr [esi]
// 004146b6  8b08                 mov ecx, dword ptr [eax]
// 004146b8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004146bc  5f                   pop edi
// 004146bd  5e                   pop esi
// 004146be  5d                   pop ebp
// 004146bf  894804               mov dword ptr [eax + 4], ecx
// 004146c2  8910                 mov dword ptr [eax], edx
// 004146c4  5b                   pop ebx
// 004146c5  83c408               add esp, 8
// 004146c8  c21400               ret 0x14
// 004146cb  eb03                 jmp 0x4146d0
// 004146cd  8d4900               lea ecx, [ecx]
// 004146d0  85ff                 test edi, edi
// 004146d2  7406                 je 0x4146da
// 004146d4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004146d8  7406                 je 0x4146e0
// 004146da  ffd5                 call ebp
// 004146dc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004146e0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004146e4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004146e8  741d                 je 0x414707
// 004146ea  8d4c2420             lea ecx, [esp + 0x20]
// 004146ee  e82df3ffff           call 0x413a20
// 004146f3  53                   push ebx
// 004146f4  57                   push edi
// 004146f5  8d442418             lea eax, [esp + 0x18]
// 004146f9  50                   push eax
// 004146fa  8bce                 mov ecx, esi
// 004146fc  e86ff9ffff           call 0x414070
// 00414701  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414705  ebc9                 jmp 0x4146d0
// 00414707  8b36                 mov esi, dword ptr [esi]
// 00414709  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041470d  5f                   pop edi
// 0041470e  8930                 mov dword ptr [eax], esi
// 00414710  5e                   pop esi
// 00414711  5d                   pop ebp
// 00414712  895804               mov dword ptr [eax + 4], ebx
// 00414715  5b                   pop ebx
// 00414716  83c408               add esp, 8
// 00414719  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
