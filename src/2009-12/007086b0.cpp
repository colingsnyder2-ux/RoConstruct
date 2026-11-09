// from server: 100% by auto
// roc 2009-12 007086b0  unit: RBX::VInstance::?$NonFactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007086b0
//
// 007086b0  83ec08               sub esp, 8
// 007086b3  53                   push ebx
// 007086b4  55                   push ebp
// 007086b5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 007086bb  56                   push esi
// 007086bc  8bf1                 mov esi, ecx
// 007086be  8b4618               mov eax, dword ptr [esi + 0x18]
// 007086c1  8b18                 mov ebx, dword ptr [eax]
// 007086c3  8b06                 mov eax, dword ptr [esi]
// 007086c5  57                   push edi
// 007086c6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007086ca  85ff                 test edi, edi
// 007086cc  7404                 je 0x7086d2
// 007086ce  3bf8                 cmp edi, eax
// 007086d0  7406                 je 0x7086d8
// 007086d2  ffd5                 call ebp
// 007086d4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007086d8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 007086dc  7562                 jne 0x708740
// 007086de  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007086e2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 007086e5  8b06                 mov eax, dword ptr [esi]
// 007086e7  85c9                 test ecx, ecx
// 007086e9  7404                 je 0x7086ef
// 007086eb  3bc8                 cmp ecx, eax
// 007086ed  7406                 je 0x7086f5
// 007086ef  ffd5                 call ebp
// 007086f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007086f5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 007086f9  7545                 jne 0x708740
// 007086fb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007086fe  8b5104               mov edx, dword ptr [ecx + 4]
// 00708701  52                   push edx
// 00708702  8bce                 mov ecx, esi
// 00708704  e8a7e6ffff           call 0x706db0
// 00708709  8b4618               mov eax, dword ptr [esi + 0x18]
// 0070870c  894004               mov dword ptr [eax + 4], eax
// 0070870f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00708712  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00708719  8900                 mov dword ptr [eax], eax
// 0070871b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0070871e  894008               mov dword ptr [eax + 8], eax
// 00708721  8b4618               mov eax, dword ptr [esi + 0x18]
// 00708724  8b16                 mov edx, dword ptr [esi]
// 00708726  8b08                 mov ecx, dword ptr [eax]
// 00708728  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0070872c  5f                   pop edi
// 0070872d  5e                   pop esi
// 0070872e  5d                   pop ebp
// 0070872f  894804               mov dword ptr [eax + 4], ecx
// 00708732  8910                 mov dword ptr [eax], edx
// 00708734  5b                   pop ebx
// 00708735  83c408               add esp, 8
// 00708738  c21400               ret 0x14
// 0070873b  eb03                 jmp 0x708740
// 0070873d  8d4900               lea ecx, [ecx]
// 00708740  85ff                 test edi, edi
// 00708742  7406                 je 0x70874a
// 00708744  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00708748  7406                 je 0x708750
// 0070874a  ffd5                 call ebp
// 0070874c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00708750  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00708754  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00708758  741d                 je 0x708777
// 0070875a  8d4c2420             lea ecx, [esp + 0x20]
// 0070875e  e8cda4ffff           call 0x702c30
// 00708763  53                   push ebx
// 00708764  57                   push edi
// 00708765  8d442418             lea eax, [esp + 0x18]
// 00708769  50                   push eax
// 0070876a  8bce                 mov ecx, esi
// 0070876c  e85feaffff           call 0x7071d0
// 00708771  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00708775  ebc9                 jmp 0x708740
// 00708777  8b36                 mov esi, dword ptr [esi]
// 00708779  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0070877d  5f                   pop edi
// 0070877e  8930                 mov dword ptr [eax], esi
// 00708780  5e                   pop esi
// 00708781  5d                   pop ebp
// 00708782  895804               mov dword ptr [eax + 4], ebx
// 00708785  5b                   pop ebx
// 00708786  83c408               add esp, 8
// 00708789  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
