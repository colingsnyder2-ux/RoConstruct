// from server: 100% by auto
// roc 2009-12 00440b90  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00440b90
//
// 00440b90  83ec08               sub esp, 8
// 00440b93  53                   push ebx
// 00440b94  55                   push ebp
// 00440b95  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 00440b9b  56                   push esi
// 00440b9c  8bf1                 mov esi, ecx
// 00440b9e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00440ba1  8b18                 mov ebx, dword ptr [eax]
// 00440ba3  8b06                 mov eax, dword ptr [esi]
// 00440ba5  57                   push edi
// 00440ba6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00440baa  85ff                 test edi, edi
// 00440bac  7404                 je 0x440bb2
// 00440bae  3bf8                 cmp edi, eax
// 00440bb0  7406                 je 0x440bb8
// 00440bb2  ffd5                 call ebp
// 00440bb4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00440bb8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00440bbc  7562                 jne 0x440c20
// 00440bbe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00440bc2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00440bc5  8b06                 mov eax, dword ptr [esi]
// 00440bc7  85c9                 test ecx, ecx
// 00440bc9  7404                 je 0x440bcf
// 00440bcb  3bc8                 cmp ecx, eax
// 00440bcd  7406                 je 0x440bd5
// 00440bcf  ffd5                 call ebp
// 00440bd1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00440bd5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00440bd9  7545                 jne 0x440c20
// 00440bdb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00440bde  8b5104               mov edx, dword ptr [ecx + 4]
// 00440be1  52                   push edx
// 00440be2  8bce                 mov ecx, esi
// 00440be4  e837feffff           call 0x440a20
// 00440be9  8b4618               mov eax, dword ptr [esi + 0x18]
// 00440bec  894004               mov dword ptr [eax + 4], eax
// 00440bef  8b4618               mov eax, dword ptr [esi + 0x18]
// 00440bf2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00440bf9  8900                 mov dword ptr [eax], eax
// 00440bfb  8b4618               mov eax, dword ptr [esi + 0x18]
// 00440bfe  894008               mov dword ptr [eax + 8], eax
// 00440c01  8b4618               mov eax, dword ptr [esi + 0x18]
// 00440c04  8b16                 mov edx, dword ptr [esi]
// 00440c06  8b08                 mov ecx, dword ptr [eax]
// 00440c08  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00440c0c  5f                   pop edi
// 00440c0d  5e                   pop esi
// 00440c0e  5d                   pop ebp
// 00440c0f  894804               mov dword ptr [eax + 4], ecx
// 00440c12  8910                 mov dword ptr [eax], edx
// 00440c14  5b                   pop ebx
// 00440c15  83c408               add esp, 8
// 00440c18  c21400               ret 0x14
// 00440c1b  eb03                 jmp 0x440c20
// 00440c1d  8d4900               lea ecx, [ecx]
// 00440c20  85ff                 test edi, edi
// 00440c22  7406                 je 0x440c2a
// 00440c24  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00440c28  7406                 je 0x440c30
// 00440c2a  ffd5                 call ebp
// 00440c2c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00440c30  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00440c34  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00440c38  741d                 je 0x440c57
// 00440c3a  8d4c2420             lea ecx, [esp + 0x20]
// 00440c3e  e81dc61800           call 0x5cd260
// 00440c43  53                   push ebx
// 00440c44  57                   push edi
// 00440c45  8d442418             lea eax, [esp + 0x18]
// 00440c49  50                   push eax
// 00440c4a  8bce                 mov ecx, esi
// 00440c4c  e80ff9ffff           call 0x440560
// 00440c51  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00440c55  ebc9                 jmp 0x440c20
// 00440c57  8b36                 mov esi, dword ptr [esi]
// 00440c59  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00440c5d  5f                   pop edi
// 00440c5e  8930                 mov dword ptr [eax], esi
// 00440c60  5e                   pop esi
// 00440c61  5d                   pop ebp
// 00440c62  895804               mov dword ptr [eax + 4], ebx
// 00440c65  5b                   pop ebx
// 00440c66  83c408               add esp, 8
// 00440c69  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
