// from server: 100% by auto
// roc 2009-06 004e8890  unit: RBX::JointsService  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e8890
//
// 004e8890  83ec08               sub esp, 8
// 004e8893  53                   push ebx
// 004e8894  55                   push ebp
// 004e8895  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 004e889b  56                   push esi
// 004e889c  8bf1                 mov esi, ecx
// 004e889e  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e88a1  8b18                 mov ebx, dword ptr [eax]
// 004e88a3  8b06                 mov eax, dword ptr [esi]
// 004e88a5  57                   push edi
// 004e88a6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004e88aa  85ff                 test edi, edi
// 004e88ac  7404                 je 0x4e88b2
// 004e88ae  3bf8                 cmp edi, eax
// 004e88b0  7406                 je 0x4e88b8
// 004e88b2  ffd5                 call ebp
// 004e88b4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004e88b8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004e88bc  7562                 jne 0x4e8920
// 004e88be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004e88c2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004e88c5  8b06                 mov eax, dword ptr [esi]
// 004e88c7  85c9                 test ecx, ecx
// 004e88c9  7404                 je 0x4e88cf
// 004e88cb  3bc8                 cmp ecx, eax
// 004e88cd  7406                 je 0x4e88d5
// 004e88cf  ffd5                 call ebp
// 004e88d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004e88d5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004e88d9  7545                 jne 0x4e8920
// 004e88db  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004e88de  8b5104               mov edx, dword ptr [ecx + 4]
// 004e88e1  52                   push edx
// 004e88e2  8bce                 mov ecx, esi
// 004e88e4  e847eeffff           call 0x4e7730
// 004e88e9  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e88ec  894004               mov dword ptr [eax + 4], eax
// 004e88ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e88f2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004e88f9  8900                 mov dword ptr [eax], eax
// 004e88fb  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e88fe  894008               mov dword ptr [eax + 8], eax
// 004e8901  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e8904  8b16                 mov edx, dword ptr [esi]
// 004e8906  8b08                 mov ecx, dword ptr [eax]
// 004e8908  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004e890c  5f                   pop edi
// 004e890d  5e                   pop esi
// 004e890e  5d                   pop ebp
// 004e890f  894804               mov dword ptr [eax + 4], ecx
// 004e8912  8910                 mov dword ptr [eax], edx
// 004e8914  5b                   pop ebx
// 004e8915  83c408               add esp, 8
// 004e8918  c21400               ret 0x14
// 004e891b  eb03                 jmp 0x4e8920
// 004e891d  8d4900               lea ecx, [ecx]
// 004e8920  85ff                 test edi, edi
// 004e8922  7406                 je 0x4e892a
// 004e8924  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004e8928  7406                 je 0x4e8930
// 004e892a  ffd5                 call ebp
// 004e892c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004e8930  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004e8934  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004e8938  741d                 je 0x4e8957
// 004e893a  8d4c2420             lea ecx, [esp + 0x20]
// 004e893e  e87d991300           call 0x6222c0
// 004e8943  53                   push ebx
// 004e8944  57                   push edi
// 004e8945  8d442418             lea eax, [esp + 0x18]
// 004e8949  50                   push eax
// 004e894a  8bce                 mov ecx, esi
// 004e894c  e8dfeaffff           call 0x4e7430
// 004e8951  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004e8955  ebc9                 jmp 0x4e8920
// 004e8957  8b36                 mov esi, dword ptr [esi]
// 004e8959  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004e895d  5f                   pop edi
// 004e895e  8930                 mov dword ptr [eax], esi
// 004e8960  5e                   pop esi
// 004e8961  5d                   pop ebp
// 004e8962  895804               mov dword ptr [eax + 4], ebx
// 004e8965  5b                   pop ebx
// 004e8966  83c408               add esp, 8
// 004e8969  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
