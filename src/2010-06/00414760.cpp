// from server: 100% by auto
// roc 2010-06 00414760  unit: CopyVerb  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00414760
//
// 00414760  83ec08               sub esp, 8
// 00414763  53                   push ebx
// 00414764  55                   push ebp
// 00414765  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0041476b  56                   push esi
// 0041476c  8bf1                 mov esi, ecx
// 0041476e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414771  8b18                 mov ebx, dword ptr [eax]
// 00414773  8b06                 mov eax, dword ptr [esi]
// 00414775  57                   push edi
// 00414776  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041477a  85ff                 test edi, edi
// 0041477c  7404                 je 0x414782
// 0041477e  3bf8                 cmp edi, eax
// 00414780  7406                 je 0x414788
// 00414782  ffd5                 call ebp
// 00414784  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414788  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0041478c  7562                 jne 0x4147f0
// 0041478e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00414792  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00414795  8b06                 mov eax, dword ptr [esi]
// 00414797  85c9                 test ecx, ecx
// 00414799  7404                 je 0x41479f
// 0041479b  3bc8                 cmp ecx, eax
// 0041479d  7406                 je 0x4147a5
// 0041479f  ffd5                 call ebp
// 004147a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004147a5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004147a9  7545                 jne 0x4147f0
// 004147ab  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004147ae  8b5104               mov edx, dword ptr [ecx + 4]
// 004147b1  52                   push edx
// 004147b2  8bce                 mov ecx, esi
// 004147b4  e807feffff           call 0x4145c0
// 004147b9  8b4618               mov eax, dword ptr [esi + 0x18]
// 004147bc  894004               mov dword ptr [eax + 4], eax
// 004147bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 004147c2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004147c9  8900                 mov dword ptr [eax], eax
// 004147cb  8b4618               mov eax, dword ptr [esi + 0x18]
// 004147ce  894008               mov dword ptr [eax + 8], eax
// 004147d1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004147d4  8b16                 mov edx, dword ptr [esi]
// 004147d6  8b08                 mov ecx, dword ptr [eax]
// 004147d8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004147dc  5f                   pop edi
// 004147dd  5e                   pop esi
// 004147de  5d                   pop ebp
// 004147df  894804               mov dword ptr [eax + 4], ecx
// 004147e2  8910                 mov dword ptr [eax], edx
// 004147e4  5b                   pop ebx
// 004147e5  83c408               add esp, 8
// 004147e8  c21400               ret 0x14
// 004147eb  eb03                 jmp 0x4147f0
// 004147ed  8d4900               lea ecx, [ecx]
// 004147f0  85ff                 test edi, edi
// 004147f2  7406                 je 0x4147fa
// 004147f4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004147f8  7406                 je 0x414800
// 004147fa  ffd5                 call ebp
// 004147fc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414800  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00414804  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00414808  741d                 je 0x414827
// 0041480a  8d4c2420             lea ecx, [esp + 0x20]
// 0041480e  e81d220d00           call 0x4e6a30
// 00414813  53                   push ebx
// 00414814  57                   push edi
// 00414815  8d442418             lea eax, [esp + 0x18]
// 00414819  50                   push eax
// 0041481a  8bce                 mov ecx, esi
// 0041481c  e89ff7ffff           call 0x413fc0
// 00414821  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414825  ebc9                 jmp 0x4147f0
// 00414827  8b36                 mov esi, dword ptr [esi]
// 00414829  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041482d  5f                   pop edi
// 0041482e  8930                 mov dword ptr [eax], esi
// 00414830  5e                   pop esi
// 00414831  5d                   pop ebp
// 00414832  895804               mov dword ptr [eax + 4], ebx
// 00414835  5b                   pop ebx
// 00414836  83c408               add esp, 8
// 00414839  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
