// from server: 100% by auto
// roc 2009-12 007c8690  unit: RBX::ScoreHud  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c8690
//
// 007c8690  83ec08               sub esp, 8
// 007c8693  53                   push ebx
// 007c8694  55                   push ebp
// 007c8695  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 007c869b  56                   push esi
// 007c869c  8bf1                 mov esi, ecx
// 007c869e  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c86a1  8b18                 mov ebx, dword ptr [eax]
// 007c86a3  8b06                 mov eax, dword ptr [esi]
// 007c86a5  57                   push edi
// 007c86a6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c86aa  85ff                 test edi, edi
// 007c86ac  7404                 je 0x7c86b2
// 007c86ae  3bf8                 cmp edi, eax
// 007c86b0  7406                 je 0x7c86b8
// 007c86b2  ffd5                 call ebp
// 007c86b4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c86b8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 007c86bc  7562                 jne 0x7c8720
// 007c86be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007c86c2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 007c86c5  8b06                 mov eax, dword ptr [esi]
// 007c86c7  85c9                 test ecx, ecx
// 007c86c9  7404                 je 0x7c86cf
// 007c86cb  3bc8                 cmp ecx, eax
// 007c86cd  7406                 je 0x7c86d5
// 007c86cf  ffd5                 call ebp
// 007c86d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c86d5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 007c86d9  7545                 jne 0x7c8720
// 007c86db  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007c86de  8b5104               mov edx, dword ptr [ecx + 4]
// 007c86e1  52                   push edx
// 007c86e2  8bce                 mov ecx, esi
// 007c86e4  e8a7f1ffff           call 0x7c7890
// 007c86e9  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c86ec  894004               mov dword ptr [eax + 4], eax
// 007c86ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c86f2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007c86f9  8900                 mov dword ptr [eax], eax
// 007c86fb  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c86fe  894008               mov dword ptr [eax + 8], eax
// 007c8701  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c8704  8b16                 mov edx, dword ptr [esi]
// 007c8706  8b08                 mov ecx, dword ptr [eax]
// 007c8708  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007c870c  5f                   pop edi
// 007c870d  5e                   pop esi
// 007c870e  5d                   pop ebp
// 007c870f  894804               mov dword ptr [eax + 4], ecx
// 007c8712  8910                 mov dword ptr [eax], edx
// 007c8714  5b                   pop ebx
// 007c8715  83c408               add esp, 8
// 007c8718  c21400               ret 0x14
// 007c871b  eb03                 jmp 0x7c8720
// 007c871d  8d4900               lea ecx, [ecx]
// 007c8720  85ff                 test edi, edi
// 007c8722  7406                 je 0x7c872a
// 007c8724  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 007c8728  7406                 je 0x7c8730
// 007c872a  ffd5                 call ebp
// 007c872c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c8730  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007c8734  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 007c8738  741d                 je 0x7c8757
// 007c873a  8d4c2420             lea ecx, [esp + 0x20]
// 007c873e  e81d4be0ff           call 0x5cd260
// 007c8743  53                   push ebx
// 007c8744  57                   push edi
// 007c8745  8d442418             lea eax, [esp + 0x18]
// 007c8749  50                   push eax
// 007c874a  8bce                 mov ecx, esi
// 007c874c  e8dfecffff           call 0x7c7430
// 007c8751  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c8755  ebc9                 jmp 0x7c8720
// 007c8757  8b36                 mov esi, dword ptr [esi]
// 007c8759  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007c875d  5f                   pop edi
// 007c875e  8930                 mov dword ptr [eax], esi
// 007c8760  5e                   pop esi
// 007c8761  5d                   pop ebp
// 007c8762  895804               mov dword ptr [eax + 4], ebx
// 007c8765  5b                   pop ebx
// 007c8766  83c408               add esp, 8
// 007c8769  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
