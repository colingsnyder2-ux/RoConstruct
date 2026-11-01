// from server: 100% by auto
// roc 2009-12 00414560  unit: CopyVerb  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00414560
//
// 00414560  83ec08               sub esp, 8
// 00414563  53                   push ebx
// 00414564  55                   push ebp
// 00414565  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0041456b  56                   push esi
// 0041456c  8bf1                 mov esi, ecx
// 0041456e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414571  8b18                 mov ebx, dword ptr [eax]
// 00414573  8b06                 mov eax, dword ptr [esi]
// 00414575  57                   push edi
// 00414576  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041457a  85ff                 test edi, edi
// 0041457c  7404                 je 0x414582
// 0041457e  3bf8                 cmp edi, eax
// 00414580  7406                 je 0x414588
// 00414582  ffd5                 call ebp
// 00414584  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414588  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0041458c  7562                 jne 0x4145f0
// 0041458e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00414592  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00414595  8b06                 mov eax, dword ptr [esi]
// 00414597  85c9                 test ecx, ecx
// 00414599  7404                 je 0x41459f
// 0041459b  3bc8                 cmp ecx, eax
// 0041459d  7406                 je 0x4145a5
// 0041459f  ffd5                 call ebp
// 004145a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004145a5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004145a9  7545                 jne 0x4145f0
// 004145ab  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004145ae  8b5104               mov edx, dword ptr [ecx + 4]
// 004145b1  52                   push edx
// 004145b2  8bce                 mov ecx, esi
// 004145b4  e8b7fdffff           call 0x414370
// 004145b9  8b4618               mov eax, dword ptr [esi + 0x18]
// 004145bc  894004               mov dword ptr [eax + 4], eax
// 004145bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 004145c2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004145c9  8900                 mov dword ptr [eax], eax
// 004145cb  8b4618               mov eax, dword ptr [esi + 0x18]
// 004145ce  894008               mov dword ptr [eax + 8], eax
// 004145d1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004145d4  8b16                 mov edx, dword ptr [esi]
// 004145d6  8b08                 mov ecx, dword ptr [eax]
// 004145d8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004145dc  5f                   pop edi
// 004145dd  5e                   pop esi
// 004145de  5d                   pop ebp
// 004145df  894804               mov dword ptr [eax + 4], ecx
// 004145e2  8910                 mov dword ptr [eax], edx
// 004145e4  5b                   pop ebx
// 004145e5  83c408               add esp, 8
// 004145e8  c21400               ret 0x14
// 004145eb  eb03                 jmp 0x4145f0
// 004145ed  8d4900               lea ecx, [ecx]
// 004145f0  85ff                 test edi, edi
// 004145f2  7406                 je 0x4145fa
// 004145f4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004145f8  7406                 je 0x414600
// 004145fa  ffd5                 call ebp
// 004145fc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414600  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00414604  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00414608  741d                 je 0x414627
// 0041460a  8d4c2420             lea ecx, [esp + 0x20]
// 0041460e  e86d3f1200           call 0x538580
// 00414613  53                   push ebx
// 00414614  57                   push edi
// 00414615  8d442418             lea eax, [esp + 0x18]
// 00414619  50                   push eax
// 0041461a  8bce                 mov ecx, esi
// 0041461c  e84ff7ffff           call 0x413d70
// 00414621  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414625  ebc9                 jmp 0x4145f0
// 00414627  8b36                 mov esi, dword ptr [esi]
// 00414629  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041462d  5f                   pop edi
// 0041462e  8930                 mov dword ptr [eax], esi
// 00414630  5e                   pop esi
// 00414631  5d                   pop ebp
// 00414632  895804               mov dword ptr [eax + 4], ebx
// 00414635  5b                   pop ebx
// 00414636  83c408               add esp, 8
// 00414639  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
