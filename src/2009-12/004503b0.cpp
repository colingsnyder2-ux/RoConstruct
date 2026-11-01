// from server: 100% by auto
// roc 2009-12 004503b0  unit: RBX::VExplosion::?$FactoryProduct::Creator  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004503b0
//
// 004503b0  83ec08               sub esp, 8
// 004503b3  53                   push ebx
// 004503b4  55                   push ebp
// 004503b5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 004503bb  56                   push esi
// 004503bc  8bf1                 mov esi, ecx
// 004503be  8b4618               mov eax, dword ptr [esi + 0x18]
// 004503c1  8b18                 mov ebx, dword ptr [eax]
// 004503c3  8b06                 mov eax, dword ptr [esi]
// 004503c5  57                   push edi
// 004503c6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004503ca  85ff                 test edi, edi
// 004503cc  7404                 je 0x4503d2
// 004503ce  3bf8                 cmp edi, eax
// 004503d0  7406                 je 0x4503d8
// 004503d2  ffd5                 call ebp
// 004503d4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004503d8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004503dc  7562                 jne 0x450440
// 004503de  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004503e2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004503e5  8b06                 mov eax, dword ptr [esi]
// 004503e7  85c9                 test ecx, ecx
// 004503e9  7404                 je 0x4503ef
// 004503eb  3bc8                 cmp ecx, eax
// 004503ed  7406                 je 0x4503f5
// 004503ef  ffd5                 call ebp
// 004503f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004503f5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004503f9  7545                 jne 0x450440
// 004503fb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004503fe  8b5104               mov edx, dword ptr [ecx + 4]
// 00450401  52                   push edx
// 00450402  8bce                 mov ecx, esi
// 00450404  e8a7f9ffff           call 0x44fdb0
// 00450409  8b4618               mov eax, dword ptr [esi + 0x18]
// 0045040c  894004               mov dword ptr [eax + 4], eax
// 0045040f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00450412  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00450419  8900                 mov dword ptr [eax], eax
// 0045041b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0045041e  894008               mov dword ptr [eax + 8], eax
// 00450421  8b4618               mov eax, dword ptr [esi + 0x18]
// 00450424  8b16                 mov edx, dword ptr [esi]
// 00450426  8b08                 mov ecx, dword ptr [eax]
// 00450428  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0045042c  5f                   pop edi
// 0045042d  5e                   pop esi
// 0045042e  5d                   pop ebp
// 0045042f  894804               mov dword ptr [eax + 4], ecx
// 00450432  8910                 mov dword ptr [eax], edx
// 00450434  5b                   pop ebx
// 00450435  83c408               add esp, 8
// 00450438  c21400               ret 0x14
// 0045043b  eb03                 jmp 0x450440
// 0045043d  8d4900               lea ecx, [ecx]
// 00450440  85ff                 test edi, edi
// 00450442  7406                 je 0x45044a
// 00450444  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00450448  7406                 je 0x450450
// 0045044a  ffd5                 call ebp
// 0045044c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00450450  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00450454  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00450458  741d                 je 0x450477
// 0045045a  8d4c2420             lea ecx, [esp + 0x20]
// 0045045e  e8cda91000           call 0x55ae30
// 00450463  53                   push ebx
// 00450464  57                   push edi
// 00450465  8d442418             lea eax, [esp + 0x18]
// 00450469  50                   push eax
// 0045046a  8bce                 mov ecx, esi
// 0045046c  e84ff6ffff           call 0x44fac0
// 00450471  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00450475  ebc9                 jmp 0x450440
// 00450477  8b36                 mov esi, dword ptr [esi]
// 00450479  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0045047d  5f                   pop edi
// 0045047e  8930                 mov dword ptr [eax], esi
// 00450480  5e                   pop esi
// 00450481  5d                   pop ebp
// 00450482  895804               mov dword ptr [eax + 4], ebx
// 00450485  5b                   pop ebx
// 00450486  83c408               add esp, 8
// 00450489  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
