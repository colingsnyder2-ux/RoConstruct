// from server: 100% by auto
// roc 2008-06 004145f0  unit: CopyVerb  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004145f0
//
// 004145f0  83ec08               sub esp, 8
// 004145f3  53                   push ebx
// 004145f4  55                   push ebp
// 004145f5  8b2d90288000         mov ebp, dword ptr [0x802890]
// 004145fb  56                   push esi
// 004145fc  8bf1                 mov esi, ecx
// 004145fe  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414601  8b18                 mov ebx, dword ptr [eax]
// 00414603  8b06                 mov eax, dword ptr [esi]
// 00414605  57                   push edi
// 00414606  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041460a  85ff                 test edi, edi
// 0041460c  7404                 je 0x414612
// 0041460e  3bf8                 cmp edi, eax
// 00414610  7406                 je 0x414618
// 00414612  ffd5                 call ebp
// 00414614  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414618  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0041461c  7562                 jne 0x414680
// 0041461e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00414622  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00414625  8b06                 mov eax, dword ptr [esi]
// 00414627  85c9                 test ecx, ecx
// 00414629  7404                 je 0x41462f
// 0041462b  3bc8                 cmp ecx, eax
// 0041462d  7406                 je 0x414635
// 0041462f  ffd5                 call ebp
// 00414631  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414635  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00414639  7545                 jne 0x414680
// 0041463b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0041463e  8b5104               mov edx, dword ptr [ecx + 4]
// 00414641  52                   push edx
// 00414642  8bce                 mov ecx, esi
// 00414644  e897fdffff           call 0x4143e0
// 00414649  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041464c  894004               mov dword ptr [eax + 4], eax
// 0041464f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414652  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00414659  8900                 mov dword ptr [eax], eax
// 0041465b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041465e  894008               mov dword ptr [eax + 8], eax
// 00414661  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414664  8b16                 mov edx, dword ptr [esi]
// 00414666  8b08                 mov ecx, dword ptr [eax]
// 00414668  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041466c  5f                   pop edi
// 0041466d  5e                   pop esi
// 0041466e  5d                   pop ebp
// 0041466f  894804               mov dword ptr [eax + 4], ecx
// 00414672  8910                 mov dword ptr [eax], edx
// 00414674  5b                   pop ebx
// 00414675  83c408               add esp, 8
// 00414678  c21400               ret 0x14
// 0041467b  eb03                 jmp 0x414680
// 0041467d  8d4900               lea ecx, [ecx]
// 00414680  85ff                 test edi, edi
// 00414682  7406                 je 0x41468a
// 00414684  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00414688  7406                 je 0x414690
// 0041468a  ffd5                 call ebp
// 0041468c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414690  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00414694  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00414698  741d                 je 0x4146b7
// 0041469a  8d4c2420             lea ecx, [esp + 0x20]
// 0041469e  e80df3ffff           call 0x4139b0
// 004146a3  53                   push ebx
// 004146a4  57                   push edi
// 004146a5  8d442418             lea eax, [esp + 0x18]
// 004146a9  50                   push eax
// 004146aa  8bce                 mov ecx, esi
// 004146ac  e8bff9ffff           call 0x414070
// 004146b1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004146b5  ebc9                 jmp 0x414680
// 004146b7  8b36                 mov esi, dword ptr [esi]
// 004146b9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004146bd  5f                   pop edi
// 004146be  8930                 mov dword ptr [eax], esi
// 004146c0  5e                   pop esi
// 004146c1  5d                   pop ebp
// 004146c2  895804               mov dword ptr [eax + 4], ebx
// 004146c5  5b                   pop ebx
// 004146c6  83c408               add esp, 8
// 004146c9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
