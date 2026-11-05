// from server: 100% by auto
// roc 2008-06 00414510  unit: CopyVerb  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00414510
//
// 00414510  83ec08               sub esp, 8
// 00414513  53                   push ebx
// 00414514  55                   push ebp
// 00414515  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0041451b  56                   push esi
// 0041451c  8bf1                 mov esi, ecx
// 0041451e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414521  8b18                 mov ebx, dword ptr [eax]
// 00414523  8b06                 mov eax, dword ptr [esi]
// 00414525  57                   push edi
// 00414526  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041452a  85ff                 test edi, edi
// 0041452c  7404                 je 0x414532
// 0041452e  3bf8                 cmp edi, eax
// 00414530  7406                 je 0x414538
// 00414532  ffd5                 call ebp
// 00414534  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414538  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0041453c  7562                 jne 0x4145a0
// 0041453e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00414542  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00414545  8b06                 mov eax, dword ptr [esi]
// 00414547  85c9                 test ecx, ecx
// 00414549  7404                 je 0x41454f
// 0041454b  3bc8                 cmp ecx, eax
// 0041454d  7406                 je 0x414555
// 0041454f  ffd5                 call ebp
// 00414551  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414555  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00414559  7545                 jne 0x4145a0
// 0041455b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0041455e  8b5104               mov edx, dword ptr [ecx + 4]
// 00414561  52                   push edx
// 00414562  8bce                 mov ecx, esi
// 00414564  e807feffff           call 0x414370
// 00414569  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041456c  894004               mov dword ptr [eax + 4], eax
// 0041456f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414572  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00414579  8900                 mov dword ptr [eax], eax
// 0041457b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041457e  894008               mov dword ptr [eax + 8], eax
// 00414581  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414584  8b16                 mov edx, dword ptr [esi]
// 00414586  8b08                 mov ecx, dword ptr [eax]
// 00414588  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041458c  5f                   pop edi
// 0041458d  5e                   pop esi
// 0041458e  5d                   pop ebp
// 0041458f  894804               mov dword ptr [eax + 4], ecx
// 00414592  8910                 mov dword ptr [eax], edx
// 00414594  5b                   pop ebx
// 00414595  83c408               add esp, 8
// 00414598  c21400               ret 0x14
// 0041459b  eb03                 jmp 0x4145a0
// 0041459d  8d4900               lea ecx, [ecx]
// 004145a0  85ff                 test edi, edi
// 004145a2  7406                 je 0x4145aa
// 004145a4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004145a8  7406                 je 0x4145b0
// 004145aa  ffd5                 call ebp
// 004145ac  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004145b0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004145b4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004145b8  741d                 je 0x4145d7
// 004145ba  8d4c2420             lea ecx, [esp + 0x20]
// 004145be  e88d2c1a00           call 0x5b7250
// 004145c3  53                   push ebx
// 004145c4  57                   push edi
// 004145c5  8d442418             lea eax, [esp + 0x18]
// 004145c9  50                   push eax
// 004145ca  8bce                 mov ecx, esi
// 004145cc  e89ff7ffff           call 0x413d70
// 004145d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004145d5  ebc9                 jmp 0x4145a0
// 004145d7  8b36                 mov esi, dword ptr [esi]
// 004145d9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004145dd  5f                   pop edi
// 004145de  8930                 mov dword ptr [eax], esi
// 004145e0  5e                   pop esi
// 004145e1  5d                   pop ebp
// 004145e2  895804               mov dword ptr [eax + 4], ebx
// 004145e5  5b                   pop ebx
// 004145e6  83c408               add esp, 8
// 004145e9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
